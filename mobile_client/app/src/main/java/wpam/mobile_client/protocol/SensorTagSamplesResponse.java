package wpam.mobile_client.protocol;

import java.util.ArrayList;

public final class SensorTagSamplesResponse extends Response
{
    private ArrayList<Integer> values;

    public SensorTagSamplesResponse(ArrayList<Integer> values) {
        super(10, ResponseType.SENSOR_TAG);
        this.values = values;
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

        for ( Integer value: values) {
            frame.add(value);
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

    @Override
    protected void initializeDataSize()
    {
        setDataSize(10);
    }
}