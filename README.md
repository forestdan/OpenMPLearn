# OpenMP Learn

## 引入
1. 一组应用程序接口（Application Program Interface, API）,可以用来显式地指导多线程、**共享内存式**程序的并行化。[更详细的OpenMP简介](https://blog.csdn.net/magicbean2/article/details/75530667)
2. 包含三个组件：  
（1）编译指令集，例：#pragma omp parallel  
（2）运行时的库函数，例：omp_set_num_threads(3)  
（3）环境变量，例：OMP_NUM_THREADS=3  
3. mac使用clang编译，原生系统的clang不支持openmp，需要先安装libomp  
```
brew install libomp
```
编译指令  
```
clang++ -Xpreprocessor -fopenmp -lomp 00_HelloOpenMP.cpp
```

## 设置线程数
三种方式：优先级依次递减  
（1）编译指令  
```
num_threads()
```
（2）函数调用
```
omp_set_num_threads()
```
（3）设置环境变量
```
OMP_NUM_THREADS
```
## 循环并行化
```
#pragma omp parallel for
```
5种策略 //TOEDIT
1. static: Divide into equal size chunks and schedule statically
2. dynamic: Divide into equal size chunks and schedule dynamically
3. guided:Divideinto(number_of_iterations_remaining/number_of_threads) 4. runtime:Decisionisdeferreduntilruntime(UseOMP_SCHEDULE)
5. auto: Decision is delegated to the compiler and runtime  
**注意只有在不同线程中的使用的变量是相互独立的才能正确并行化，相互有影响的，例如```a[i] = a[i] + a[i + 1]```这样的，由于不知道循环并行化以后不知道切割点在哪，就会导致最终结果与线性执行有区别
## 变量范围
在并行范围（parallel region）外声明的变量在并行范围内默认是共享的， 使用thread
在并行范围内声明的变量只影响范围内，就算名称和外部有重复，也不会形成拷贝，具体有代码04_variablesScope.cpp
