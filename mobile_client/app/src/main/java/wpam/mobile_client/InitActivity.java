package wpam.mobile_client;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.TextView;


public class InitActivity extends AppCompatActivity {

    private TextView ipAddress;
    private TextView portNumber;
    private TextView warning;
    private Button connectButton;
    private ProgressBar progressBar;

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

                Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                intent.putExtra("ipAdress", ip);
                intent.putExtra("port", port);

                startActivity(intent);
                finish();
            }
        });
    }
}
