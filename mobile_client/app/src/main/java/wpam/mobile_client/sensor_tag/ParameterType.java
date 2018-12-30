package wpam.mobile_client.sensor_tag;

import java.io.Serializable;

public enum ParameterType implements Serializable
{
    TEMPERATURE(10),
    HUMIDITY(20),
    LUMINACIA(30);

    private int value;
    private static java.util.HashMap<Integer, ParameterType> mappings;
    private static java.util.HashMap<Integer, ParameterType> getMappings()
    {
        if (mappings == null)
        {
            synchronized (ParameterType.class)
            {
                if (mappings == null)
                {
                    mappings = new java.util.HashMap<Integer, ParameterType>();
                }
            }
        }
        return mappings;
    }

    private ParameterType(int value)
    {
        this.value = value;
        getMappings().put(this.value, this);
    }

    public int getValue()
    {
        return this.value;
    }
    public static ParameterType forValue(int value)
    {
        return getMappings().get(value);
    }
    public static String getName() {
        return "ParameterType";
    }
}