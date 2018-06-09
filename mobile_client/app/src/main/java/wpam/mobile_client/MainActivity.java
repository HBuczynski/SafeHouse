package wpam.mobile_client;

import wpam.mobile_client.protocol.*;
import wpam.mobile_client.client.*;

import android.content.Intent;
import android.os.Bundle;
import android.os.Message;
import android.support.annotation.NonNull;
import android.support.constraint.solver.widgets.Snapshot;
import android.support.design.widget.BottomNavigationView;
import android.support.v7.app.AppCompatActivity;
import android.view.MenuItem;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;



public class MainActivity extends AppCompatActivity {

    private TextView mTextMessage;
    private ImageView viewer;
    private String address;
    private String port;
    private final static String TAG = "MainActivity";


    ClientThread clientThread;

    private BottomNavigationView.OnNavigationItemSelectedListener mOnNavigationItemSelectedListener
            = new BottomNavigationView.OnNavigationItemSelectedListener() {

        @Override
        public boolean onNavigationItemSelected(@NonNull MenuItem item) {

            switch (item.getItemId()) {
                case R.id.logger: {


                    return true;
                }
                case R.id.blinds: {


                    return true;
                }
                case R.id.snpashot:
                {
                    SnapshotCommand command = new SnapshotCommand();
                    try
                    {
                        Message msg = new Message();
                        msg.obj = command;
                        clientThread.sendHandler.sendMessage(msg);
                    }
                    catch (Exception e)
                    {
                        e.printStackTrace();
                    }

                    Intent intent = new Intent(getApplicationContext(), SnapshotActivity.class);
                    startActivity(intent);

                    return true;
                }
            }
            return false;
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mTextMessage = (TextView) findViewById(R.id.message);
        BottomNavigationView navigation = (BottomNavigationView) findViewById(R.id.navigation);
        navigation.setOnNavigationItemSelectedListener(mOnNavigationItemSelectedListener);

        address = getIntent().getStringExtra("ipAdress");
        port = getIntent().getStringExtra("port");

        clientThread = new ClientThread(address, port);

        //TODO: catch exception or do it better !!
        new Thread(clientThread).start();

        viewer = (ImageView) findViewById(R.id.viewer);
        viewer.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v)
            {
                Intent intent = new Intent(getApplicationContext(), StreamActivity.class);
                intent.putExtra("ipAdress", address);

                StartStreamCommand command = new StartStreamCommand();
                try
                {
                    Message msg = new Message();
                    msg.obj = command;
                    clientThread.sendHandler.sendMessage(msg);
                }
                catch (Exception e)
                {
                    e.printStackTrace();
                }

                startActivity(intent);
            }
        });
    }

}
