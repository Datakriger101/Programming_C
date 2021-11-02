/**
 *  Skjelett/grunnlag for oblig nr 3 i GrProg, høsten 2021.
 *
 * @file    Oblig3.tpl
 * @author  Malin Foss, William Eide Seiner & FrodeH
 */


#include <stdio.h>          //  printf, scanf
#include <stdbool.h>        //  bool
#include <ctype.h>          //  toupper


#define  ANTRUTER    9      ///<  Antall ruter på brettet
const int STRLEN  = 80;     ///<  Tekstlengde

void nullstillBrett();              //Funksjon for å nullstille brettet
bool sjekkBrett(const int pos);     //Sjekker om posisjon er opptatt
bool sjekkVinner();                 //Sjekker om en spiller har vunnet
void skrivBrett();                  //Skriver ut brettet, med innskrevne bokstav
int  spillSpillet();                //Bruker ^^ for å spillet
//char svarKommando();

char gBrett[ANTRUTER];     ///<  Spillebrettet.

/**
 * Hovedprogrammet.
 */
int main() {
    char spillere[2][STRLEN];          //  Begge spillernes navn.

    char nyttSpill;                  // Kjøre programmet/spillet EN gang til.
	int  vinner;                    // Evt. spillernummer som har vunnet.
	char spill_tegn;               // Startet spillet eller avslutter

	printf("Vil du spille en runde? (J/n): "); scanf("%c", &spill_tegn);
    getchar; spill_tegn = toupper(spill_tegn);

    if(spill_tegn == 'J') //Spør om bruker ønsker å starte spiller :)
        printf("Lykke til mine snupper ;)\n\n");
    else{
        printf("See u later <3"); exit(0);} getchar();

do  {

    nullstillBrett();   //Nullstiller og gjør klar for ny runde

    skrivBrett();       //Skirver ut eksistrende brett

    //Skriver inn spillere
    printf("\n\nNavn på spiller 1:  "); gets(spillere[0]);
    printf("Navn på spiller 2:  ");     gets(spillere[1]);
    printf("\n");

    //Tester spillere
    printf("Spiller. 1: %s\nSpiller. 2: %s\n\n", spillere[0], spillere[1]);
    vinner = spillSpillet(); //Bruker spillspillet() for å avgjøre vinner



    //Sjekker hvem som har vunnet og skriver ut spilleren.
    if      (vinner == 1) printf("\nGratulerer %s!!\n\n", spillere[0]);
    else if (vinner == 2) printf("\nGratulerer %s!!\n\n", spillere[1]);
            //  'vinner' == 0:
    else    printf("\nIngen vinner denne gangen dessverre.\n\n");

    //Spør bruker om de vil spille en ny runde
    printf("\n\nEn ny runde (N/j):  ");
    scanf(" %c", &nyttSpill);  nyttSpill = toupper(nyttSpill);
    getchar();

    }  while (nyttSpill == 'J');

    return 0;
}


/**
 *  Nullstiller/blanker ut alle brettets ruter.
 */
void nullstillBrett() {
int i;
for(i = 0; i < 10; i++){ //for-loop som setter alle plasser til blank (' ')
gBrett[i] = ' ';
    }
}


/**
 *  Finner ut om et trekk er gyldig eller ei.
 *
 *  @param    n - Ruten (0-8) det forsøkes å sette en brikke i
 *  @return	  Om det var mulig å sette brikken der (true) eller ei (false)
 */
bool sjekkBrett(const int pos) { // Sjekker om pos er gyldig

    if(gBrett[pos] == ' ') //Er plassen ledig?
        return true;
    else
        return false;
}

/**
 *  Sjekker om noen har tre på rad i en eller annen retning.
 *
 *  @return   Om noen har tre på rad (true) eller ei (false) i noen retning
 */
bool sjekkVinner() {
int i;
char tegn;

//Sjekker brett vannrett
for(i = 0; i < 7; i+=3){
if(gBrett[i] != ' ' && gBrett[i+1] == gBrett[i] && gBrett[i+2] == gBrett[i+1]){
    return true;}
}

//Sjekker brett loddrett
for(i = 0; i < 3; i++){
if(tegn != ' ' && gBrett[i+3] == tegn && gBrett[i+6] == tegn){
    return true;}
}

//Sjekker på tvers 0-4-8
if(gBrett[0] != ' ' && gBrett[4] == gBrett[0] && gBrett[8] == gBrett[0]){
    return true;
}

//Sjekker på tvers 2-4-6
if(gBrett[2] != ' ' && gBrett[4] == gBrett[2] && gBrett[6] == gBrett[2]){
    return true;
}
    return false;
}

/**
 *  Skriver ut spillebrettet.
 */
void skrivBrett() {

printf("\n\n"
       " ---1-----2-----3---    \n "
       " |  %c |   %c  |  %c |  \n "
       " ---4-----5-----6---    \n "
       " |  %c  |  %c  |  %c |  \n "
       " ---7-----8-----9---    \n "
       " |  %c  |  %c  |  %c |  \n "
       " -------------------", gBrett[0], gBrett[1], gBrett[2], gBrett[3],
       gBrett[4], gBrett[5], gBrett[6], gBrett[7], gBrett[8]);
}


/**
 *  Lar spillerne sette brikker, og finner evt en vinner.
 *
 *  @return   Spillernummeret som har vunnet (1, 2), evt. 0 (ingen vinner)
 *  @see      sjekkBrett(...)
 *  @see      skrivBrett(...)
 *  @see      sjekkVinner(...)
 */
int spillSpillet() {
bool sjekk, vinn = false;
int i, runder = 0;  //Teller antall runder spillt
int player = 0,    /*For å avgjøre spiller*/ pos; /*Avgjøre posisjon*/

    do{
        do{
            printf("\n");
            printf("Brikker plassert: %i", runder);
            printf("\nSpiller: %i\n", player+1);
            printf("Velg en posisjon (1-9): "); scanf("%i", &pos);

    }while(pos < 1 || pos > 9);     // Max 9 trekk tillatt

        sjekk = sjekkBrett(pos-1);  //Sender med posisjon, sjekker om ledig

        if(sjekk == true){
            runder++;                   //Legger til runder spillt
            player = player % 2;
            if(player % 2 == 0){        //Avgjør spiller
                gBrett[pos-1] = 'X';    //Spiller 1
            }else{
                gBrett[pos-1] = 'O';}   //Spiller 2
            player++;
        }else
            printf("Plassen er opptatt!");

            skrivBrett(); //Skriver ut nåværende brett

            if(sjekkVinner()){
                if(player == 1){//Spiller 1 vant
                    return 1;   //Spiller 1 har 3 på rad
                }else{          //Spiller 2 vant ikke
                    return 2;   //Spiller 2 har 3 på rad
                }
            }else{}

    }while(runder < 9);
}
