#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void zmieniamy(char ktoto[16])
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
     fp=fopen("klienci.txt","a+");
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
         fp=fopen("klienci.txt","a+");
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
         fp=fopen("klienci.txt","w");
         for (i=0;i<numer-1;i++)
            fprintf(fp,"%s",linie[i]);
         fclose(fp);
        }
}

void tokoniec(char mistrzu[16])
{
       FILE *zapomnij=NULL;       
       char moze;
       char linija[35];
       int i;
       int pliczor=0;
       printf("\nCzy na pewno chcesz usunac swoje konto?(T/N)\n");
       do
         moze=getch();
       while (moze!='T'&&moze!='N'&&moze!='t'&&moze!='n');
       if (moze!='n'&&moze!='N')
          {  
             zapomnij=fopen("klienci.txt","r");
                 do
                   {
                    fgets(linija,33,zapomnij);
                    pliczor++;
                   }
                 while (!feof(zapomnij));
             fclose(zapomnij);
             zapomnij=fopen("klienci.txt","r");
             int numer=0;
             do
               {
                fgets(linija,33,zapomnij);
                if (!strstr(linija,mistrzu))
                   numer++;
               }
             while (!strstr(linija,mistrzu)&&!feof(zapomnij));
             fclose(zapomnij);             
             char linijapliku[pliczor-1][35];
             if (moze=='T'||moze=='t')
                {
                 zapomnij=fopen("Pracownicy.txt","a+");
                    for (i=0;i<pliczor;i++)
                        {
                         if (i>numer)
                            fgets(linijapliku[i-1],34,zapomnij);
                         else
                             fgets(linijapliku[i],34,zapomnij);
                        }
                 fclose(zapomnij);
                 zapomnij=fopen("Pracownicy.txt","w");
                 for (i=0;i<pliczor-1;i++)
                     fprintf(zapomnij,"%s",linijapliku[i]);
                 fclose(zapomnij);
                 printf("Pomyslnie usunales swoje konto.\nDziekujemy za ");
                 printf("korzystanie z naszych uslug!\n");
                }
          }
       printf("\n\n");
}

void wyborna()
{
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
     fclose(piz);
     printf ("\n\nWprowadz numer swojej ulubionej pizzy.");
     int ulub;
     char ulu[128];
     scanf("%d",&ulub);
     piz=fopen("Pizza.txt","r");
     for (i=0;i<ulub;i++)
        fgets(ulu,127,piz);
     fclose(piz);
     printf("%s",ulu);
     getch();
}

int kliencik (char mistrzu[16])
{
     char unem;
     do
     {    
        printf ("\n\n\nWitaj %s!\n",mistrzu);
        printf ("Oto Twoje mozliwosci:\n\n");
        printf ("1. Przejrzec swoje ostatnie zamowienia\n");
        printf ("2. Wybrac ulubiona pizze\n");
        printf ("3. Zamowic to co ostatnio\n");
        printf ("4. Zamowic ulubiona pizze\n");
        printf ("5. Usunac swoje konto\n");
        printf ("6. Zmienic swoje haslo\n");
        printf ("7. Wrocic do menu\n");
        printf ("\n\n\n");
        unem=getch();
        switch (unem)
        {
           case '1':
           break;
           case '2':
           break;
           case '3':
           break;
           case '4':               
           break;
           case '5':
                tokoniec(mistrzu);
                return 0;
           break;
           case '6':
                zmieniamy(mistrzu);
           break;
           case '7':
                return 0;
           break;
        }
        printf("\n\n");
     }
     while(true);
}
