#include <cstdio>
#include <omp.h>

int main() {
  int i = 1;
#pragma omp parallel sections firstprivate(i)
  {
#pragma omp section
    printf("%d: %d\n",++i, omp_get_thread_num());
#pragma omp section
    printf("%d\n",++i);
  }
}