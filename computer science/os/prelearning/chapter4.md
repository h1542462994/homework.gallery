# 操作系统 第四章 虚拟内存技术

## 虚拟内存的起因

## 覆盖技术(Overlay)

目标：实在较小的可用内存中运行较大的程序。常用于多道程序系统，与分区存储管理配合使用
原理：把程序按照其自身逻辑结构，划分为若干个功能上相对独立的程序模块，那些不会同时执行的模块共享同一块内存区域，按事件先后来运行。

## 交换技术(Swapping)

目标：多道程序在内存中时，让正在运行的程序或需要运行的程序获得更多的内存资源。
- 交换技术实现中的几个问题
    - 交换时机的确定，何时需要发生交换？只当内存空间不够或有不够使用的趋势时发生交换。
    - 交换区的大小：必须足够大以存放所有用户进程的所有内存映像的拷贝，必要能对这些内存映像直接存取
    - 程序换入时的重定位

## 虚存技术

目标：像覆盖技术那样，不是把程序的所有内容都放到内存中，因而能够运行比当前的内存空间还要大的程序。但做得更好，由操作系统自动来完成。
像交换技术那样，能够实现进程在内存与外村之间的交换。但做得给更好，只对进程的部分内容在内存和外存之间进行交换。

### 程序的局部性原理

指程序在执行过程中的一个较短时期，所执行的地址和指令的操作数地址，分别局限于一定区域

- 时间局部性：一个数据的一次访问和下次访问都集中在一个较短时期内。
- 空间局部性：当前指令和邻近的几条指令，当前访问的数据和邻近的几个数据都集中在一个较小区域内。

### 基本概念

可以在页式或段式内存管理的基础上实现

### 基本特征

大的用户空间：通过把物理内存与外村相结合，提供给用户的虚拟内存空间通常大于实际的物理内存，即实现了这两者的分离。如32位的虚拟地址理论上可以访问4GB。

部分交换：与交换技术相比较，虚拟存储的调入和调出是对部分虚拟地址空间进行的。

不连续性：物理内存分配和虚拟地址空间使用的不连续。

### 虚拟页式内存管理

大部分虚拟存储系统都采用虚拟页式存储管理技术，即在页式存储管理的基础上，增加请求调页和页面置换功能。

访问位，修改位，保护位，驻留页

#### 缺页中断

1. 如果有空闲的物理界面，则非陪物理页帧f，然后转第4步。
2. 采用页面置换算法，写回外存
3. 驻留位置0
4. 装入物理页帧
5. 驻留位置1，页帧号置f
6. 重新运行被中断的指令

#### 后备存储

- 在何处保存未被映射的页？
    - 能够简单地识别在二级存储器中的页
    - 交换空间（磁盘或者文件）：特殊格式，用于存储未被映射的页面
- 后背存储
    - 一个虚拟地址空间的页面可以被映射到一个文件的某个位置
    - 代码段
    - 动态加载的共享库程序段
    - 其他段：交换文件

#### 虚拟内存性能

有效存储器访问时间

EAT = 访存时间 * 页表命中几率 + page fault 处理时间 * page fault 几率

p: page fault几率 q: dirty page几率

EAT = 10(1-p)+5,000,000p(1+q)

## 页面置换算法

### 局部页面置换算法

功能：当缺页中断发生，需要调入新的页面二内存已满时，选择内存当中那个物理页面被置换

目标：尽可能地减少页面的换入换出次数

页面锁定：常驻内存

1. 最优页面置换算法（计算出等待时间最长的那个替换）

2. 先进先出算法（FIFO）：性能较差，调出的界面可能是经常要访问的页面，容易产生Belady现象。

3. 最近最久为使用算法（Least Recently Used，LRU）：是对最优页面置换算法的一个近似

4. 时钟页面置换算法：LRU的近似，对FIFO的一种近似。（操作系统定期清零）

5. 二次机会法：同时使用脏位和使用位来导致替换。

6. 最不常用算法：LFU（Least Frequently Used）

#### Belady现象

在FIFO算法中分配物理帧增加缺页异常却更加多的现象。

#### 比较

LRU算法和FIFO算法本质上都是先进先出的思路。Clock是对LRU的近似，即不精确计算各个内存的访问顺序和时间。

LRU算法性能较好，但系统开销较大，FIFO算法系统开销较小，但可能会发生Belady现象。

### 全局页面置换算法

#### 工作集（working set）模型

工作集：一个进程当前正在使用的逻辑页面集合，可以用一个二元函数$w(t,\Delta)$来表示

#### 常驻集

常驻集是指在当前时刻，进程实际驻留在内存当中的页面集合。

#### 工作集页替换算法

追踪之前$\tau$个的引用

#### 缺页率页面替换算法

可变分配策略：常驻集大小可变。例如：每个进程在刚开始运行的时候，先根据程序大小给它分配一定数目的物理页面。

可以使用缺页率算法（PFF）来动态调整常驻集的大小。

#### 抖动问题（thrashing）

常驻集$\subset$工作集，那么进程将会造成很多的缺页中断，使程序的运行效率变得很低。

平均页缺失时间MTBF=页缺失服务时间PFST。