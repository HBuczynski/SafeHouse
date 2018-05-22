package protocol;

import java.io.Closeable;
import java.util.ArrayList;

public final class BlindsDOWNOnTimeBuilder implements CommandBuilder, Closeable
	{
		private final int INIT_EPOCH_TIME_POSITION_IN_FRAME = 6;

		public BlindsDOWNOnTimeBuilder()
		{
		}
		public final void close()
		{
		}

		@Override
		public Command create(ArrayList<Integer> commandInBytes)
		{
			int dateAndTime = BytesConverter.fromVectorOfUINT8toUINT32(commandInBytes, INIT_EPOCH_TIME_POSITION_IN_FRAME);
			Command command  = new BlindsDOWNOnTimeCommand(dateAndTime);
			return command;
		}
	}