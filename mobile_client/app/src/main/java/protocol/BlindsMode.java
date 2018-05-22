package protocol;

	public enum BlindsMode
	{
		MANUAL(10),
		AUTOMATIC(20),
		SET_ON_TIME_UP(30),
		SET_ON_TIME_DOWN(40),
		SET_ON_TIME_UP_AND_DOWN(50);

		private int value;
		private static java.util.HashMap<Integer, BlindsMode> mappings;
		private static java.util.HashMap<Integer, BlindsMode> getMappings()
		{
			if (mappings == null)
			{
				synchronized (BlindsMode.class)
				{
					if (mappings == null)
					{
						mappings = new java.util.HashMap<Integer, BlindsMode>();
					}
				}
			}
			return mappings;
		}

		private BlindsMode(int value)
		{
			this.value = value;
			getMappings().put(value, this);
		}

		public int getValue()
		{
			return this.value;
		}

		public static BlindsMode forValue(int value)
		{
			return getMappings().get(value);
		}
	}