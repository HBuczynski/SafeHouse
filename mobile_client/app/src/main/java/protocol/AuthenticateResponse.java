package protocol;

import java.util.ArrayList;

public final class AuthenticateResponse extends Response
	{
		public AuthenticateResponse()
		{
			super(10, ResponseType.AUTHENTICATE);
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

			return frame;
		}
		@Override
		public String getName()
		{
			return new String("AuthenticateResponse");
		}
		@Override
		public void accept(ResponseVisitor visitor)
		{
			visitor.visit(this);
		}

		@Override
		protected void initializeDataSize()
		{
			setDataSize(1);
		}
	}