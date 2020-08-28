# 数学物理方法 1-4 复变积分

## 定义

设$C$是复平面上的曲线，函数$f(z)$在$C$上有定义，将曲线$C$任意分割为$n$段，分点为$z_0=A,z_1,z_2,\cdots,z_n=B,\zeta_k$是$z_{k-1}\rightarrow z_k$段上的任意一点，作和数

$$\sum_{k=1}^nf(\zeta_k)(z_k-z_{k-1})\equiv\sum_{k=1}^nf(\zeta_k)\Delta z_k$$

若当$n\rightarrow\infty$时，且$\max_{i}|z_k-z_{k-1}|\rightarrow0$，极限存在，则称复变积分存在。

一个复变积分实际上是两个实变线积分的有序组合

$$\int_Cf(z)dz=\int_C(u+iv)(dx+idy)=\int_C(udx-vdy)+i\int_C(vdx+udy)$$


因此，如果$C$是分段光滑曲线，$f(z)$是$C$上的连函数，则复变积分一定存在

## 复变积分的基本性质

### 积分函数可加性

### 积分路径可加性

### 曲线逆向

$$\int_{C^-}f(z)dz=-\int_Cf(z)dz$$

### 提取常数

$$\int_Caf(z)dz=a\int_Cf(z)dz$$

### 积分不等式

$$|\int_Cf(z)dz|\le\int_C|f(z)||dz|$$

### 有界性

$$|\int_Cf(z)dz|\leq Ml$$，其中$M$为$|f(z)|$在$C$上的上界，$l$为$C$的长度

复变积分的数值依赖于

1. 被积函数
2. 端点位置
3. 积分路径

## 柯西定理

单连通区域：在区域中作任何简单闭合围道，围道内的点都属于该区域

复连通区域，或称多连通区域

### 单连通区域的Cauchy定理

如果函数$f(z)$在单连通区域$\overline G$中解析，则沿$\overline G$中任何一个分段光滑的闭合围道$C$有

$$\oint_Cf(z)dz=0$$

这里的$C$也可以是$\overline G$的边界。

为简单起见，下面在更强的条件下证明这个定理

附加的条件是$f'(z)$在$\overline G$中连续

#### 证明

在上述附加条件下可以应用Green公式

$$\oint_C[P(x,y)dx+Q(x,y)dy]=\iint_S(\frac{\partial Q}{\partial x}-\frac{\partial P}{\partial y})dxdy$$

于是

$$\oint_Cf(z)dz=\oint_C(udx-vdy)+i\oint_C(vdx+udy)$$

根据

$$\oint_C(udx-vdy)=-\iint_S(\frac{\partial v}{\partial x}+\frac{\partial u}{\partial y})dxdy$$
$$\oint_C(vdx+udy)=\iint_S(\frac{\partial u}{\partial x}-\frac{\partial v}{\partial y})dxdy$$

由于其满足C-R条件，因此两个曲线积分都为0。

#### 说明

1. 这里所说的单连通区域，只能是一个有界区域，不能是(绕$\infty$点的)无界区域
2. 即使$f(z)$在$\infty$点解析，它绕$\infty$点一周的积分也可以并不为0

3. **Cauchy定理从一个侧面反映了解析函数的一个基本特性：解析函数在它的解析区域内，各点的函数值是密切相关的**

    - Cauchy-Riemann方式是这种关联性的微分形式
    - Cauchy定理则是它的积分形式

#### 推论

若$f(z)$在单连通区域$\overline G$中解析，则复变积分$\int_Cf(z)dz$与路径无关。

### 不定积分

既然在单连通区域中解析函数的积分与路径无关，因此，如果固定起点$z_0$，而令终点$z$为变点，则作为积分上限的函数

$$\int_{z_0}^zf(z)dz=F(z)$$

是单连通区域$G$内的单值函数，称为$f(z)$的不定积分

#### 定理（不定积分的解析性）

如果函数$f(z)$在单连通区域$G$内解析，则$F(z)=\int_{z_0}^z$也在G内解析，且

$$F'(z)=\frac{d}{dz}\int_{z_0}^zf(z)dz=f(z)$$

证明

只要直接求出$F(z)$的导数即可，设$z$是$G$内一点，$z+\Delta z$是它的邻点

$$F(z)=\int_{z_0}^zf(\zeta)d\zeta$$

$$F(z+\Delta z)=\int_{z_0}^{z+\Delta z}f(\zeta)d\zeta$$

$$\frac{\Delta F}{\Delta z}=\frac{F(z+\Delta z)-F(z)}{\Delta z}=\frac{1}{\Delta z}\int_{z}^{z+\Delta z}f(\zeta)d\zeta$$

$$|\frac{\Delta F}{\Delta z}-f(z)|=|\frac{1}{\Delta z}\int_{z}^{z+\Delta z}f(\zeta)d\zeta-f(z)|$$

$$=|\frac{1}{\Delta z}\int_{z}^{z+\Delta z}[f(\zeta)-f(z)]d\zeta|\leq\frac{1}{|\Delta z|}\int_{z}^{z+\Delta z}|f(\zeta)-f(z)||d\zeta|$$

由于$f(z)$连续，故对于任给的$\varepsilon>0$，存在$\delta>0$，使当$|\zeta-z|<\delta$时，$|f(\zeta)-f(z)|<\varepsilon$，所以

$$|\frac{\Delta F}{\Delta z}-f(z)|\leq\frac{1}{\Delta z}\cdot\varepsilon\cdot|\Delta z|=\varepsilon$$

因此

$$F'(z)=\lim_{\Delta z\rightarrow0}\frac{\Delta F}{\Delta z}=f(z)$$

### 原函数

定义

若$\Phi'(z)=f(z)$，则称$\Phi(z)$为$f(z)$的原函数

- $f(z)$的不定积分就是$f(z)$的一个原函数
- 对于给定的$f(z)$来说，原函数不唯一
- 任意两个原函数之间只只相差一个常数
- 设$\Phi(z)$为$f(z)$的原函数，则$f(z)$的不定积分

$$F(z)=\int_{z_0}^zf(z)dz=\Phi(z)+C=\Phi(z)-\Phi(z_0)=\Phi(z)|_{z_0}^z$$

### 例题

计算积分$\int_a^bz^ndz$，其中$n$为正整数

### 复连通区域的Cauchy定理

如果$f(z)$是**复连通区域**$\overline G$中的**单值解析函数**，则

$$\oint_{C_0}f(z)dz=\sum_{i=1}^n\oint_{C_i}f(z)dz$$

即

$$\oint_{C_0}f(z)dz-\sum_{i=1}^n\oint_{C^{i-}}f(z)dz=0$$

其中$C_0,C_1,\cdots,C_n$是构成复连通区域$\overline G$的边界的各个分段光滑曲线，$C_1,C_2,\cdots,C_n$都包含在$C_0$的内部，而且所有的积分路径走向相同。

### 例题

**计算$\oint_{C}z^ndz$值，$n$为整数，$C$为逆时针方向**

若$C$内含有$z=0$，则按复连通区域Cauchy定理

$$\oint_Cz^ndz=\oint_{|z|=1}z^ndz=\int_0^{2\pi}(e^{i\theta})^ne^{i\theta}id\theta$$
$$=\int_0^{2\pi}e^{i(n+1)\theta}id\theta=2\pi i(n=-1且区域包含|z|=0);0$$

