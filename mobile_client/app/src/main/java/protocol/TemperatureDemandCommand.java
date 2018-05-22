package protocol;

import java.util.ArrayList;

public final class TemperatureDemandCommand extends Command
	{
		public TemperatureDemandCommand()
		{
			super(10, CommandType.TEMPERATURE_DEMAND);
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
			return new String("TemperatureDemandCommand");
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