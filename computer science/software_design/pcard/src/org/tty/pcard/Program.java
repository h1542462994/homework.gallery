package org.tty.pcard;

import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class Program {
    public static void main(String[] args) throws IOException, ClassNotFoundException {

        CardFactory factory = new CardFactoryBuilder()
            .withPackage("org.tty.pcard.shop")
            .withIdGenerator(new IncrementalCardIdGenerator(BigInteger.valueOf(20000000)))
            .build();
        List<String> types = new ArrayList<>();
        types.add("gold");
        types.add("silver");
        types.add("copper");

        for (int i = 0; i < 100; i++) {
            Card card = factory.create(types.get(i % types.size()));
            System.out.println(card.getInfo());
        }

    }
}
