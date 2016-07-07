/*
ID: thepier1
LANG: C
TASK: skidesign
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_HILLS 1000
#define SQ(a) ((a)*(a))

int compar(int *a, int *b);

int main() {
  FILE *fin = fopen("skidesign.in", "r");
  FILE *fout = fopen("skidesign.out", "w");
  int i, N, hills[MAX_HILLS], mincost = INT_MAX;
  fscanf(fin, "%d\n", &N);
  for (i = 0; i < N; ++i)
    fscanf(fin, "%d\n", hills + i);
  qsort(hills, N, sizeof(int), (int (*)(const void *, const void *))compar);
  if (hills[N-1] - hills[0] <= 17) {
    fprintf(fout, "%d\n", 0);
    return 0;
  }
  i = hills[0];
  do {
    int j, mycost = 0;
    for (j = 0; hills[j] < i; ++j)
      mycost += SQ(hills[j] - i);
    for (j = N - 1; hills[j] > i + 17; --j)
      mycost += SQ(hills[j] - (i + 17));
    if (mycost < mincost)
      mincost = mycost;
  } while (++i + 17 <= hills[N-1]);
  fprintf(fout, "%d\n", mincost);
}

int compar(int *a, int *b) {
  return *a - *b;
}
