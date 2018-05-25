package wpam.mobile_client.protocol;

public enum FrameType
	{
		COMMAND(10),
		RESPONSE(20),
		MEASUREMENT_DATA(30);

		private int value;
		private static java.util.HashMap<Integer, FrameType> mappings;
		private static java.util.HashMap<Integer, FrameType> getMappings()
		{
			if (mappings == null)
			{
				synchronized (FrameType.class)
				{
					if (mappings == null)
					{
						mappings = new java.util.HashMap<Integer, FrameType>();
					}
				}
			}
			return mappings;
		}

		private FrameType(int value)
		{
			this.value = value;
			getMappings().put(value, this);
		}

		public int getValue()
		{
			return value;
		}

		public static FrameType forValue(int value)
		{
			return getMappings().get(value);
		}
	}