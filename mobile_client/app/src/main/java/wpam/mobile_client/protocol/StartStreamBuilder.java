package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

	public final class StartStreamBuilder implements CommandBuilder, Closeable
	{
		public StartStreamBuilder()
		{
		}
		public final void close()
		{
		}

		@Override
		public Command create(ArrayList<Integer> commandInBytes)
		{
			Command command  = new StartStreamCommand();
			return command;
		}
	}