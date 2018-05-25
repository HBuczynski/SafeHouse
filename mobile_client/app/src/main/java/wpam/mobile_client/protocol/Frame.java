package wpam.mobile_client.protocol;

import java.io.*;
import java.util.ArrayList;

public abstract class Frame implements Closeable
	{
		public Frame(FrameType frameTypeIn, int dataSizeIn)
		{
			this.systemVersion_ = 1;
			this.frameType_ = frameTypeIn;
			this.packetNumber_ = 0;
			this.dataSize_ = dataSizeIn;
		}
		public void close()
		{}

		public abstract ArrayList<Integer> getFrameBytes();
		public abstract String getName();

		public ArrayList<Integer> getHeader()
		{
			ArrayList<Integer> header = new ArrayList<Integer>();
			header.add(systemVersion_ & 0xFF);
			header.add(frameType_.getValue() & 0xFF);
			header.add(packetNumber_ & 0xFF);
			header.add((dataSize_ >> 8) & 0xFF);
			header.add((dataSize_ ) & 0xFF);

			return header;
		}

		public final int getPacketNumber()
		{
			return this.packetNumber_;
		}
		public void setPacketNumber(int number)
		{

			this.packetNumber_ = number;
		}

		public int getDataSize()
		{
			return this.dataSize_;
		}

		public final void setDataSize(int dataSize)
		{
			this.dataSize_ = dataSize;
		}

		public int getSystemVersion()
		{
			return this.systemVersion_;
		}

		public final FrameType getFrameType()
		{
			return frameType_;
		}

		protected abstract void initializeDataSize();

		protected int systemVersion_;
		protected FrameType frameType_;
		protected int packetNumber_;
		protected int dataSize_;
	}