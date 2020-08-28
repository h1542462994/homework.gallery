# 数学物理方法 1-6 含参量的积分

## Cauchy型积分

在一条分段光滑的（闭合或不闭合）曲线$C$上**连续** 的函数$\phi(\zeta)$所构成的积分

$$f(z)=\frac{1}{2\pi i}\int_C\frac{\phi(\zeta)}{\zeta-z}d\zeta$$

（称为Cauchy型积分）是曲线外点$z$的解析函数，$f'(z)$可通过积分号下求导而得到

$$f^{(p)}(z)=\frac{p!}{2\pi i}\int_C\frac{\phi(\zeta)}{(\zeta-z)^{p+1}}d\zeta$$

### 例题

> 需要用到lecture1-4的例题的结论

计算积分

$$f(z)=\frac{1}{2\pi i}\oint_{|\zeta|=1}\frac{\zeta^*}{\zeta-z}d\zeta,|z|\neq1$$

因为$|\zeta|=1$，因此有$\zeta\zeta^*=1$

$$f(z)=\frac{1}{2\pi i}\oint_{|\zeta|=1}\frac{1}{\zeta(\zeta-z)}d\zeta$$

当$|z|>1$时，可以用Cauchy积分公式计算

$$f(z)=\frac{1}{2\pi i}\oint_{|\zeta|=1}\frac{1}{\zeta}\frac{1}{\zeta-z}d\zeta=-\frac{1}{z}$$

当$0<|z|<1$时，

$$f(z)=\frac{1}{2\pi i}\oint_{|\zeta|=1}\frac{1}{z}[\frac{1}{\zeta-z}-\frac{1}{\zeta}]d\zeta=\frac{1}{z}[1-1]=0$$

当$|z|=0$时，

$$f(z)=\frac{1}{2\pi i}\oint_{|\zeta|=1}\frac{1}{\zeta^2}d\zeta=0$$

### 含参量积分的解析性

设

1. $f(t,z)$时$t$和$z$的连续函数，$t\in[a,b],z\in\overline G$
2. $\forall t\in[a,b]，f(t,z)$是$\overline G$上的单值解析函数

$$则F(z)=\int_a^bf(t,z)dt在G内解析，且$$

$$F'(z)=\int_a^b\frac{\partial f(t,z)}{\partial z}dt$$

证明：

$$F(z)=\int_a^bf(t,z)dt=\int_a^b[\frac{1}{2\pi i}\oint_C\frac{f(t,\zeta)}{\zeta-z}d\zeta]dt$$

$$=\frac{1}{2\pi i}\oint_C\frac{1}{\zeta-z}[\int_a^bf(t,\zeta)dt]d\zeta$$

可以得出$F(z)$是$z\in G$的解析函数，并且

$$F'(z)=\frac{1}{2\pi i}\oint_C\frac{1}{(\zeta-z)^2}[\int_a^bf(t,\zeta)dt]d\zeta$$

$$=\int_a^b[\frac{1}{2\pi i}\oint_C\frac{f(t,\zeta)}{(\zeta-z)^2}d\zeta]dt$$

$$=\int_a^b\frac{\partial f(t,z)}{\partial t}dt$$