# 数学物理方法 第一章复习

## 知识点

### 复数的定义和表示

#### 复数的定义

- 有序实数对+运算法则

#### 特殊的复数

$i$，$0$，$1$，$\infty$

- 特别地，$\infty$是一个复数，其模长为$\infty$，辐角不定
- 复数$0$辐角不定

#### 复数的表示

- 笛卡尔坐标系 $z=x+iy$
- 极坐标系 $z=r(\cos\theta+i\sin\theta)$，$r=|z|，\theta=\arg z$。**复数函数的多值性只要来自于辐角的不定性**
    - *复数的乘法和除法在极坐标系有非常简单的表示方法*
- 指数函数$z=re^{i\theta}$，来源于欧拉函数
    - $\alpha=r_1e^{i\theta_1}，\beta=r_2e^{i\theta_2}，\alpha\beta=r_1r_2e^{i(\theta_1+\theta_2)}$
- 复数球面（不要求掌握）

#### 复数的运算

#### 聚点和极限

- 聚点不等于极限
- *有界序列至少存在一个聚点*
- *无界序列至少有一个$\infty$的聚点*
- 极限即聚点唯一

### 区域

- 点集的内点
- 单连通区域，复连通区域
- 点集的边界

### 复变函数

- $w=f(z)=u(x,y)+v(x,y)i$，其中$w$可以是多值的，分为单值函数和多值函数。
- 若复变函数在一个区域内连续，则必定存在可达的上下界，而且一致连续。
- 复数的积分只能在单值分支中进行，复数可以使用Riemann面来表示多个分支的情况
- 复变函数支点的定义

### 初等函数的复变函数

- 指数函数（周期为$2\pi i$）
- 三角函数（周期为$2\pi$）
- 幂函数
- 对数函数
- 反三角函数

### 解析函数

- 解析函数指在一个闭区域$\overline G$内处处可微的函数。
- 解析函数满足C-R（柯西-黎曼）方程，即

$$\frac{\partial u}{\partial x}=\frac{\partial v}{\partial y},\frac{\partial u}{\partial y}=-\frac{\partial v}{\partial x}$$
- 解析函数的**实函数和虚函数存在密切联系**。
- 解析函数的任意阶导数均存在（将在之后证明）
- 单连通区域和复连通区域的柯西定理
- 解析函数在解析区域内的积分与路径无关（需要用到Green公式）

$$\oint_CPdx+Qdy=\iint_S(\frac{\partial Q}{\partial x}-\frac{\partial P}{\partial y})dxdy$$

### 柯西积分公式

- 小圆弧引理

若函数$f(z)$在$z=a$点的邻域内**连续**，且当$\theta_1\leq\arg(z-a)\leq\theta_2$，$|z-a|\rightarrow0，(z-a)f(z)\rightrightarrows k$，则

$$\lim_{\delta\rightarrow0}\int_{C_\delta}f(z)dz=ik(\theta_2-\theta_1)$$

- 大圆弧引理

设$f(z)$在$\infty$点的邻域内**连续**，且当$\theta_1\leq\arg z\leq\theta_2,z\rightarrow\infty$时（此时$\infty$不是奇点），$zf(z)\rightrightarrows K$，则

$$\lim_{R\rightarrow\infty}\int_{C_R}f(z)dz=iK(\theta_2-\theta_1)$$

- 有界区域的Cauchy积分公式

设$f(z)$是区域$\overline G$中的单值解析函数，$\overline G$的边界$C$是分段光滑曲线，$a$为$G$内一点，则

$$f(a)=\frac{1}{2\pi i}\oint_C\frac{f(z)}{z-a}dz$$

其中积分路线沿$C$的正向

- 无界区域的Cauchy积分公式

对于无界区域，需要假设$f(z)$在简单闭合围道$C$上及$C$外（包括无穷远点）单值解析

其中$a$为$C$外一点，积分路线$C$的走向是顺时针方向，即绕无穷远点的正向

$$\frac{1}{2\pi i}\oint_{C}\frac{f(z)}{z-a}dz=f(a)-f(\infty)$$

### Cauchy积分公式的重要推论

#### 解析函数的高阶导数公式

若$f(z)$在$\overline G$中解析，则在$G$内$f(z)$的任何阶导数$f^{(n)}(z)$均存在，且

$$f^{(n)}(z)=\frac{n!}{2\pi i}\oint_C\frac{f(\zeta)}{(\zeta-z)^{n+1}}d\zeta$$

其中$C$是$\overline G$的正向边界，$z\in G$

### Cauchy不等式

$$|f^{(n)}(z)|\leq\frac{n!}{2\pi}\frac{Ml}{d^{n+1}}$$

- $l$是边界$C$的周长

- $d$是$z$到边界的最短距离

特别是$C:|\zeta-z|=R$，有

$$|f^{(n)}(z)|\leq\frac{n!M}{R^n}$$

### 最大模定理

若$f(z)$是闭区域$\overline G$中的解析函数，则模$|f(z)|$的最大值在$\overline G$的边界上

#### 证明

根据Cauchy不等式

$$|f^{(n)}(z)|\leq\frac{n!}{2\pi}\frac{Ml}{d^{n+1}}$$

$$|f(z)|^m\leq\frac{M^ml}{2\pi d}$$

$$|f(z)|\leq M(\frac{l}{2\pi d})^{1/m}$$

$$令m\rightarrow\infty\rightrightarrows|f(z)|\leq M$$

### Lionville定理

如果$f(z)$在全平面上解析（无穷远点可能除外），且当$z\rightarrow\infty$时$|f(z)|$有界，则$f(z)$是一个常数

根据Cauchy不等式

$$|f^{(n)}(z)|\leq\frac{n!M}{R^n}$$

$$|f'(z)|\leq\frac{M_R}{R}$$

令$R\rightarrow\infty\rightrightarrows f'(z)=0$

因此$f'(\infty)=C$

### 技巧

- 极限相等使用无穷小来证明，并使用$\varepsilon-\delta$语言来说明。
- 特别需要考虑复数宗量的辐角的多值性
- 进行环积分时必须考虑奇点的影响
- 