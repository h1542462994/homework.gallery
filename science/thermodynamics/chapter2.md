# 热力学 第二章 平衡态系统的统计分布律

## 第一节 无序系统

在完全无序这一假设下得到的关于微观无序系统的一些物理规律，就是平衡态系统的统计规律。

统计规律。微观上千变万化，宏观上有一定数值和规律的现象为统计规律

### 例一、醉鬼问题

> 不为0是因为两个变量并不是独立变量

一个最初站在一个路灯下醉鬼忽然想起来走一走，我们想知道他走了M步后离路灯的距离

$$R^2=(\sum_{i=1}^MX_i)^2+(\sum_{i=1}^MY_i)^2\quad X_i^2+Y_i^2=1$$

$$R^2=\sum_{i=1}^M(X_i^2+Y_i^2)=M\quad R=\sqrt{M}$$

统计性质：计算只能给出醉鬼的平均距离，不能计算出分布

各态历经：如果有一群醉鬼同时开始游动，在$\sqrt{M}$位置上找到醉鬼的数目最多。它与一个醉鬼重复多次游走的结果一致

统计误差：只用平均值不能反映醉鬼的行为。必须在计算中引入计算的不确定性

统计误差的规律：
$$\frac{\delta R}{R}=1/\sqrt{R}$$

### 例二、布朗运动

> 得到布朗运动的扩散速率与平均动能成正比，也就是与温度成正比。

基本图像：粒子受无序驱动力驱动在流体中运动

牛顿定律：

$$m\frac{d^2\overline{r}}{dt^2}=-6\pi a\eta\frac{d\overline{r}}{dt}+\overline{F}(t)$$

$$m\frac{d^2s}{dt^2}=-6\pi \eta\frac{ds}{dt}+F_s(t)$$

条件：$$\overline{F_s(t)}=0,\frac12m\overline{(\frac{ds}{dt})^2}=\frac12m\overline{(\frac{ds_m}{dt})^2}=\frac12k_BT$$

$$\frac{d^2(s^2)}{2dt^2}=\frac{d}{2dt}(\frac{d(s^2)}{dt})=\frac{d}{dt}(s\frac{ds}{dt})=(\frac{ds}{dt})^2+s\frac{d^2s}{dt^2}$$

$$\frac{m}{2}\frac{d^2(\overline{s^2})}{dt^2}-k_BT=-2\pi a\eta\frac{d(\overline{s^2})}{dt}$$

令

$$Z(t)=\frac{d(\overline{s^2})}{dt}\quad \frac{mdZ}{2dt}-k_BT=-3\pi a\eta Z$$

$$Z(t)=\frac{k_BT}{3\pi a\eta}(1-e^{-\frac{6\pi a\eta}{m}t})\approx\frac{k_BT}{3\pi a\eta}$$

$$\overline{s^2}=\frac{k_BT}{2\pi a\eta}t=2Dt，其中D=\frac{k_BT}{6\pi a\eta}为Elnstein扩散系数$$

## 第二节 概率论简介

### 一、事件及其概率

随机事件：随机实验中，对实验可能出现的事件称为事件

概率：在一定条件下，一系列可能发生的事件组合中，发生某一事件的机会和可能性

互补相容事件：$$P(A_i+A_j)=P(A_i)+P(A_j)$$

独立事件：$$P(A_iA_j)=P(A_i)P(A_j)$$

独立相容事件：

$$P(A_i+A_j)=P(A_i)+P(A_j)-P(A_i)P(A_j)$$

例一：生日问题

计算n个朋友同一天生日的概率

24个朋友中至少有两个同生日的概率为54%

### 二、随机变量与分布函数

#### 分立随机变量

随机变量的特征数值

平均值

$$\overline{x}=\sum_iP(x_i)x_i$$

n次矩

$$\overline{\Delta x^n}=\overline{(x-\overline{x})^n}$$

二次矩是随机变量偏离平均值的度量，又叫色散，其平方根为均方差

有意义的统计系统必须要求各次矩有限，各次矩无限的系统是复杂系统

#### 连续随机变量

概率密度函数

$$f(x)=\lim_{\Delta x\rightarrow0}\frac{P(x\rightarrow x+\Delta x)}{\Delta x}=\frac{dP}{dx}$$

均方差：

$$\sigma=\sqrt{\overline{(x-\overline{x})^2}}=\sqrt{\overline{x^2}-\overline{x}^2}$$

$$简单系统：\lim_{N\rightarrow\infty}\sigma=0，复杂系统：\lim_{N\rightarrow\infty}\sigma=\infty$$

#### 一些常见的分布

1. 二项分布

$$P(n_1)=C_{N}^{n_1}p^{n1}q^{N-n_1}$$

性质：

$$平均值=pN，涨落=Npq，相对涨落=\frac{1}{\sqrt{N}}(\frac{q}{p})^{1/2}$$