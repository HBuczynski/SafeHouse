package wpam.mobile_client;

import android.os.Bundle;
import android.preference.EditTextPreference;
import android.preference.Preference;
import android.preference.PreferenceActivity;

import wpam.mobile_client.client.ClientThread;

public class InformationActivity extends PreferenceActivity {
    ClientThread client;
    EditTextPreference logger;
    Preference blinds;
    Preference guard;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        addPreferencesFromResource(R.xml.information);

        client = ClientThread.getInstance();


        guard = (Preference) findPreference("guard_state");
        logger = (EditTextPreference) findPreference("logger_state");
        blinds = (Preference) findPreference("blidns_state");

        logger.setSummary(client.getLogData());
        blinds.setSummary(client.getBlindsStatus());

        if(client.getUserInHome())
        {
            guard.setSummary("User is in home");
        }
        else
        {
            guard.setSummary("User is out of home");
        }
    }
}
