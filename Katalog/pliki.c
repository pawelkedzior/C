#include <stdio.h>


int main()
{
  char miesiac[20];
  int dzien,rok;

  FILE *fp=NULL;
   fp=fopen ("Jejeje.txt","w");
   if (fp==NULL)
     {
       printf ("\nBłąd otwierania pliku!\n");
       perror("system");
       return 0;
     }
   while (scanf("%d %s %d",&dzien,miesiac,&rok)==3)
     fprintf (fp,"dzień: %d, miesiąc: %s, rok: %d\n",dzien,miesiac,rok);
   fclose (fp);
   return 0;
}
