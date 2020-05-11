#include <cstdio>
#include <omp.h>

int main() {
    #pragma omp parallel for
    for (int i = 0; i < 8; i++) {
        printf("%d: %d\n", omp_get_thread_num(), i);
    }

    /* 注意拆开写法
    // #pragma omp parallel num_threads(4)
    // #pragma omp for
    // for (size_t i = 0; i < count; i++)
    // {
    //     /* code */
    // }
}