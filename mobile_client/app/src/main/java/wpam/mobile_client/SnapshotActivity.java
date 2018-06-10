package wpam.mobile_client;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.ImageView;

public class SnapshotActivity extends AppCompatActivity {

    private ImageView imageView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.snapshot);

        imageView = (ImageView)findViewById(R.id.image);

        //TODO: wait a one second
        String url = "http://89.65.72.7/img.jpg";
        new com.concretepage.AsyncTaskLoadImage(imageView).execute(url);
    }
}
