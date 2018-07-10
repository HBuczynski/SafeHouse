package wpam.mobile_client.protocol;

import java.io.Closeable;

public abstract class ResponseVisitor implements Closeable
{
    public ResponseVisitor()
    {
    }
    public void close()
    {
    }

    public abstract void visit(AuthenticateResponse response);
    public abstract void visit(AckResponse response);
    public abstract void visit(ErrorResponse data);
    public abstract void visit(MotorStatusResponse data);
    public abstract void visit(BlindsStatusResponse data);
    public abstract void visit(GuardStatusResponse data);

}

