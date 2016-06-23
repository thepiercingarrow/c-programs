/*
ID: thepier1
LANG: C
TASK: milk2
*/
#include <stdio.h>
#include <stdlib.h>

int compar(const void *a, const void *b);

struct farmer {
  int start, end;
};

int compar(const void *a, const void *b) {
  return ((struct farmer*)a)->start - ((struct farmer*)b)->start;
}

int main() {
  FILE *fin = fopen("milk2.in", "r");
  FILE *fout = fopen("milk2.out", "w");
  int i, N, start, end, max_cont = 0, max_idle = 0;
  struct farmer farmers[5000];
  getw(fin, &N);
  for (i = 0; i < N; ++i) {
    getw(fin, &farmers[i].start);
    getw(fin, &farmers[i].end);
  }
  qsort(farmers, N, sizeof(struct farmer), compar);
  start = farmers[0].start;
  end = farmers[0].end;
  for (i = 1; i < N; ++i) {
    if (farmers[i].start > end) {
      //If this farmer enters an empty farm
      if (farmers[i].start - end > max_idle)
	max_idle = farmers[i].start - end;
      if (end - start > max_cont)
	max_cont = end - start;
      start = farmers[i].start;
      end = farmers[i].end;
    }
    else {
      //If this farmer meets other farmers
      if (farmers[i].end > end)
	end = farmers[i].end;
    }
  }
  if (end - start > max_cont)
    max_cont = end - start;
  fprintf(fout, "%d %d\n", max_cont, max_idle);
}
