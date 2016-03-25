/* Vanya and Cubes */

#include <stdio.h>
#define SUMTRI(i) (i*(i+1)*(i+2)/6)

int main() {
  int n, i = 1;
  scanf("%d", &n);
  while (SUMTRI(i) <= n)
    ++i;
  printf("%d\n", i - 1);
}
