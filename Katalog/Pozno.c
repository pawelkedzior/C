#include <stdio.h>
#include <stdlib.h>

main (int argc,char *argv[])
{
  FILE *fp=NULL;
    printf("Podaj nazwę pliku:\n");
    scanf("%s",argv[1]);
   fp = fopen (argv[1], "w");
  if (argc!=5)
    printf("Błędna ilość parametrów i użycie... %s!\n",argv[0]);
  if ((fp=fopen (argv[1],"a+"))==NULL)
    {
      printf("Błąd otwarcia!\n");
      perror("System");
      return 5;
    }
  if (fp==NULL)
  {
    printf ("Błąd otwarcia pliku\n");
    return 0;
    }
  fprintf (fp,"Imię: %s, Nazwisko: %s\n data: %s",argv[2],argv[3],argv[4]);
  fclose(fp);
}
