# 语法分析

## 消除左递归

$$
A\rightarrow A\alpha | \beta \\
A\rightarrow A'|\beta \quad A'\rightarrow\alpha A'|\varepsilon \\
\alpha,\beta\in(V\cup T)
$$