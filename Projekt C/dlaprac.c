#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void usunk()
{
       FILE *usuwaj=NULL;
       int dlug=0;
       int j;       
       char moze;
       printf("\n\n\nOto pelna lista kompozycji:\n");
       usuwaj=fopen("Pizza.txt","r");
       char linija[128];
       char linija2[128];
       int pliczor=0;
       while (!feof(usuwaj))
             {
                 fgets(linija,127,usuwaj);
                 printf("%s",linija);
                 pliczor++;                     
             }
       fclose(usuwaj);
       printf("\n\nPodaj numer kompozycji,ktora chcesz usunac. Wpisz obie");
       printf(" cyfry.\n");
       int ta;
       char taz[2];
       do
         {
          taz[0]=getch();
          taz[1]=getch();
          ta=(taz[0]-48)*10+(taz[1]-48);
          if (ta>pliczor+1||ta<1)
             printf("Podales zly numer! Podaj nowy.\n");
         }
       while (ta>pliczor+1||ta<1);
       usuwaj=fopen("Pizza.txt","r");
       for (j=0;j<ta;j++)
              fgets(linija,127,usuwaj);
       fclose(usuwaj);
       printf("%s",linija);
       printf ("\nCzy te pizze chcesz usunac?(T/N)\n");
       char wyrok;
       do
         wyrok=getch();
       while (wyrok!='T'&&wyrok!='t'&&wyrok!='N'&&wyrok!='n');
       char linijapliku[pliczor-1][128];
       if (wyrok=='T'||wyrok=='t')
          {
           usuwaj=fopen("Pizza.txt","a+");
                 for (j=0;j<pliczor;j++)
                     {
                      if (j>ta-1)
                         {
                          fgets(linijapliku[j-1],127,usuwaj);
                          char nachwile[3];
                          linijapliku[j-1][1]=(ta%10)+48;
                          linijapliku[j-1][0]=(ta/10)+48;
                          ta++;
                          getch();
                         }
                      else
                          fgets(linijapliku[j],127,usuwaj);
                     }
           fclose(usuwaj);
           usuwaj=fopen("Pizza.txt","w");
           for (j=0;j<pliczor-1;j++)
               fprintf(usuwaj,"%s",linijapliku[j]);
           fclose(usuwaj);
           printf("\nPomyslnie usunales kompozycje.");
          }
       printf("\n\n");
}

void dodajk() //TU JEST B£¥D!!!! Maj¹ byæ kompozycje a nie klient
{
    printf("Podaj nazwe kompozycji, ktora chcesz utworzyc.\n");
    char nazwusia[16];
    scanf("%s",&nazwusia);
    char przelsklad[2];
    int skladlicz[9];
    char wers[9][64];
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
    printf("Mozesz wybrac do 8 skladnikow.\n");
    skladlicz[8]=0;
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
       if (!skladlicz[8])
          ENT=przelsklad[0];
       if (przelsklad[0]!='!'&&ENT!=13&&!(skladlicz[8]>0))
          przelsklad[1]=getch();
       if (przelsklad[0]!='!'&&ENT!=13&&!(skladlicz[8]>0))
          {
           skladlicz[0]=((przelsklad[0]-48)*10)+(przelsklad[1]-48);
           for (i=1;i<9;i++)
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
       if (ENT!=13&&!(skladlicz[8]>0)&&da[skladlicz[0]])
           printf ("%i. %s",j,wers[j-1]);
      }
    while (ENT!=13&&!(skladlicz[8]>0));
    int nomer=0;
    char srew[128];
    FILE *dlugo=NULL;
    dlugo=fopen("Pizza.txt","r");
         do
           {
               fgets(srew,127,dlugo);
               nomer++;
           }
         while (!feof(dlugo));
    fclose(dlugo);
    char nomerz[3];
    srew[0]='\0';
    nomerz[1]=nomer%10+48;
    nomerz[0]=nomer/10+48;
    nomerz[2]='\0';
    strcat(srew,nomerz);
    strcat(srew,". ");
    strcat(srew,nazwusia);
    strcat(srew," (");
    for (i=0;i<j-1;i++)
        {
         int kuku;
         kuku=strlen(wers[i])-1;
         strncat(srew,wers[i],kuku);
         strcat(srew,", ");
        }
        int kuku;
        kuku=strlen(wers[j-1])-1;
        strncat(srew,wers[j-1],kuku);
        strcat(srew,")\n");
    dlugo=fopen("Pizza.txt","a+");
    fseek(dlugo,0,SEEK_END);
    fprintf(dlugo,"%s",srew);
    fclose(dlugo);
    printf("\n\n\n");
}

