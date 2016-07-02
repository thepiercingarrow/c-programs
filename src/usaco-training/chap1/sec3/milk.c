/*
ID: thepier1
LANG: C
TASK: milk
*/
#include <stdio.h>
#include <stdlib.h>

struct farmer {
  int P, A;
};

int compar(struct farmer *a, struct farmer *b);

int main() {
  FILE *fin = fopen("milk.in", "r");
  FILE *fout = fopen("milk.out", "w");
  int N, M;
  struct farmer farmers[5000], *p = farmers;
  fscanf(fin, "%d %d\n", &N, &M);
  int i, price = 0;
  for (i = 0; i < M; ++i)
    fscanf(fin, "%d %d\n", &(farmers[i].P), &(farmers[i].A));
  qsort(farmers, i, sizeof(struct farmer), (int (*)(const void *, const void *))compar);
  do {
    if (N > p->A) {
      price += p->P * p->A;
      N -= p->A;
    }
    else {
      price += p->P * N;
      break;
    }
  }
  while (++p);
  fprintf(fout, "%d\n", price);
}

int compar(struct farmer *a, struct farmer *b) {
  return a->P - b->P;
}
