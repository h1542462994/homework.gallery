# pintos 安装笔记

## 安装环境

ubuntu-18.04

```json
{
    "guid": "{c6eaf9f4-32a7-5fdc-b5cf-066e8a4b1e40}",
    "hidden": false,
    "name": "Ubuntu-18.04",
    "source": "Windows.Terminal.Wsl",
    "startingDirectory": "//wsl$/Ubuntu-18.04/home/cht"
}
```

### 更换软件源

软件源配置目录：/etc/apt/sources.list

项目地址：https://github.com/Berkeley-CS162/group0

```
cd /etc/apt
sudo mv sources.list sources.list.backup
sudo nano sources.list
```

然后将以下内容粘贴进去

```
deb https://mirrors.ustc.edu.cn/ubuntu/ bionic main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse
```

### 安装qemu


```
sudo apt-get update
# 安装虚拟机
sudo apt-get install qemu
```

### 下载项目
```
cd ~
mkdir os
cd os
# 下载项目文件
git clone https://github.com/Berkeley-CS162/group0.git
```

### 使用vscode连接

vs-code 安装 remote-wsl插件
连接，打开group0目录

### 设置path

```
nano ~/.bashrc
```

在文件末尾加入这句话

```
export PATH=$PATH:/usr/bin:/home/cht/os/group0/pintos/src/utils
```

### 安装必要工具

```

# 编译工具
sudo apt-get install gcc
sudo apt-get install make
```

### 进行除此编译并测试

```
cd pintos/src/threads
# 将Make.vars中
SIMULATOR = --bochs 改成 --qemu
make
make check
```

### 第1次（未修改代码测试结果）

```
cht@cht-Surface:~/os/group0/pintos/src/threads$ make check
cd build && make check
make[1]: Entering directory '/home/cht/os/group0/pintos/src/threads/build'
pintos -v -k -T 480 --qemu  -- -q -mlfqs run mlfqs-fair-2 < /dev/null 2> tests/threads/mlfqs-fair-2.errors > tests/threads/mlfqs-fair-2.output
perl -I../.. ../../tests/threads/mlfqs-fair-2.ck tests/threads/mlfqs-fair-2 tests/threads/mlfqs-fair-2.result
pass tests/threads/mlfqs-fair-2
pintos -v -k -T 480 --qemu  -- -q -mlfqs run mlfqs-fair-20 < /dev/null 2> tests/threads/mlfqs-fair-20.errors > tests/threads/mlfqs-fair-20.output
perl -I../.. ../../tests/threads/mlfqs-fair-20.ck tests/threads/mlfqs-fair-20 tests/threads/mlfqs-fair-20.result
pass tests/threads/mlfqs-fair-20
pintos -v -k -T 480 --qemu  -- -q -mlfqs run mlfqs-nice-2 < /dev/null 2> tests/threads/mlfqs-nice-2.errors > tests/threads/mlfqs-nice-2.output
perl -I../.. ../../tests/threads/mlfqs-nice-2.ck tests/threads/mlfqs-nice-2 tests/threads/mlfqs-nice-2.result
FAIL tests/threads/mlfqs-nice-2
Some tick counts were missing or differed from those expected by more than 50.
thread   actual <-> expected explanation
------ -------- --- -------- ----------------------------------------
     0     1500 <<< 1904     Too small, by 354.
     1     1500 >>> 1096     Too big, by 354.
pintos -v -k -T 480 --qemu  -- -q -mlfqs run mlfqs-nice-10 < /dev/null 2> tests/threads/mlfqs-nice-10.errors > tests/threads/mlfqs-nice-10.output
perl -I../.. ../../tests/threads/mlfqs-nice-10.ck tests/threads/mlfqs-nice-10 tests/threads/mlfqs-nice-10.result
FAIL tests/threads/mlfqs-nice-10
Some tick counts were missing or differed from those expected by more than 25.
thread   actual <-> expected explanation
------ -------- --- -------- ----------------------------------------
     0      301 <<< 672      Too small, by 346.
     1      301 <<< 588      Too small, by 262.
     2      301 <<< 492      Too small, by 166.
     3      300 <<< 408      Too small, by 83.
     4      300  =  316      
     5      300 >>> 232      Too big, by 43.
     6      300 >>> 152      Too big, by 123.
     7      300 >>> 92       Too big, by 183.
     8      301 >>> 40       Too big, by 236.
     9      301 >>> 8        Too big, by 268.
pintos -v -k -T 480 --qemu  -- -q -mlfqs run mlfqs-block < /dev/null 2> tests/threads/mlfqs-block.errors > tests/threads/mlfqs-block.output
perl -I../.. ../../tests/threads/mlfqs-block.ck tests/threads/mlfqs-block tests/threads/mlfqs-block.result
FAIL tests/threads/mlfqs-block
Test output failed to match any acceptable form.

Acceptable output:
  (mlfqs-block) begin
  (mlfqs-block) Main thread acquiring lock.
  (mlfqs-block) Main thread creating block thread, sleeping 25 seconds...
  (mlfqs-block) Block thread spinning for 20 seconds...
  (mlfqs-block) Block thread acquiring lock...
  (mlfqs-block) Main thread spinning for 5 seconds...
  (mlfqs-block) Main thread releasing lock.
  (mlfqs-block) ...got it.
  (mlfqs-block) Block thread should have already acquired lock.
  (mlfqs-block) end
Differences in `diff -u' format:
  (mlfqs-block) begin
  (mlfqs-block) Main thread acquiring lock.
  (mlfqs-block) Main thread creating block thread, sleeping 25 seconds...
  (mlfqs-block) Block thread spinning for 20 seconds...
  (mlfqs-block) Block thread acquiring lock...
  (mlfqs-block) Main thread spinning for 5 seconds...
  (mlfqs-block) Main thread releasing lock.
- (mlfqs-block) ...got it.
  (mlfqs-block) Block thread should have already acquired lock.
  (mlfqs-block) end
pass tests/threads/alarm-single
pass tests/threads/alarm-multiple
pass tests/threads/alarm-simultaneous
FAIL tests/threads/alarm-priority
pass tests/threads/alarm-zero
pass tests/threads/alarm-negative
FAIL tests/threads/priority-change
FAIL tests/threads/priority-donate-one
FAIL tests/threads/priority-donate-multiple
FAIL tests/threads/priority-donate-multiple2
FAIL tests/threads/priority-donate-nest
FAIL tests/threads/priority-donate-sema
FAIL tests/threads/priority-donate-lower
FAIL tests/threads/priority-fifo
FAIL tests/threads/priority-preempt
FAIL tests/threads/priority-sema
FAIL tests/threads/priority-condvar
FAIL tests/threads/priority-donate-chain
FAIL tests/threads/mlfqs-load-1
FAIL tests/threads/mlfqs-load-60
FAIL tests/threads/mlfqs-load-avg
FAIL tests/threads/mlfqs-recent-1
pass tests/threads/mlfqs-fair-2
pass tests/threads/mlfqs-fair-20
FAIL tests/threads/mlfqs-nice-2
FAIL tests/threads/mlfqs-nice-10
FAIL tests/threads/mlfqs-block
20 of 27 tests failed.
../../tests/Make.tests:37: recipe for target 'check' failed
make[1]: *** [check] Error 1
make[1]: Leaving directory '/home/cht/os/group0/pintos/src/threads/build'
../Makefile.kernel:10: recipe for target 'check' failed
make: *** [check] Error 2
```
