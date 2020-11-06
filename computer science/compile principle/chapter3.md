# 自定向下的语法分析

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