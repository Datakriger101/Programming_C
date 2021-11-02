/**

*Kode input og output for 2 b�ker, antall sider og sjangere for hver bok mm.

*I denne oppgaven har jeg brukt ulike kommandoer for � kunne skrive inn
*informasjon og deretter skrive det ut i konsollen. Det lagres ogs� verdier
*i arrayer underveies i koden, som senere blir brukt for � skirve ut info.
*M�ten jeg setter op koden p� er � f�rst ta input for begge b�kene for s� �
*skrive dem ut i andre del. Dette skaper orden og gj�r koden lettere � lses.

*@file obligg1
*@date 09.10.21
*@version 1
*@auther Eskil Refsgaard

*/

#include <stdio.h>

const STRLEN = 30;
//Dette er en konstant. Dette er satt utenfor main() slik at det skal gjelde
//for alt som skjer videre.

int main()

{

char    bok1[STRLEN][25], //Definerer bok1 som en array, inneholder navn bok1
        bok2[STRLEN][25], //Definerer bok2 som en array, inneholder navn bok2

        //Inneholder sjangere for begge b�ker. sjanger[0] for bok1, og
        //sjanger[1] for bok2
        sjanger[STRLEN][25];

        //array for antall sider. Inneholder 2 elementer [0] og [1]
int     antall_sider[STRLEN],
        x = 0, //variabel for hvor mange b�ker som er lest, legges automatisk
        //til n�r en bok er lest inn.

        sider_lest; // Variabel for antall sider, summeres sammen til slutt.

printf("Bok 1: ");
x++; // Denne llegger til "1" til x vaiabelen. Dette gj�res etter bok1 og bok2
//har f�tt en en verdi i arrayen.

printf("\n\nHva heter boken:" );
scanf("%s", &bok1[0]);
//Skriver inn f�rste verdi i bok1 array. Den blir
//Lagret i f�rste element bok1[0].

/*
En annen array er int antallsider[], hvor antall sider for begge b�kene
blir lagret. antallsider[0] og antallsider[1] blir senere brukt til � finne
finne ut hvor mange sider som totalt har blit lest i sider_lest.
*/
printf("\nHvor mange sider har boken: ");
scanf("%i", &antall_sider[0]);

//Det er en sjanger array som inneholder totalt 2 sjangere i index 0 og 1.
//For bok1 legges sjangeren i (boks) 0 og bok2 (boks) 1.
printf("\nHvilken sjanger har boken?");
printf("\nSjanger (B - Biografi, F - Fiksjon, T - Thriller): ");
scanf("%s", &sjanger[0]);

/// Samme opplegget for bok2

printf("\n\nBok 2: \n");
x++;
printf("Hva heter boken: ");
getchar();
gets(bok2);
printf("\nHvor mange sider har boken: ");
scanf("%i", &antall_sider[1]);
printf("\nHvilken sjanger har boken: ");
printf("\nSjanger (B - Biografi, F - Fiksjon, T - Thriller): ");
scanf("%s", sjanger[1]);


printf("------------------------"); //Linje som skiller input og output.

printf("\nBok 1");

printf("\n\tNavn pa bok: \b%s", bok1[0]); //skriver ut bok[0] verdi
printf("\n\tAntall sider: %i", antall_sider[0]); //skrver ut antall_sider[0]
printf("\n\tBoken er av sjanger: %s\n\n", sjanger[0]);
//skriver ut sjanger[0]

///Sammme for bok2

printf("Bok 2");

printf("\n\tNavn pa bok: \b%s", bok2[0]);
printf("\n\tAntall sider: %i", antall_sider[1]);
printf("\n\tBoken er av sjangeren: %s", sjanger[1]);

printf("\n\nBok 1: %s\nSjanger: %s", bok1[0], sjanger[0]);
//Skriver ut bok1[0] og sjanger[0]

printf("\n\n\nBok2 2: %s\nSjanger: %s", bok2[0], sjanger[1]);
//Skriver ut bok2[0] og sjanger[1]

sider_lest = antall_sider[0] + antall_sider[1];
//legger sammen verdiene til arrayen antallsider[0] og antallsider[1], og
//legger den nye verdien i sider_lest, som senere blir sjrevet ut.

printf("\n\nBoker lest: %i\nSider lest totalt: %i\n", x, sider_lest);
//Til slutt skrives ut sider_lest som er verdien av antall_sider[0] og [1]

//S�kte opp om det er mulig � skrive ut (bold) teksten i konsollen
//Stod at det ikke fungerte.

return 0;


}
