#include <stdlib.h>
#include <stdio.h>

int main ()
{
  int rozmiar;
  char wart;
  float (*tablica), (*tmp);
  int i=0;

  printf("Podaj rozmiar tablicy.\n");
  scanf("%d",&rozmiar);
  printf ("Nie przejmuj się, jeśli przekroczysz rozmiar tablicy, zostanie ona powiększona dwukrotnie.\n");
  tablica = malloc (rozmiar *sizeof (*tablica));
  while (wart!='!')
    {
      printf ("\nPodaj kolejny argument do tablicy. Jeśli wpiszesz znak \"!\" zakończysz działanie programu.\n");
      if (i==rozmiar)
	{
	  tmp = realloc (tablica, rozmiar *sizeof (*tablica));
	  tablica = tmp;
	}
      scanf ("%s",&wart);
      *tablica=wart;
      i++;
    }
  printf ("Zapisywanie do pliku\n");
  FILE *fp=NULL;
  fp = fopen ("tablica.txt","w");   
  for (i=0;i<rozmiar;i++)
    fprintf (fp,"%f \n",*tablica);
  fclose(fp);
  free (tablica);
  free (tmp);
  return 0;
}
