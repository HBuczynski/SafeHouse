package wpam.mobile_client.sensor_tag;

import java.io.Serializable;

public enum SensorDataType implements Serializable
{
    SAMPLE(10),
    PLOT(20);

    private int value;
    private static java.util.HashMap<Integer, SensorDataType> mappings;
    private static java.util.HashMap<Integer, SensorDataType> getMappings()
    {
        if (mappings == null)
        {
            synchronized (SensorDataType.class)
            {
                if (mappings == null)
                {
                    mappings = new java.util.HashMap<Integer, SensorDataType>();
                }
            }
        }
        return mappings;
    }

    private SensorDataType(int value)
    {
        this.value = value;
        getMappings().put(this.value, this);
    }

    public int getValue()
    {
        return this.value;
    }
    public static SensorDataType forValue(int value)
    {
        return getMappings().get(value);
    }
    public static String getName() {
        return "SensorDataType";
    }
}
