argc , argv : 表示命令行模式下输入参数的个数和参数内容；
argv是一个字符串数组

```
int main(int argc, char** argv){
    ...
}
```
```
./a.out a b c
```
argc=4
argv[0]="./a.out"
argv[1]="a"
...
