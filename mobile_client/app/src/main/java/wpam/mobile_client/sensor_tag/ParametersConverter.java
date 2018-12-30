package wpam.mobile_client.sensor_tag;

public class ParametersConverter {

    public static float getTemperatureCelcius(int value) {
        final float SCALE = 0.03125f;
        return ((value >> 2) & 0xFF) * SCALE;
    }

    public static float getHumidity(int value) {
        value &= ~0x0003;
        return ((float)value / 65536.0f)*100.0f;
    }
}
