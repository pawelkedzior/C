#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main (int argc,char *argv[])
{
    FILE *fp=NULL;
  if (argc!=6)
    printf("Błędna ilość parametrów i użycie tego pliku %s!\n",argv[0]);
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
  if (argv[2][0]=='w')
    {
      printf("argument %s",argv[2]);
    fprintf (fp,"Imię: %s, Nazwisko: %s data: %s\n",argv[3],argv[4],argv[5]);
    }
  if (argv[2][0]=='r')   
    fscanf (fp,"%s",argv[3]);
  while (!feof(fp))
    {
      printf ("%s", argv[3]);
      fscanf (fp,"%s", argv[3]);
    }
      fclose(fp);
}
