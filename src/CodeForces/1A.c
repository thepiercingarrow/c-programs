/* Theatre Square */

#include <stdio.h>
#include <math.h>

int main() {
    long unsigned int n, m, a;
    scanf("%lu %lu %lu", &n, &m, &a);
    printf("%llu\n", (long long unsigned int)(ceil((long double)(n)/(long double)(a))*ceil((long double)(m)/(long double)(a))));
}
