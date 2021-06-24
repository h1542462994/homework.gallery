package org.tty.pcard;

import java.math.BigInteger;

public class IncrementalCardIdGenerator implements CardIdGenerator {
    public IncrementalCardIdGenerator(BigInteger first) {
        this.current = first;
    }

    BigInteger current;

    @Override
    public String nextId(Class<? extends Card> card) {
        String currentStr = current.toString();
        current = current.add(BigInteger.valueOf(1));
        return currentStr;
    }
}
