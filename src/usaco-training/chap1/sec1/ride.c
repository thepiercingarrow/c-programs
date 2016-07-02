/*
ID: thepier1
LANG: C
TASK: ride
*/
#include <stdio.h>

int main() {
  FILE *fin = fopen("ride.in", "r");
  FILE *fout = fopen("ride.out", "w");
  int c, i, comet = 1, group = 1;
  while ((c = getc(fin)) != '\n')
    comet *= (c - 64);
  while ((c = getc(fin)) != '\n')
    group *= (c - 64);
  fprintf(fout, (comet - group) % 47 ? "STAY\n" : "GO\n");
  return 0;
}
