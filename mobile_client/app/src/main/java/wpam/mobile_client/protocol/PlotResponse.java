package wpam.mobile_client.protocol;

import java.util.ArrayList;

import wpam.mobile_client.sensor_tag.ParameterType;

public final class PlotResponse extends Response
{
    private ArrayList<Integer> values;
    private ArrayList<Integer> timestamps;
    private ParameterType parameterType;

    public PlotResponse(ArrayList<Integer> values, ArrayList<Integer> timestamps, ParameterType parameterType) {
        super(10, ResponseType.PLOT);
        this.values = values;
        this.timestamps = timestamps;
        this.parameterType = parameterType;
    }
    public final void close()
    {
        super.close();
    }

    @Override
    public ArrayList<Integer> getFrameBytes()
    {
        initializeDataSize();

        ArrayList<Integer> frame = getHeader();
        frame.add(responseType_.getValue());
        frame.add(parameterType.getValue());

        for ( Integer value: values) {
            frame.add(value);
        }

        for ( Integer time: timestamps) {
            frame.add(time);
        }
        return frame;
    }

    @Override
    public String getName()
    {
        return new String("BlindsStatusResponse");
    }

    @Override
    public void accept(ResponseVisitor visitor)
    {
        visitor.visit(this);
    }

    public ArrayList<Integer> getValues()
    {
        return this.values;
    }

    public void setValues(ArrayList<Integer> values)
    {
        this.values = values;
    }

    public ArrayList<Integer> getTimestamps() {
        return timestamps;
    }

    public void setTimestamps(ArrayList<Integer> timestamps) {
        this.timestamps = timestamps;
    }

    public ParameterType getParameterType() {
        return parameterType;
    }

    public void setParameterType(ParameterType parameterType) {
        this.parameterType = parameterType;
    }

    @Override
    protected void initializeDataSize()
    {
        setDataSize(10);
    }
}