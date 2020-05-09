#include <iostream>
#include <omp.h>

/**
 * 第三种 OMP_NUM_THREADS=4
 **/

int main() {
  omp_set_num_threads(3);
#pragma omp parallel num_threads(2)
  std::cout << "hello\n";
}