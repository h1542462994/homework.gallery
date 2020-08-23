# 操作系统 第六章 CPU调度

## 调度

### 背景

内核运行调度程序的条件（满足一条即可）

1. 一个进程从运行状态切换到等待状态
2. 一个进程被终结了

- 不可抢占
    - 调度程序必须等待事件结束
- 可以抢占
    - 调度程序在中断被响应后执行
    - 当前的进程从运行切换到就绪，或者一个进程从等待切换到就绪
    - 当前运行的进程可以被换出

### 调度原则

执行模型：程序在CPU突发和I/O中交替
    - 每个调度决定都是关于在下一个CPU突发时将哪个工作交给CPU
    - 在时间分片机制下，线程可能在结束当前CPU突发前被迫放弃CPU。

- CPU使用率
    - CPU处于忙状态所占时间的百分比
- 吞吐量
    - 在单位时间内完成的进程数量
- 周转时间
    - 一个进程从初始化到结束，包括所有等待时间所花费的时间
- 等待时间
    - 进程在就绪队列中的总时间
- 响应时间
    - 从一个强求被提交到产生第一次响应所花费的总时间

- 人们通常都需要“更快的服务”
- 什么是更快
    - 传输文件时的高带宽
    - 玩游戏时的低延迟
    - 这两个因素是独立的
- 公平的定义
    - 保证每个进程占用相同的CPU时间

### 调度算法

- FCFS 先来先服务 First Come, First Serve
    - 波动比较大
- SPN(SJF) SRT 短进程优先 Shortest Job Next Shortest-Remaining-Time
    - 可能导致饥饿
    - 需要预知未来
- HRRN 最高响应比优先 Highest Response Robin Next
    - 不可抢占
    - 关注进程等待了多长时间
    - 防止无限期推迟
- Round Robin 轮询
    - 等待时间过长
    - 时间量子太小
    - 目标：选择一个合适的时间量子，维持上下文切换开销处于1%以内
    - CPU密集型任务的优先级下降，I/O密集型任务停留在高优先级
- Multilevel Feedback Queues 多级反馈队列
    - 时间量子大小随优先级级别增加而减小
    - 如果任务在当前的时间量子中没有完成，则降到下一个优先级
- Fair Share Scheduling 公平共享调度
    - 一些用户组比其他用户组更重要
    - 保证不重要的组无法垄断资源
    - 未使用的资源按照每个组所分配的资源的比例来分配
    - 没有达到资源使用率目标的组获得更高的优先级

### 实时调度（Real Time System）

定义：

正确依赖于其时间和功能两方面的一种操作系统

性能指标：
1. 时间约束的及时性
2. 速度和平均性能相对不重要

主要特性：时间约束的可预测性

强实时系统：需要在保证的时间内完成重要的任务，必须完成
弱实时系统：要求重要的进程的优先级更高，尽量完成，并非必须

表示一个实时系统是否能够满足deadline要求
- 决定实时任务执行的顺序
- 静态优先级调度
- 动态优先级调度

RM（Rate Monotonic）速率单调调度
- 最佳静态优先级调度
- 通过周期安排优先级
- 周期越短优先级越高

EDF（Earliest Deadline First）最早期限调度
- 最佳的动态优先级调度
- Deadline最早优先级越高
- 执行Deadline最早的任务

### 多处理器调度

多处理器的CPU调度更加复杂

- 多个相同的单处理器组成一个多处理器
- 优点：负载共享

对称多处理器（SMP）
 
- 每个处理器运行自己的调度程序
- 需要在调度程序中同步

### 优先级反转

没有优先级反转：低优先级的线程使用共享资源被中途抢断导致高优先级的线程使用资源时被迫等待的现象。从而导致次优先的线程反而等待时间比高优先级短的现象。

解决方法：继承共享资源所占用的线程的最高的优先级

## 同步

- 独立的线程：不和其他线程共享资源或状态
    - 确定性 => 输入状态决定结果
    - 可重现 => 能够重现起始条件，I/O
    - 调度顺序不重要
- 合作线程
    - 在多个线程中共享状态
    - 不确定性
    - 不可重现
- 不确定性和不可重现意味着bug可能时间歇性发生的。

- 进程/线程，计算机/设备需要合作
    - 优点1：共享资源
        - 一台电脑，多个用户
    - 优点2：加速
    - 优点3：模块化

### 希望情况

1. 无论多个线程的指令序列怎样交替执行，程序都必须正常工作

2. 不确定性要求并行程序的正确性

