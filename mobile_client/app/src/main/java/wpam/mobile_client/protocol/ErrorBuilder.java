package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

public final class ErrorBuilder implements ResponseBuilder, Closeable
	{
		public ErrorBuilder()
		{
		}
		public final void close()
		{
		}

		@Override
		public Response create(ArrayList<Integer> commandInBytes)
		{
			ErrorType type = ErrorType.forValue(commandInBytes.get(initialDataPosition));

			Response response  = new ErrorResponse(type);
			return response;
		}
	}