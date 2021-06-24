package org.tty.pcard;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * 卡片工厂builder
 */
public class CardFactoryBuilder {
    ArrayList<String> packages = new ArrayList<>();
    ArrayList<Class<? extends Card>> types = new ArrayList<>();
    CardIdGenerator generator;

    /**
     * 导入包
     * @param packageName 包名
     */
    public CardFactoryBuilder withPackage(String packageName) {
        packages.add(packageName);
        return this;
    }

    /**
     * 导入类
     * @param type 类型
     */
    public CardFactoryBuilder with(Class<? extends Card> type) {
        types.add(type);
        return this;
    }

    /**
     * 设置id生成器
     * @param generator
     * @return
     */
    public CardFactoryBuilder withIdGenerator(CardIdGenerator generator) {
        this.generator = generator;
        return this;
    }

    private String getType(Class<? extends Card> type) {
        CardIdentity identity = type.getDeclaredAnnotation(CardIdentity.class);
        assert identity != null;
        return identity.type();
    }

    public CardFactory build() {
        HashMap<String, Class<? extends Card>> cards = new HashMap<>();
        packages.forEach(p -> {
            ClassScanner scanner = new ClassScanner(p, false, s -> true, c -> true);
            try {
                scanner.doScanAllClasses().forEach(c -> {
                    if (Card.class.isAssignableFrom(c) && c.getDeclaredAnnotation(CardIdentity.class) != null) {
                        Class<? extends Card> cType = (Class<? extends Card>) c;
                        cards.put(getType(cType), cType);
                    }
                });
            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        });
        types.forEach(t -> {
            cards.put(getType(t), t);
        });

        return new CardFactory() {
            @Override
            public Card create(String type) {
                try {
                    Card instance = cards.get(type).newInstance();
                    instance.setId(generator.nextId(instance.getClass()));
                    return instance;
                } catch (InstantiationException | IllegalAccessException e) {
                    e.printStackTrace();
                    return null;
                }
            }
        };
    }
}
