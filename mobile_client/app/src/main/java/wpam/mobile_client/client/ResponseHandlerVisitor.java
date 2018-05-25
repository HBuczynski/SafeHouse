package wpam.mobile_client.client;

import wpam.mobile_client.protocol.*;

import java.io.*;

	public final class ResponseHandlerVisitor extends ResponseVisitor implements Closeable
	{
		public ResponseHandlerVisitor()
		{
		}
		public final void close()
		{
		}

		@Override
		public  void visit(AuthenticateResponse response)
		{
			System.out.println(response.getName());
		}
		
		@Override
		public  void visit(AckResponse response)
		{
			System.out.println(response.getName());
		}
		
		@Override
		public  void visit(ErrorResponse response)
		{
			System.out.println(response.getName());
		}

		@Override
		public  void visit(MotorStatusResponse response)
		{
			System.out.println(response.getName());
		}

		@Override
		public  void visit(BlindsStatusResponse response)
		{
			System.out.println(response.getName());
		}
	}