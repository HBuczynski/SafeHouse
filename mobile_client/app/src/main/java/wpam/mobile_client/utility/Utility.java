package wpam.mobile_client.utility;

import java.sql.Timestamp;
import java.util.Date;

public class Utility {
    public static Date getDateFromEpochTime(int epochTime) {
        Timestamp stamp = new Timestamp(epochTime);
        return new Date(stamp.getTime());
    }
}
