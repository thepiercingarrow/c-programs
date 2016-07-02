/*
ID: thepier1
LANG: C
TASK: beads
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calc(int N, const char *beads);
int allwhite(int N, char *beads);

int main() 
{
  FILE *fin = fopen("beads.in", "r");
  FILE *fout = fopen("beads.out", "w");
  int N, i, max = 0, t;
  char beads[351], color;
  fscanf(fin, "%d\n%s\n", &N, beads);
  if (allwhite(N, beads) == 1) {
    fprintf(fout, "%d\n", N);
    exit(0);
  }
  for (i = 0; i < N; ++i) {
    t = calc(N, beads);
    if (t > max)
      max = t;
    color = beads[0];
    memmove(beads, beads+1, N-1);
    beads[N-1] = color;
  }
  fprintf(fout, "%d\n", max);
}

int calc(int N, const char *beads) {
  int i, a;
  char color;
  if (beads[0] == 'w')
    return 0;
  color = beads[0];
  i = 0;
  while (beads[i] == color || beads[i] == 'w') {
    if (i == N - 1) 
      return N;
    ++i;
  }
  for (a = N - 1; beads[a] == 'w'; a--) ;
  for (color = beads[a];
       beads[a] == color || beads[a] == 'w';
       a--)
    if (a == i)
      return N;
  return i + N - ++a;
}

int allwhite(int N, char *beads) {
  int i;
  for (i = N; i-- > 0; )
    if (beads[i] != 'w')
      return 0;
  return 1;
}
