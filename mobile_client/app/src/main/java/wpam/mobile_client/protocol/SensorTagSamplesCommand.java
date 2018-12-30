package wpam.mobile_client.protocol;

import java.util.ArrayList;

public class SensorTagSamplesCommand extends Command
{
    public SensorTagSamplesCommand()
    {
        super(10, CommandType.SENSOR_TAG_SAMPLES);
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
        frame.add(commandType_.getValue());

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