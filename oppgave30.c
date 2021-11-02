/**
*
* Dette er en lang oppgave som likner ganske mye auf en obligg. Kan tenkes litt
* er en obligg 3.5. Bruker mye tid auf denne slik at jeg blir bedre i prog.
* Keep it Norwegian in the chat!
*
* NB: Jeg gjør om litt på oppgaven slik at kuden nå også må skrive inn en kode
* når dem skal levere tilbake trallen.
*
* @file oppgave30.c
* @auther Eskil Refsgaard NTNU, 20 kvm
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


struct Tralle {
  bool  utlaant;
  char  navn [80];
  int   tlfNr;
  int   kode;
};

struct Tralle gTraller[30]; //Array av Tralle-structer
int gAntallUtlaant = 0;     //Antall traller som pt- er utlånt
const int MAXTRALLER = 30;  ///< Max. antall traller til utlån

/**
* Hardkoder for testing
*/

char  lesKommando();
void  setFalseTraller();
void  ledigeTraller();
void  leiTralle();
void  lesNavn(const char ledetekst[], char tekst[]);
int   lesNummer();
void  innlevering();
void  skrivMeny();
void  finnLaaner();

int main(){
char kommando;
  setFalseTraller();
/*
  gTraller[5].utlaant = true;
  gTraller[5].navn = "Eskil Refsgaard";
  gTraller[5].tlfNr = 12345678;
  gTraller[5].kode = 123;
*/
kommando = lesKommando();

while(kommando != 'Q'){
  switch(kommando){
    case 'L': ledigeTraller(); break;
    case 'U': leiTralle(1, 30); break;
    case 'I': innlevering(); break;
    case 'F': finnLaaner(); break;
    default: skrivMeny(); break;
    }
    kommando = lesKommando();
  }
}

char lesKommando(){
char tegn;
  printf("\nType a command: "), scanf("%c", &tegn); getchar();
  return toupper(tegn);
}

void skrivMeny(){
  printf("(L) ledigeTraller\n");
  printf("(U) Lei en tralle\n");
  printf("(I) Lever tilbake tralle\n");
  printf("( ) ...");
}

void finnLaaner(){
char  tekst[20];
int   tralleNr, sjekk;
  if(gAntallUtlaant > 0){
    printf("Hva heter du: "); gets(tekst);
    for(int i = 0; i < MAXTRALLER; i++){
      sjekk = strcmp(tekst, gTraller[i].navn);
      if(sjekk == 0){
        tralleNr = i+1;
      }else{}
    }
      if(tralleNr > 0){
          printf("\nTralle nr: %i\nTralle i navnet: %s\n", tralleNr, tekst);
      }else
        printf("Det finnes ingen traller i dette navnet");
    }else
      printf("Ingen traller er utlaant enda!");
  }


void setFalseTraller(){
int i;
  for(i = 0; i < MAXTRALLER; i++){
    gTraller[i].utlaant = false;
  }
}

void ledigeTraller(){
int i; bool n; //Hjelpevariabeler
printf("\nTralle nr: \t Informasjon:\n\n");
  for(i = 0; i < MAXTRALLER; i++){
  n = gTraller[i].utlaant;
    printf("  Nr: %2i", i+1);
    if(n == true)
      printf("%20s\n", "Ikke ledig");
    else
      printf("%18s\n", "Ledig");
  }
}

void leiTralle(const int min, const int max){
if(gAntallUtlaant < MAXTRALLER){
int tralle; bool n; //Hjelpevariabeler
  printf("Disse trallene er tilgjengelig ATM");
  ledigeTraller();
  do{
    printf("Hvilken vil du bruke: ");
    scanf("%i", &tralle); getchar();
    n = gTraller[tralle-1].utlaant;
    if(n == true)
      printf("Denne er opptatt, velg en annen");
    else{};
  }while(n == true || tralle < min || tralle > max);
  gTraller[tralle-1].utlaant = true;
  lesNavn("Hva heter du?", gTraller[tralle-1].navn);
  gTraller[tralle-1].tlfNr = lesNummer("Telefon nummer");
  gTraller[tralle-1].kode = lesNummer("Lag en hemmelig kode");
  gAntallUtlaant++;
}else
  printf("Alle trallene er leid ut");
}

void lesNavn(const char ledetekst[], char tekst[]){
  printf("%s ", ledetekst); gets(tekst);
}
int lesNummer(const char ledetekst[]){
int nummer;
printf("%s: ", ledetekst); scanf("%i", &nummer); getchar();
  return nummer;
}

void innlevering(){
char  svar;
int   kode, tralleNr;
  printf("Vil du levere tilbake trallen: (J/n)"); svar = lesKommando();
  if(svar == 'J'){
    tralleNr = lesNummer("Hvilken tralle hadde du: ");
    if(gTraller[tralleNr-1].utlaant == true){
      do{
      kode = lesNummer("Hva er koden din: ");
        if(kode == gTraller[tralleNr-1].kode){
          gTraller[tralleNr-1].utlaant = false;
          gAntallUtlaant--;
          printf("Supert, Ha en god dag videre %s", gTraller[tralleNr-1].navn);
        }else
          printf("Koden er feil");
      }while(gTraller[tralleNr-1].kode != kode);
    }else
      printf("Denne trallen er ikke i bruk");
  }
}
