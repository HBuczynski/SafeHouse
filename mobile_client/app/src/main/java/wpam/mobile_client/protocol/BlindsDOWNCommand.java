package wpam.mobile_client.protocol;

import java.util.ArrayList;

public class BlindsDOWNCommand extends Command
	{
		public BlindsDOWNCommand()
		{
			super(10, CommandType.BLINDS_DOWN);
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
			frame.add(commandType_.getValue() & 0xFF);

			return frame;
		}
		@Override
		public String getName()
		{
			return new String("BlindsDOWNCommand");
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