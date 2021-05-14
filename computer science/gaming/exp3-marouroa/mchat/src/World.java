import marauroa.server.game.rp.RPWorld;
import marauroa.server.game.rp.MarauroaRPZone;

public class World extends RPWorld {
    private static World instance;

    public static World get() {
        if (instance == null) {
            instance = new World();
        }
        return instance;
    }

    @Override
    public void onInit() {
        super.onInit();
        MarauroaRPZone zone = new MarauroaRPZone("lobby");
        addRPZone(zone);
    }
}