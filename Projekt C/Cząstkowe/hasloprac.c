#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char szyfr (char haslo[16])
{
      char alf[63]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E',
                    'F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T',
                    'U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i',
                    'j','k','l','m','n','o','p','q','r','s','t','u','v','w','x',
                    'y','z','!'};
      char szyf[4][63] = {{'k','l','m','n','o','p','q','r','s','t','U','V','W',
                           'X','Y','Z','0','1','2','3','4','5','6','7','8','9',
                           'a','b','c','d','e','f','g','h','i','j','u','v','w',
                           'x','y','z','A','B','C','D','E','F','G','H','I','J',
                           'K','L','M','N','O','P','Q','R','S','T','!'},
                          {'9','a','b','c','d','e','f','g','h','i','J','K','L',
                           'M','N','O','P','Q','R','S','T','U','V','W','X','Y',
                           'Z','0','1','2','3','4','5','6','7','8','j','k','l',
                           'm','n','o','p','q','r','s','t','u','v','w','x','y',
                           'z','A','B','C','D','E','F','G','H','I','!'},
                          {'e','f','g','h','i','j','k','l','m','n','O','P','Q',
                           'R','S','T','U','V','W','X','Y','Z','0','1','2','3',
                           '4','5','6','7','8','9','a','b','c','d','o','p','q',
                           'r','s','t','u','v','w','x','y','z','A','B','C','D',
                           'E','F','G','H','I','J','K','L','M','N','!'},
                          {'j','k','l','m','n','o','p','q','r','s','T','U','V',
                           'W','X','Y','Z','0','1','2','3','4','5','6','7','8',
                           '9','a','b','c','d','e','f','g','h','i','t','u','v',
                           'w','x','y','z','A','B','C','D','E','F','G','H','I',
                           'J','K','L','M','N','O','P','Q','R','S','!'} 
                         }; //KLUCZ: UJOT
      int kod[16];
      int i,j;
      j=0;
        for (i=0;i<strlen(haslo);i++)
          {
           kod[i]=haslo[i];
           if (kod[i]<58&&kod[i]>47)
              {
                 kod[i]-=48;
              }
           else
               {
                  if (kod[i]<91&&kod[i]>64)
                     {
                         kod[i]-=55;
                     }
                  else
                      {
                          if (kod[i]>96&&kod[i]<123)
                             {
                                kod[i]-=61;
                             }
                          else
                              {
                                 kod[i]=62;
                              }
                      }
               }
           haslo[i]=szyf[j][kod[i]];
           j++;
           j=j%4;
          }
      return *haslo;
}

main()
{
      char login[16];
      char haslo[16];
      int i=0;
      int j;
      char wers[128];
      char wers2[128];
      printf("Podaj log i has\nLog:");
      scanf("%s",&login);
      printf("Has:");
      scanf("%s",&haslo);
      printf("%s\n%s\n",login,haslo);
      *haslo=szyfr(haslo);
      printf("%s\n",haslo);
      FILE *fp=NULL;
      fp=fopen("Pracownicy.txt","r");
      while ((*wers)!=(*wers2))
            {
            int roz;
            roz=i%2;
              if (roz==0)
               for (j=0;j<i;j++)
                   fgets(wers,128,fp);
              else
                for (j=0;j<i;j++)
                    fgets(wers2,128,fp);
              i++;
              printf("%d",i);
              if ((*wers2)!=(*wers))
                 if (roz==0)
                    printf("%s",wers);
                 else
                     printf("%s",wers2);
            }
      fclose(fp);
      getch();
      return 0;
}
