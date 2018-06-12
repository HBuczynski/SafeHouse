package wpam.mobile_client.protocol;

public enum GuardStatus
{
	ON(10),
	OFF(20);

	private int  Value;
	private static java.util.HashMap<Integer, GuardStatus> mappings;
	private static java.util.HashMap<Integer, GuardStatus> getMappings()
	{
		if (mappings == null)
		{
			synchronized (GuardStatus.class)
			{
				if (mappings == null)
				{
					mappings = new java.util.HashMap<Integer, GuardStatus>();
				}
			}
		}
		return mappings;
	}

	private GuardStatus(int value)
	{
		Value = value;
		getMappings().put(value, this);
	}

	public int getValue()
	{
		return Value;
	}

	public static GuardStatus forValue(int value)
	{
		return getMappings().get(value);
	}
}