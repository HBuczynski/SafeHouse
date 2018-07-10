package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

public final class GuardStatusBuilder implements ResponseBuilder, Closeable
{
	public GuardStatusBuilder()
	{
	}
	public final void close()
	{
	}

	@Override
	public Response create(ArrayList<Integer> commandInBytes)
	{
		GuardStatus type = GuardStatus.forValue(commandInBytes.get(initialDataPosition));

		Response response  = new GuardStatusResponse(type);
		return response;
	}
}