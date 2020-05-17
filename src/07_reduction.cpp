#include<cstdio>

int main() {
    int a = 0;
    #pragma omp parallel for reduction(+ : a)
    for (int i = 0; i < 8; i++) {
        a += 2;
        printf("%d\n", a);
    }
    printf("%d\n", a);
}