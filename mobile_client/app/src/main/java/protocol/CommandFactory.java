package protocol;
import java.io.*;
import java.util.ArrayList;

public class CommandFactory implements Closeable
	{
		private CommandBuilder builder;
		private final int COMMAND_TYPE_POSITION = 5;

		public CommandFactory()
		{
		}
		public final void close()
		{
		}

		public Command createCommand(ArrayList<Integer> commandInBytes)
		{
			CommandType type = CommandType.forValue(commandInBytes.get(COMMAND_TYPE_POSITION));
			Command command;
			switch (type)
			{
				case BLINDS_DOWN:
				{
					this.builder = new BlindsDOWNBuilder();
					command = this.builder.create(commandInBytes);
					break;
				}
				case BLINDS_DOWN_ON_TIME:
				{
					this.builder = new BlindsDOWNOnTimeBuilder();
					command = this.builder.create(commandInBytes);
					break;
				}
				case BLINDS_UP:
				{
					this.builder = new BlindsUPBuilder();
					command = this.builder.create(commandInBytes);
					break;
				}
				case BLINDS_UP_ON_TIME:
				{
					this.builder = new BlindsUPOnTimeBuilder();
					command = this.builder.create(commandInBytes);
					break;
				}
				case SNAPSHOT:
				{
					this.builder = new SnapshotBuilder();
					command = this.builder.create(commandInBytes);
					break;
				}
				case AUTOMATIC_BLINDS:
				{
					this.builder = new AutomaticBlindsBuilder();
					command = this.builder.create(commandInBytes);
					break;
				}
				case BLINDS_STATUS:
				{
					this.builder = new BlindsStatusBuilder();
					command = this.builder.create(commandInBytes);
					break;
				}
				case USER_OUT_OF_HOME:
				{
					this.builder = new UserOutOfHomeBuilder();
					command = this.builder.create(commandInBytes);
					break;
				}
				case TEMPERATURE_DEMAND:
				{
					this.builder = new TemperatureDemandBuilder();
					command = this.builder.create(commandInBytes);
					break;
				}
				case END_CONNECTION:
				{
					this.builder = new EndConnectionBuilder();
					command = this.builder.create(commandInBytes);
					break;
				}
				default:
				{
					throw new IllegalArgumentException("Score is not valid!");
				}
			}
			return command;
		}
	}