#include <stdio.h>
#include <stdlib.h>

main (int argc, char *argv[])

{
  int i;
  FILE *fp=NULL;
  if (argc!=3)
    {
      printf ("Błędna liczba parametrów i użycie pliku %s\n", argv[1]);  
    }
  if ((fp=fopen (argv [1],"a+"))==NULL)
      {
	printf ("Błąd otwarcia pliku\n");
	return 5;
      }

      if (argv[2][0]=='a')
	{
	  for (i=1;i<11;i++)
	    fprintf (fp,"%d\n",i);
	}
      if (argv[2][0]=='b')
	{
	  for (i=11;i<101;i++)
	    fprintf (fp,"%d ",i);
	}
      fclose(fp);
      return 0;
}
