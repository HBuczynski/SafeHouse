package wpam.mobile_client.client;


import wpam.mobile_client.MainActivityInterface;
import wpam.mobile_client.protocol.*;

import java.io.*;


public final class ResponseHandlerVisitor extends ResponseVisitor implements Closeable
	{
		private MainActivityInterface mainActivityInterface;

		public ResponseHandlerVisitor()
		{
		}
		public final void close()
		{
		}

		public void setMainActivityInterface(MainActivityInterface mainActivityInterface)
		{
			this.mainActivityInterface = mainActivityInterface;
		}

		@Override
		public  void visit(AuthenticateResponse response)
		{
			System.out.println(response.getName());

			//this.mainActivityInterface.thiefOccurred();
		}
		
		@Override
		public  void visit(AckResponse response)
		{
			this.mainActivityInterface.thiefOccurred();
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