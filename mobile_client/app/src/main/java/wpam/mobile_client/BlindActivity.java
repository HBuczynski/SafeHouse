package wpam.mobile_client;

import android.os.Bundle;
import android.preference.PreferenceActivity;
import android.widget.ImageView;

import wpam.mobile_client.client.ClientThread;

public class BlindActivity extends PreferenceActivity {

    ClientThread client;

    ImageView image;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        addPreferencesFromResource(R.xml.preferences);


        client = ClientThread.getInstance();



        }
}