### 名词解释

#### Race Condition 竞争条件

#### Atomic Operation 原子操作

1. 原子操作是指一次不存在任何中断或者失败的执行
2. 实际上操作往往不是原子的

#### Critical section 临界区

临界区是指进程中的一段需要访问共享资源并且当另一个进程处于相应代码区域时便不会被执行的代码区域

#### Mutual exclusion

当一个进程处于临界区并访问共享资源时，没有其他进程会处于临界区并且访问任何相同的共享资源

#### Dead lock

两个或以上的进程，在相互等待完成特定任务，而最终没法将自身任务进行下去

#### Starvation

一个可执行的进程，被调度器持续忽略，以至于虽然处于可执行状态却不被执行

#### 锁，解锁，死锁

互斥：同一时间临界区中最多存在一个线程
Progress：如果一个线程想要进入临界区，那么它最终会成功
有限等待：如果一个线程i处于入口区，那么在i的请求被接受之前，其他线程进入临界区的时间是有限制的。
无忙等待（可选）：如果一个进程在等待进入临界区，那么它可以进入之前会被挂起

### 实现方法

#### 禁用硬件中断

1. 没有中断，没有上下文切换，因此没有并发
2. 进入临界区禁用中断，离开临界区开启中断

缺点：

1. 一旦中断被禁用，线程就无法被停止
    - 整个系统都会为你停下来
    - 可能导致其他线程处于饥饿状态
2. 要是临界区可以任意长怎么办
3. 要小心使用
4. 无法适用于多CPU的情况

#### 基于软件的解决方案

1. 交替轮转法
    - 缺点：满足互斥，但不满足process

2. Peterson算法
3. Dekker算法：第一个针对双线程例子的正确解决方案
4. Eisenberg and McGuire's Algorithm
5. Bakery算法：针对n线程的临界区问题解决方案

没有硬件保证的情况下无真正的软件解决方案，需要原子的LOAD和STORE指令

#### 更高级的抽象

1. 硬件提供了一些原语
    - 像中断禁用，原子操作指令等
    - 大多数现代体系结构都这样
2. 操作系统提供更高级的编程抽象来简化并行编程
    - 例如：锁，信号量
    - 从硬件原语中构建

3. 使用原子指令test-and-set和exchange可以完成锁的操作

- 优点：
    - 适用于单处理器或者共享主存的多处理器
    - 简单并且容易证明
    - 可以用于支持多临界区
- 缺点：
    - 忙等待消耗处理器时间
    - 当进程离开临界区并且多个进程在等待的时候可能导致饥饿
    - 死锁：如果一个低优先级的进程拥有临界区并且一个高优先级进程也需求，那么高优先级进程会获得处理器并等待临界区

## 信号量

抽像数据类型

- 一个整形（semaphore），两个原子操作
    - P()：sem减1，如果sem<0，等待，否则继续
    - V()：如果sem<=0，唤醒一个等待的P

特点：
    - 信号量是整数
    - 信号量是被保护的变量
    - P()能够阻塞，V()不会阻塞
    - 我们假定信号量是“公平的”

### 信号量使用

- 两种类型信号量
    - 二进制信号量：可以是0或1
    - 一般/计数信号量：可取任何非负值
- 信号量可以用在2个方面
    - 互斥
    - 条件同步（调度约束——一个线程等待另一个线程的事情发生）
- 一个线程等待另一个线程处理事情
    - 比如生产东西或消费东西
    - 互斥（锁机制）是不够的
    - 例如：有限缓冲区的生产者——消费者问题

### 信号量实现

- 读/开发代码比较困难
    - 程序员必须非常精通信号量
- 容易出错
    - 使用的信号量已经被另一个线程占用
    - 忘记释放信号量
- 不能够处理死锁问题

## 管程（难点）

目的：分离互斥和条件同步的关注
- 什么是管程
    - 一个锁：指定临界区
    - 0或者多个条件变量：等待/通知信号量用于管理并发访问共享数据
- 一般方法
    - 收集在对象/模块中的相关共享数据
    - 定义方法来访问共享数据

## 经典同步问题

### 读者-写者问题

- 动机
    - 共享数据的访问
- 两种类型使用者
    - 读者：不需要修改数据
    - 写者：读取和修改数据
- 问题的约束
    - 允许同一时间有多个读者，但在任何时候只有一个写者
    - 当没有写者时读者才能访问数据
    - 当没有读者和写者时写者才能访问数据
    - 在任何时候只能有一个线程可以操作共享变量

