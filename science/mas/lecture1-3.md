# 数学物理方法 1-3 初等函数

## 幂函数

- 当$n=0,1,2,\cdots$时，$z^n$在全平面解析，且当$n=1,2,\cdots$时，$z=\infty$是奇点。

- 当$n=-1,-2,\cdots$时，$z^n$除$z=0$外处处解析，在$z=\infty$也解析。

$$(z^n)'=nz^{n-1}$$

还可以进一步定义(n次)多项式和有理函数。

## 指数函数

$$e^z=e^{x+iy}=e^xe^{iy}=e^x(\cos y+i\sin y)$$

$$e^{2\pi i}=1$$

1. 复指数函数是周期函数，周期为$2\pi i$

$$e^{z+2\pi i}=e^{x+i(y+2\pi)}=e^{x+iy}=e^{z}$$

2. $e^z$在无穷远点无定义

$$e^{iz}=e^{i(x+iy)}=e^{-y}e^{ix}=e^{-y}(\cos x+i\sin x)=\cos z+i\sin z$$

$$e^{-iz}=e^{-i(x+iy)}=e^y(\cos x-i\sin x)=\cos z-i\sin z$$

## 三角函数

通过欧拉公式定义：

$$\sin z=\frac{1}{2i}[e^{iz}-e^{-iz}]$$

$$\cos z=\frac{1}{2}[e^{iz}+e^{-iz}]$$

1. $\sin z,\cos z$在全平面解析

$$(\sin z)'=\cos z,(\cos z)'=-\sin z$$

2. $z=\infty$是它们的唯一奇点

3. $\sin z$和$\cos z$都是周期函数，周期为$2\pi$

4. $\sin z$和$\cos z$的模可以大于

5. 根据三角函数，实三角函数的各种恒等式依然在复数范围上成立

## 双曲函数

$\sinh z$和$\cosh z$也是通过复指数函数定义的

$$\sinh z=\frac{1}{2}[e^z-e^{-z}]\quad
\cosh z=\frac{1}{2}[e^z+e^{-z}]$$

$$\sin z=\frac{e^{iz}-e^{-iz}}{2i}=\frac{1}{i}\sinh iz=-i\sinh iz$$

$$\cosh z=-i\cos iz$$

双曲函数的周期是$2\pi i$

## 根式函数

### 多值函数

设有复数平面上的一个区域$G$，如果对于$G$内的每一个$z$值，有多个复数值$w$与之对应，则$w=f(z)$为$z$的多值函数

### 定义

给定一个自变量值$z$，凡是满足等式$w^2=z$的$w$值，就是根式函数$\sqrt{z}$的函数值。

### 根式函数$w=\sqrt{z-a}$的多值性

采用极坐标表达式$w=\rho e^{i\phi},z-a=re ^{i\theta}$

得到

$$\rho=\sqrt{r},\phi=\frac{\theta}{2}+k\pi$$

$$z_1=\sqrt{r}e^{i\theta /2},z_2=\sqrt{r}e^{i(\theta/2+\pi)}=-\sqrt{r}e^{i\theta/2}$$

1. 多值性来源于辐角的多值性
2. 准确说，多值性来源于宗量$z-a$辐角的多值性
3. 多值性的表现则是函数$w$的多值性

为了确定起见，以后就把函数$w=\sqrt{z-a}$明确表示成

$$|w|=\sqrt{|z-a|},\arg w=\frac{1}{2}\arg{(z-a)}$$

### 根式函数的支点

1. 闭合曲线内不包含$a$点，$z$沿闭合曲线变化一周回到原处，$\arg(z-a)$也还原，因此对应的函数值不变
2. 反之，对应的函数值变

则称$a$是多值函数$\sqrt{z-a}$的支点

$$w=r^{1/2}(\cos \frac{\theta}{2}+i\sin \frac{\theta}{2})$$

比较简单的方法是规定宗量$z-a$的辐角变化范围

当宗量$z-a$的辐角限制在某个周期内时，$w=\sqrt{z-a}$的辐角也就唯一地确定，因而$w$值也就唯一地确定。

### 根式函数$w=\sqrt{z-a}$的单值化

例如，规定$0\le\arg(z-a)<2\pi$。

只要适当规定宗量的辐角变化范围，就可以将多个函数单值化

辐角变化的各个周期，给出多值函数的各个单值分支

这种规定可以用几何方法形象化地表现出来：在$z$平面上平行于实轴从$z=a$点向右作一割线，一直延续到$\infty$点

### 根式函数的Riemann面

规定起点和起点的值，并按照一个规定的方向进行曲线运动，函数值连续变化。

**并将不同的函数变化的复数平面合并在一起，就构成了Riemann面。**

## 对数函数

1. 多值函数及其应用在解析函数理论中占有重要地位

### 定义

$w=\ln z$的定义是$e^w=z$，即给定自变量$z$，凡是满足$e^w=z$的所有$w$值均称为对数$w=\ln z$的函数值

令$w=u+iv,z=re^{i\theta}$，就得到$e^u\cdot e^{iv}=re^{i\theta}$，于是$u=\ln r=\ln{|z|},v=\theta+2n\pi$

以后就把对数函数$w=\ln z$明确表示为

$$w=\ln z=\ln |z|+i(\theta+2n\pi)=ln |z|+i\arg z$$

给定一个$z$值，有无穷多个$w$值。即$w=\ln z$有无穷多个单值分支

### 多数函数的单值化

支点是$z=0和\infty$

每个单值分支内，
$$\frac{d}{dz}(\ln z)=\frac{1}{z}$$

## 其他多值函数

反三角函数和一般的幂函数

$$\arcsin z=\frac{1}{i}\ln(iz+\sqrt{1-z^2})$$

$$\arccos z=\frac{1}{i}\ln(z+\sqrt{z^2-1})$$

$$\arctan z=\frac{1}{2i}\ln\frac{1+iz}{1-iz}$$

$$z^\alpha=e^{\alpha\ln z}(\alpha为任意复数)$$
