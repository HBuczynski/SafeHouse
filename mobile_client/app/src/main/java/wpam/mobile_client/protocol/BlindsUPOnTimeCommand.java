package wpam.mobile_client.protocol;

import java.util.ArrayList;

public final class BlindsUPOnTimeCommand extends Command
	{
		private int epochTime_;

		public BlindsUPOnTimeCommand(int epochTime)
		{
			super(10, CommandType.BLINDS_UP_ON_TIME);
			this.epochTime_ = epochTime;
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
			BytesConverter.appendUINT32toVectorOfUINT8(epochTime_, frame);

			return frame;
		}

		@Override
		public String getName()
		{
			return new String("BlindsUPOnTimeCommand");
		}
		@Override
		public void accept(CommandVisitor visitor)
		{
			visitor.visit(this);
		}

		public void setEpochDateAndTime(int dateAndTime)
		{
            epochTime_ = dateAndTime;
		}

		public int getEpochDateAndTime()
		{
			return this.epochTime_;
		}

		@Override
		protected void initializeDataSize()
		{
			setDataSize(5);
		}
	}