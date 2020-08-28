# 数学物理方法 1-2 解析函数

## 导数

设$w=f(z)$时区域$G$内的单值函数，如果在$G$内的某点$z$

$$\lim_{\Delta x\rightarrow0}\frac{\Delta w}{\Delta z}=\lim_{\Delta x\rightarrow0}\frac{f(z+\Delta z)-f(z)}{\Delta z}$$

存在，则称函数$f(z)$在$z$点可导，此极限值，记为$f'(z)$，则称为$f(z)$在$z$点的导数。

## 微分

若函数$w=f(z)$在$z$点的改变量

$\Delta w=f(z+\Delta z)-f(z)$可以写成

$$\Delta w=A(z)\Delta z+\rho(\Delta z)$$

其中

$$\lim_{\Delta z\rightarrow0}\frac{\rho(\Delta z)}{\Delta z}=0$$

则称$w=f(z)$在$z$点可微。

可以证明，若函数$w=f(z)$在$z$点可到，则一定在该点可微，反之亦然，并且

$$dw=f'(z)dz,\frac{dw}{dz}=f'(z)$$

### 微分定理

$$\frac{\partial u}{\partial x}=\frac{\partial v}{\partial y},\frac{\partial u}{\partial y}=-\frac{\partial v}{\partial x}$$

可以证明，若$f(z)=u(x,y)+iv(x,y)$的实部$u(x,y)$和虚部$v(x,y)$均可微，且满足Cauchy-Riemann方程，则函数$f(z)$可导

1. 如果函数$f(z)$在$z$点可到，则在$z$点必连续
2. 但是函数在某点连续，并不能退出函数在该点可导
3. **甚至有这样的情况：函数在某区域内处处连续，却处处不可导。**

### 解析函数

> **Important**

**在区域$G$内每一点都可导的函数，则称$f(z)$在$G$内解析**。

解析函数的实部和虚部不是独立的

Cauchy-Riemann方程反映了解析函数的实部与虚部之间的联系

例如，因为

$$dv=\frac{\partial v}{\partial x}dx+\frac{\partial v}{\partial y}dy=-\frac{\partial u}{\partial y}dx+\frac{\partial u}{\partial x}dy$$

是全微分，因此，由解析函数的实部$u(x,y)$，通过积分

$$\int^{(x,y)}(-\frac{\partial u}{\partial y}dx+\frac{\partial u}{\partial x}dy)$$

#### Laplace方程

可以唯一地（可差一个可加常数）确定虚$v(x,y)$。

注意：并不是对于每个连续可微的二元函数$u(x,y)$，都有一个解析函数的实部或虚部与之对应。

**以后将证明，作为解析函数的实部和虚部，$u(x,y)$和$v(x,y)$的任意阶导数存在且连续**。

因此，根据Cauchy-Riemann方程，有

$$\frac{\partial^2u}{\partial x^2}=\frac{\partial}{\partial x}\frac{\partial v}{\partial y}=\frac{\partial^2v}{\partial x\partial y}，\frac{\partial^2u}{\partial x^2}+\frac{\partial^2u}{\partial y^2}=0$$

$$\frac{\partial^2v}{\partial x^2}+\frac{\partial^2v}{\partial y^2}=0$$

所以$u(x,y)$和$v(x,y)$都必须满足二维Laplace方程

$$\frac{\partial^2u}{\partial x^2}+\frac{\partial^2u}{\partial y^2}=0,\frac{\partial^2v}{\partial x^2}+\frac{\partial^2v}{\partial y^2}=0$$

即解析函数的实部和虚部都必须是调和函数。

#### 奇点

如果一个函数
- 在某点$z_0$无定义
- 或者在$z_0$虽有定义但不可导
- 或者在$z_0$虽可导但不解析
则$z_0$称为函数的奇点。