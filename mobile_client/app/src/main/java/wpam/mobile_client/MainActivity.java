package wpam.mobile_client;

import wpam.mobile_client.protocol.*;
import wpam.mobile_client.client.*;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Message;
import android.support.annotation.NonNull;
import android.support.design.widget.BottomNavigationView;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.MenuItem;
import android.webkit.WebView;
import android.widget.ImageView;
import android.widget.TextView;



public class MainActivity extends AppCompatActivity {

    private TextView mTextMessage;
    private final static String TAG = "MainActivity";
    private ImageView imageView;

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

                    clientThread = new ClientThread("89.65.72.7", "9000");
                    new Thread(clientThread).start();

                    mTextMessage.setText(R.string.title_dashboard);
                    return true;
                }
                case R.id.navigation_notifications:
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


                    String url = "http://89.65.72.7/img.jpg";
                    new com.concretepage.AsyncTaskLoadImage(imageView).execute(url);

                    mTextMessage.setText(R.string.title_notifications);
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
        imageView = (ImageView)findViewById(R.id.image);
        BottomNavigationView navigation = (BottomNavigationView) findViewById(R.id.navigation);
        navigation.setOnNavigationItemSelectedListener(mOnNavigationItemSelectedListener);
    }

}
