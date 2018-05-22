package protocol;


	public enum ErrorType
	{
		ENGINE_FAILURE(10),
		CONNECTION_TIMEOUT(20);

		private int value;
		private static java.util.HashMap<Integer, ErrorType> mappings;
		private static java.util.HashMap<Integer, ErrorType> getMappings()
		{
			if (mappings == null)
			{
				synchronized (ErrorType.class)
				{
					if (mappings == null)
					{
						mappings = new java.util.HashMap<Integer, ErrorType>();
					}
				}
			}
			return mappings;
		}

		private ErrorType(int value)
		{
			this.value = value;
			getMappings().put(value, this);
		}

		public int getValue()
		{
			return this.value;
		}

		public static ErrorType forValue(int value)
		{
			return getMappings().get(value);
		}
	}