package wpam.mobile_client.protocol;
import java.io.Closeable;
import java.util.ArrayList;

public final class MotorStatusBuilder implements ResponseBuilder, Closeable
	{
		public MotorStatusBuilder()
		{
		}
		public final void close()
		{
		}

		@Override
		public Response create(ArrayList<Integer> commandInBytes)
		{
			MotorStatus status = MotorStatus.forValue(commandInBytes.get(initialDataPosition));

			Response response  = new MotorStatusResponse(status);
			return response;
		}

	}