package org.tty.pcard;

/**
 * 卡片工厂
 */
public interface CardFactory {
    Card create(String type);
}
