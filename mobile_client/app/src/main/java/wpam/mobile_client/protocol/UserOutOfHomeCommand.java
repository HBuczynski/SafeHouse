package wpam.mobile_client.protocol;

import java.util.ArrayList;

public final class UserOutOfHomeCommand extends Command
	{
		public UserOutOfHomeCommand()
		{
			super(10, CommandType.USER_OUT_OF_HOME);
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
			return new String("UserOutOfHomeCommand");
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