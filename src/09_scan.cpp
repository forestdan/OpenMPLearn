#include <cstdio>
#include <cstdlib>

int main() {
//   const int N = 8;
//   int a[N], b[N];
//   for (int i = 0; i < N; i++) {
//     a[i] = i;
//     printf("%*d", 2, a[i]);
//   }
//   printf("\n");
//   for (int i = 1; i < N; i++)
//     a[i] += a[i - 1];
//   for (int i = 0; i < N; i++)
//     printf("%*d", 3, a[i]);
//   printf("\n");
    
  const int N=8;
  int a[N], b[N];
  for(int i=0; i<N; i++) {
    a[i] = rand() & 3;
    printf("%*d ",2,a[i]);
  }
  printf("\n");
#pragma omp parallel
  for(int j=1; j<N; j<<=1) {
#pragma omp for
    for(int i=0; i<N; i++)
      b[i] = a[i];
#pragma omp for
    for(int i=j; i<N; i++)
      a[i] += b[i-j];
  }
  for(int i=0; i<N; i++)
    printf("%*d ",2,a[i]);
  printf("\n");
}