#include <stdio.h>
#include <time.h>

long long fibo(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int get_gcd(long long a, long long b, int* count) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
        (*count)++;
    }
    return (int)a;
}

int main() {
    printf("n | F(n) | F(n-1) | 연산횟수 | 실행시간(ms)\n");
    printf("------------------------------------------\n");

    for (int n = 5; n <= 40; n++) { 
        long long fn = fibo(n);
        long long fn_1 = fibo(n - 1);
        int count = 0;

        clock_t start = clock();
        get_gcd(fn, fn_1, &count);
        clock_t end = clock();

        double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000;
        printf("%d | %lld | %lld | %d | %.4f\n", n, fn, fn_1, count, duration);
    }
    return 0;
}