/*
ID: thepier1
LANG: C
TASK: namenum
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORDS 5000

#define true 1
#define false 0

int namecmp(long long num, char *str);

int main() {
  FILE *dict = fopen("dict.txt", "r");
  FILE *fin = fopen("namenum.in", "r");
  FILE *fout = fopen("namenum.out", "w");
  int i, none = true;
  long long name;
  char names[MAXWORDS][13];
  for (i = 0; fscanf(dict, "%s\n", names[i]) != EOF; ++i);
  int words = i - 1;
  fscanf(fin, "%lld\n", &name);
  for (i = 0; i < words; ++i) {
    if (namecmp(name, names[i])) {
      fprintf(fout, "%s\n", names[i]);
      none = false;
    }
  }
  if (none)
    fprintf(fout, "NONE\n");
}

int namecmp(long long num, char *str) {
  int i;
  char res[13];
  for (i = 0; i < strlen(str); ++i) {
    if (str[i] == 'Q' || str[i] == 'Z')
      return false;
    res[i] = str[i] > 'Q' ? (str[i] - 'B')/3 + '2' : (str[i] - 'A')/3 + '2';
  }
  res[i] = 0;
  long long num2 = strtoll(res, (char**)NULL, 10);
  return num == num2;
}
