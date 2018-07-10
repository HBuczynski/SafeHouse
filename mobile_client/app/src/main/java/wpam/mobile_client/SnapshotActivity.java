package wpam.mobile_client;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ImageView;
import android.widget.ProgressBar;

public class SnapshotActivity extends AppCompatActivity {

    private ImageView imageView;
    private ProgressBar progressBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.snapshot);

        imageView = (ImageView)findViewById(R.id.image);
        progressBar = (ProgressBar)findViewById(R.id.progress_bar);

        progressBar.setVisibility(View.VISIBLE);
        android.os.SystemClock.sleep(1500);
        progressBar.setVisibility(View.INVISIBLE);

        String url = "http://89.65.72.7/img.jpg";
        new com.concretepage.AsyncTaskLoadImage(imageView).execute(url);
    }
}
