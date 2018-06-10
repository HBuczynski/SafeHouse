package wpam.mobile_client.protocol;

import java.io.Closeable;
import java.util.ArrayList;

public final class UserInHomeBuilder implements CommandBuilder, Closeable
{
    public UserInHomeBuilder()
    {
    }
    public final void close()
    {
    }

    @Override
    public Command create(ArrayList<Integer> commandInBytes)
    {
        Command command  = new UserInHomeCommand();
        return command;
    }
}