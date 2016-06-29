/*
ID: thepier1
LANG: C
TASK: dualpal
*/
#include <stdio.h>

int isPalendrome(int A, int base);

int main() {
  FILE *fin = fopen("dualpal.in", "r");
  FILE *fout = fopen("dualpal.out", "w");
  int N, S;
  fscanf(fin, "%d %d\n", &N, &S);
  int i, j, tcount = 0;
  for (i = S + 1; tcount < N; ++i) {
    int icount = 0;
    for (j = 2; j <= 10; ++j) {
      if (isPalendrome(i, j)) {
	++icount;
	if (icount == 2) {
	  fprintf(fout, "%d\n", i);
	  ++tcount;
	  break;
	}
      }
    }
  }
}

int isPalendrome(int A, int base) {
  int i, j;
  int a[18];
  for (i = 0; A > 0; ++i) {
    a[i] = A % base;
    A /= base;
  }
  for (j = 0; j < i / 2; ++j)
    if (a[j] != a[i-j-1])
      return 0;
  return 1;
}
