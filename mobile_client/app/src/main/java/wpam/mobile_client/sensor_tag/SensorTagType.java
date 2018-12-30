package wpam.mobile_client.sensor_tag;

import java.io.Serializable;

public enum SensorTagType implements Serializable
{
    FIRST(10),
    SECOND(20),
    THIRD(30),
    ALL(40);

    private int value;
    private static java.util.HashMap<Integer, SensorTagType> mappings;
    private static java.util.HashMap<Integer, SensorTagType> getMappings()
    {
        if (mappings == null)
        {
            synchronized (SensorTagType.class)
            {
                if (mappings == null)
                {
                    mappings = new java.util.HashMap<Integer, SensorTagType>();
                }
            }
        }
        return mappings;
    }

    private SensorTagType(int value)
    {
        this.value = value;
        getMappings().put(this.value, this);
    }

    public int getValue()
    {
        return this.value;
    }
    public static SensorTagType forValue(int value)
    {
        return getMappings().get(value);
    }
    public static String getName() {
        return "SensorTagType";
    }
}