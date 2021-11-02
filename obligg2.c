/**
*
* Dette programmet kan kan legge til/ vise alle baner samt avslutte programmet
* Dette gjøes med en switch
*
* @file obligg2.c
* @author Eskil Refsgaard, NTNU
*
*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

const int MAXBANER = 18; ///< Maks antall baner
const int STRLEN = 100; ///< Maks tekstlengde

/**
*   Hovedprogrammet starter
*/
int main() {

char baneBeskrivelse[MAXBANER][STRLEN]; //Todimensjonalarray for beskrivelse

int baneLengde[MAXBANER];               //Array for banelengde

int banePar[MAXBANER];                  //Array for par pr bane.

bool baneOB[MAXBANER];                  //Array for OB, true false

int antallBaner = 2, svarLengde, svarPar;
int i = 1;
char    svarOB,         //J/n for OB
        beskrivelse,    //Beskivelse som blir sent til todimensjonal array
        svar;           //Om koden skal kjøres


/**
HARDKODER                               //Verdier som skal gjelde før start.
*/

strcpy(baneBeskrivelse[0], "Denne var veldig morsom");
strcpy(baneBeskrivelse[1], "Kjeeeeedelig bane!");

baneLengde[0] = 59;
baneLengde[1] = 42;

banePar[0] = 4;
banePar[1] = 2;

baneOB[0] = false;
baneOB[1] = true;

//Skriver ut menyen for bruker
printf("Menyvalg:\n\tL - Legg til bane\n\tS - Se alle baner\n\tQ - Avslutt");
printf("\n\tValg: ");
scanf("%c", &svar); svar = toupper(svar);   //Gjør alle bokstaver store

while(svar != 'Q'){                         //Sjekker for Q
    switch (svar) {                         //Starter switchen
        case 'L':                           //Kjører for L
           if (antallBaner < MAXBANER){     //Sjekker om mindre enn MAXBANER

                printf("\nEr OB lovlig? (J/n): ");
                scanf(" %c", &svarOB);

            if(svarOB == 'j' || svarOB == 'J') //Sjekker for OB, setter bool.
                baneOB[antallBaner] = true;
            else
                baneOB[antallBaner] = false;

            do{                             //Skriver inn lengde, while(blah)
                printf("\nBanen kan være mellom 1 og 100 meter");
                printf("\nHvor lang er bane %i: ", antallBaner+1);
                scanf("%i", &svarLengde);
            }while(svarLengde > STRLEN || svarLengde < 0 );
                baneLengde[antallBaner] = svarLengde;

            do{                             //Skriver inn par, while(blah)
                printf("\nPar kan være mellom 2 og 8\n");
                printf("Hva er par for bane %i: ", antallBaner+1);
                scanf("%i", &svarPar);

            }while(svarPar > 8 || svarPar < 2);{
                banePar[antallBaner] = svarPar;
                };

            //Skriver inn helt linje, max 100 tegn (STRLEN)
            printf("\nSkriv inn en beskrivelse for bane %i: ", antallBaner+1);

            getchar();                          //Fjerner linjeskift
            fgets(baneBeskrivelse[antallBaner], STRLEN, stdin);

            antallBaner++;                      //Legger til 1 i antallBaner

        }else{

printf("Imponerende! Tar ganske lang tid å skrive inn %i baner ;)", MAXBANER);
            //exit(0); //Avslutter koden hvis ATTEN baner er skrevet inn.

        }break;                                 //Avslutter L blokken


            case 'S': for(i = 0; i < antallBaner; i++){
                                                //Skriver ut for antall baner
            printf("Bane %i.\n", i+1);

            printf("\tBanelengde: %5i\n", baneLengde[i]);       //Lengde
            printf("\tPar for bane: %3i\n", banePar[i]);        //Par
            printf("\tBeskrivelse: %s\n", baneBeskrivelse[i]);  //Beskrivelse

            if(baneOB[i] == 1)
                printf("\tBanen er med OB\n");  //Hvis true, skirver ut
            else
                printf("\tBanen er uten OB\n"); //Hvis false, skirver ut

            printf("\n\n");

        }break;                                 //Avslutter blokken.

        //Kjører default når ikke noen case starter
        default:    printf("\n\nUgyldig svar! Prov igjen!\n ");
                    scanf("%c", &svar); svar = toupper(svar);
                    printf("\n"); break;
        }

        //Skriver ut meny på nytt for bruker
        printf("\n");
        printf("Menyvalg:\n\tL - Legg til bane\n\tS - Se alle baner\n\tQ - Avslutt");
        printf("\n\tValg: ");
        scanf(" %c", &svar); svar = toupper(svar);

    }
    printf("Aufwidersehn!\n\n");            //Hilser til nestegang!

    return 0;
}
