package wpam.mobile_client;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Message;
import android.preference.CheckBoxPreference;
import android.preference.Preference;
import android.preference.PreferenceActivity;
import android.os.Bundle;
import android.support.v4.content.LocalBroadcastManager;

import java.util.ArrayList;

import wpam.mobile_client.client.ClientThread;
import wpam.mobile_client.protocol.BlindsUPCommand;
import wpam.mobile_client.protocol.SensorTagSamplesCommand;
import wpam.mobile_client.sensor_tag.ParameterType;
import wpam.mobile_client.sensor_tag.ParametersConverter;
import wpam.mobile_client.sensor_tag.SensorDataType;
import wpam.mobile_client.sensor_tag.SensorTagType;
import wpam.mobile_client.sensor_tag.SensorsInterface;
import wpam.mobile_client.utility.Utility;

public class TemperatureActivity extends PreferenceActivity implements SensorsInterface {

    ClientThread clientThread;
    CheckBoxPreference temp_I;
    CheckBoxPreference temp_II;

    CheckBoxPreference temp_III;
    final String tempUnits = " \u00b0" + " C";

    CheckBoxPreference humidity_I;
    CheckBoxPreference humidity_II;
    CheckBoxPreference humidity_III;
    final String humidityUnits = " RH";

    CheckBoxPreference luminacia_I;
    CheckBoxPreference luminacia_II;
    CheckBoxPreference luminacia_III;
    final String luminaciaUnits = " lx";

    Preference plot_I;
    Preference plot_II;
    Preference plot_III;

    Preference globalPlot;
    CheckBoxPreference globalTemp;
    CheckBoxPreference globalHumidity;
    CheckBoxPreference globalLuminacia;

    ParameterType currentParameter;
    SensorTagType sensorTagType;
    SensorDataType dataType;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        addPreferencesFromResource(R.xml.temperature_preferences);

        clientThread = ClientThread.getInstance();
        clientThread.setSensorsTagInterface(this);

        LocalBroadcastManager.getInstance(this).registerReceiver(mReceiver, new IntentFilter("SensorTagSamplesResponse"));

        temp_I = (CheckBoxPreference) findPreference("temp_I");
        temp_I.setSummary(0 + tempUnits);
        temp_II = (CheckBoxPreference) findPreference("temp_II");
        temp_II.setSummary(0 + tempUnits);
        temp_III = (CheckBoxPreference) findPreference("temp_III");
        temp_III.setSummary(0 + tempUnits);
        //globalTemp = (CheckBoxPreference) findPreference("tempCheck");

        humidity_I = (CheckBoxPreference) findPreference("humidity_I");
        humidity_I.setSummary(0 + humidityUnits);
        humidity_II = (CheckBoxPreference) findPreference("humidity_II");
        humidity_II.setSummary(0 + humidityUnits);
        humidity_III = (CheckBoxPreference) findPreference("humidity_III");
        humidity_III.setSummary(0 + humidityUnits);
        //globalHumidity = (CheckBoxPreference) findPreference("humidityCheck");

        luminacia_I = (CheckBoxPreference) findPreference("luminacia_I");
        luminacia_I.setSummary(0 + luminaciaUnits);
        luminacia_II = (CheckBoxPreference) findPreference("luminacia_II");
        luminacia_II.setSummary(0 + luminaciaUnits);
        luminacia_III = (CheckBoxPreference) findPreference("luminacia_III");
        luminacia_III.setSummary(0 + luminaciaUnits);
        //globalLuminacia = (CheckBoxPreference) findPreference("luminaciaCheck");

//        plot_I = (Preference) findPreference("plot_I");
//        plot_II = (Preference) findPreference("plot_II");
//        plot_III = (Preference) findPreference("plot_III");

        globalPlot = (Preference) findPreference("summary_plot");

        setPlotListeners();
        setCheckboxListenersI();
        setCheckboxListenersII();
        setCheckboxListenersIII();
        setCheckboxListenersGlobal();
        resetCheckBoxes();

