package protocol;

import java.util.ArrayList;

public final class AckResponse extends Response
	{
		private AckType type_;

		public AckResponse(AckType type)
		{
			super(10, ResponseType.ACK);
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
			return new String("AckResponse");
		}
		@Override
		public void accept(ResponseVisitor visitor)
		{
			visitor.visit(this);
		}

		public AckType getAckType()
		{
			return this.type_;
		}
		public void setAckType(AckType type)
		{
			type_ = type;
		}

		@Override
		protected void initializeDataSize()
		{
			setDataSize(2);
		}


	}