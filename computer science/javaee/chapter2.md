# Hibernate

## ORM

object-relation mapping

Hibernate，myBaties

### Hibernate

```py
*.cfg.xml  # config
*.hbm.xml  # hibernate mapping

dependencies

hibernate:^
jdbc:^

configuration
sessionFactory
session

composite-id
```

#### 单向关联

Person Country

```java
class Person implements Serializable {
    Uuid id;
    String name;
    Set<Country> country;
}

class Country {
    // 其他字段
}
```

表格：Person表，Country表，CountryPersons表

#### 关联

inverse, cascade

### myBaties

hibernate 切片

### JPA