#include <stdio.h>



long int silnia (int l)
{
  if (l==0 || l==1)
    return 1;
  return l*silnia(l-1);
}

long int potega (int l,int m)
{
  if (m==1);
     return l;
  return l*potega(l,m-1);
}

int main ()
{
int a,b,c,r;
	printf ("Cześć kochanie! Chcesz skorzystać z kalkulatorka?\n");
	while (c!=7)
	{
		printf ("Co chcesz zrobić?\n");
		printf ("1. Dodać\n2. Odjąć\n3. Pomnożyć\n4. Podzielić\n5. Obliczyć silnię\n6. Spotegować\n7. Wyjść\n\n");
		scanf ("%d",&c);
		printf ("\n");
		if (c!=7)
		  {
		    printf ("Na jakich liczbach chcesz działać?\n");
		    scanf ("%d",&a);
		    scanf ("%d",&b);
		  }
		switch (c)
		       {
				case 1:
				  {
				     a+=b;
				     printf("Wynik to: %d \n",a);
				     break;}
				case 2:
				     a-=b;
				     printf ("Wynik to: %d \n",a);
				break;
				case 3:
				     a*=b;
				     printf ("Wynik to: %d \n",a);
				break;
				case 4:
				  if (b==0)
				    {
				      printf ("Nie ma tak");
				      break;
				    }
				     r=a%b;
				     a/=b;
				     printf ("Wynik to: %d Reszty %d\n",a,r);
				break;
				case 7:
				     printf ("Żegnaj! ;(\n");
				break;
		                case 5:
				  /*sil=silnia (a);*/
				     printf ("Oto wynik: %ld\n\n",silnia(a));
				break;
		                case 6:
				  /* sil=potega (a,b);*/
				  printf ("Potega to: %ld\n\n",potega(a,b));
				break;
				default:
					printf ("Chyba się pomyliłeś.\n");
				break;
		       }/*koniec switch*/
	}
	return (0);
}
