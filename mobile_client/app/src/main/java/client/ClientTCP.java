package client;

import protocol.Response;
import protocol.ResponseFactory;

import java.io.*;
import java.net.*;
import java.io.DataInputStream;
import java.util.ArrayList;

public class ClientTCP
{
    private InputStream streamInput;
    private OutputStream  streamOutput;
    private Socket socket;
    ResponseFactory responseFactory;
    ResponseHandlerVisitor responseHandler;

    private final int HEADER_SIZE = 5;

    private String server;
    private int port;

    public ClientTCP(String server, int port)
    {
        this.server = server;
        this.port = port;

        responseFactory = new ResponseFactory();
        responseHandler = new ResponseHandlerVisitor();
    }

    public void initialize()
    {

        try {
            socket = new Socket(server, port);
        }
        catch(Exception ec) {
            System.out.println("Error connectiong to server:" + "Server");
        }

        try
        {
            streamInput  = new DataInputStream(socket.getInputStream());
            streamOutput = new DataOutputStream(socket.getOutputStream());
        }
        catch (IOException eIO)
        {

            System.out.println("Error connectiong to server:" + "Server");
        }

        new ListenFromServer().start();

    }

    public void disconnect()
    {
        try {
            if(streamInput != null) streamInput.close();
        }
        catch(Exception e) {}
        try {
            if(streamOutput != null) streamOutput.close();
        }
        catch(Exception e) {}
        try{
            if(socket != null) socket.close();
        }
        catch(Exception e) {}
    }

    public void sendMessage(ArrayList<Integer> msg)
    {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream out = new DataOutputStream(baos);

        try {
            for (int element : msg) {
                out.write(element);
            }
        }
        catch (Exception e)
        {}
        byte[] bytes = baos.toByteArray();

        try {
            streamOutput.write(bytes, 0, bytes.length);
        }
        catch(IOException e) {}
    }

    class ListenFromServer extends Thread {

        public void run()
        {
            while(true)
            {
                ArrayList<Integer> payload = new ArrayList<Integer>();

                try {
                    byte[] rawBytes = new byte[1000];
                    streamInput.read(rawBytes);
                    int dataSize = (rawBytes[3] << 8 & 0xFF00) | (rawBytes[4] &0xFF);
                    int totalSize = dataSize + HEADER_SIZE;

                    for (int i = 0; i < totalSize; i++) {
                        payload.add((int)rawBytes[i]);
                    }
                    System.out.println(payload);
                }
                catch(IOException e) {
                    System.out.println("Server has close the connection: "  +  "Server");
                    break;
                }

                Response response = responseFactory.createCommand(payload);
                response.accept(responseHandler);
            }
        }
    }
}

