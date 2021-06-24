package org.tty.pcard;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

/**
 * 卡片标识
 */
@Retention(RetentionPolicy.RUNTIME)
public @interface CardIdentity {
    String type();
}
