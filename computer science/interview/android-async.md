# 安卓-异步知识点

1. [AsyncTask将在API 30中废弃](https://www.jianshu.com/p/41e2d04a35b4)\

## kotlin 协程

1. 了解Scope的概念，以及何时使用GlobalScope、ViewModelScope、ActivityScope。

2. [Android Kotlin携程的概念](https://www.cnblogs.com/fuyaozhishang/p/14582581.html)

3. [在Android开发中使用协程|上手指南](https://zhuanlan.zhihu.com/p/135203063)

协程的特点
- 以近似同步代码的形式执行异步代码。
- 主线程安全
- 可以执行耗时的任务，代码块。

其他注意的问题
- 需要使用Scope来追踪协程。

## 其他

1. Thread
2. HandlerThread
3. AsyncTask
4. IntentService
5. Executor

## 老的技术框架

1. RxJava
2. Executors
3. AsyncTask