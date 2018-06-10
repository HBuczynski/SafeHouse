package wpam.mobile_client.protocol;
import java.util.ArrayList;

public class BytesConverter
	{
		public static void appendUINT16toVectorOfUINT8(int number, ArrayList<Integer> vec)
		{
			vec.add(((number >> 8) & 0x000000FF));
			vec.add((number) & 0x000000FF);
		}
		public static int fromVectorOfUINT8toUINT16(ArrayList<Integer> vec, int variablePosition)
		{
			int number =0;
			number = (vec.get(variablePosition) << 8) & 0x0000FF00;
			number |= vec.get(++variablePosition) & 0x000000FF;

			return number;
		}

		public static void appendUINT32toVectorOfUINT8(int number, ArrayList<Integer> vec)
		{
			for (int i = 24; i >= 0; i = i - 8)
			{
				vec.add((number >> i) & 0x000000FF);
			}
		}

		public static int fromVectorOfUINT8toUINT32(ArrayList<Integer> vec, int variablePosition)
		{
			int number =0;
			number = (vec.get(variablePosition) << 24) & 0xFF000000;
			number |= vec.get(++variablePosition << 16) & 0x00FF0000;
			number |= vec.get(++variablePosition << 8) & 0x0000FF00;
			number |= vec.get(++variablePosition) & 0x000000FF;

			return number;
		}
	}