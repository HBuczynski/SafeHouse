package protocol;

import java.io.Closeable;
import java.util.ArrayList;

public final class AutomaticBlindsBuilder implements CommandBuilder, Closeable
	{
		public AutomaticBlindsBuilder()
		{
		}
		public final void close()
		{
		}

		@Override
		public Command create(ArrayList<Integer> commandInBytes)
		{
			Command command  = new AutomaticBlindsCommand();
			return command;
		}
	}