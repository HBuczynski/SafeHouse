package wpam.mobile_client.client;


import wpam.mobile_client.MainActivityInterface;
import wpam.mobile_client.protocol.*;
import wpam.mobile_client.sensor_tag.SensorsInterface;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;


public final class ResponseHandlerVisitor extends ResponseVisitor implements Closeable
	{
		private MainActivityInterface mainActivityInterface;
		private SensorsInterface sensorsInterface;

		SimpleDateFormat sdf = new SimpleDateFormat("yyyy.MM.dd HH:mm:ss");

		String blindsStatus;

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

		public void setSensorsTagInterface(SensorsInterface sensorsInterface)
		{
			this.sensorsInterface = sensorsInterface;
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


			BlindsStatus status = response.getBlindsStatus();
			blindsStatus = "Blinds status: " + status.name();

			switch (status)
			{
				case UP:
				{
					mainActivityInterface.blindsUP();
					break;
				}
				case DOWN:
				{
					mainActivityInterface.blindsDOWN();
					break;
				}
			}

		}

		@Override
		public  void visit(GuardStatusResponse response)
		{
			String currentDateandTime = sdf.format(new Date());
			client.addToQueue("--" + currentDateandTime +"-- Received:: " +
					response.getName() + ", guard status: " + response.getGuardStatus().toString() + ".");

			if(response.getGuardStatus() == GuardStatus.OFF)
			{
				client.setUserInHome(true);
			}
			else
			{
				client.setUserInHome(false);
			}
			System.out.println(response.getName() + " " + response.getGuardStatus().toString());
		}

		@Override
		public void visit(SensorTagSamplesResponse response)
		{
			String currentDateandTime = sdf.format(new Date());
			client.addToQueue("--" + currentDateandTime +"-- Received:: " +
					response.getName() + ".");

			sensorsInterface.singleSamples(response.getValues());
		}

		public String getBlindsStatus()
		{
			return blindsStatus;
		}
	}