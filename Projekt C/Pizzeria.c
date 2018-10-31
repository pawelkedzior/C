#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>


char loginw[16];

void pomoc(void)
{
     printf ("\n\nOd Twojego wyboru zalezy sposob doboru pizzy.\n");
     printf ("Wybierajac pierwsza opcje decydujesz sie na samodzielny ");
     printf ("dobor zamowienia.\nProgram przedstawia Ci liste dostepnych ");
     printf ("rodzajow pizzy, a nastepnie Ty\nwybierasz te, ktora ");
     printf ("najbardziej przypadla Ci do gustu.\n");
     printf ("Po potwierdzeniu swojego wyboru ");
     printf ("dostaniesz informacje o cenie i zostaniesz\nwyslany do kasy,");
     printf (" zeby dopelnic swoje zamowienie.\n\n\n");
     
     printf ("Opcja druga jest dla klientow,\nktorzy nie sa zdecydowani");
     printf (" na konkretna kompozycje.\nAby wybrac pizze, z listy dostepnych");
     printf (" skladnikow wybierasz te");
     printf (",\nktore chcialbys zobaczyc na swojej pizzy,\na potem program");
     printf (" wybiera kompozycje najbardziej pasujace do Twoich preferencji");
     printf ("\ni wyswietla je na ekranie.\n");
     printf ("Ty decydujesz sie na jedna z nich");
     printf (", badz na zadna\ni albo zostaniesz skierowany do kasy,\n");
     printf ("tak jak");
     printf (" po wyborze pizzy za pomoca opcji pierwszej,\nalbo wracasz do");
     printf (" menu, gdzie mozesz wybrac opcje pierwsza.\n\n");
     
     printf ("Jesli jestes stalym klientem mozesz wybrac opcje trzecia.\n");
     printf ("W tej opcji logujesz sie nia swoje konto,\ngdzie mozesz ");
     printf ("zobaczyc swoje ostatnie zamowienia,\nwybrac ulubiona kompozycje");
     printf (" lub usunac swoje konto.\nWybor nalezy do Ciebie.\n\n");
     
     printf ("Opcja czwarta jest przeznaczona dla pracownikow\ni wymaga ");
     printf ("autoryzacji. Jezeli jestes pracownikiem,\nzostaniesz zapytany");
     printf (" o swoj login i haslo.\nPotem bedziesz mogl edytowac dostepne");
     printf (" kompozycje oraz skladniki.\n");
     printf ("Jesli jestes administratorem mozesz");
     printf (" tez dodawac\nlub usuwac konta pracownikow.\n\n\n");
     
     printf ("Piata opcja to ta, ktora wlasnie wybrales,\naby dowiedziec");
     printf ("sie wiecej o dzialaniu programu.\n\n\n");
     
     printf ("Ostatnia opcja konczy dzialanie programu,\nale administrator ");
     printf ("musi podac swoje haslo, aby tego dokonac.\n\n\n");
     printf ("Jesli zapoznales sie z trescia \"pomocy\",\nnacisnij dowolny");
     printf (" klawisz, zeby wrocic do menu.\n\n\n");
     getch();
}

int logow (int opcja)
{
    char haslow[16];
    int i=0;
    int ENTER=0;
    printf ("Aby sie zalogowac podaj login i haslo.\nLogin: ");
    for (i=0;i<15;i++)
         {
              loginw[i]=getch();
              ENTER=loginw[i];
              if (ENTER!=27&&ENTER!=13)
                 printf ("%c",loginw[i]);
              if (ENTER==13||ENTER==27)
                 {
                  loginw[i]='\0';
                  if (i!=0||ENTER==27)
                    break;
                  else
                    printf("\nNajpierw podaj nazwe uzytkownika\n");
                 }
              if (ENTER==8)
                 {
                  printf(" \b");
                  i--;
                  i--;
                 }
         }
    if (ENTER!=27)
    printf ("\nHaslo: ");
    if (ENTER!=27)
       ENTER=0;
    i=0;
    while (ENTER!=13&&i!=15&&ENTER!=27)
           {
                haslow[i]=getch();
                ENTER=haslow[i];
                if (ENTER!=13&&ENTER!=8&&ENTER!=27)
                   printf("*");
                if (ENTER==8)
                   {
                      printf ("\b \b");
                      i--;
                   }
                else
                    i++;
           }
    if (ENTER==13)
       {
          i--;
          haslow[i]='\0';
       }
    if (opcja==1)
       {
        bool prawa=false;
        char prawal[]="Admin";
        char prawah[]="aDmin";
             for (i=0;i<strlen(loginw);i++)
                 {
                  if (loginw[i]!=prawal[i])
                     {
                      prawa=false;
                      break;
                     }
                  else
                  {
                      prawa=true;
                  }
                 }
             if (prawa)
                for (i=0;i<strlen(haslow);i++)
                    {
                     if (haslow[i]!=prawah[i])
                        {
                         prawa=false;
                         break;
                        }
                    }
                if (prawa)
                   return 3;
       }
    printf ("\n");
    bool nie=false;
    if (ENTER!=27)
       {
        *haslow=szyfr(haslow);
        FILE *prac=NULL;
        char linijka[35];
        bool czylogin=false;
        if (opcja==1)
           prac=fopen("Pracownicy.txt","r");
        if (opcja==2)
           prac=fopen("Klienci.txt","r");
             do
                   {
                       fgets(linijka,34,prac);
                       for (i=0;i<strlen(loginw);i++)
                           {
                               if (loginw[i]!=linijka[i])
                                  {
                                   czylogin=false;
                                   break;
                                  }
                               else
                                   czylogin=true;                   
                           }
                       if (czylogin)
                          {
                           i++;
                           int j=i;
                               for (i;i<strlen(haslow)+j;i++)
                                   {                                 
                                    if (haslow[i-j]!=linijka[i])
                                       {
                                        nie=true;
                                        break;
                                       }
                                    else
                                        nie=false;
                                   }
                          }
                   }
             while (!feof(prac)&&!czylogin);
             if (feof(prac))
                nie=true;
        fclose (prac);
       }
    if (nie)
       {
           return 1;
       }
    else
        if (ENTER==27)
           {
            printf("\n\n\n");
            return 0;
           }
        else
            {
              return 2;
            }
}

