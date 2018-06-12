package wpam.mobile_client.protocol;

public enum ResponseType
	{
		ACK(10),
		BLINDS_STATUS_RSP(15),
		MOTOR_STATUS(20),
		ERROR(25),
		AUTHENTICATE(30),
		GUARD_STATUS(35);

		private int value;
		private static java.util.HashMap<Integer, ResponseType> mappings;
		private static java.util.HashMap<Integer, ResponseType> getMappings()
		{
			if (mappings == null)
			{
				synchronized (ResponseType.class)
				{
					if (mappings == null)
					{
						mappings = new java.util.HashMap<Integer, ResponseType>();
					}
				}
			}
			return mappings;
		}

		private ResponseType(int value)
		{
			this.value = value;
			getMappings().put(value, this);
		}

		public int getValue()
		{
			return this.value;
		}

		public static ResponseType forValue(int value)
		{
			return getMappings().get(value);
		}
	}