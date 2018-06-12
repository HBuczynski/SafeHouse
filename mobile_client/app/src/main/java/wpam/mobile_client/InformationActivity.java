package wpam.mobile_client;

import android.os.Bundle;
import android.os.PersistableBundle;
import android.preference.CheckBoxPreference;
import android.preference.Preference;
import android.preference.PreferenceActivity;

import wpam.mobile_client.client.ClientThread;

public class InformationActivity extends PreferenceActivity {
    ClientThread client;
    Preference logger;
    Preference blinds;
    Preference guard;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        addPreferencesFromResource(R.xml.information);

        client = ClientThread.getInstance();


        guard = (Preference) findPreference("guard_state");
        logger = (Preference) findPreference("logger_state");
        blinds = (Preference) findPreference("blidns_state");

        logger.setSummary(client.getLogdata());
        blinds.setSummary(client.getBlindsStatus());

        if(client.getUserFlag())
        {
            guard.setSummary("User is out of home");
        }
        else
        {
            guard.setSummary("User is in home");
        }
    }
}
