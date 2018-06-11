package wpam.mobile_client;

import android.os.Bundle;
import android.view.View;
import android.graphics.BitmapFactory;
import android.graphics.Bitmap;
import android.widget.ImageView;
import android.support.v7.app.AppCompatActivity;

import wpam.mobile_client.client.ClientThread;

public class BlindActivity extends AppCompatActivity {

    ClientThread client;

    ImageView image;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.blinds);

        client = ClientThread.getInstance();

        image = (ImageView) findViewById(R.id.imageView);
        Bitmap bImage = BitmapFactory.decodeResource(this.getResources(), R.drawable.second_meadow);
        image.setImageBitmap(bImage);

         android.os.SystemClock.sleep(2000);

         android.support.v4.graphics.drawable.DrawableCompat.setTint(image.getDrawable(), android.support.v4.content.ContextCompat.getColor(getApplicationContext(), R.color.orange));

        }
}
