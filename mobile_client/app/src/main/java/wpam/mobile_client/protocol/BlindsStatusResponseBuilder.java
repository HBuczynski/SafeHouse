package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

public final class BlindsStatusResponseBuilder implements ResponseBuilder, Closeable
	{
		public BlindsStatusResponseBuilder()
		{
		}
		public final void close()
		{
		}

        @Override
        public Response create(ArrayList<Integer> commandInBytes)
        {
            BlindsStatus status = BlindsStatus.forValue(commandInBytes.get(initialDataPosition));
            BlindsMode mode = BlindsMode.forValue(commandInBytes.get(initialDataPosition+1));

            Response response  = new BlindsStatusResponse(status, mode);
            return response;
        }
	}