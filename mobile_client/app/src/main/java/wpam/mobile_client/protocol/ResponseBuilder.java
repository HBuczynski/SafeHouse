package wpam.mobile_client.protocol;

import java.util.ArrayList;

public interface ResponseBuilder
	{
		public abstract Response create(ArrayList<Integer> commandInBytes);

		public int initialDataPosition = 6;
	}