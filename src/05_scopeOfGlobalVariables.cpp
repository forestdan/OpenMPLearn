#include<cstdio>
#include<omp.h>


static int a = 1000;

#pragma omp threadprivate(a)

void foo() {
    a++;
    printf("a:%d----tread:%d\n", a, omp_get_thread_num());
}

int main() {
    #pragma omp parallel for
    for (int i = 0; i < 4; i++) {
        foo();
    }
}