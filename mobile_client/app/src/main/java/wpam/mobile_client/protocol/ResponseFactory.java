package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

public class ResponseFactory implements Closeable
	{
		private final int RESPONSE_DATA_TYPE_POSITION = 5;
		private ResponseBuilder builder;

		public ResponseFactory()
		{
		}
		public final void close()
		{
		}

		public Response createCommand(ArrayList<Integer> commandInBytes)
		{

			ResponseType type = ResponseType.forValue(commandInBytes.get(RESPONSE_DATA_TYPE_POSITION));
			Response response;
			switch (type)
			{
				case AUTHENTICATE:
				{
					this.builder = new AuthenticateBuilder();
					response = builder.create(commandInBytes);
					break;
				}
				case MOTOR_STATUS:
				{
					this.builder = new MotorStatusBuilder();
					response = builder.create(commandInBytes);
				}
				case BLINDS_STATUS_RSP:
				{
					this.builder = new BlindsStatusResponseBuilder();
					response = builder.create(commandInBytes);
					break;
				}
				case ACK:
				{
					this.builder = new AckResponseBuilder();
					response = builder.create(commandInBytes);
					break;
				}
				case GUARD_STATUS:
				{
					this.builder = new GuardStatusBuilder();
					response = builder.create(commandInBytes);
					break;
				}
				case SENSOR_TAG:
				{
					this.builder = new SensorTagSamplesResbuilder();
					response = builder.create(commandInBytes);
					break;
				}
				default:
				{
					throw new IllegalArgumentException("Score is not valid!");
				}
			}
			return response;
		}
	}