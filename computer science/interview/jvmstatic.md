# Java虚拟机

## 简介

GraalVM：次世代多语言虚拟机，目前处于实验阶段。

HotSpot：Oracle JDK和Open JDK通常使用的虚拟机。

JVM：稳定，高的可扩展性，但是在微服务等要求小而快捷的场合疲软。

JIT即时编译和AOT提前编译

## 内存管理

构成：
1. 方法区 Method Area
    - 永久代、本地内存、元空间
    - 运行时常量池
2. 堆 Heap
3. 虚拟机栈 VM Stack
    - 栈帧 Stack Frame
    - 局部变量表
4. 本地方法栈 Native Method Stack
5. 程序计数器 Program Counter Register

其他：
1. 直接内存 Direct Memory
   - 基于通道（Channel）和缓冲区（Buffer）的方式

### HotSpot虚拟机

四锁原理：https://cloud.tencent.com/developer/article/1447345

- 对象的创建
  - 常量表类的符号引用、类初始化与加载、分配内存、调用构造函数。
  - 如何面对同步问题：CAS锁（失败重试）或者本地线程分配缓冲（TLAB）
  - 对象的内存布局：对象头（Header）、实例数据（Instance Data）、对齐填充（Padding）。
    - 对象头含有"Mark Word"部分
    - 访问方式定位：直接地址、句柄。

## 垃圾回收(GC)


1. 引用计数算法
2. 可达性分析算法（Reachability Analysis）
   - GC Roots
   - 局部回收
   - 强引用、软引用SoftReference、弱引用WeakReference、虚引用PhantomReference
   - 两次标记法
   - F-Queue，在生命周期内仅使用一次finalize()。
3. 回收方法区
    - 使用场合：反射，动态代理，CGLib，JSP，OSGi

### 垃圾回收算法

1. 分代收集理论
    - 弱分代假说
    - 强分代假说
    - 跨代引用假说：记忆集 Remember Set
2. 标记清除算法 Mark-Sweep
3. 标记复制算法 Mark-Copy
    - Appel式回收：8Eden空间，1*2Survivor空间
4. 标记整理算法 Mark-Compact

### HotSpot的算法细节实现

1. 根节点枚举，借用OopMap的数据结构来达到这个目的。
2. 安全点：主动式中断，内存保护陷阱。
3. 安全区域：能够确保在某一段代码片段之中，引用关系不会发生变化。
4. 记忆集与卡表。
5. 写屏障：高并发情形下的伪共享问题。
6. 并发的可达性分析：需要保障一致性的快照
    - 赋值器插入了一条或多条从黑色对象到白色对象的新引用。解决方法：插入更新（Incremental Update）
    - 赋值器删除了全部从灰色对象到该白色对象的直接或简介引用。解决方法：Snapshot At The Beginning（SATB）

### 经典垃圾收集器

1. Serial收集器
    - 最基础、历史最悠久的收集器。
    - 特点：简单，占用内存小。
2. ParNew和Serial Old收集器。再到ParNew到CMS（并发）。
3. CMS（Concurrent Mark Sweep）收集器
    - 特点：老生代，标记-清除算法。
    - 四个步骤：初始标记、并发标记、重新标记、并发清除。
    - 缺点：对CPU资源敏感，无法处理浮动垃圾。碎片问题。
4. G1（Garbage First收集器）
    - 特点：不对新生代和老生代进行分类，使用Region进行标记
    - 过程：初始标记，并发标记，最终标记，筛选回收
    - 缺点：高的内存占用，无法使用小型场景。


### 低延迟垃圾收集器