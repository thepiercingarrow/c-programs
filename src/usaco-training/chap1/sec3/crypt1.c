/*
ID: thepier1
LANG: C
TASK: crypt1
*/
#include <stdio.h>
#include <stdlib.h>

int digitsIn(char *a, char *digits, int N);

int main() {
  FILE *fin = fopen("crypt1.in", "r");
  FILE *fout = fopen("crypt1.out", "w");
  int N;
  char digits[9] = {0,0,0,0,0,0,0,0,0};
  char a[4], b[3], c[4], d[4], e[5];
  int i, j, k, l, m, count = 0;
  fscanf(fin, "%d", &N);
  for (i = 0; i < N; ++i) {
    getc(fin);
    digits[i] = getc(fin);
  }
  for (i = 0; i < N; ++i)
    for (j = 0; j < N; ++j)
      for (k = 0; k < N; ++k)
	for (l = 0; l < N; ++l)
	  for (m = 0; m < N; ++m) {
	    a[0] = digits[i];
	    a[1] = digits[j];
	    a[2] = digits[k];
	    a[3] = 0;
	    b[0] = digits[l];
	    b[1] = digits[m];
	    b[2] = 0;
	    if (atoi(a)*(b[1]-'0') > 999 || atoi(a)*(*b-'0') > 999 || atoi(a)*atoi(b) > 9999) // if partial products are 4 digits
	      continue;
	    snprintf(c, sizeof c, "%d", atoi(a) * (b[1] - '0'));
	    snprintf(d, sizeof d, "%d", atoi(a) * (b[0] - '0'));
	    snprintf(e, sizeof e, "%d", atoi(c) + 10*atoi(d));
	    if (digitsIn(c, digits, N) && digitsIn(d, digits, N) && digitsIn(e, digits, N)) {
	      ++count;
	    }
	  }
  fprintf(fout, "%d\n", count);
}

int digitsIn(char *a, char *digits, int N) {
  int i, j, eq;
  for (i = 0; a[i] != 0; ++i) { // loop through *a
    for (eq = 0, j = 0; j < N; ++j) // check digits
      if (a[i] == digits[j]) {
	eq = 1;
	break;
      }
    if (!eq)
      return 0;
  }
  return 1;
}