void zamow(int wybrana)
{
     printf ("Dziekujemy za skorzystanie z naszych uslug!\nPizza bedzie ");
     printf ("dostarczona panstwu do stolika\npo uiszczeniu oplaty w kasie.\n");
     printf ("Przewidywany czas oczekiwania: ");
     int godzina,minuty;
     godzina=1+(time(NULL)%(3600*24))/3600;
     printf("%d\n",godzina);
     minuty=(time(NULL)%(3600*24))/(60*24);
     printf("%d\n",minuty);
     printf ("O cenie pizzy zostana panstwo poinformowani przy kasie.\n\n");
     printf ("Aby umozliwic zakupy innym wcisnij dowolny klawisz.\n");
     getch();
     printf ("\n\n");
}   

void zawartosc()
{
    printf("Nie mozesz sie zdecydowac?\n");
    printf("Nic nie szkodzi! Mozesz wybrac skladniki,");
    printf("ktore Cie interesuja,\na potem otrzymasz propozycje kompozycji");
    printf(" wybranych wlasnie dla Ciebie!\nAby wrocic do menu wpisz:\"!\"\n");
    printf("\nTe skladniki masz do dyspozycji:\n\n");
    char przelsklad[2];
    int skladlicz[7];
    char wers[7][64];
    FILE *skladn=NULL;
    skladn=fopen("Sklad.txt","r");
    char znak='0';
    while (znak!=EOF)
          {
           znak=fgetc(skladn);
           if (znak!=EOF)
           printf("%c",znak);
          }
    znak=' ';
    printf("\n");
    printf("Aby wybrac skladnik wpisz jego pelny numer\n(jesli numerem jest ");
    printf("01, to wpisz tez 0).\nAby przerwac wybieranie wcisnij ENTER.\n");
    printf("Mozesz wybrac do 6 skladnikow.\n");
    skladlicz[6]=0;
    printf("\nWybrales:\n");
    int ENT;
    int j=0;
    int ciezar=0;
    skladn=fopen("Sklad.txt","r");
        do
          {
           fgets(wers[0],64,skladn);
           ciezar++;
          }
        while (!feof(skladn));
    fclose(skladn);
    bool da[ciezar];
    int i;
    for (i=0;i<ciezar;i++)
        da[i]=true;
    do
      {
       przelsklad[0]=getch();
       if (!skladlicz[6])
          ENT=przelsklad[0];
       if (przelsklad[0]!='!'&&ENT!=13&&!(skladlicz[6]>0))
          przelsklad[1]=getch();
       if (przelsklad[0]!='!'&&ENT!=13&&!(skladlicz[6]>0))
          {
           skladlicz[0]=((przelsklad[0]-48)*10)+(przelsklad[1]-48);
           for (i=1;i<7;i++)
               if (skladlicz[0]==skladlicz[i])
                  da[skladlicz[0]]=false;
               if (da[skladlicz[0]])
                  {
                   skladn=fopen("Sklad.txt","r");
                   for (i=0;i<skladlicz[0];i++)
                       {
                          fgets(wers[j],64,skladn);
                       }
                   fclose(skladn);
                   for (i=0;i<strlen(wers[j])-4;i++)
                       wers[j][i]=wers[j][i+4];
                   wers[j][i]='\0';
                   skladlicz[j]=skladlicz[0];
                     j++;
                  }
          }
       if (ENT!=13&&!(skladlicz[6]>0)&&da[skladlicz[0]])
           printf ("%i. %s",j,wers[j-1]);
      }
    while (ENT!=13&&!(skladlicz[6]>0));
    
    printf("\n\n\n");
}

