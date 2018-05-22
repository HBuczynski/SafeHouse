package protocol;

import java.io.*;
import java.util.ArrayList;

public class BlindsDOWNBuilder implements CommandBuilder, Closeable
	{
		public BlindsDOWNBuilder()
		{
		}
		public final void close()
		{
		}

		@Override
		public Command create(ArrayList<Integer> commandInBytes)
		{
			Command command  = new BlindsDOWNCommand();
			return command;
		}
	}