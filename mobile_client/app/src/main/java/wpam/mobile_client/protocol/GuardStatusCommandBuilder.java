package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

public final class GuardStatusCommandBuilder implements CommandBuilder, Closeable
{
	public GuardStatusCommandBuilder()
	{
	}
	public final void close()
	{
	}

	@Override
	public Command create(ArrayList<Integer> commandInBytes)
	{
		Command command  = new GuardStatusCommand();
		return command;
	}
}