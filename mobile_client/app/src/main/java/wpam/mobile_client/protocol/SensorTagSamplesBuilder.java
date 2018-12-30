package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

public final class SensorTagSamplesBuilder implements CommandBuilder, Closeable
{
    public SensorTagSamplesBuilder() {
    }
    public final void close() {
    }

    @Override
    public Command create(ArrayList<Integer> commandInBytes)  {
        Command command  = new SensorTagSamplesCommand();
        return command;
    }
}