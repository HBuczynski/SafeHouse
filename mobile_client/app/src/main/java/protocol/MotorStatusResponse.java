package protocol;

import java.util.ArrayList;

public final class MotorStatusResponse extends Response
	{
		public MotorStatusResponse(MotorStatus type)
		{
			super(10, ResponseType.MOTOR_STATUS);
			this.type_ = type;
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
			frame.add(responseType_.getValue());
			frame.add(type_.getValue());

			return frame;
		}
		@Override
		public String getName()
		{
			return new String("MotorStatusResponse");
		}

		@Override
		public void accept(ResponseVisitor visitor)
		{
			visitor.visit(this);
		}

		public MotorStatus getMotorStatus()
		{
			return this.type_;
		}
		public void setMotorStatus(MotorStatus type)
		{
			this.type_ = type;
		}

		@Override
		protected void initializeDataSize()
		{
			setDataSize(2);
		}

		private MotorStatus type_;
	}