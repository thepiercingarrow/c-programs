/*
ID: thepier1
LANG: C
TASK: combo
*/
#include <stdio.h>
#include <stdlib.h>

#define PUSH(a, b, c) (working[s][0] = (a), working[s][1] = (b), working[s][2] = (c))
#define A_CMP(w) (w[s][0] == w[s+1][0] && w[s][1] == w[s+1][1] && w[s][2] == w[s+1][2])

int compar(int a[][3], int b[][3]);

int main() {
  FILE *fin = fopen("combo.in", "r");
  FILE *fout = fopen("combo.out", "w");
  int N;
  int john[3], master[3], working[250][3], s = 0;
  fscanf(fin, "%d\n%d %d %d\n%d %d %d\n", &N, john, john+1, john+2, master, master+1, master+2);
  --john[0],--john[1],--john[2],--master[0],--master[1],--master[2];
  int i, j, k, count;
  for (i = -2; i <= 2; ++i)
    for (j = -2; j <= 2; ++j)
      for (k = -2; k <= 2; ++k) {
	PUSH((i + john[0] + N) % N, (j + john[1] + N) % N, (k + john[2] + N) % N);
	++s;
	PUSH((i + master[0] + N) % N, (j + master[1] + N) % N, (k + master[2] + N) % N);
	++s;
      }
  qsort(working, s, 3*sizeof(int), (int (*)(const void *, const void *))compar);
  for (count = 1, s -= 2; s >= 0; --s)
    if (!A_CMP(working))
      ++count;
  fprintf(fout, "%d\n", count);
}

int compar(int a[][3], int b[][3]) {
  if (a[0][0] > b[0][0])
    return 1;
  if (**a < **b)
    return -1;
  if ((*a)[1] > (*b)[1])
    return 1;
  if ((*a)[1] < (*b)[1])
    return -1;
  if ((*a)[2] > (*b)[2])
    return 1;
  if ((*a)[2] < (*b)[2])
    return -1;
  return 0;
}