void usunp()
{
       FILE *usuwaj=NULL;
       int dlug=0;       
       char moze;
       printf("Oto lista wszystkich pracownikow:\n");
       usuwaj=fopen("Pracownicy.txt","r");
       char linija[35];
       char linija2[35];
       int pliczor=0;
       while (!feof(usuwaj))
             {
                 fgets(linija,34,usuwaj);
                 if (!feof(usuwaj))
                    {
                     while (linija[dlug]!=' ')
                           {
                            printf("%c",linija[dlug]);
                            dlug++;
                           }
                     dlug=0;
                     printf("\n");
                     pliczor++;                     
                    }
             }
       fclose(usuwaj);
       printf("\n\nPodaj konto pracownika, ktore chcesz usunac.\n");
       char jego[16];
       int wprow;
       int i;
       for (i=0;i<15;i++)
         {
              jego[i]=getch();
              wprow=jego[i];
              if (wprow!=27)
                 printf ("%c",jego[i]);
              if (wprow==13||wprow==27)
                 {
                  jego[i]='\0';
                  if (i!=0||wprow==27)
                    break;
                  else
                    printf("\nNajpierw podaj nazwe uzytkownika\n");
                 }
              if (wprow==8)
                 {
                  printf(" \b");
                  i--;
                  i--;
                 }
         }
     if (wprow!=27)
      {  
       usuwaj=fopen("Pracownicy.txt","r");
       int numer=0;
       do
         {
              fgets(linija,33,usuwaj);
              if (!strstr(linija,jego))
                 numer++;
         }
       while (!strstr(linija,jego)&&!feof(usuwaj));
       fclose(usuwaj);
       dlug=0;
       while (linija[dlug]!=' ')
         {
                 dlug++;
         }
       for (i=0;i<dlug;i++)
           {
               linija2[i]=linija[i];
           }
       linija2[i]='\0';
       if (strstr(linija,jego))
          {
              printf("\nCzy na pewno chcesz usunac konto tego pracownika: ");
              printf("%s",linija2);
              printf("?(T/N)\n");
              do
                moze=getch();
              while (moze!='T'&&moze!='N'&&moze!='t'&&moze!='n');
          }
       else
           {
            printf ("Konto o podanej nazwie nie istnieje.\n");
            getch();
           }
       char linijapliku[pliczor-1][35];
       if (moze=='T'||moze=='t')
          {
           usuwaj=fopen("Pracownicy.txt","a+");
                 for (i=0;i<pliczor;i++)
                     {
                      if (i>numer)
                          fgets(linijapliku[i-1],34,usuwaj);
                      else
                          fgets(linijapliku[i],34,usuwaj);
                     }
           fclose(usuwaj);
           usuwaj=fopen("Pracownicy.txt","w");
           for (i=0;i<pliczor-1;i++)
               fprintf(usuwaj,"%s",linijapliku[i]);
           fclose(usuwaj);
           printf("Pomyslnie usunales pracownika.");
          }
      }
       printf("\n\n");
}

