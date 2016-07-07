/*
ID: thepier1
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <string.h>

struct friend {
  char name[15];
  int given, received;
};

int indexName(char *name, struct friend *friends);

int main() {
  FILE *fin = fopen("gift1.in", "r");
  FILE *fout = fopen("gift1.out", "w");
  struct friend friends[10] = {
    {"\0", 0, 0},
    {"\0", 0, 0},
    {"\0", 0, 0},
    {"\0", 0, 0},
    {"\0", 0, 0},
    {"\0", 0, 0},
    {"\0", 0, 0},
    {"\0", 0, 0},
    {"\0", 0, 0},
    {"\0", 0, 0}
  };
  int NP, i, NG, index, given;
  fscanf(fin, "%d", &NP);
  char name[15];
  for (i = 0; i < NP; i++)
    fscanf(fin, "%s\n", friends[i].name);
  for (i = 0; i < NP; i++) {
    fscanf(fin, "%s\n%d %d\n", name, &given, &NG);
    given = given / (NG ? NG : 1);
    friends[indexName(name, friends)].given = given * NG;
    for (; NG > 0; NG--) {
      fscanf(fin, "%s\n", name);
      friends[indexName(name, friends)].received += given;
    }
  }
  for (i = 0; i < NP; i++)
    fprintf(fout, "%s %d\n", friends[i].name, friends[i].received - friends[i].given);
}

int indexName(char *name, struct friend *friends) {
  int i = 0;
  while (strcmp(friends[i].name, name) != 0)
    ++i;
  return i;
}
