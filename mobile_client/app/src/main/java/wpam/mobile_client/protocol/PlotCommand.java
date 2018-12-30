package wpam.mobile_client.protocol;

import java.util.ArrayList;

import wpam.mobile_client.sensor_tag.ParameterType;
import wpam.mobile_client.sensor_tag.SensorTagType;

public class PlotCommand extends Command
{
    private ParameterType parameterType;
    private SensorTagType sensorTagType;

    public PlotCommand(ParameterType parameterType, SensorTagType sensorTagType) {
        super(10, CommandType.PLOT);
        this.parameterType = parameterType;
        this.sensorTagType = sensorTagType;
    }
    public final void close()
    {
        super.close();
    }

    public ParameterType getParameterType() {
        return parameterType;
    }

    public void setParameterType(ParameterType parameterType) {
        this.parameterType = parameterType;
    }

    public SensorTagType getSensorTagType() {
        return sensorTagType;
    }

    public void setSensorTagType(SensorTagType sensorTagType) {
        this.sensorTagType = sensorTagType;
    }

    @Override
    public ArrayList<Integer> getFrameBytes()
    {
        initializeDataSize();

        ArrayList<Integer> frame = getHeader();
        frame.add(commandType_.getValue());
        frame.add(parameterType.getValue());
        frame.add(sensorTagType.getValue());

        return frame;
    }

    @Override
    public String getName()
    {
        return new String("SensorTagSamplesCommand");
    }

    @Override
    public void accept(CommandVisitor visitor)
    {
        visitor.visit(this);
    }

    @Override
    protected void initializeDataSize()
    {
        setDataSize(1);
    }
}