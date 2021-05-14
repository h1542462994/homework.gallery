import marauroa.common.game.RPObject;

public class Test {
    public static void main(String[] args) {
        boolean runClient = true;
        Client client = Client.get();
        try {
            client.connect("localhost", 5555);
            if (args.length == 3) {
                client.createAccount(args[0], args[1], args[2]);
            }
            client.login(args[0], args[1]);
            if (client.getAvailableCharacters().length == 0) {
                RPObject character = new RPObject();
                client.createCharacter(args[0], character);
            }
            client.chooseCharacter(args[0]);
        } catch (Exception e) {
            runClient = false;
        }
        int i = 0;
        while (runClient) {
            i++;
            client.loop(0);
            if (i % 100 == 50) {
                client.sendMessage("test" + i);
            }
            String s = client.popQuote();
            while (s != null) {
                System.out.println(s);
                s = client.popQuote();
            }
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                runClient = false;
            }
        }
    }
}