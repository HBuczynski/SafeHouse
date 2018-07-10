package wpam.mobile_client.protocol;

import java.util.ArrayList;

public final class GuardStatusResponse extends Response
{
	public GuardStatusResponse(GuardStatus type)
	{
		super(10, ResponseType.GUARD_STATUS);
		this.type_ = type;
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
		frame.add(type_.getValue());

		return frame;
	}
	@Override
	public String getName()
	{
		return new String("GuardStatusResponse");
	}
	@Override
	public void accept(ResponseVisitor visitor)
	{
		visitor.visit(this);
	}

	public GuardStatus getGuardStatus()
	{
		return type_;
	}
	public void setGuardStatus(GuardStatus type)
	{
		type = type_;
	}

	@Override
	protected void initializeDataSize()
	{
		setDataSize(2);
	}

	private GuardStatus type_;
}