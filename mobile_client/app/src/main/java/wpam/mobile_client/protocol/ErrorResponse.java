package wpam.mobile_client.protocol;

import java.util.ArrayList;

public final class ErrorResponse extends Response
	{
		private ErrorType type_;

		public ErrorResponse(ErrorType type)
		{
			super(10, ResponseType.ERROR);
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
			return new String("ErrorResponse");
		}

		@Override
		public void accept(ResponseVisitor visitor)
		{
			visitor.visit(this);
		}

		public ErrorType getErrorType()
		{
			return this.type_;
		}

		public void setErrorType(ErrorType type)
		{
			this.type_ = type;
		}

		@Override
		protected void initializeDataSize()
		{
			setDataSize(2);
		}
	}