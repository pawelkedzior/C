#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main ()
{
  int rozmiar, wart, msc;
  bool a = false;
  float *tablica, *tmp;
  printf ("Podaj rozmiar tablicy.\nLepiej zapamiętaj tę wartość!\n");
  scanf ("%d", &rozmiar);
  tablica = malloc (rozmiar *sizeof (*tablica));
  if (!tablica)
    {
      printf ("Podałeś zły rozmiar. Podaj nowy");
      scanf ("%d", &rozmiar);
      tmp = realloc (tablica, rozmiar *sizeof (*tablica));
      if (!tmp)
	{
	  perror ("malloc");
	  free (tablica);
	  return 3;
	}
      tablica = tmp;
    }
  a = false;
  do
    {
      printf ("Podaj wartość i miejsce do tablicy:\nWartość: ");
      if (scanf ("%d",&wart)==1)  
	{
	  printf ("\nA dokąd?:\n");
	  if ((scanf ("%d",&msc)>rozmiar)||(msc<0))
	    {
	      goto ble;
	    }
	  else
	    {
	      if (msc==rozmiar)
		{
		  rozmiar *= 2;  
		  tmp = realloc (tablica, rozmiar *sizeof *tablica);
		}
	        tablica[msc]=wart;
	    }
      }
    else
      {
	a = true;
      }
    }
  while (!a);
 ble:
  free (tablica);
  free (tmp);
  return 0;
}
