package wpam.mobile_client;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;

import wpam.mobile_client.client.ClientThread;

public class BlindActivity extends AppCompatActivity {

    ClientThread client;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.blinds);

        client = ClientThread.getInstance();

        }
}
