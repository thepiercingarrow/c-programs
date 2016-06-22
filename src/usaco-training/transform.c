/*
ID: thepier1
LANG: C
TASK: transform
*/
#include <stdio.h>

#define XORSWAP(a, b) ((a)^=(b),(b)^=(a),(a)^=(b))

void r90(char matrix[10][11], int N);
int mtxcmp(char before[10][11], char after[10][11], int N);

int main() {
  FILE *fin = fopen("transform.in", "r");
  FILE *fout = fopen("transform.out", "w");
  int N, i, j;
  char before[10][11], after[10][11];

  fscanf(fin, "%d\n", &N);
  for (i = 0; i < N; ++i)
    fscanf(fin, "%s\n", before[i]);
  for (i = 0; i < N; ++i)
    fscanf(fin, "%s\n", after[i]);

  r90(before, N);
  if (mtxcmp(before, after, N)) {
    fprintf(fout, "1\n");
    return 0;
  }
  r90(before, N);
  if (mtxcmp(before, after, N)) {
    fprintf(fout, "2\n");
    return 0;
  }
  r90(before, N);
  if (mtxcmp(before, after, N)) {
    fprintf(fout, "3\n");
    return 0;
  }
  r90(before, N);

  for (i = 0; i < N; ++i)
    for (j = 0; j <= N/2 - 1; ++j)
      XORSWAP(before[i][j], before[i][N-j-1]);
  if (mtxcmp(before, after, N)) {
    fprintf(fout, "4\n");
    return 0;
  }

  r90(before, N);
  if (mtxcmp(before, after, N)) {
    fprintf(fout, "5\n");
    return 0;
  }
  r90(before, N);
  if (mtxcmp(before, after, N)) {
    fprintf(fout, "5\n");
    return 0;
  }
  r90(before, N);
  if (mtxcmp(before, after, N)) {
    fprintf(fout, "5\n");
    return 0;
  }
  r90(before, N);

  if (mtxcmp(before, after, N)) {
    fprintf(fout, "6\n");
    return 0;
  }
  
  fprintf(fout, "7\n");
  return 0;
}

void r90(char matrix[10][11], int N) {
  int i, j;
  for (i = 0; i < N; ++i)
    for (j = 0; j < i; ++j)
      XORSWAP(matrix[i][j], matrix[j][i]);
  for (i = 0; i < N; ++i)
    for (j = 0; j <= N/2 - 1; ++j)
      XORSWAP(matrix[i][j], matrix[i][N-j-1]);
}

int mtxcmp(char before[10][11], char after[10][11], int N) {
  int i, j;
  for (i = 0; i < N; ++i)
    for (j = 0; j < N; ++j)
      if (before[i][j] != after[i][j])
	return 0;
  return 1;
}
