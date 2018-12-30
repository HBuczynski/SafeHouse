package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

public final class SensorTagSamplesResbuilder implements ResponseBuilder, Closeable
{
    public SensorTagSamplesResbuilder() {
    }
    public final void close() {
    }

    @Override
    public Response create(ArrayList<Integer> commandInBytes)  {

        ArrayList<Integer> data = new ArrayList<>();

        int counter = initialDataPosition;

        for(int i = 0; i<18; ++i) {
            data.add((commandInBytes.get(counter+i) << 8) & commandInBytes.get(counter+i+1));
            ++i;
        }

        Response response  = new SensorTagSamplesResponse(data);
        return response;
    }
}