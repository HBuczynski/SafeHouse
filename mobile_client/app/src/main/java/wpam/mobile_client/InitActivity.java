package wpam.mobile_client;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.TextView;

import wpam.mobile_client.client.ClientThread;


public class InitActivity extends AppCompatActivity {

    private TextView ipAddress;
    private TextView portNumber;
    private TextView warning;
    private Button connectButton;
    private ProgressBar progressBar;

    private ClientThread client;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.init);

        ipAddress = (TextView)findViewById(R.id.ip_address);
        portNumber = (TextView)findViewById(R.id.port_number);
        warning = (TextView)findViewById(R.id.warning_label);
        connectButton = (Button)findViewById(R.id.connect_button);
        progressBar = (ProgressBar)findViewById(R.id.progress_bar);
        progressBar.setVisibility(View.INVISIBLE);

        connectButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v)
            {

                progressBar.setVisibility(View.VISIBLE);
                String ip = ipAddress.getText().toString();
                String port = portNumber.getText().toString();

                ClientThread.setPort(port);
                ClientThread.setAdress(ip);

                client = ClientThread.getInstance();
                new Thread(client).start();

                android.os.SystemClock.sleep(200);

//                if (client.isConnect) {
                    warning.setText("");
                    Intent intent = new Intent(getApplicationContext(), MainActivity.class);

                    startActivity(intent);
                    finish();
//                } else if (!client.isConnect){
//                    progressBar.setVisibility(View.INVISIBLE);
//
//                    warning.setText("Cannot connect !");
//                }

            }
        });
    }
}
