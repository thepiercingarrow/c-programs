/*
ID: thepier1
LANG: C
TASK: wormhole
*/
#include <stdio.h>
#include <limits.h>

#define MAX_WORMHOLES 12
#define SWAP(a, b) ((tmp)=(a),(a)=(b),(b)=(tmp))

struct coor {
  int x, y;
};

void assignPairs(int filled);
int wormsTrapBessie();
int findnextX(int worm);

int numworms, count = 0;
struct coor worms[MAX_WORMHOLES];

int main() {
  FILE *fin = fopen("wormhole.in", "r");
  FILE *fout = fopen("wormhole.out", "w");
  fscanf(fin, "%d\n", &numworms);
  int i;
  for (i = 0; i < numworms; ++i)
    fscanf(fin, "%d %d\n", &worms[i].x, &worms[i].y);
  assignPairs(0);
  fprintf(fout, "%d\n", count);
}

void assignPairs(int filled) {
  if (numworms - filled == 2) {
    if (wormsTrapBessie())
      ++count;
    return;
  }
  int i;
  struct coor myworms[MAX_WORMHOLES];
  for (i = 0; i < numworms; ++i)
    myworms[i] = worms[i]; // backup worms
  for (i = filled+1; i < numworms; ++i) {
    struct coor tmp;
    int j;
    for (j = filled; j < numworms; ++j)
      worms[j] = myworms[j]; // copy myworms into worms
    SWAP(worms[filled+1], worms[i]);
    assignPairs(filled + 2);
  }
}

int wormsTrapBessie() {
  int i, pairs[MAX_WORMHOLES];
  for (i = 0; i < numworms; ++i)
    pairs[i] = findnextX(i);
  for (i = 0; i < numworms; ++i) {
    if (pairs[i] == -1)
      continue;
    int j = i;
    do { // while cow hasn't looped or exited
      int tmp = j;
      j = pairs[j];
      pairs[tmp] = -1;
      j % 2 ? --j : ++j;
    } while (j != i && pairs[j] != -1);
    if (j == i)
      return 1;
  }
  return 0;
}

int findnextX(int worm){ // returns portal index of next portal, or -1
  int i, x = INT_MAX, y = -1;
  for (i = 0; i < numworms; ++i) {
    if (worms[i].y == worms[worm].y)
      if (worms[worm].x < worms[i].x && worms[i].x < x) {
	x = worms[i].x;
	y = i;
      }
  }
  return y;
}
