package wpam.mobile_client.protocol;

import java.util.ArrayList;

    public interface CommandBuilder
	{
		public abstract Command create(ArrayList<Integer> commandInBytes);

		public int initialDataPosition = 7;
	}