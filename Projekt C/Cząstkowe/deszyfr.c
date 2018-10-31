#include <stdlib.h>
#include <stdio.h>
//Szyfr Vigenere'a
main()
{
      char alf[63]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','!'};
      char szyf[4][63] = {{'k','l','m','n','o','p','q','r','s','t','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','!'},
                          {'9','a','b','c','d','e','f','g','h','i','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','!'},
                          {'e','f','g','h','i','j','k','l','m','n','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','a','b','c','d','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','!'},
                          {'j','k','l','m','n','o','p','q','r','s','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','!'} 
                         }; //KLUCZ: UJOT
      char haslo[64];
      int kod[64];
      char czy='a';
      int i,j;
      while (czy!='q')
      {
      scanf("%s",&haslo);
      for (j=0;j<strlen(haslo);j++)
        for (i=0;i<63;i++)
          {
             if (haslo[j]==szyf[j%4][i])
                {
                   haslo[j]=alf[i];
                   break;
                }
          }
      printf ("%s\n",haslo);
      printf ("Aby kontynuowac wcisnij dowolny klawisz.\nJesli naciœniesz \"q\" wyjdziesz z programu.\n");
      czy=getch();
      }
      return 0;
}
