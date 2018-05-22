package protocol;

import java.util.*;

	public abstract class Response extends Frame
	{
		protected ResponseType responseType_;

		public Response(int dataSizeIn, ResponseType responseTypeIn)
		{
			super(FrameType.RESPONSE, dataSizeIn);
			this.responseType_ = responseTypeIn;
		}
		public void close()
		{
			super.close();
		}

		public abstract ArrayList<Integer > getFrameBytes();
		public abstract String getName();
		public abstract void accept(ResponseVisitor visitor);

		public ResponseType getResponseType()
		{
			return this.responseType_;
		}

		protected abstract void initializeDataSize();
	}