void dodajp()
{
     printf("\n\n\nWlasnie tworzysz konto pracownika.\n");
     printf("\nPodaj nazwe uzytkownika\n");
     int i;
     char nazwau[16];
     char haslou[16];
     int wprow;
     char lin[35];
     FILE *dodawaj=NULL;
     for (i=0;i<15;i++)
         {
              nazwau[i]=getch();
              wprow=nazwau[i];
              if (wprow!=27)
                 printf ("%c",nazwau[i]);
              if (wprow==13||wprow==27)
                 {
                  nazwau[i]='\0';
                  if (i!=0||wprow==27)
                    break;
                  else
                    printf("\nNajpierw podaj nazwe uzytkownika\n");
                 }
              if (wprow==8)
                 {
                  printf(" \b");
                  i--;
                  i--;
                 }
         }
     dodawaj=fopen("Pracownicy.txt","a+");
             while ((!feof(dodawaj))&&(nazwau!=strstr(lin,nazwau)))
                   { 
                     fgets(lin,34,dodawaj);            
                   }
     fclose(dodawaj);
     if (wprow!=27&&!strstr(lin,nazwau))
        {
         printf("\nA teraz podaj haslo.\n");
         for (i=0;i<15;i++)
             {
              haslou[i]=getch();
              wprow=haslou[i];
              if (wprow!=13&&wprow!=27)
                 printf ("*");
              if (wprow==13||wprow==27)
                 {
                  haslou[i]='\0';
                  if (i!=0||wprow==27)
                    break;
                  else
                    printf("\nNajpierw podaj nazwe haslo\n");
                 }
              if (wprow==8)
                 {
                  printf("\b \b");
                  i--;
                  i--;
                 }
             }
        }
     if (wprow!=27&&!strstr(lin,nazwau))
        {
         *haslou=szyfr(haslou);
         char razem[33];
         razem[0]='\0';
         strcat(razem,nazwau);
         strcat(razem," ");
         strcat(razem,haslou);
         strcat(razem,"\n");
         dodawaj=fopen("Pracownicy.txt","a+");
             fseek(dodawaj,0,2);
             fprintf(dodawaj,"%s",razem);
         fclose(dodawaj);
         printf("\nPomyslnie dodales pracownika!");
        }
     else
         if (wprow!=27)
            printf("\nTaki uzytkownik juz istnieje!");
     printf("\n\n\n");
}     

char haslok (char klient[16])

{
     char linijka[35];
     bool czylogin;
     int i;
     FILE *odzysk=NULL;
     odzysk=fopen("klienci.txt","r");
     do
       {
        fgets(linijka,34,odzysk);
        for (i=0;i<strlen(klient);i++)
            {
             if (klient[i]!=linijka[i])
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
            for (i;i<strlen(linijka);i++)
                {
                    klient[i-j]=linijka[i];   
                }
           }
       }
     while (!feof(odzysk)&&!czylogin);
     fclose(odzysk);
     return *klient;
}

void dodajsk()
{
     printf("\n\n\nWlasnie dodajesz nowe skladniki.\n");
     printf("\nJaki skladnik chcesz dodac?\n");
     int i;
     char nazwas[24];
     int dane;
     for (i=0;i<23;i++)
         {
              nazwas[i]=getch();
              dane=nazwas[i];
              if (dane!=27)
                 printf ("%c",nazwas[i]);
              if (dane==13||dane==27)
                 {
                  nazwas[i]='\0';
                  if (i!=0||dane==27)
                    break;
                  else
                    printf("\nNajpierw podaj skladnik\n");
                 }
              if (dane==8)
                 {
                  printf(" \b");
                  i--;
                  i--;
                 }
         }
     if (dane!=27)
        {
         char razem[33];
         char numerek[4];
         numerek[2]='.';
         numerek[3]='\0';
         char linijeczka[35];
         int zmiana;
         FILE *dodawaj=NULL;
         dodawaj=fopen("Sklad.txt","a+");
             while ((!feof(dodawaj))&&!(strstr(linijeczka,nazwas)))
             { 
                 fgets(linijeczka,34,dodawaj);
             }
         fclose(dodawaj);
         if (!(strstr(linijeczka,nazwas)))
           {
            zmiana=(linijeczka[0]-48)*10+(linijeczka[1]-48)+1;
            numerek[0]=zmiana/10+48;
            numerek[1]=zmiana%10+48;
            strcat(razem,numerek);
            strcat(razem," ");
            strcat(razem,nazwas);
            strcat(razem,"\n");         
            dodawaj=fopen("Sklad.txt","a+");
                fseek(dodawaj,0,2);
                fprintf(dodawaj,"%s",razem);
            fclose(dodawaj);
            printf("\nPomyslnie dodales skladnik!");
           }
         else
             {
                   printf("\nTaki skladnik jest juz na liscie.");
             }
        }
     printf("\n\n\n");
}     

void usunsk();

