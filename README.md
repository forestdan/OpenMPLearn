# OpenMP Learn

1. 一组应用程序接口（Application Program Interface, API）,可以用来显式地指导多线程、共享内存式程序的并行化。
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