        SensorTagSamplesCommand command = new SensorTagSamplesCommand();
        try {
            Message msg = new Message();
            msg.obj = command;
            clientThread.sendHandler.sendMessage(msg);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    BroadcastReceiver mReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            ArrayList<Integer> data = intent.getIntegerArrayListExtra("data");
            singleSamples(data);
        }
    };

    private void setPlotListeners() {

//        plot_I.setOnPreferenceClickListener( new Preference.OnPreferenceClickListener() {
//             @Override
//             public boolean onPreferenceClick(Preference preference) {
//             Intent intent = new Intent(getApplicationContext(), Plot.class);
//             intent.putExtras(plotArguments());
//             startActivity(intent);
//             return true;
//             }
//         });
//
//        plot_II.setOnPreferenceClickListener( new Preference.OnPreferenceClickListener() {
//            @Override
//            public boolean onPreferenceClick(Preference preference) {
//            Intent intent = new Intent(getApplicationContext(), Plot.class);
//            intent.putExtras(plotArguments());
//            startActivity(intent);
//            return true;
//            }
//        });
//
//        plot_III.setOnPreferenceClickListener( new Preference.OnPreferenceClickListener() {
//            @Override
//            public boolean onPreferenceClick(Preference preference) {
//            Intent intent = new Intent(getApplicationContext(), Plot.class);
//            intent.putExtras(plotArguments());
//            startActivity(intent);
//            return true;
//            }
//        });

        globalPlot.setOnPreferenceClickListener( new Preference.OnPreferenceClickListener() {
            @Override
            public boolean onPreferenceClick(Preference preference) {
//            Intent intent = new Intent(getApplicationContext(), Plot.class);
//            intent.putExtras(plotArguments());
//            startActivity(intent);
            SensorTagSamplesCommand command = new SensorTagSamplesCommand();
            try {
                Message msg = new Message();
                msg.obj = command;
                clientThread.sendHandler.sendMessage(msg);
            } catch (Exception e) {
                e.printStackTrace();
            }

            return true;
            }
        });
    }

    private Bundle plotArguments() {
        Bundle bundle = new Bundle();
        bundle.putSerializable(SensorTagType.getName(), sensorTagType);
        bundle.putSerializable(ParameterType.getName(), currentParameter);
        bundle.putSerializable(SensorDataType.getName(), dataType);

        return  bundle;
    }

    private void setCheckboxListenersI() {
        temp_I.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
            @Override
            public boolean onPreferenceClick(Preference preference) {
                CheckBoxPreference checkBoxPreference = (CheckBoxPreference)preference;
                if(checkBoxPreference.isChecked()) {
                    humidity_I.setEnabled(false);
                    luminacia_I.setEnabled(false);

                    sensorTagType = SensorTagType.FIRST;
                    currentParameter = ParameterType.TEMPERATURE;
                    dataType = SensorDataType.PLOT;
                } else {
                    humidity_I.setEnabled(true);
                    luminacia_I.setEnabled(true);

                    sensorTagType = null;
                    currentParameter = null;
                    dataType = null;
                }
                return true;
            }
        });

        humidity_I.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
            @Override
            public boolean onPreferenceClick(Preference preference) {
                CheckBoxPreference checkBoxPreference = (CheckBoxPreference)preference;
                if(checkBoxPreference.isChecked()) {
                    temp_I.setEnabled(false);
                    luminacia_I.setEnabled(false);

                    sensorTagType = SensorTagType.FIRST;
                    currentParameter = ParameterType.HUMIDITY;
                    dataType = SensorDataType.PLOT;
                } else {
                    temp_I.setEnabled(true);
                    luminacia_I.setEnabled(true);

                    sensorTagType = null;
                    currentParameter = null;
                    dataType = null;
                }
                return true;
            }
        });

        luminacia_I.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
            @Override
            public boolean onPreferenceClick(Preference preference) {
                CheckBoxPreference checkBoxPreference = (CheckBoxPreference)preference;
                if(checkBoxPreference.isChecked()) {
                    temp_I.setEnabled(false);
                    humidity_I.setEnabled(false);

                    sensorTagType = SensorTagType.FIRST;
                    currentParameter = ParameterType.LUMINACIA;
                    dataType = SensorDataType.PLOT;
                } else {
                    temp_I.setEnabled(true);
                    humidity_I.setEnabled(true);

                    sensorTagType = null;
                    currentParameter = null;
                    dataType = null;
                }
                return true;
            }
        });
    }

    private void setCheckboxListenersII() {
        temp_II.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
            @Override
            public boolean onPreferenceClick(Preference preference) {
                CheckBoxPreference checkBoxPreference = (CheckBoxPreference)preference;
                if(checkBoxPreference.isChecked()) {
                    humidity_II.setEnabled(false);
                    luminacia_II.setEnabled(false);

                    sensorTagType = SensorTagType.SECOND;
                    currentParameter = ParameterType.TEMPERATURE;
                    dataType = SensorDataType.PLOT;
                } else {
                    humidity_II.setEnabled(true);
                    luminacia_II.setEnabled(true);

                    sensorTagType = null;
                    currentParameter = null;
                    dataType = null;
                }
                return true;
            }
        });

        humidity_II.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
            @Override
            public boolean onPreferenceClick(Preference preference) {
                CheckBoxPreference checkBoxPreference = (CheckBoxPreference)preference;
                if(checkBoxPreference.isChecked()) {
                    temp_II.setEnabled(false);
                    luminacia_II.setEnabled(false);

                    sensorTagType = SensorTagType.SECOND;
                    currentParameter = ParameterType.HUMIDITY;
                    dataType = SensorDataType.PLOT;
                } else {
                    temp_II.setEnabled(true);
                    luminacia_II.setEnabled(true);

                    sensorTagType = null;
                    currentParameter = null;
                    dataType = null;
                }
                return true;
            }
        });

        luminacia_II.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
            @Override
            public boolean onPreferenceClick(Preference preference) {
                CheckBoxPreference checkBoxPreference = (CheckBoxPreference)preference;
                if(checkBoxPreference.isChecked()) {
                    temp_II.setEnabled(false);
                    humidity_II.setEnabled(false);

                    sensorTagType = SensorTagType.SECOND;
                    currentParameter = ParameterType.LUMINACIA;
                    dataType = SensorDataType.PLOT;
                } else {
                    temp_II.setEnabled(true);
                    humidity_II.setEnabled(true);

                    sensorTagType = null;
                    currentParameter = null;
                    dataType = null;
                }
                return true;
            }
        });
    }

    private void setCheckboxListenersIII() {
        temp_III.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
            @Override
            public boolean onPreferenceClick(Preference preference) {
                CheckBoxPreference checkBoxPreference = (CheckBoxPreference)preference;
                if(checkBoxPreference.isChecked()) {
                    humidity_III.setEnabled(false);
                    luminacia_III.setEnabled(false);

                    sensorTagType = SensorTagType.THIRD;
                    currentParameter = ParameterType.TEMPERATURE;
                    dataType = SensorDataType.PLOT;
                } else {
                    humidity_III.setEnabled(true);
                    luminacia_III.setEnabled(true);

                    sensorTagType = null;
                    currentParameter = null;
                    dataType = null;
                }
                return true;
            }
        });

        humidity_III.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
            @Override
            public boolean onPreferenceClick(Preference preference) {
                CheckBoxPreference checkBoxPreference = (CheckBoxPreference)preference;
                if(checkBoxPreference.isChecked()) {
                    temp_III.setEnabled(false);
                    luminacia_III.setEnabled(false);

                    sensorTagType = SensorTagType.THIRD;
                    currentParameter = ParameterType.HUMIDITY;
                    dataType = SensorDataType.PLOT;
                } else {
                    temp_III.setEnabled(true);
                    luminacia_III.setEnabled(true);

                    sensorTagType = null;
                    currentParameter = null;
                    dataType = null;
                }
                return true;
            }
        });

        luminacia_III.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
            @Override
            public boolean onPreferenceClick(Preference preference) {
                CheckBoxPreference checkBoxPreference = (CheckBoxPreference)preference;
                if(checkBoxPreference.isChecked()) {
                    temp_III.setEnabled(false);
                    humidity_III.setEnabled(false);

                    sensorTagType = SensorTagType.THIRD;
                    currentParameter = ParameterType.LUMINACIA;
                    dataType = SensorDataType.PLOT;
                } else {
                    temp_III.setEnabled(true);
                    humidity_III.setEnabled(true);

                    sensorTagType = null;
                    currentParameter = null;
                    dataType = null;
                }
                return true;
            }
        });
    }

    private void setCheckboxListenersGlobal() {
//        globalTemp.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
//            @Override
//            public boolean onPreferenceClick(Preference preference) {
//                CheckBoxPreference checkBoxPreference = (CheckBoxPreference)preference;
//                if(checkBoxPreference.isChecked()) {
//                    globalHumidity.setEnabled(false);
//                    globalLuminacia.setEnabled(false);
//
//                    sensorTagType = SensorTagType.ALL;
//                    currentParameter = ParameterType.TEMPERATURE;
//                    dataType = SensorDataType.PLOT;
//                } else {
//                    globalHumidity.setEnabled(true);
//                    globalLuminacia.setEnabled(true);
//
//                    sensorTagType = null;
//                    currentParameter = null;
//                    dataType = null;
//                }
//                return true;
//            }
//        });
//
//        globalHumidity.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
//            @Override
//            public boolean onPreferenceClick(Preference preference) {
//                CheckBoxPreference checkBoxPreference = (CheckBoxPreference)preference;
//                if(checkBoxPreference.isChecked()) {
//                    globalTemp.setEnabled(false);
//                    globalLuminacia.setEnabled(false);
//
//                    sensorTagType = SensorTagType.ALL;
//                    currentParameter = ParameterType.HUMIDITY;
//                    dataType = SensorDataType.PLOT;
//                } else {
//                    globalTemp.setEnabled(true);
//                    globalLuminacia.setEnabled(true);
//
//                    sensorTagType = null;
//                    currentParameter = null;
//                    dataType = null;
//                }
//                return true;
//            }
//        });
//
//        globalLuminacia.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
//            @Override
//            public boolean onPreferenceClick(Preference preference) {
//                CheckBoxPreference checkBoxPreference = (CheckBoxPreference)preference;
//                if(checkBoxPreference.isChecked()) {
//                    globalTemp.setEnabled(false);
//                    globalHumidity.setEnabled(false);
//
//                    sensorTagType = SensorTagType.ALL;
//                    currentParameter = ParameterType.LUMINACIA;
//                    dataType = SensorDataType.PLOT;
//                } else {
//                    globalTemp.setEnabled(true);
//                    globalHumidity.setEnabled(true);
//
//                    sensorTagType = null;
//                    currentParameter = null;
//                    dataType = null;
//                }
//                return true;
//            }
//        });
    }

    @Override
    public void singleSamples(ArrayList<Integer> data) {
        if(data.size() == 9) {
            temp_I.setSummary(ParametersConverter.getTemperatureCelcius(data.get(0)) + tempUnits);
            humidity_I.setSummary(ParametersConverter.getHumidity(data.get(1)) + humidityUnits);
            luminacia_I.setSummary(ParametersConverter.getOptical(data.get(2)) + luminaciaUnits);

            temp_II.setSummary(data.get(3) + tempUnits);
            humidity_II.setSummary(data.get(4) + humidityUnits);
            luminacia_II.setSummary(data.get(5) + luminaciaUnits);

            temp_III.setSummary(data.get(6) + tempUnits);
            humidity_III.setSummary(data.get(7) + humidityUnits);
            luminacia_III.setSummary(data.get(8) + luminaciaUnits);
        }
    }

    private void resetCheckBoxes() {
        temp_I.setChecked(false);
        temp_II.setChecked(false);
        temp_III.setChecked(false);
        //globalTemp.setChecked(false);

        humidity_I.setChecked(false);
        humidity_II.setChecked(false);
        humidity_III.setChecked(false);
        //globalHumidity.setChecked(false);

        luminacia_I.setChecked(false);
        luminacia_II.setChecked(false);
        luminacia_III.setChecked(false);
        //globalLuminacia.setChecked(false);
    }
}
