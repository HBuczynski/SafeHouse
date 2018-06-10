package wpam.mobile_client;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.widget.MediaController;
import android.widget.Toast;
import android.widget.VideoView;
import android.net.Uri;
import android.os.Bundle;

import wpam.mobile_client.client.ClientThread;
import wpam.mobile_client.protocol.StopStreamCommand;


public class StreamActivity extends AppCompatActivity {

    private VideoView streamView;
    MediaController mediaController;
    String address;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.stream);

        streamView = (VideoView)findViewById(R.id.streamview);
        address = (ClientThread.getInstance()).getIp();

        String url = "http://"+address+":8090";
        playStream(url);
    }

    private void playStream(String src){
        Uri UriSrc = Uri.parse(src);
        if(UriSrc == null){
            Toast.makeText(StreamActivity.this,
                    "UriSrc == null", Toast.LENGTH_LONG).show();
        }else{
            streamView.setVideoURI(UriSrc);
            mediaController = new MediaController(this);
            streamView.setMediaController(mediaController);
            streamView.start();

            Toast.makeText(StreamActivity.this,
                    "Connect: " + src,
                    Toast.LENGTH_LONG).show();
        }
    }

    @Override
    public void onBackPressed() {
        streamView.stopPlayback();

        StopStreamCommand command = new StopStreamCommand();
        Intent intent = new Intent();

        intent.putExtra("command", command);
        setResult(RESULT_OK, intent);
        finish();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        streamView.stopPlayback();

        StopStreamCommand command = new StopStreamCommand();
        Intent intent = new Intent();

        intent.putExtra("command", "lol");
        setResult(RESULT_OK, intent);
        finish();
    }
}
