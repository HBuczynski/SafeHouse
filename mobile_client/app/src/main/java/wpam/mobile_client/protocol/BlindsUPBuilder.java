package wpam.mobile_client.protocol;
import java.io.Closeable;
import java.util.ArrayList;

public final class BlindsUPBuilder implements CommandBuilder, Closeable
	{
		public BlindsUPBuilder()
		{
		}
		public final void close()
		{
		}

		@Override
		public Command create(ArrayList<Integer> commandInBytes)
		{
			Command command  = new BlindsUPCommand();
			return command;
		}
	}