读者优先，写者优先。

### 哲学家就餐问题

## 死锁

### 死锁问题

一组阻塞的进程持有一种资源等待获取另一个进程所占有的一个资源

### 系统模型

- 可重复使用的资源：
    - 在一个事件只能一个进程使用且并不能被删除
    - 进程获得资源，后来释放由其他进程宠用
    - 数据库，I/O通道，存储器，设备和数据结构
    - 如果每个进程拥有一个资源并请求其它资源，死锁可能发生

- 使用资源
    - 创建和销毁
    - 在I/O缓冲区的中断，信号，消息，信息
    - 如果接受消息阻塞可能会发生死锁
    - 可能少见的组合事件会引起死锁

#### 资源分配图

- 如果图中不包含循环==>没有死锁
- 如果途中包括循环
    - 如果每个资源类只有一个实例，那么死锁
    - 如果每个资源类有几个实例，可能死锁

### 死锁特征

- 互斥：在一个时间只能有一个进程使用资源
- 持有并等待：进程保持至少一个资源正在等待获取其他进程所持有的额外资源
- 无抢占：一个资源只能被进程自愿释放，进程已经完成了它的任务之后
- 循环等待：

### 死锁处理办法

- 确保系统永远不会进入死锁状态
- 运行系统进入死锁状态，然后恢复
- 忽略这个问题，假装系统中从来没有发生，用于大多数操作系统，包括UNIX。

#### 死锁预防

限制申请方式
- 互斥——共享资源不是必须的，必须占用非共享资源
- 占用并等待——必须保持当一个进程请求的资源，它不持有任何其他资源
- 无抢占——如果进程占有某些资源，并请求其他不能被立即分配的资源，则释放当前正占用的资源
- 循环等待——对所有资源类型进行排序，并要求每个进程按照资源的顺序进行申请

#### 死锁避免

需要系统具有一些额外的先验信息提供
- 最简单的最有效的模式是要求每个进程声明它可能需要的每个类型资源的最大数目
- 资源的分配状态是通过限定提供与分配的资源数量，和进程的最大需求
- **死锁避免算法**动态检查的资源分配状态，以确保永远不会有一个环形等待状态

序列$<P1,P2,\cdots,PN>$是安全的，针对每个$P_i$，$P_i$要求的资源当前可用的资源+所有的$P_j$持有的资源来满足，其中$j<i$

#### Banker's Algorithm

n = 进程数量，m=资源类型数量，Max：n*m矩阵，Available剩余空闲量，Allocation已分配量，Need未来需要量

使用搜索的方法即可解决

1. 如果Request<=Need，转到步骤2，否则，提出错误条件，因为进程已经超过了其最大需求
2. 如果Request<=Available，转到步骤3，否则P必须等待，因为资源不可用
3. 通过修改状态来分配请求资源给P

#### 死锁检测与死锁恢复

使用类似于死锁避免的银行家算法，时间复杂度$O(mn^2)$

- 中止所有的死锁进程
- 在一个时间内终止一个进程知道死锁清楚
- 中止进程的顺序

## IPC

### 概述

- 通信模型
- 直接及间接通信
    - 直接通信
        - 自动建立链路
        - 一个链路恰好对应一个通信模型
        - 每对进程之间只有一个链接存在
        - 链接可以是单向的，但通常为双向的
    - 间接通信
        - 只有进程共享一个共同的消息队列，才建立链路
        - 链接可以与许多进程相关联
        - 没对进程可以共享多个通信链路
        - 链接可以是单向或双向
- 阻塞与非阻塞
    - 阻塞被认为是同步
    - 非阻塞被认为是异步的
- 通信链路缓冲
    - 0容量，有限容量，无限容量

### 信号

- 软件中断通知事件处理
- 接收到信号时会发生什么
    - Catch：指定信号处理函数被调用
    - Ignore：依靠操作系统的默认操作
    - Mask：闭塞信号因此不会传送
- 不足
    - 不能传递要交换的任何数据

### 管道

- 子进程从父进程继承文件描述符
- 创建管道，设置管道

### 消息队列

- 消息队列按FIFO的来管理消息
    - Message：作为一个字节序列存储
    - Message Queues：消息数组

### 共享内存

- 进程
    - 每个进程都有私有地址空间
    - 在每个地址空间内，明确地设置了共享内存段
- 优点
    - 快速、方便地共享数据
- 不足
    - 必须同步数据访问

### 最快的方法
    
将同一块物理内存映射到不同进程的不同的虚拟地址空间。