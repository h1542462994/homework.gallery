# 进程管理

## 进程

并发性是操作系统最重要的特征，进程是操作系统最基本最重要的概念。

进程：可**并发执行**的程序在一个**数据**集合上的**运行过程**。

### 特征

- 动态性（Dynamic）：有生命周期
- 并发性
- 独立性（Isolation）
- 异步性（Async）

### 进程控制块（PCB）

#### 运行状态

> 掌握知识点1：五状态模型、四个状态的更换

- Ready 就绪状态
- Blocked 阻塞状态
- Running 运行状态
- New 新建
- Exit 终止
- [Suspended 挂起]
- 就绪态->运行态：处理器调度
- 运行态->就绪态：超时，高优先级抢占CPU
- 运行态->阻塞态：等待某个事件
- 阻塞态->就绪态：事件发生

#### 进程创建

分配标识、分配空间、初始化进程控制块，加入到正确的队列中

#### 进程切换

操作系统获得控制权的时候

- 保存处理器的上下文环境，包括PC和其他寄存器
- 更新A的PCB中的相关内容
- A的PCB加入到合适的队列
- 调度算法
- 更新B的PCB中的相关内容（变为运行态）
- 更新内存管理的数据结构，如基址寄存器和界限寄存器
- 恢复处理器的上下文环境，载入PC和其他寄存器最后一次保存的值。

//

- 模式切换可以不改变正处于运行态的进程状态。
- 进程切换时，操作系统必须使其运行环境发生改变。

#### 进程撤销

### 进程描述

PCB：进程标识信息，处理器状态信息，进程控制信息。

### 进程控制

执行模式：用户模式，系统模式、控制模式或内核模式

### 操作系统的执行

1. 无进程的内核
2. 在用户进程中执行
3. 基于进程的操作系统

### Unix/Linux进程控制原语

```
int pid = fork();
int execl(path, args);

void exit();
int wait();

#include <stdio.h>
void main(){
    int pid;
    pid = fork();
    
}
```