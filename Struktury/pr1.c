#include <stdio.h>
#include <stdlib.h>

int main ()
{
  union foo {int l; char c;} foo;
  struct bar {int l; char c;} bar;
  union foo x;
  x.l = 3;
  x.c = 'a';
  printf ("%i, %c \n", x.l, x.c);
  x.l = 0xBABEFACE;
  x.c = 0x22;
  printf ("%x, %x \n", x.l, x.c);
  struct bar y;
  y.l = 3;
  y.c = 'c';
  printf ("%i, %c \n", y.l, y.c);
  y.l = 0xDEADBEEF;
  y.c = 0x22;
  printf ("%x, %x \n", y.l, y.c);
  return 0;
}
