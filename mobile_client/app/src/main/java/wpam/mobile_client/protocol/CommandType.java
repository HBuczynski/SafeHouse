package wpam.mobile_client.protocol;

import java.util.*;

	public enum CommandType
	{
		BLINDS_UP(5),
		BLINDS_DOWN(10),
		BLINDS_UP_ON_TIME(15),
		BLINDS_DOWN_ON_TIME(20),
		BLINDS_STATUS(25),
		AUTOMATIC_BLINDS(30),
		TEMPERATURE_DEMAND(35),
		USER_OUT_OF_HOME(40),
		USER_IN_HOME(41),
		SNAPSHOT(45),
		END_CONNECTION(50),
		START_STREAM(60),
		STOP_STREAM(70),
		MOTOR_STATUS_COMMAND(71),
		GUARD_STATUS_COMMAND(72);

		private int Value;
		private static java.util.HashMap<Integer, CommandType> mappings;
		private static java.util.HashMap<Integer, CommandType> getMappings()
		{
			if (mappings == null)
			{
				synchronized (CommandType.class)
				{
					if (mappings == null)
					{
						mappings = new java.util.HashMap<Integer, CommandType>();
					}
				}
			}
			return mappings;
		}

		private CommandType(int value)
		{
			Value = value;
			getMappings().put(value, this);
		}

		public int getValue()
		{
			return Value;
		}

		public static CommandType forValue(int value)
		{
			return getMappings().get(value);
		}
	}