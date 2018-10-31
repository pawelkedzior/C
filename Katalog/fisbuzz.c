#include <stdio.h>

int tab[100];
int i;

main ()
{
  for (i=0;i<100;i++)
    {
      tab[i]=i+1;
      printf ("%d",tab[i]);
	  if ((tab[i]%3)==0)
	    printf (" FIZZ");
	  if ((tab[i]%5)==0)
	    printf (" BUZZ");
      printf ("\n");
    }
}
