#include <stdio.h>

#define A 100

char a;
int b;

main ()
{
  puts ("zgadnij jaka to liczba");
  while (b==!1)
  {
  scanf (a);
  if (a==100)
    {
      puts ("Brawo");
      b=1;
    }
  if (a>A)
    {
      puts ("dużo");
    }
  if (a<A)
    {
      puts ("mało");
    }
  }
}