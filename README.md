# OpenMP Learn

## 引入
1. 一组应用程序接口（Application Program Interface, API）,可以用来显式地指导多线程、**共享内存式**程序的并行化。[更详细的OpenMP简介](https://blog.csdn.net/magicbean2/article/details/75530667)
2. 包含三个组件：  
（1）编译指令集，例：#pragma omp parallel  
（2）运行时的库函数，例：omp_set_num_threads(3)  
（3）环境变量，例：OMP_NUM_THREADS=3  
3. mac使用clang编译，原生系统的clang不支持openmp，需要先安装libomp  
```shell
brew install libomp
```
编译指令  
```shell
clang++ -Xpreprocessor -fopenmp -lomp 00_HelloOpenMP.cpp
```

## 设置线程数
三种方式：优先级依次递减  
（1）编译指令  
```c++
num_threads()
```
（2）函数调用
```c++
omp_set_num_threads()
```
（3）设置环境变量
```c++
OMP_NUM_THREADS
```
## 循环并行化
```c++
#pragma omp parallel for
```
5种策略 //TOEDIT
1. static: Divide into equal size chunks and schedule statically
2. dynamic: Divide into equal size chunks and schedule dynamically
3. guided:Divideinto(number_of_iterations_remaining/number_of_threads) 4. runtime:Decisionisdeferreduntilruntime(UseOMP_SCHEDULE)
5. auto: Decision is delegated to the compiler and runtime  
**注意只有在不同线程中的使用的变量是相互独立的才能正确并行化，相互有影响的，例如```a[i] = a[i] + a[i + 1]```这样的，由于不知道循环并行化以后不知道切割点在哪，就会导致最终结果与线性执行有区别**
## 变量范围
在并行范围（parallel region）外声明的变量在并行范围内默认是共享的， 使用```threadprivate(list)```可以将共享的变量变为私有，并且拷贝在并行之外的相同的, 见05_scopeOfGlobalVariables.cpp  

在并行范围内声明的变量默认是并行范围私有的，范围外的没有关系，形式如```private(list)```的用法，见04_variablesScope.cpp  

关于private系列的clause的作用  
||private|firstprivate|lastprivate|threadprivate|
|----|:----:|:----:|:----:|:----:|
|copy in|N(uninitialized)|Y|N(uninitialized)||
|copy out|N|N|Y||
这里有一篇好的[Blog](https://blog.csdn.net/gengshenghong/article/details/6985431)可以参考，讨论了这些private的范围问题  

## 并行的三种方式
1. 循环并行 **for**
```c++
#pragma omp for
// for body
```
将循环切割，并行分配至各个线程执行  

2. **section** 并行
```c++
#pragma omp sections [num_threads(num)]  
#pragma omp section
// section1
#pragma omp section
// section2
// .....
```
每个section使用一个线程，并行  

3. **task** 并行
```c++
#pragma omp task [shared()]
// task1 body
#pragma omp task [shared()]
// task2 body
#pragma omp taskwait|barrier
// after task
```
每个task使用一个线程，并行  
**同步task**  
taskwait：等待所有子任务的完成
barrier：等待所有任务的完成

## 聚集