package wpam.mobile_client;

import android.content.Intent;
import android.preference.Preference;
import android.preference.PreferenceActivity;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class TemperatureActivity extends PreferenceActivity {

    Preference temp_I;
    Preference temp_II;
    Preference temp_III;
    final String tempUnits = " \u00b0" + " C";

    Preference humidity_I;
    Preference humidity_II;
    Preference humidity_III;
    final String humidityUnits = " RH";

    Preference luminacia_I;
    Preference luminacia_II;
    Preference luminacia_III;
    final String luminaciaUnits = " lx";

    Preference plot_I;
    Preference plot_II;
    Preference plot_III;

    Preference globalPlot;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        addPreferencesFromResource(R.xml.temperature_preferences);

        temp_I = (Preference) findPreference("temp_I");
        temp_I.setSummary(0 + tempUnits);
        temp_II = (Preference) findPreference("temp_II");
        temp_II.setSummary(0 + tempUnits);
        temp_III = (Preference) findPreference("temp_III");
        temp_III.setSummary(0 + tempUnits);

        humidity_I = (Preference) findPreference("humidity_I");
        humidity_I.setSummary(0 + humidityUnits);
        humidity_II = (Preference) findPreference("humidity_II");
        humidity_II.setSummary(0 + humidityUnits);
        humidity_III = (Preference) findPreference("humidity_III");
        humidity_III.setSummary(0 + humidityUnits);

        luminacia_I = (Preference) findPreference("luminacia_I");
        luminacia_I.setSummary(0 + luminaciaUnits);
        luminacia_II = (Preference) findPreference("luminacia_II");
        luminacia_II.setSummary(0 + luminaciaUnits);
        luminacia_III = (Preference) findPreference("luminacia_III");
        luminacia_III.setSummary(0 + luminaciaUnits);

        plot_I = (Preference) findPreference("plot_I");
        plot_II = (Preference) findPreference("plot_II");
        plot_III = (Preference) findPreference("plot_III");

        globalPlot = (Preference) findPreference("summary_plot");

        setListeners();
    }

    private void setListeners() {

        plot_I.setOnPreferenceClickListener( new Preference.OnPreferenceClickListener() {
             @Override
             public boolean onPreferenceClick(Preference preference) {
             Intent intent = new Intent(getApplicationContext(), Plot.class);
             startActivity(intent);
             return true;
             }
         });

        plot_II.setOnPreferenceClickListener( new Preference.OnPreferenceClickListener() {
            @Override
            public boolean onPreferenceClick(Preference preference) {
            Intent intent = new Intent(getApplicationContext(), Plot.class);
            startActivity(intent);
            return true;
            }
        });

        plot_III.setOnPreferenceClickListener( new Preference.OnPreferenceClickListener() {
            @Override
            public boolean onPreferenceClick(Preference preference) {
            Intent intent = new Intent(getApplicationContext(), Plot.class);
            startActivity(intent);
            return true;
            }
        });

        globalPlot.setOnPreferenceClickListener( new Preference.OnPreferenceClickListener() {
            @Override
            public boolean onPreferenceClick(Preference preference) {
            Intent intent = new Intent(getApplicationContext(), Plot.class);
            startActivity(intent);
            return true;
            }
        });
    }
}
