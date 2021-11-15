/**
 * Dette er Eskil sin toolbox. Det er her alle hans fabelaktige 
 * funksjoner venter i spenning for å blir brukt. De er alle feilfrie
 * og ekstremt godt laget
 * 
 * @file lesData4.c
 * @file Eskil Refsgaard, NTNU Gjøvik
 */

#include <ctype.h>              //  toupper
#include <stdio.h>              //  printf, scanf
#include <stdlib.h>             //  sizeof, malloc
#include <string.h>             //  strlen, strcpy

#define STRLEN 50

void lesText(const char *t, char *tekst, const int antall);
char lesKommando(const char *ledetekst);
int lesTall(const char *ledetekst, const int min, const int max);

char *lagOgLesTekst(const char *t);
void sjekk();

char *lagOgLesTekst(const char* t)  {
   char buffer[50];               //  Hjelpebuffer til � lese teksten.
   char* temp;                     //  Returnerende innlest tekst.

   lesText(t, buffer, 50);        //  Leser teksten.
                                   //  Allokerer EKSAKT NOK plass til teksten:
   temp = (char*) malloc((strlen(buffer)+1) * sizeof(char));
   

   if (temp)  {                    //  Allokeringen lyktes:
      strcpy(temp, buffer);        //  Kopierer inn teksten.
      return temp;                 //  Returnerer opprettet og fylt tekst.
   } else  {                       //  Allokeringen mislyktes.
      printf("ERROR 404! Feil i memorylokalisering\n");
      return NULL;
   }
}

//forkaring kommer siden
void lesText(const char* t, char* tekst, const int len)  {
  printf("%s: ", t);
  fgets(tekst, len, stdin); // Oppdaterer tilpekte char'er (derfor ORIGINALEN)
  tekst[strlen(tekst)-1] = '\0';  //  Tar vekk avsluttende innlest '\n'.
}

char lesKommando(const char *ledetekst){
char tegn;
    printf("%s", ledetekst); scanf("%c", &tegn); getchar();
    return toupper(tegn);
}

int lesTall(const char *ledetekst, const int min, const int max){
    int tall;
    do{
        printf("%s (%i-%i): ", ledetekst, min, max); scanf("%i", &tall); getchar();
    }while(tall < min || tall > max);
        return tall;
}

void sjekk1(){
    printf("\nsjekk1\n");
}
void sjekk2(){
    printf("\nsjekk2\n");
}

//Solo runner lesTekst
/*
char lesTekst(const char *ledetekst){
char *tekst;
    printf("%s", ledetekst); gets(tekst);
    return tekst;
}
*/
