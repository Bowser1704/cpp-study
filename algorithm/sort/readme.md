# c++问题

## 编译环境 ubuntu18.04 g++ 7.4.0

```c++
    ./main 99
    // 无问题，三次destructor
    ./main 100
    // error double free， 只有一次destructor
```
