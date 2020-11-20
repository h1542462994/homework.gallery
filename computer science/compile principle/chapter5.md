# 自底向上的语法分析

## 短语

$$S\rightarrow\alpha A\beta,A\rightarrow^+\gamma,\gamma是A的短语$$

最左规约

## 问题

1. 移进规约冲突
   
    解决方法：算符优先级分析法，状态法

### 算符的优先关系

$$
a\equiv b \Leftrightarrow A\rightarrow\cdots ab\cdots\in P 或者 A\rightarrow\cdots aBb\cdots\in P \\
a\nless b \Leftrightarrow A\rightarrow\cdots aB\cdots \in P且(B\Rightarrow^+b\cdots或者 B\Rightarrow^+Cb\cdots) \\
a\ngtr b \Leftrightarrow A\rightarrow \cdots Ab\cdots\in P且(A\Rightarrow^+\cdots b或者A\Rightarrow^+\cdots bC)
$$
    
#### 求FIRSTOP和LASTOP

对于$OG G=(V,T,P,S)$

$$FIRSTOP(A)=\{b|A\Rightarrow^+b\cdots或者A\Rightarrow^+Cb\cdots\} \\
LASTOP(A)=\{b|A\Rightarrow^+\cdots b或者A\Rightarrow^+\cdots bC\}
$$

#### 素短语(Prime Phrase)

## LR分析法

1. L 对输入进行从左到右的扫描
2. R right，reduce（规约），最右推导
3. k 提前读入k个符号

collection.reduce(state, action(state))

### LR分析器

输入缓冲区
状态、符号栈
分析表：动作表、转移表

当句柄在栈顶形成时，进行归结。否则，进行移进的操作。

### 项目

移进项目、待约项目、归约项目

后继项目

项目的定义：
$$
A\rightarrow\alpha . \beta
$$


核心项目、项目闭包

LR(0)、SLR(1)、LR(1)

LR(0)+FOLLOW=SLR

LR(0)+ANY FOLLOW=LR(1)