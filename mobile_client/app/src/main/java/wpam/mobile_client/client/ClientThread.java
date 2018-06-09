package wpam.mobile_client.client;

import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.Serializable;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.net.UnknownHostException;
import java.util.ArrayList;

import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.util.Log;
import android.widget.EditText;

import wpam.mobile_client.protocol.*;
import wpam.mobile_client.client.*;

public class ClientThread implements Serializable, Runnable
{
	//For debug
	private final String TAG = "ClientThread";
    private final int HEADER_SIZE = 5;

	private Socket socket;
	private String ip;
	private int port;
	public Handler sendHandler;

	private InputStream inputStream;
	private OutputStream outputStream;
    ResponseFactory responseFactory;
    ResponseHandlerVisitor responseHandler;
	public boolean isConnect = false;

	public ClientThread(String ip, String port) {
		// TODO Auto-generated constructor stub
		this.ip = ip;
		this.port = Integer.valueOf(port);

        responseFactory = new ResponseFactory();
        responseHandler = new ResponseHandlerVisitor();

		Log.d(TAG, "ClientThread's construct is OK!!");
	}
	public ClientThread()
	{
		Log.d(TAG, "It is may be construct's problem...");
	}

	public String getIp() {
		return ip;
	}

	public void run()
	{
		try 
		{
			Log.d(TAG, "Into the run()");
			socket = new Socket(ip, port);
			isConnect = socket.isConnected();
			inputStream = socket.getInputStream();
			outputStream = socket.getOutputStream();

			new Thread()
			{
				@Override
				public void run()
				{
					byte[] buffer = new byte[1024];

					try
					{
						while(socket.isConnected())
						{
                            ArrayList<Integer> payload = new ArrayList<Integer>();

                            byte[] rawBytes = new byte[1000];
                            inputStream.read(rawBytes);
                            int dataSize = (rawBytes[3] << 8 & 0xFF00) | (rawBytes[4] &0xFF);
                            int totalSize = dataSize + HEADER_SIZE;

                            for (int i = 0; i < totalSize; i++) {
                                payload.add((int)rawBytes[i]);
                            }
                            System.out.println(payload);

                            Response response = responseFactory.createCommand(payload);
                            response.accept(responseHandler);
						}
					}
					catch(IOException e)
					{
						Log.d(TAG, e.getMessage());
						e.printStackTrace();
					}
				}
				
			}.start();

            Looper.prepare();
            sendHandler = new Handler()
            {
                @Override
                public void handleMessage(Message msg)
                {
                   ByteArrayOutputStream baos = new ByteArrayOutputStream();
                   DataOutputStream out = new DataOutputStream(baos);
                   Command command = (Command) msg.obj;

                   ArrayList<Integer> rawData = command.getFrameBytes();
                   try {
                       for (int element : rawData) {
                           out.write(element);
                       }
                   }
                   catch (Exception e)
                   {}

                   byte[] bytes = baos.toByteArray();

                   try
                   {
                       outputStream.write(bytes);
                       outputStream.flush();
                   }
                   catch (Exception e)
                   {
                       Log.d(TAG, e.getMessage());
                       e.printStackTrace();
                   }
                }
            };
            Looper.loop();

		} catch (SocketTimeoutException e) 
		{
			// TODO Auto-generated catch block
			Log.d(TAG, e.getMessage());
			e.printStackTrace();
		}catch (UnknownHostException e) 
		{
			// TODO Auto-generated catch block
			Log.d(TAG, e.getMessage());
			e.printStackTrace();
		} catch (IOException e) 
		{
			// TODO Auto-generated catch block
			Log.d(TAG, e.getMessage());
			e.printStackTrace();
		}
	}
}
