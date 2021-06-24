package org.tty.pcard.shop;

import org.tty.pcard.Card;
import org.tty.pcard.CardIdentity;

@CardIdentity(type = "copper")
public class CopperCard implements Card {

    private String id;

    @Override
    public void setId(String id) {
        this.id = id;
    }

    @Override
    public String getId() {
        return id;
    }

    @Override
    public String getInfo() {
        return "shop,copper,id=" + id;
    }
}
