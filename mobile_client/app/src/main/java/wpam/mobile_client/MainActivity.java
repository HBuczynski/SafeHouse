package wpam.mobile_client;

import wpam.mobile_client.protocol.*;
import wpam.mobile_client.client.*;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.support.annotation.NonNull;
import android.support.constraint.solver.widgets.Snapshot;
import android.support.design.widget.BottomNavigationView;
import android.support.v4.content.ContextCompat;
import android.support.v4.graphics.drawable.DrawableCompat;
import android.support.v7.app.AppCompatActivity;
import android.view.MenuItem;
import android.view.View;
import android.widget.ImageView;
import android.widget.SeekBar;
import android.widget.TextView;

import static java.security.AccessController.getContext;


public class MainActivity extends AppCompatActivity implements MainActivityInterface {

    private TextView mTextMessage;
    private ImageView viewer;
    private ImageView thiefImage;
    private ImageView firstWindow;
    private ImageView secondWindow;
    private SeekBar  seekBar;

    private String address;
    private String port;
    private final static String TAG = "MainActivity";
    private static final int REQUEST_CODE = 100;
    private static final int SHOW_THIEF = 50;

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

                    Intent intent = new Intent(getApplicationContext(), BlindActivity.class);
                    startActivity(intent);

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

        clientThread = ClientThread.getInstance();
        clientThread.setMainActivityInterface(this);

        viewer = (ImageView) findViewById(R.id.viewer);

        firstWindow = (ImageView) findViewById(R.id.first_window);
        secondWindow = (ImageView) findViewById(R.id.second_window);

        seekBar = (SeekBar) findViewById(R.id.seek_bar);
        seekBar.incrementProgressBy(100);
        seekBar.setMax(100);

        thiefImage = (ImageView)findViewById(R.id.thiefImage);
        thiefImage.setVisibility(View.INVISIBLE);

        setListeners();
    }

    private void setListeners()
    {
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
                startActivityForResult(intent, REQUEST_CODE);
            }
        });

        thiefImage.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v)
            {
                Intent intent = new Intent(getApplicationContext(), SnapshotActivity.class);
                startActivity(intent);

                thiefImage.setVisibility(View.INVISIBLE);
            }
        });

        seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                // TODO Auto-generated method stub
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
                // TODO Auto-generated method stub
            }

            @Override
            public void onProgressChanged(SeekBar seekBar, int progress,boolean fromUser) {
                // TODO Auto-generated method stub
                if(progress == 0)
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
                }
                else if(progress == 100)
                {
                    BlindsDOWNCommand command = new BlindsDOWNCommand();
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
                }

            }
        });
    }


    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {

        super.onActivityResult(requestCode, resultCode, data);

        if(requestCode == REQUEST_CODE && resultCode == RESULT_OK && data != null)
        {
            resultCode = RESULT_OK;
            Command command = (Command) data.getSerializableExtra("command");
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
        }
    }

    @Override
    public void thiefOccurred()
    {
        Handler handler = new Handler(Looper.getMainLooper());
        handler.post(new Runnable() {
            @Override
            public void run() {
                thiefImage.setVisibility(View.VISIBLE);
            }
        });
    }

    @Override
    public void blindsUP()
    {
        Handler handler = new Handler(Looper.getMainLooper());
        handler.post(new Runnable() {
            @Override
            public void run() {

            }
        });
    }

    @Override
    public void blindsDOWN()
    {
        Handler handler = new Handler(Looper.getMainLooper());
        handler.post(new Runnable() {
            @Override
            public void run() {
                //DrawableCompat.setTint(firstWindow.getDrawable(), ContextCompat.getColor(getApplicationContext(), R.color.orange));
                //DrawableCompat.setTint(secondWindow.getDrawable(), ContextCompat.getColor(getApplicationContext(), R.color.orange));

            }
        });
    }

    @Override
    public void setSeekBarValue(int value)
    {
        seekBar.setProgress(0);
    }
}
