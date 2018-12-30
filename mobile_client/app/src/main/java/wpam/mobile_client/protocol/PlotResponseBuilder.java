package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

import wpam.mobile_client.sensor_tag.ParameterType;

public final class PlotResponseBuilder implements ResponseBuilder, Closeable
{
    public PlotResponseBuilder()
    {}
    public final void close()
    {}

    @Override
    public Response create(ArrayList<Integer> commandInBytes)
    {
        ArrayList<Integer> data = new ArrayList<>();
        ArrayList<Integer> timestamps = new ArrayList<>();

        int counter = initialDataPosition;

        ParameterType parameterType = ParameterType.forValue(commandInBytes.get(counter));
        counter++;

        for(int i = 0; i<1000*2; ++i) {
            data.add((commandInBytes.get(counter+i) << 8) | commandInBytes.get(counter+i+1));
            ++i;
            counter+=2;
        }

        for(int i = 0; i<1000*8; ++i) {
            int sample = 0;
            for(int j=0; j<8; ++j) {
                sample |= (commandInBytes.get(counter+i+j) << (56-j*8));
            }
            timestamps.add(sample);
            i+=8;
        }

        Response response  = new PlotResponse(data, timestamps, parameterType);
        return response;
    }
}