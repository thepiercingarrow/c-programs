`/*
ID: thepier1
LANG: C
TASK: barn1
*/
#include <stdio.h>
#include <stdlib.h>

struct board {
  int start, end;
};

int compar(int *a, int *b);

int main() {
  FILE *fin = fopen("barn1.in", "r");
  FILE *fout = fopen("barn1.out", "w");
  int M, S, C, stalls[201];
  fscanf(fin, "%d %d %d\n", &M, &S, &C);
  int i, num, fc = 1;
  for (i = 1; i <= S; ++i) {
    stalls[i] = 0;
  }
  for (i = 0; i < C; ++i) {
    fscanf(fin, "%d\n", &num);
    stalls[num] = 1;
  }
  while (!stalls[S]) // find last cow
    --S;
  while (!stalls[fc]) // find first cow
    ++fc;
  int spaces[200], j = 0;
  for (i = 0; i < S; ++i)
    spaces[i] = 0;
  int firstspace, lastspace;
  for (i = fc; stalls[i]; ++i)
    ;
  firstspace = i;
  for (i = S; stalls[i]; --i)
    ;
  lastspace = i + 1;
  for (i = firstspace; i < lastspace; ++i)
    if (stalls[i]) { // if occupied
      while (stalls[i]) // find next unoccupied
	++i;
      ++spaces[++j];
    }
    else // if empty
      ++spaces[j];
  qsort(spaces, j + 1, sizeof(int), (int (*)(const void *, const void *))compar); // sort in descending order
  int len = S - fc + 1;
  i = 0;
  printf("S:%d fc:%d len:%d\n",S,fc,len);
  while (len != C && --M) // while still empty spaces and more boards
    len -= spaces[i++];
  fprintf(fout, "%d\n", len);
}

int compar(int *a, int *b) {
  return *b - *a;
}
