package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

public final class MotorStatusCommandBuilder implements CommandBuilder, Closeable
{
	public MotorStatusCommandBuilder()
	{
	}
	public final void close()
	{
	}

	@Override
	public Command create(ArrayList<Integer> commandInBytes)
	{
		Command command  = new MotorStatusCommand();
		return command;
	}
}