package org.tty.pcard.shop;

import org.tty.pcard.Card;
import org.tty.pcard.CardIdentity;

/**
 * 金卡
 */
@CardIdentity(type = "gold")
public class GoldCard implements Card {

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
        return "shop,gold,id=" + getId();
    }
}
