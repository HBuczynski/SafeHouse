package wpam.mobile_client.protocol;
import java.util.ArrayList;

public final class StartStreamCommand extends Command
	{
		public StartStreamCommand()
		{
			super(10, CommandType.START_STREAM);
		}
		public final void close()
		{
			super.close();
		}

		@Override
		public  ArrayList<Integer> getFrameBytes()
		{
			initializeDataSize();

			ArrayList<Integer> frame = getHeader();
			frame.add(commandType_.getValue());

			return frame;
		}
		@Override
		public String getName()
		{
			return new String("StartStreamCommand");
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