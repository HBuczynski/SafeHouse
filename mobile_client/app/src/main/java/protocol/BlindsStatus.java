package protocol;

	public enum BlindsStatus
	{
		UP(10),
		DOWN(20);

		private int value;
		private static java.util.HashMap<Integer, BlindsStatus> mappings;
		private static java.util.HashMap<Integer, BlindsStatus> getMappings()
		{
			if (mappings == null)
			{
				synchronized (BlindsStatus.class)
				{
					if (mappings == null)
					{
						mappings = new java.util.HashMap<Integer, BlindsStatus>();
					}
				}
			}
			return mappings;
		}

		private BlindsStatus(int value)
		{
			this.value = value;
			getMappings().put(value, this);
		}

		public int getValue()
		{
			return this.value;
		}

		public static BlindsStatus forValue(int value)
		{
			return getMappings().get(value);
		}
	}