package wpam.mobile_client.protocol;

	public enum AckType
	{
		OK(10),
		FAIL(20),
		CONNECTION_ENDED(30),
		CHANGED_MODE(40);

		private int value;
		private static java.util.HashMap<Integer, AckType> mappings;
		private static java.util.HashMap<Integer, AckType> getMappings()
		{
			if (mappings == null)
			{
				synchronized (AckType.class)
				{
					if (mappings == null)
					{
						mappings = new java.util.HashMap<Integer, AckType>();
					}
				}
			}
			return mappings;
		}

		private AckType(int value)
		{
			this.value = value;
			getMappings().put(this.value, this);
		}

		public int getValue()
		{
			return this.value;
		}

		public static AckType forValue(int value)
		{
			return getMappings().get(value);
		}
	}