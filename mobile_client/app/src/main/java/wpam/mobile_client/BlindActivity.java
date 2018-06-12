package wpam.mobile_client;

import android.os.Bundle;
import android.os.Message;
import android.preference.CheckBoxPreference;
import android.preference.EditTextPreference;
import android.preference.Preference;
import android.preference.PreferenceActivity;
import android.widget.ImageView;

import wpam.mobile_client.client.ClientThread;
import wpam.mobile_client.protocol.Command;

public class BlindActivity extends PreferenceActivity {

    ClientThread client;

    CheckBoxPreference userOutHome;
    CheckBoxPreference userInHome;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        addPreferencesFromResource(R.xml.preferences);

        client = ClientThread.getInstance();

        userOutHome = (CheckBoxPreference)findPreference("user_out_home");
        userInHome = (CheckBoxPreference)findPreference("user_in_home");

        if(userOutHome.isChecked())
        {
            userInHome.setEnabled(false);
        }

        if(userInHome.isChecked())
        {
            userOutHome.setEnabled(false);
        }

        setListeners();
        }

    private void setListeners()
    {
        userOutHome.setOnPreferenceChangeListener(new Preference.OnPreferenceChangeListener() {
            @Override
            public boolean onPreferenceChange(Preference preference, Object newValue) {

                CheckBoxPreference checkBoxPreference = (CheckBoxPreference)preference;
                if(checkBoxPreference.isChecked())
                {
                    userInHome.setEnabled(true);
                }
                else
                {
                    userInHome.setEnabled(false);
                }

                return true;
            }
        });

        userInHome.setOnPreferenceChangeListener(new Preference.OnPreferenceChangeListener() {
            @Override
            public boolean onPreferenceChange(Preference preference, Object newValue) {

                CheckBoxPreference checkBoxPreference = (CheckBoxPreference)preference;
                if(checkBoxPreference.isChecked())
                {
                    userOutHome.setEnabled(true);
                }
                else
                {
                    userOutHome.setEnabled(false);
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
