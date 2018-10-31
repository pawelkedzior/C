#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
      FILE *prac=NULL;
      prac=fopen("Pracownicy.txt","r");
      char znak;
      char *linijka, *tymcz;
      int rozmiar=2;
      linijka=malloc(rozmiar *sizeof (*linijka));
      
//      fprintf(prac,"Admin KJHFG\n");
      char admin[]="Admin";
      int i=0;
          while (znak!=EOF)
                {
                 znak=fgetc(prac);
                 if (znak!=EOF)
                    linijka[i]=znak;
                 i++;
                 if (i==rozmiar)
                    {
                     rozmiar+=1;
                     tymcz=realloc(linijka, rozmiar *sizeof (*tymcz));
                     linijka=realloc(tymcz, rozmiar *sizeof (*linijka));
                    }
                }
          char *wynik = strstr(linijka,admin);
      printf("%s\n",wynik);
      getch();
      fclose (prac);
      return 0;
}
