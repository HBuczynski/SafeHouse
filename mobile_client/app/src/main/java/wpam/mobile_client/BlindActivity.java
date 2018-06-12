package wpam.mobile_client;

import android.os.Bundle;
import android.os.Message;
import android.preference.CheckBoxPreference;
import android.preference.EditTextPreference;
import android.preference.Preference;
import android.preference.PreferenceActivity;

import wpam.mobile_client.client.ClientThread;
import wpam.mobile_client.protocol.AutomaticBlindsCommand;
import wpam.mobile_client.protocol.Command;
import wpam.mobile_client.protocol.GuardStatusCommand;
import wpam.mobile_client.protocol.UserInHomeCommand;
import wpam.mobile_client.protocol.UserOutOfHomeCommand;

public class BlindActivity extends PreferenceActivity {

    ClientThread client;

    CheckBoxPreference userOutHome;
    CheckBoxPreference userInHome;
    CheckBoxPreference automaticBlinds;

    EditTextPreference upOnTime;
    EditTextPreference downOnTime;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        addPreferencesFromResource(R.xml.preferences);

        client = ClientThread.getInstance();

        userOutHome = (CheckBoxPreference)findPreference("user_out_home");
        userInHome = (CheckBoxPreference)findPreference("user_in_home");
        automaticBlinds = (CheckBoxPreference)findPreference("automatic_blinds");

        upOnTime = (EditTextPreference)findPreference("up_on_time");
        downOnTime = (EditTextPreference)findPreference("down_on_time");

        if(client.getUserInHome())
        {
            userInHome.setEnabled(true);
            userInHome.setChecked(true);
            userOutHome.setEnabled(false);
            userOutHome.setChecked(false);
        }
        else
        {
            userOutHome.setEnabled(true);
            userOutHome.setChecked(true);
            userInHome.setEnabled(false);
            userInHome.setChecked(false);
        }

        setListeners();
        }

    private void setListeners()
    {
        userOutHome.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
            @Override
            public boolean onPreferenceClick(Preference preference) {
                CheckBoxPreference checkBoxPreference = (CheckBoxPreference)preference;
                if(checkBoxPreference.isChecked())
                {
                    UserOutOfHomeCommand guardStatusCommand = new UserOutOfHomeCommand();
                    sendMessage(guardStatusCommand);
                }
                else
                {
                    userInHome.setEnabled(true);
                }

                return true;
            }
        });

        userInHome.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
            @Override
            public boolean onPreferenceClick(Preference preference) {
                CheckBoxPreference checkBoxPreference = (CheckBoxPreference)preference;
                if(checkBoxPreference.isChecked())
                {
                    UserInHomeCommand guardStatusCommand = new UserInHomeCommand();
                    sendMessage(guardStatusCommand);
                }
                else
                {
                    userOutHome.setEnabled(true);
                }

                return true;
            }
        });

        automaticBlinds.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
            @Override
            public boolean onPreferenceClick(Preference preference) {
                CheckBoxPreference checkBoxPreference = (CheckBoxPreference)preference;
                if(checkBoxPreference.isChecked())
                {
                    AutomaticBlindsCommand automaticBlindsCommand = new AutomaticBlindsCommand();
                    sendMessage(automaticBlindsCommand);

                    upOnTime.setEnabled(false);
                    downOnTime.setEnabled(false);
                }
                else
                {
                    upOnTime.setEnabled(true);
                    downOnTime.setEnabled(true);
                }
                return true;
            }
        });

    }

    private void sendMessage(Command command)
    {
        try
        {
            Message msg = new Message();
            msg.obj = command;
            client.sendHandler.sendMessage(msg);
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }

    }
}
