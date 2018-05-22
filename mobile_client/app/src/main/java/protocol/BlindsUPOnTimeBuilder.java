package protocol;

import java.io.Closeable;
import java.util.ArrayList;

public final class BlindsUPOnTimeBuilder implements CommandBuilder, Closeable
	{
		public BlindsUPOnTimeBuilder()
		{
		}
		public final void close()
		{
		}

		@Override
		public Command create(ArrayList<Integer> commandInBytes)
		{
			int dateAndTime = BytesConverter.fromVectorOfUINT8toUINT32(commandInBytes, INIT_EPOCH_TIME_POSITION_IN_FRAME);
			Command command  = new BlindsUPOnTimeCommand(dateAndTime);
			return command;
		}

		private final int INIT_EPOCH_TIME_POSITION_IN_FRAME = 6;
	}