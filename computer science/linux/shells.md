# shells

## 1

```
read a,b
echo "$a+$b=`$a+$b`"
```

```sh
#!/bin/bash
if [[ $# -eq 0 ]]
then
        # 没有输入参数
        echo "Syntax Error:"
        echo "    Usage:isactive username"
else
        # 输入了参数
        name=$1   # 获取名字
        isin=0  # 名字是否存在，默认为不存在
        for line in `cat /etc/passwd`  # 逐行读取文件，cat xxx
        do
                tokens=`echo $line | tr ':' ' '`  # 将 ':' 替换成空格
                for token in ${tokens[@]}  # 进行分割，获取每行的各个token
                do
                        first=$token  # 获取第一个部分，并退出循环
                        break
                done
                if [[ $name = $first ]]  # 判断是否是输入的用户
                then
                        isin=1
                        break  # 如果是则置1，退出循环
                fi
        done
        if [[ $isin -eq 0 ]]
        then
                echo "$name is not a valid name."  # 不存在用户
        else
                # active=`who`  # 获取活跃用户
                # if [[ $name = $active ]]
                # then
                #         echo "user $name is active."  # 活跃
                # else
                #         echo "user $name is inactive"  # 不活跃
                # fi
                isactive=0  # 是否活跃，默认为不活跃
                i=0
                for line in `who`  # 获取活跃用户的每个token
                do
                        if [[ $(( $i % 5 )) = 0 ]]
                        then
                                active=$line  # 获取活跃用户
                                # echo $active
                                if [[ $active = $name ]]  # 判断是否活跃
                                then
                                        isactive=1
                                        break
                                fi
                        fi
                        i=$(( $i + 1 ))
                done
                if [[ $isactive -eq 0 ]]
                then
                        echo "user $name is inactive."  # 不活跃
                else
                        echo "user $name is active."  # 活跃
                fi
        fi
fi
```

```sh
hour=$((10#`date +%H`))
user=`whoami`
if [[ hour -lt 12 ]]
then
        echo "Good morning $user, hava a nice day!"
else
        echo "Good afternoon $user, hava a good evening!"
fi
```

```cs
public interface IEnumrable<T> : IEnumrable {
    IEnumrator<T> GetEnumrator();
    IEnumrator IEnumrable.GetEnumrator();
}

public interface IEnumrable {
    IEnumrator GetEnumrator();
}

public partial class MainActivity : Activity {
    [AutoInject]
    MainActivityViewModel ViewModel;
}


```

