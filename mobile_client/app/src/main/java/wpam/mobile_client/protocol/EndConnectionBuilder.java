package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

public final class EndConnectionBuilder implements CommandBuilder, Closeable
	{
		public EndConnectionBuilder()
		{
		}
		public final void close()
		{
		}

		@Override
		public Command create(ArrayList<Integer> commandInBytes)
		{
			Command command  = new EndConnectionCommand();
			return command;
		}
	}