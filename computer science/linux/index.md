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

```
grep
sort
uniq -- delete the duplicated lines in a sorted file
comm
cmp

cp
rm

mkdir
rmdir
cd
pwd -- print working directory
ps -- process snapshot

gzip -- global zip
tar

.tar.gz
.dpkg
.deb
```

### 文本编辑器

```
notepad
visual studio code
记事本
gedit:gnome
kwrite:KDE

vi/vim
nano
```

#### vi

```
:wq write and quit
:x save and quit
:q! quit without save
:q quit and prompt if it changes

h left
j up
k down
l right

Ctrl+f scroll down one screen
Ctrl+b scroll up one screen
Ctrl+u scroll up a half screen
Ctrl+d scroll down a half screen

$ the end of the line
0 the beginning of the line
^ move cursor to the first character of the line
nG move cursor to the beginning of the nth line
gg beginning of the file

:line-number

x delete the character under the cursor
X delete the character before the cursor
dw delete -> word
dd delete the whole line
d0 delete <- start of the line
d$/D delete -> end of the line
```

