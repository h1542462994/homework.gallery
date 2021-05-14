package org.tty.psellor.printer;

import java.lang.annotation.Inherited;
import java.lang.annotation.Repeatable;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

/**
 * 打印机的品牌
 */
@Retention(RetentionPolicy.RUNTIME)
public @interface PrintBrand {
    /**
     * 厂商，例如hp
     */
    String vendor();

    /**
     * 版本，例如5129x
     */
    String version();
}
