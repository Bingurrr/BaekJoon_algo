#include <cstdio>
 
long long int n, t = 1;
const long long int MOD = 1e12;
void f()
{
    while (t % 10 == 0) {
        t /= 10;
    }
}
int main()
{
    scanf("%lld", &n);
    for (long long int i = 1; i <= n; ++i) {
        t *= i;
        f();
        t %= MOD;
    }
    printf("%05lld", t%100000);
    return 0;
}