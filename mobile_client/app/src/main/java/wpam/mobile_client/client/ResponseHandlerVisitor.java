package wpam.mobile_client.client;

import android.app.Activity;
import android.content.Intent;

import wpam.mobile_client.MainActivityInterface;
import wpam.mobile_client.protocol.*;

import java.io.*;

import static android.app.Activity.RESULT_OK;

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

			this.mainActivityInterface.blindsDOWN();
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