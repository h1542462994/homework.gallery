# 并发与同步

在多道程序环境下，系统中各进程以不可预测的速度向前推进，进程的异步性会造成结果的不可再现性。

1. 相互竞争关系

- 互斥（mutual exclusion）
- 死锁（deadlock）
- 饥饿（starvation）

2. 相互合作关系

- 同步（sync）

## 进程同步机制

- 空闲让进
- 忙则等待
- 有限等待
- 让权等待

## 互斥部分

软件方法

- Dekker's算法
- Barkely算法
- Peterson算法

## 硬件部分

- 特殊的机器指令 Testset，exchange

## 操作系统实现方式

- 信号量（Semaphore）
- Binary Semaphore，Semaphore