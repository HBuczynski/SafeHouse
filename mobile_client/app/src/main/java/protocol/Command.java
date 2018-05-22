package protocol;

import java.util.*;

	public abstract class Command extends Frame
	{
		protected CommandType commandType_;

		public Command(int dataSizeIn, CommandType commandTypeIn)
		{
			super(FrameType.COMMAND, dataSizeIn);
			this.commandType_ = commandTypeIn;
		}
		public void close()
		{
			super.close();
		}

		public abstract ArrayList<Integer> getFrameBytes();
		public abstract String getName();
		public abstract void accept(CommandVisitor visitor);

		public CommandType getCommandType()
		{
			return this.commandType_;
		}

		protected abstract void initializeDataSize();
	}