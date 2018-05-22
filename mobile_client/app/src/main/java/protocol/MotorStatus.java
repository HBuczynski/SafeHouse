package protocol;

	public enum MotorStatus
	{
		START(10),
		STOP(20);

		private int value;
		private static java.util.HashMap<Integer, MotorStatus> mappings;
		private static java.util.HashMap<Integer, MotorStatus> getMappings()
		{
			if (mappings == null)
			{
				synchronized (MotorStatus.class)
				{
					if (mappings == null)
					{
						mappings = new java.util.HashMap<Integer, MotorStatus>();
					}
				}
			}
			return mappings;
		}

		private MotorStatus(int value)
		{
			value = value;
			getMappings().put(value, this);
		}

		public int getValue()
		{
			return this.value;
		}

		public static MotorStatus forValue(int value)
		{
			return getMappings().get(value);
		}
	}