# 数学物理方法 1-5 柯西积分公式

## 两个有用的引理

引理：适用于半径为无穷小的圆弧

若函数$f(z)$在$z=a$点的邻域内**连续**，且当$\theta_1\leq\arg(z-a)\leq\theta_2$，$|z-a|\rightarrow0，(z-a)f(z)\rightrightarrows k$，则

$$\lim_{\delta\rightarrow0}\int_{C_\delta}f(z)dz=ik(\theta_2-\theta_1)$$

因为

$$\int_{C_\delta}\frac{dz}{z-a}=i\int_{\theta_1}^{\theta_2}\frac{1}{r}\cdot r\cdot d\theta=i(\theta_2-\theta_1)$$

引理：适用于半径为无穷大的圆弧

设$f(z)$在$\infty$点的邻域内**连续**，且当$\theta_1\leq\arg z\leq\theta_2,z\rightarrow\infty$时（此时$\infty$不是奇点），$zf(z)\rightrightarrows K$，则

$$\lim_{R\rightarrow\infty}\int_{C_R}f(z)dz=iK(\theta_2-\theta_1)$$

其中$C_R$是以$z=0$为圆心，$R$为半径，夹角为$\theta_2-\theta_1$的圆弧

### 有界区域的Cauchy积分公式

设$f(z)$是区域$\overline G$中的单值解析函数，$\overline G$的边界$C$是分段光滑曲线，$a$为$G$内一点，则

$$f(a)=\frac{1}{2\pi i}\oint_C\frac{f(z)}{z-a}dz$$

其中积分路线沿$C$的正向

在$G$内作圆$|z-a|<r$（保持圆周$|z-a|=r$在$G$内），则根据复连通区域的Cauchy定理，有

$$\oint_C\frac{f(z)}{z-a}dz=\lim_{r\rightarrow0}\oint_{|z-a|=r}\frac{f(z)}{z-a}dz$$

又由于

$$\lim_{z\rightarrow a}(z-a)\frac{f(z)}{z-a}=f(a)$$

因此

$$\lim_{r\rightarrow0}\oint_{|z-a|=r}\frac{f(z)}{z-a}dz=2\pi if(a)$$

#### 特殊形式

取$C$为以$a$为圆心、$R$为半径的圆周，$z-a=Re^{i\theta}$

$$dz=Re^{i\theta}id\theta$$

$$f(a)=\frac{1}{2\pi}\int_{0}^{2\pi}f(a+Re^{i\theta})d\theta$$

#### 均值定理

解析函数$f(z)$在解析区域$G$内任意一点$a$的函数值$f(a)$，等于（完全位于$G$内的）以$a$为圆心的任一圆周上的函数值的平均

### 无界区域的Cauchy积分公式

对于无界区域，需要假设$f(z)$在简单闭合围道$C$上及$C$外（包括无穷远点）单值解析

其中$a$为$C$外一点，积分路线$C$的走向是顺时针方向，即绕无穷远点的正向

$$\frac{1}{2\pi i}\oint_{C}\frac{f(z)}{z-a}dz=f(a)-\lim_{R\rightarrow\infty}[\frac{1}{2\pi i}\oint_{C_R}\frac{f(z)}{z-a}dz]$$

又由于

$$\lim_{R\rightarrow\infty}[\frac{1}{2\pi i}\oint_{C_R}\frac{f(z)}{z-a}dz]=K$$

其中$$K=\lim_{z\rightarrow\infty}z\cdot\frac{f(z)}{z-a}=f(\infty)$$

最后

$$\frac{1}{2\pi i}\oint_{C}\frac{f(z)}{z-a}dz=f(a)-f(\infty)$$

特别是当

$$K=\lim_{z\rightarrow\infty}z\cdot\frac{f(z)}{z-a}=0$$

时

满足无界区域的Cauchy积分公式。

### Cauchy积分公式的重要推论

#### 解析函数的高阶导数公式

若$f(z)$在$\overline G$中解析，则在$G$内$f(z)$的任何阶导数$f^{(n)}(z)$均存在，且

$$f^{(n)}(z)=\frac{n!}{2\pi i}\oint_C\frac{f(\zeta)}{(\zeta-z)^{n+1}}d\zeta$$

其中$C$是$\overline G$的正向边界，$z\in G$

$$f'(z)=\lim_{h\rightarrow0}\frac{f(z+h)-f(z)}{h}$$

$$=(使用围道积分)\lim_{h\rightarrow0}\frac{1}{2\pi i}\frac{1}{h}\oint_{C}[\frac{f(\zeta)}{\zeta-z-h}-\frac{f(\zeta)}{\zeta-z}]d\zeta$$

$$\lim_{h\rightarrow0}\frac{1}{2\pi i}\oint_C\frac{f(\zeta)}{(\zeta-z-h)(\zeta-z)}d\zeta$$

$$=?\quad\frac{1}{2\pi i}\oint_C\frac{f(\zeta)}{(\zeta-z)^2}d\zeta$$

$$f'(z)=\frac{df(z)}{dz}=\frac{d}{dz}[2\pi i\oint_{C}\frac{f(\zeta)}{\zeta-z}d\zeta]$$

$$=?\quad\frac{1}{2\pi i}\oint_C\frac{d}{dz}[\frac{f(\zeta)}{\zeta-z}]d\zeta$$

$$=!\quad \frac{1}{2\pi i}\oint_C\frac{f(\zeta)}{(\zeta-z)^2}d\zeta$$

之后使用数学归纳法就可以证明高阶导数公式。

- 这个结果说明，一个复变函数，只要在一个区域中一阶导数处处存在（因此是区域内的解析函数），则它的任何阶导数都存在，并且都是这个区域内的解析函数
- 在实变函数中并非如此，我们并不由$f'(x)$的存在推断出$f''(x)$的存在。

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