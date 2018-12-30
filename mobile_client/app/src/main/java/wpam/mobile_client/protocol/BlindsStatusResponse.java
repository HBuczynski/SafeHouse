package wpam.mobile_client.protocol;

import java.util.ArrayList;

public final class BlindsStatusResponse extends Response
{
	private BlindsStatus status_;
	private BlindsMode mode_;

	public BlindsStatusResponse(BlindsStatus status, BlindsMode mode)

	{
		super(10, ResponseType.BLINDS_STATUS_RSP);
		this.status_ = status;
		this.mode_ = mode;
	}
	public final void close()
	{
		super.close();
	}

	@Override
	public ArrayList<Integer> getFrameBytes()
	{
		initializeDataSize();

		ArrayList<Integer> frame = getHeader();
		frame.add(responseType_.getValue());
		frame.add(status_.getValue());
		frame.add(mode_.getValue());

		return frame;
	}

	@Override
	public String getName()
	{
		return new String("BlindsStatusResponse");
	}

	@Override
	public void accept(ResponseVisitor visitor)
	{
		visitor.visit(this);
	}

	public BlindsStatus getBlindsStatus()
	{
		return this.status_;
	}

	public void setBlindsStatus(BlindsStatus status)
	{
		this.status_ = status;
	}

	public BlindsMode getBlindsMode()
	{
		return this.mode_;
	}
	public void setBlindsMode(BlindsMode mode)
	{
		this.mode_ = mode;
	}

	@Override
	protected void initializeDataSize()
	{
		setDataSize(3);
	}
}