package wpam.mobile_client.protocol;

import java.util.ArrayList;

public final class BlindsDOWNOnTimeCommand extends Command
	{
		private int epochTime_;
		// 32 bit int !
		public BlindsDOWNOnTimeCommand(int epochTime)
		{
			super(10, CommandType.BLINDS_DOWN_ON_TIME);

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
			return new String("BlindsDOWNOnTimeCommand");
		}

		@Override
		public void accept(CommandVisitor visitor)
		{
			visitor.visit(this);
		}

		public void setEpochDateAndTime(int dateAndTime)
		{
			this.epochTime_ = dateAndTime;
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