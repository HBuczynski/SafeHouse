package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

public final class AckResponseBuilder implements ResponseBuilder, Closeable
{
	public AckResponseBuilder()
	{
	}
	public final void close()
	{
	}

	@Override
	public Response create(ArrayList<Integer> commandInBytes)
	{
		AckType type = AckType.forValue(commandInBytes.get(initialDataPosition));

		Response response  = new AckResponse(type);
		return response;
	}
}