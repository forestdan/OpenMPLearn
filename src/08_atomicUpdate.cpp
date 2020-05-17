#include <cstdio>

int main() {
  float x[10];
  for (int i = 0; i < 10; i++)
    x[i] = 0.0;
#pragma omp parallel for shared(x)
  for (int i = 0; i < 1000; i++) {
    x[i % 10]++;
  }
  for (int i = 0; i < 10; i++)
    printf("%d %g\n", i, x[i]);
}
