package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

public final class AuthenticateBuilder implements ResponseBuilder, Closeable
	{
		public AuthenticateBuilder()
		{
		}
		public final void close()
		{
		}

		@Override
		public Response create(ArrayList<Integer> commandInBytes)
		{
			Response response  = new AuthenticateResponse();
			return response;
		}
	}