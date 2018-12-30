package wpam.mobile_client;

import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import com.jjoe64.graphview.GraphView;
import com.jjoe64.graphview.LegendRenderer;
import com.jjoe64.graphview.series.DataPoint;
import com.jjoe64.graphview.series.LineGraphSeries;

import java.util.ArrayList;

import wpam.mobile_client.client.ClientThread;
import wpam.mobile_client.sensor_tag.ParameterType;
import wpam.mobile_client.sensor_tag.PlotInterface;
import wpam.mobile_client.sensor_tag.SensorDataType;
import wpam.mobile_client.sensor_tag.SensorTagType;

public class Plot extends AppCompatActivity implements PlotInterface {

    GraphView graph;
    ClientThread clientThread;

    ParameterType parameterType;
    SensorDataType sensorDataType;
    SensorTagType sensorTagType;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_plot);

        Bundle bundle = getIntent().getExtras();
        parameterType = (ParameterType) bundle.get(ParameterType.getName());
        sensorDataType = (SensorDataType) bundle.get(SensorDataType.getName());
        sensorTagType = (SensorTagType) bundle.get(SensorTagType.getName());

        if(parameterType != null && sensorDataType != null && sensorTagType != null ) {
            clientThread = ClientThread.getInstance();
            graph = (GraphView) findViewById(R.id.graph);

            drawPlot();
        }
    }

    private void setDefaultSettings() {
        graph.setTitleTextSize(75.98f);
        graph.setTitleColor(Color.CYAN);

        graph.getGridLabelRenderer().setHorizontalAxisTitle("Time [h:m:s]");

        graph.getLegendRenderer().setTextSize(30.0f);
        graph.getLegendRenderer().setAlign(LegendRenderer.LegendAlign.TOP);
        graph.getLegendRenderer().setVisible(true);

        graph.getGridLabelRenderer().setVerticalAxisTitleTextSize(35.05f);
        graph.getGridLabelRenderer().setVerticalAxisTitleColor(Color.CYAN);
        graph.getGridLabelRenderer().setHorizontalAxisTitleTextSize(35.05f);
        graph.getGridLabelRenderer().setHorizontalAxisTitleColor(Color.CYAN);

        graph.getViewport().setScalable(true);
        graph.getViewport().setScalableY(true);
    }

    private String getSensorTitle(SensorTagType sensorTagType) {
        switch (sensorTagType) {
            case FIRST:
                return "I Sensor Tag";
            case SECOND:
                return "II Sensor Tag";
            case THIRD:
                return "III Sensor Tag";
            case ALL:
                return "All Sensors";
            default:
                return "NULL";
        }
    }

    private String getLabelY(ParameterType parameterType) {
        switch (parameterType) {
            case HUMIDITY:
                return "HUMIDITY";
            case LUMINACIA:
                return "LUMINACIA";
            case TEMPERATURE:
                return "TEMPERATURE";
            default:
                return "NULL";
        }
    }

    public void plotData() {

    }

    private void drawPlot() {
        LineGraphSeries<DataPoint> series = new LineGraphSeries<DataPoint>(new DataPoint[]{
                new DataPoint(0, 1),
                new DataPoint(1, 5),
                new DataPoint(2, 3),
                new DataPoint(3, 2),
                new DataPoint(4, 6),
                new DataPoint(44, 66)
        });
        series.setTitle(getSensorTitle(sensorTagType));

        graph.addSeries(series);
        graph.setTitle(getSensorTitle(sensorTagType)+" - "+getLabelY(parameterType));
        graph.getGridLabelRenderer().setVerticalAxisTitle(getLabelY(parameterType));

        setDefaultSettings();
    }
}
