package wpam.mobile_client.client;


import wpam.mobile_client.MainActivityInterface;
import wpam.mobile_client.protocol.*;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.LinkedList;
import java.util.Queue;


public final class ResponseHandlerVisitor extends ResponseVisitor implements Closeable
	{
		private MainActivityInterface mainActivityInterface;

		SimpleDateFormat sdf = new SimpleDateFormat("yyyy.MM.dd HH:mm:ss");

		String blindsStatus;
		String motorStatus;

		ClientThread client;

		public ResponseHandlerVisitor(ClientThread client)
		{
			this.client = client;
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
			String currentDateandTime = sdf.format(new Date());
			client.addToQueue("--" + currentDateandTime +"-- Received:: " + response.getName() + ".");
		}
		
		@Override
		public  void visit(AckResponse response)
		{
			String currentDateandTime = sdf.format(new Date());
			client.addToQueue("--" + currentDateandTime +"-- Received:: "+
					response.getName() + ", type of ack: " + response.getAckType().toString() + ".");
			this.mainActivityInterface.thiefOccurred();
		}
		
		@Override
		public  void visit(ErrorResponse response)
		{
			String currentDateandTime = sdf.format(new Date());
			client.addToQueue("--" + currentDateandTime +"-- Received:: " +
					response.getName() + ", type of error: " + response.getErrorType().toString() + ".");
			System.out.println(response.getName());
		}

		@Override
		public  void visit(MotorStatusResponse response)
		{
			String currentDateandTime = sdf.format(new Date());
			client.addToQueue("--" + currentDateandTime +"-- Received:: " +
					response.getName() + ", motor status: " + response.getMotorStatus().toString() + ".");
			System.out.println(response.getName());
		}

		@Override
		public  void visit(BlindsStatusResponse response)
		{
			String currentDateandTime = sdf.format(new Date());
			client.addToQueue("--" + currentDateandTime +"-- Received:: " +
					response.getName() + ", blinds status: " + response.getBlindsStatus().toString() + ".");

			blindsStatus = "Blinds status: " + response.getBlindsStatus().toString();
			System.out.println(response.getName());
		}

		@Override
		public  void visit(GuardStatusResponse response)
		{
			String currentDateandTime = sdf.format(new Date());
			client.addToQueue("--" + currentDateandTime +"-- Received:: " +
					response.getName() + ", blinds status: " + response.getGuardStatus().toString() + ".");

			blindsStatus = "Blinds status: " + response.getGuardStatus().toString();
			System.out.println(response.getName());
		}

		public String getBlindsStatus()
		{
			return blindsStatus;
		}
	}