void zmienhaslo(char ktoto[16])
{
     FILE *fp=NULL;
     bool czylogin=false;
     bool nie=true;
     char linijka[35];
     char haslo[16];
     int i, ENTER, j, pliczor;
     printf ("\n\nWlasnie zmieniasz swoje haslo.\nAby je zmienic wpisz obecne");
     printf (".\n");
     i=0;
     while (ENTER!=13&&i!=15&&ENTER!=27)
            {
                 haslo[i]=getch();
                 ENTER=haslo[i];
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
           haslo[i]='\0';
        }
     *haslo=szyfr(haslo);
     pliczor=0;
     fp=fopen("Pracownicy.txt","a+");
     do
       {
        fgets(linijka,34,fp);
        pliczor++;
        for (i=0;i<strlen(ktoto);i++)
            {
             if (ktoto[i]!=linijka[i])
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
            j=i;
            for (i;i<strlen(haslo)+j;i++)
                {                                 
                   if (haslo[i-j]!=linijka[i])
                      {
                       nie=true;
                       break;
                      }
                   else
                       nie=false;
                }
           }
       }
     while (!feof(fp)&&!czylogin);
     fclose(fp);
     char nowalinia[35];
     nowalinia[0]='\0';
     ENTER=0;
     i=0;
     if (!nie)
        {
         printf("\nTeraz wprowadz nowe haslo.\n");
         while (ENTER!=13&&i!=15&&ENTER!=27)
               {
                   haslo[i]=getch();
                   ENTER=haslo[i];
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
             haslo[i]='\0';
            }
         *haslo=szyfr(haslo);
         printf("\n");
         strcat(nowalinia,ktoto);
         strcat(nowalinia," ");
         strcat(nowalinia,haslo);
         strcat(nowalinia,"\n");
         printf("\n%i\n%s",pliczor,nowalinia);
         int numer=0;
         fp=fopen("Pracownicy.txt","a+");
            do
              {
               fgets(linijka,34,fp);
               numer++;
              }
            while(!feof(fp));
            fseek(fp,0,0);
            char linie[numer][35];
            numer=0;
            do
              {
                  fgets(linie[numer],34,fp);
               if (numer==pliczor-1)
                  {
                   linie[numer][0]='\0';
                   strcat(linie[numer],nowalinia);
                  }
               numer++;
              }
            while(!feof(fp));     
         fclose(fp);
         fp=fopen("Pracownicy.txt","w");
         for (i=0;i<numer-1;i++)
            fprintf(fp,"%s",linie[i]);
         fclose(fp);
        }
}

int pracus (char ktoto[16],bool adminek)
{
     char wybierz;
     do
     {    
        printf ("\nWitaj %s!\n",ktoto);
        printf ("Oto Twoje mozliwosci:\n\n");
        printf ("0. Wrocic do menu\n");
        printf ("1. Dodac kompozycje\n");
        printf ("2. Usunac kompozycje\n");
        printf ("3. Przypomniec haslo klienta\n");
        printf ("4. Dodac skladniki do listy\n");
        printf ("5. Usunac skladniki z listy\n");
        if (!adminek)
        printf ("6. Zmienic swoje haslo\n");
        if (adminek)
           {
            printf ("6. Dodac pracownika\n");
            printf ("7. Usunac pracownika\n\n\n\n");
           }
        else
            printf ("\n\n\n");
        wybierz=getch();
        if (adminek&&wybierz>53)
           wybierz++;
        switch (wybierz)
        {
           case '0':
                return 0;
           break;
           case '1':
                dodajk();
           break;
           case '2':
                usunk();
           break;
           case '3':
                printf ("Jakiemu klientowi chcesz przypomniec haslo?\n");
                char maczo[16];
                scanf ("%s",&maczo);
                *maczo=haslok(maczo);
                *maczo=deszyfr(maczo);
                printf("%s",maczo);
                printf ("\n\n\n");
           break;
           case '7':
                dodajp();                
           break;
           case '8':
                printf("\n\n");
                usunp();
           break;
           case '4':
                dodajsk();
           break;
           case '5':
           break;
           case '6':
                zmienhaslo(ktoto);
           break;
        }
        printf("\n\n");
     }
     while(true);
}
