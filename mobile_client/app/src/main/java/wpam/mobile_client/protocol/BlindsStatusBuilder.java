package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

public final class BlindsStatusBuilder implements CommandBuilder, Closeable
	{
		public BlindsStatusBuilder()
		{
		}
		public final void close()
		{
		}

		@Override
		public Command create(ArrayList<Integer> commandInBytes)
		{
			Command command  = new BlindsStatusCommand();
			return command;
		}
	}