package wpam.mobile_client;

import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import com.jjoe64.graphview.GraphView;
import com.jjoe64.graphview.LegendRenderer;
import com.jjoe64.graphview.series.DataPoint;
import com.jjoe64.graphview.series.LineGraphSeries;

public class Plot extends AppCompatActivity {

    GraphView graph;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_plot);

        graph = (GraphView) findViewById(R.id.graph);

        LineGraphSeries<DataPoint> series = new LineGraphSeries<DataPoint>(new DataPoint[] {
                new DataPoint(0, 1),
                new DataPoint(1, 5),
                new DataPoint(2, 3),
                new DataPoint(3, 2),
                new DataPoint(4, 6),
                new DataPoint(44, 66),
                new DataPoint(76, 36),
        });
        series.setTitle("foo");

        graph.addSeries(series);
        graph.setTitle("Plot");

        graph.getGridLabelRenderer().setVerticalAxisTitle("Vertical Axis");
        graph.getGridLabelRenderer().setHorizontalAxisTitle("Horizontal Axis");

        setDefaultSettings();
    }

    private void setDefaultSettings() {
        graph.setTitleTextSize(75.98f);
        graph.setTitleColor(Color.CYAN);

        graph.getLegendRenderer().setTextSize(30.0f);
        graph.getLegendRenderer().setAlign(LegendRenderer.LegendAlign.TOP);
        graph.getLegendRenderer().setVisible(true);

        graph.getGridLabelRenderer().setVerticalAxisTitleTextSize(35.05f);
        graph.getGridLabelRenderer().setVerticalAxisTitleColor(Color.CYAN);
        graph.getGridLabelRenderer().setHorizontalAxisTitleTextSize(35.05f);
        graph.getGridLabelRenderer().setHorizontalAxisTitleColor(Color.CYAN);

        graph.getViewport().setScrollable(true); // enables horizontal scrolling
        graph.getViewport().setScalable(true); // enables horizontal zooming and scrolling
        graph.getViewport().setScalableY(true); // enables vertical zooming and scrolling
        graph.getViewport().setScrollableY(true); // enables vertical scrolling
    }
}
