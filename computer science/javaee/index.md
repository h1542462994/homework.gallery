# JAVAEE 绪论

## 课程内容

SpringMVC+Mybatis+Spring

理解JavaEE所表达的软件架构和设计思想

注重动手能力，关注设计思想。

## 课程考核

- 课内实验 50%
- 期末考试 50%
    - SSH案例开发
    - 3-5人一组
    - 演示+提问
    - 上交源代码+文档

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