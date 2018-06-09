package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

	public final class StopStreamBuilder implements CommandBuilder, Closeable
	{
		public StopStreamBuilder()
		{
		}
		public final void close()
		{
		}

		@Override
		public Command create(ArrayList<Integer> commandInBytes)
		{
			Command command  = new StopStreamCommand();
			return command;
		}
	}