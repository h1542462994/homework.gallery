package org.tty.pcard;

public interface CardIdGenerator {
    String nextId(Class<? extends Card> card);
}
