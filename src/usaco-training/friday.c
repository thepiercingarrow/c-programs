/*
ID: thepier1
LANG: C
TASK: friday
*/
#include <stdio.h>
#define ISLEAPYEAR(year) (((year) & 3) == 0 && (((year) % 25) != 0 || ((year) & 15) == 0))

int main() {
  FILE *fin  = fopen ("friday.in", "r");
  FILE *fout = fopen ("friday.out", "w");
  const int ndays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  const int ldays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  const int *days;
  int N, day = 2, date, month, year, thirteenths[7] = {0, 0, 0, 0, 0, 0, 0};
  getw(fin, &N);
  for (year = 0; year < N; year++) {
    if (ISLEAPYEAR(year + 1900))
      days = ldays;
    else
      days = ndays;
    for (month = 0; month < 12; month++) {
      for (date = 1; date <= days[month]; date++) {
        if (date == 13)
          thirteenths[day]++;
        day = (day + 1) % 7;
      }
    }
  }
  fprintf(fout, "%d %d %d %d %d %d %d\n", thirteenths[0], thirteenths[1], thirteenths[2],   \
          thirteenths[3], thirteenths[4], thirteenths[5], thirteenths[6]);
}
