#include <stdio.h>

char wybor;

main ()
{
  printf ("Wybierz coś\n");
  scanf ("%d",wybor);
  switch (wybor)
  case "a":
    
       printf ("wybrales a\n");
       
     break;
    
 case "b":
       
       printf ("no już nie miałeś czego wybrać");
     break;
       
 case "c":
       
       printf ("to chybanajlepszy wybór");
     break;
       
     default:
       
       printf ("hahaha ale jesteś śmieszny");
     break;
       

     return 0;
}
