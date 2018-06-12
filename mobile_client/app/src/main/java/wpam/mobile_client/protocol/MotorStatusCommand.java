package wpam.mobile_client.protocol;
import java.util.ArrayList;

public final class MotorStatusCommand extends Command
{
	public MotorStatusCommand()
	{
		super(10, CommandType.MOTOR_STATUS_COMMAND);
	}
	public final void close()
	{
		super.close();
	}

	@Override
	public ArrayList<Integer> getFrameBytes()
	{
		initializeDataSize();

		ArrayList<Integer> frame = getHeader();
		frame.add(commandType_.getValue());

		return frame;
	}
	@Override
	public String getName()
	{
		return new String("MotorStatusCommand");
	}
	@Override
	public void accept(CommandVisitor visitor)
	{
		visitor.visit(this);
	}

	@Override
	protected void initializeDataSize()
	{
		setDataSize(1);
	}
}