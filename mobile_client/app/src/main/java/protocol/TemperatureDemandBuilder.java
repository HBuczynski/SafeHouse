package protocol;

import java.io.Closeable;
import java.util.ArrayList;

public final class TemperatureDemandBuilder implements CommandBuilder, Closeable
	{
		public TemperatureDemandBuilder()
		{
		}
		public final void close()
		{
		}

		@Override
		public Command create(ArrayList<Integer> commandInBytes)
		{
			Command command  = new TemperatureDemandCommand();
			return command;
		}
	}