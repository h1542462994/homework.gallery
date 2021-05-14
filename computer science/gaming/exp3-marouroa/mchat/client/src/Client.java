import marauroa.client.ClientFramework;

import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.LinkedList;

import marauroa.client.ClientFramework;
import marauroa.client.net.IPerceptionListener;
import marauroa.client.net.PerceptionHandler;
import marauroa.common.game.RPAction;
import marauroa.common.game.RPObject;
import marauroa.common.net.message.MessageS2CPerception;
import marauroa.common.net.message.TransferContent;

public class Client extends ClientFramework {
    private PerceptionHandler handler;
    private static Client client;
    private Map<RPObject.ID, RPObject> worldObjects;
    private String[] availableCharacters;
    private LinkedList<String> quotes = new LinkedList<String>();

    public static Client get() {
        if (client == null) {
            client = new Client();
        }
        return client;
    }

    protected Client() {
        super("log4j.properties");
        worldObjects = new HashMap<RPObject.ID, RPObject>();
        handler = new PerceptionHandler(new PerceptionListener());
    }

    public String[] getAvailableCharacters() {
        return availableCharacters;
    }

    public String popQuote() {
        if (quotes.isEmpty()) {
            return null;
        }
        return quotes.pop();
    }

    public void sendMessage(String text) {
        RPAction action;
        action = new RPAction();
        action.put("type", "chat");
        action.put("text", text);
        send(action);
    }

    @Override
    protected void onPerception(MessageS2CPerception message) {
        try {
            handler.apply(message, worldObjects);
        } catch (java.lang.Exception e) {
            // Something weird happened while applying perception
        }
    }

    @Override
    protected List<TransferContent> onTransferREQ(List<TransferContent> items) {
        return items;
    }

    @Override
    protected void onTransfer(List<TransferContent> items) {
    }

    @Override
    protected void onAvailableCharacters(String[] characters) {
        availableCharacters = characters;
    }

    @Override
    protected void onServerInfo(String[] info) {
        for (String s : info) {
            quotes.add(s);
        }
    }

    @Override
    protected String getGameName() {
        return "Chat";
    }

    @Override
    protected String getVersionNumber() {
        return "0.5";
    }

    @Override
    protected void onPreviousLogins(List<String> previousLogins) {
    }

    class PerceptionListener implements IPerceptionListener {
        @Override
        public boolean onAdded(RPObject object) {
            if (object.has("text")) {
                quotes.add("*" + object.get("from") + "* : " + object.get("text"));
            }
            return false;
        }

        @Override
        public boolean onModifiedAdded(RPObject object, RPObject changes) {
            return false;
        }

        @Override
        public boolean onModifiedDeleted(RPObject object, RPObject changes) {
            return false;
        }

        @Override
        public boolean onDeleted(RPObject object) {
            return false;
        }

        @Override
        public boolean onMyRPObject(RPObject added, RPObject deleted) {
            return false;
        }

        @Override
        public void onSynced() {
        }

        @Override
        public void onUnsynced() {
        }

        @Override
        public void onException(Exception e, MessageS2CPerception perception) {
            e.printStackTrace();
            System.exit(-1);
        }

        @Override
        public boolean onClear() {
            return false;
        }

        @Override
        public void onPerceptionBegin(byte type, int timestamp) {
        }

        @Override
        public void onPerceptionEnd(byte type, int timestamp) {
        }
    }
}