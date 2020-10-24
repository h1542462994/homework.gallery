# Structs

## JavaWeb

### JavaEE的特点

1. 开放的，基于标准的平台。 
2. 简化企业级的解决方案
3. 是一系列技术标准，其核心是包含各类组件、服务架构的技术标准

### JaveWeb复习

```
forword(),include()的区别

<%@include %>和<jsp:include>的区别
```

bean在JSP页面中的应用

表单bean

### 设计线程安全三个解决方案

实现SingleThreadModel接口

```java
public class OurSTServlet extends HttpServlet implements SingleThreadModel {
    ...
}
```

```java
synchronized(this){
}
```

```java
int localCount;
synchronized(this){
    localCount = ++count;

}
out.print("Count is " + localCount);

```

### 状态

session和cookie

## MVC模式简介

Model-View-Controller

Model：数据模型，业务逻辑模型。

## Structs

### View层

```jsp
<%@taglib prefix="s" url="/struts-tags"%>
<s:form action="login.action" method=post>
</s:form>
```

### Controller层

LoginAction

structs.xml

RegisterAction

在web.xml中配置structs2

拦截器 Interceptor

### Action自定义方法