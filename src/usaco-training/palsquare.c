/*
ID: thepier1
LANG: C
TASK: palsquare
*/

#include <stdio.h>
int main() {
  FILE *fin = fopen("palsquare.in", "r");
  FILE *fout = fopen("palsquare.out", "w");
  int i, B;
  char i2InB[17];
  fscanf(fin, "%d\n", &B);
  for (i = 1; i <= 300; ++i) {
    int j, i2 = i * i;
    for (j = 0; i2 > 0; ++j) {
      i2InB[j] = i2 % B + (i2 % B >= 10 ? 'A' - 10 : '0');
      i2 /= B;
    }
    i2InB[j] = 0;
    int len = j - 1, equal = 1;
    for (j = 0; j <= len/2; ++j)
      if (i2InB[j] != i2InB[len - j]) {
	equal = 0;
	break;
      }
    if (equal) {
      int ic = i;
      char iInB[10];
      for (iInB[9] = 0, j = 8; ic > 0; --j) {
	iInB[j] = ic % B + (ic % B >= 10 ? 'A' - 10 : '0');
	ic /= B;
      }
      fprintf(fout, "%s %s\n", iInB + j + 1, i2InB);
    }
  }
}