void wyborp(void)
{
     char przel[2];
     int przeln[2];
     int czy=0;
     do
       {
               if (czy==0)
               {
                  printf ("Wlasnie wybierasz pizze. Aby wrocic do menu wpisz:");
                  printf (" \"!\".\n");
               }
               else
               {
                   printf ("\n\n\nW takim razie wybierz ponownie.\n");
               }
               printf ("Oto pelna lista kompozycji:\n\n");
               FILE *piz=NULL;
               piz=fopen("Pizza.txt","r");
               char znak;
               int i=0;
               znak='0';
                   while (znak!=EOF)
                         {
                            znak=fgetc(piz);
                            if (znak!=EOF)
                            printf("%c",znak);
                         }
                   printf("\n\n\n");
               przel[0]=getch();
               if (przel[0]!='!')
                  przel[1]=getch();
               fclose(piz);
               if (przel[0]!='!')
               {
               char wers[128];
               przeln[0]=((przel[0]-48)*10)+(przel[1]-48);
                      piz=fopen("Pizza.txt","r");
                          for (i=0;i<przeln[0];i++)
                          {
                              fgets(wers,128,piz);
                          }
                          printf("Oto Twoj wybor:\n%s\nCzy o te pizze ",wers);
                          printf("Ci chodzilo(T/N)?\n");
                          do
                            {
                                przel[0]=getch();
                            }
                          while ((przel[0]!='T')&&(przel[0]!='N')\
                          &&(przel[0]!='t')&&(przel[0]!='n'));
                          printf("\n\n");
                          czy=1;
                      fclose(piz);
               if (przel[0]=='T'||przel[0]=='t')
                  {
                       przel[0]='!';
                       zamow(przeln[0]);
                  }
               }
       }
     while (przel[0]!='!');
}

bool wylacz()
{
     printf ("\nAby wyjsc podaj haslo administratora.\n");
     char haslowyj[16];
     int ENTER;
     int i=0;
     printf ("Haslo: ");
     while (ENTER!=13&&i!=16)
           {
                haslowyj[i]=getch();
                ENTER=haslowyj[i];
                if (ENTER!=13&&ENTER!=8)
                   printf("*");
                if (ENTER==8)
                   {
                      printf ("\b \b");
                      i--;
                   }
                else
                    i++;
           }
           if (ENTER==13)
              {
               i--;
               haslowyj[i]=' ';
              }
     char haslowlasc[]="aDmin";
     bool tak;
     for (i=0;i<strlen(haslowlasc);i++)
         {
          
          if (haslowyj[i]!=haslowlasc[i])
             {
               tak=true;
               break;
             }
         }
     if (!tak)
        return true;
     else
         {     
               printf ("\nPodales niewlasciwe haslo.\n\n\n");
               return false;
         }
}

int main ()
{
     int wyb;
     while (1)
       {
         printf ("Witamy w naszej pizzerii!\nCo chcesz zrobic?\n");
         printf ("1. Wybrac pizze\n");
         printf ("2. Wybrac skladnkiki\n");
         printf ("3. Zalogowac sie jako klient\n");
         printf ("4. Zalogowac sie jako pracownik\n");
         printf ("5. Uzyskac pomoc co do swojego wyboru\n");
         printf ("6. Wyjsc.\n\n");
         wyb=getch();
         switch (wyb)
         {
              case '1':
                   {
                     wyborp();
                   }
              break;
              case '2':
                   {
                     zawartosc();           
                   }
              break;
              case '5':
                   {
                       pomoc();
                   }
              break;
              case '4':
                   {
                    int zaloguj;
                    do
                      {
                       zaloguj=logow(1);
                          if (zaloguj==2)
                             {
                                 pracus(loginw,false);
                             }
                          else
                              {
                               if (zaloguj==1)
                                 {            
                                    printf("\nNieprawidlowa nazwa uzytkownika");
                                    printf(" lub haslo.\n\n\n");
                                 }
                               else
                                  if (zaloguj==3)
                                     {
                                        pracus("Admin",true);
                                     }
                              }
                      }
                    while(zaloguj==1);
                   }
              break;
              case '6':
                   {
                       if (wylacz())
                          return 0;
                   }
              break;
              case '3':
                {
                   int zaloguj;
                    do
                      {
                       zaloguj=logow(1);
                          if (zaloguj==2)
                             {
                                 pracus(loginw);
                             }
                          else
                              {
                               if (zaloguj==1)
                                 {            
                                    printf("\nNieprawidlowa nazwa uzytkownika");
                                    printf(" lub haslo.\n\n\n");
                                 }
                              }
                      }
                    while(zaloguj==1);
                }
              break;
         }
     }
}
