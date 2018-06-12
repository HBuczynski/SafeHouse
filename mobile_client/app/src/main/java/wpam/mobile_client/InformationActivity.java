package wpam.mobile_client;

import android.os.Bundle;
import android.preference.PreferenceActivity;

import wpam.mobile_client.client.ClientThread;

public class InformationActivity extends PreferenceActivity {
    ClientThread client;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        addPreferencesFromResource(R.xml.information);

        client = ClientThread.getInstance();
    }
}
