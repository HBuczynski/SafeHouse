package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

import wpam.mobile_client.sensor_tag.ParameterType;
import wpam.mobile_client.sensor_tag.SensorTagType;

public final class PlotBuilder implements CommandBuilder, Closeable
{
    public PlotBuilder()
    {}
    public final void close()
    {}

    @Override
    public Command create(ArrayList<Integer> commandInBytes)
    {
        ParameterType type = ParameterType.forValue(commandInBytes.get(initialDataPosition));
        SensorTagType sensorType = SensorTagType.forValue(commandInBytes.get(initialDataPosition+1));

        Command response  = new PlotCommand(type, sensorType);
        return response;
    }
}