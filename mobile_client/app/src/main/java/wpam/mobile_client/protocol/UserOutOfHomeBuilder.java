package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

public final class UserOutOfHomeBuilder implements CommandBuilder, Closeable
	{
		public UserOutOfHomeBuilder()
		{
		}
		public final void close()
		{
		}

		@Override
		public Command create(ArrayList<Integer> commandInBytes)
		{
			Command command  = new UserOutOfHomeCommand();
			return command;
		}
	}