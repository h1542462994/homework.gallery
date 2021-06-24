package org.tty.pcard;

/**
 * 一张卡片
 */
public interface Card {
    void setId(String id);
    String getId();
    String getInfo();
}
