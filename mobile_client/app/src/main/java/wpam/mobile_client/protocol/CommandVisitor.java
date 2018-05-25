package wpam.mobile_client.protocol;

import java.io.*;

	public abstract class CommandVisitor implements Closeable
	{
		public CommandVisitor()
		{
		}
		public void close()
		{
		}

		public abstract void visit(BlindsDOWNOnTimeCommand command);
		public abstract void visit(BlindsUPOnTimeCommand command);
		public abstract void visit(BlindsUPCommand command);
		public abstract void visit(BlindsDOWNCommand command);
		public abstract void visit(BlindsStatusCommand command);
		public abstract void visit(AutomaticBlindsCommand command);
		public abstract void visit(TemperatureDemandCommand command);
		public abstract void visit(UserOutOfHomeCommand command);
		public abstract void visit(EndConnectionCommand command);
		public abstract void visit(SnapshotCommand command);
	}