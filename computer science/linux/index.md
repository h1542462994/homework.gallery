# Linux系统

## 介绍

### Shell and Terminal

- Interactive
- Batch

### 查看使用的shell类型

```sh
echo $SHELL
```

### 多shell类型

```sh
cat /etc/shells
```

### 登出

```sh
exit
logout
[Ctrl+D]
```

###  截断

```sh
[\+Enter]
```

### 其他

```sh
whoami  # 显示用户名
echo "Hello world"  # 显示空格
read name  # 读取变量
echo "$name It is a test"  # 变量替换
echo '$name\"'  # 原封不动

echo -e "OK! \n"
echo -e "OK! \c"
echo `date`
echo "It is a test " > myfile

cal 10 2020  # 输出日历
cal 2020

passwd  # 修改密码

clear

sudo date --set="20201009 8:00"
sudo su

adduser
```

### File System

```sh
cat [concatenate]  # 
more  # 支持向下翻页
less  # 支持上下滚动翻页
head  # 头部
tail  # 尾部

touch
```

