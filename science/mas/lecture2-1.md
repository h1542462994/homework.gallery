# 数学物理方法 2-1 复数级数

## 复数级数

$$u_0+u_1+u_2+\cdots+u_n+\cdots=\sum_{n=0}^{\infty}u_n$$

## 无穷级数的收敛和发散

如果级数的部分和

$$S_n=u_0+u_1+u_2+\cdots+u_n$$

所构成的序列$\{S_n\}$收敛，则称级数$\sum u_n$收敛，序列$\{S_n\}$的和$S=lim_{n\rightarrow\infty}\{S_n\}$称为级数的和。

令$u_n=\alpha_n+i\beta_n$，则部分和序列

复数级数$\sum u_n$的收敛性完全等价于实数级数$\sum \alpha_n$和$\sum \beta_n$的收敛性

一个复数级数$\sum u_n$完全等价于两个实数级数$\sum \alpha_n$和$\sum \beta_n$

### 级数收敛的Cauchy充要条件

任意给定$\varepsilon\gt 0$，$\exists$正整数$n$，$\forall$正整数$p$，有$|u_{n+1}+u_{n+2}+\cdots+u_{n+p}|\lt\varepsilon$

### 收敛级数的必要条件

$$\lim_{n\rightarrow\infty}u_n=0$$

### 收敛级数的基本性质

在不改变求和次序的前提下，可将收敛级数并项$u_1+u_2+u_3+u_4+\cdots=(u_1+u_2)+(u_3+u_4)+\cdots$

## 绝对收敛级数

若级数$$\sum_{n=0}^{\infty}|u_n|$$

收敛，则称级数$$\sum_{n=0}^{\infty}u_n$$

绝对收敛

一个绝对收敛级数一定是收敛级数，但是，一个收敛级数不一定是绝对收敛级数。