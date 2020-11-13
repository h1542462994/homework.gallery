# 自顶向下的语法分析

## 问题

1. 虚假匹配
2. 无限循环（左递归）
3. 二义性

## 增加变量（解决二义性问题）

## 消除左递归（解决无限循环问题）

$$
A\rightarrow A\alpha | \beta \\
A\rightarrow A'|\beta \quad A'\rightarrow\alpha A'|\varepsilon \\
\alpha,\beta\in(V\cup T)
$$

## 提取公因式（解决虚假匹配问题）

$$
A\rightarrow\alpha\beta_1|\alpha\beta_2|\cdots|\alpha\beta_m|\gamma_1|\gamma_2|\cdots|\gamma_n \\
A\rightarrow\alpha A'|\gamma_1|\gamma_2|\cdots|\gamma_n\quad A'\rightarrow\beta_1|\beta_2|\cdots|\beta_m
$$

## 候选式的确定与回溯

### FIRST集和FOLLOW集

FIRST集指一个变量的首字符可选集，可以为$\varepsilon$

SECOND集指一个后随符号可选集，当碰到尾部时，用$\#$标识

$$
\forall \alpha \in (V \cup T)^*，\alpha的首符号集 \\
FIRST(\alpha)=\{a|\alpha\Rightarrow^*a\cdots,\alpha \in T \} \\
FIRST(\alpha)=\varepsilon \quad \alpha\Rightarrow^*\varepsilon
$$

令$\#$为句子的结束符，对于所有非终结符，重复进行以下计算
$$
\# \rightrightarrows FOLLOW(B) \\
A \rightarrow \alpha B \beta \quad FIRST(\beta) - \{\varepsilon\}\rightrightarrows FOLLOW(B) \\
A \rightarrow \alpha B, A\rightarrow \alpha B \beta,\beta\rightarrow^*=\varepsilon \quad FOLLOW(A)\rightrightarrows FOLLOW(B)
$$

### 满足条件

$$
\forall A\rightarrow\alpha|\beta \\
FIRST(\alpha)\cap FIRST(\beta) = \Phi \\
\alpha\Rightarrow^*\varepsilon和\beta\Rightarrow^*\varepsilon仅有一个成立
$$

## LL(1)型文法

### 预测分析器（LL(1)分析器）

预测分析表。

procedure
