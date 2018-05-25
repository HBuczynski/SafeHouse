package wpam.mobile_client;

import wpam.mobile_client.protocol.*;
import wpam.mobile_client.client.*;

import android.os.Bundle;
import android.os.Message;
import android.support.annotation.NonNull;
import android.support.design.widget.BottomNavigationView;
import android.support.v7.app.AppCompatActivity;
import android.view.MenuItem;
import android.widget.TextView;



public class MainActivity extends AppCompatActivity {

    private TextView mTextMessage;
    ClientThread clientThread;

    private BottomNavigationView.OnNavigationItemSelectedListener mOnNavigationItemSelectedListener
            = new BottomNavigationView.OnNavigationItemSelectedListener() {

        @Override
        public boolean onNavigationItemSelected(@NonNull MenuItem item) {
            switch (item.getItemId()) {
                case R.id.navigation_home:
                    mTextMessage.setText(R.string.title_home);
                    return true;
                case R.id.navigation_dashboard: {

                    clientThread = new ClientThread("10.0.2.2", "9000");
                    new Thread(clientThread).start();

                    mTextMessage.setText(R.string.title_dashboard);
                    return true;
                }
                case R.id.navigation_notifications:
                {
                    BlindsUPCommand command = new BlindsUPCommand();
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

                    mTextMessage.setText(R.string.title_notifications);
                    return true;}
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
    }

}
