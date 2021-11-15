/**
 *  Skjelett/grunnlag for oblig nr 4 i GrProg, hÃ¸sten 2021.
 *
 *  Det er mulig Ã¥:
 *     - legge inn nye produsenter
 *     - legge inn nytt produkt hos en produsent
 *     - skrive ALLE produsenter
 *     - skrive ALLE produkter hos/for EN produsent
 *     - skrive ALLE produkter
 *     - slette ALLE produsenter og deres produkter
 *
 *  @file    Oblig4.tpl
 *  @author  Martin Kristensen Eide,  Peter Behncke Nes  &  FrodeH
 */


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lesData4.h"     //   Ligger pÃ¥ emnets EKSEMPLER-katalog.


#define MAXPRODUSENTER  50      ///< Max antall produsenter
#define MAXPRODUKTER    20      ///< Max antall produkter hos hver produsent

const int MAXPRIS = 100000;     ///< Max pris


/**
 *  Produkt (med navn, beskrivelse, pris).
 */
struct Produkt {
    char  *navn, *beskrivelse;
    int   pris;
};


/**
 *  Produsent (med navn, by, antallprodukter, og array med produktene).
 */
struct Produsent {
    char   *navn, *by;
    int    antallProdukter;
    struct Produkt* produktene[MAXPRODUKTER];
};


struct Produkt* finnProdukt(const struct Produsent* produsent, const char* navn);       //done
struct Produsent* finnProdusent(const char* navn);                                      //done
void   fjernAllkokerteData();                                                           //
void   leggTilEttProdukt();                                                             //done
void   nyProdusent();                                                                   //done
void   produktLesData(struct Produkt* produkt, const char* navn);                       //done
void   produktSkrivData(const struct Produkt* produkt, const int tall);                 //done
void   produktSlettData(struct Produkt* produkt);                                       //
void   produsentLesData(struct Produsent* produsent, const char* navn);                 //done
void   produsentNyttProdukt(struct Produsent* produsent, const char* navn);             //done
void   produsentSkrivData(const struct Produsent* produsent);                           //done
void   produsentSlettData(struct Produsent* produsent);                                 //
void   skrivAbsoluttAlt();                                                              //
void   skrivMeny();                                                                     //done


struct Produsent* gProdusentene[MAXPRODUSENTER];    ///< Alle produsentene.
int gAntallProdusenter = 0;         ///< Antall produsenter registrert hittil.


/**
 *  Hovedprogrammet.
 */
int main() {
    char kommando;

    skrivMeny();
    kommando = lesKommando("\nKommando: ");

    while (kommando != 'Q')  {
        switch (kommando) {
            case 'N': nyProdusent();         break;
            case 'L': leggTilEttProdukt();   break;
            case 'A': skrivAbsoluttAlt();    break;
            default:  skrivMeny();           break;
        }
        kommando = lesKommando("\nKommando: ");

    };

    fjernAllkokerteData();

return 0;
}


/**
 *  Returnerer (om mulig) peker til et navngitt produkt hos en produsent.
 *
 *  @param    produsent  - Produsenten for produktet
 *  @param    navn       - Navnet til produktet
 *  @return   Peker til produktet eller NULL
 */
struct Produkt* finnProdukt(const struct Produsent* produsent, const char* navn) {

    if(produsent->antallProdukter > 0){
        for(int i = 0; i < produsent->antallProdukter; i++){
            if(!strcmp(navn, produsent->produktene[i]->navn)){
                return produsent->produktene[i];
        }else return NULL;
    } return NULL;
}
}


/**
 *  Returnerer (om mulig) peker til en navngitt produsent.
 *
 *  @param    navn   - Navnet til produsenten
 *  @return   Peker til produsenten eller NULL
 */
struct Produsent* finnProdusent(const char* navn) {
    //int tall;
    if(gAntallProdusenter > 0){
        
        for(int i = 0; i < gAntallProdusenter; i++){
            if(!strcmp(navn, gProdusentene[i]->navn)){
                return gProdusentene[i];
                
            }
        } return 0;
    } return 0;
}

/**
 *  Fjerner ALLE allokerte data fra minnet/memory.
 *
 *  @see   produsentSlettData(...)
 */
void fjernAllkokerteData() {

for(int i = 0; i < gAntallProdusenter; i++){
        
        produsentSlettData(gProdusentene[i]);   
        sjekk2();
        free(*gProdusentene);
    }
printf("\nAlle allokert data er fjernet\n");
}


/**
 *  Legger til (om mulig) ETT nytt produkt hos en produsent.
 *
 *  @see   finnProdusent(...)
 *  @see   finnProdukt(...)
 *  @see   produsentNyttProdukt(...)
 */
void leggTilEttProdukt()  {
char *navn;
    if(gAntallProdusenter > 0){

        navn = lagOgLesTekst("Hva heter dere: ");

        if(finnProdusent(navn)){

            produsentNyttProdukt(finnProdusent(navn), navn);

        }else printf("Denne produsenten finnes ikke");
    }else printf("Ingen produsenter har registrert seg enda");
}


/**
 *  Legger inn (om mulig) en ny produsent.
 *
 *  @see   finnProdusent(...)
 *  @see   produsentLesData(...)
 */
void nyProdusent()  {
    char *navn, *pStruct;

    if(gAntallProdusenter < MAXPRODUSENTER){

        navn = lagOgLesTekst("Hva heter dere");
        if(!finnProdusent(navn)){
            
            gProdusentene[gAntallProdusenter] = (struct Produsent*) malloc(sizeof(struct Produsent));
            produsentLesData(gProdusentene[gAntallProdusenter], navn);
            gAntallProdusenter++;
        
        }else
            printf("Denne produsenten eksiterer allerde!");
    }
}


/**
 *  Leser inn ALLE dataene om ETT produkt.
 *
 *  @param   produkt  - Produktet som fÃ¥r sine data lest inn
 *  @param   navn     - Hittil innlest produktnavn
 */
void produktLesData(struct Produkt* produkt, const char* navn){


    produkt->navn = navn;
    produkt->pris = lesTall("Hvor mye koster produktet", 1, 10000);
    produkt->beskrivelse = lagOgLesTekst("Skriv noen fine ord om produktet");

    //printf("Navn: %s\nPris: %i\nBeskrivelse: %s", produkt->navn, produkt->pris, produkt->beskrivelse);
}


/**
 *  Skriver ALLE et produkts data pÃ¥ skjermen.
 *
 *  @param   produkt  - Produktet hvis alle data skrives ut.
 */
void produktSkrivData(const struct Produkt* produkt, const int tall) {

    printf("\n\tProdukt %i: %s\n\tPris: %i\n\tBeskrivelse: %s\n", tall, produkt->navn, produkt->pris
                                                           , produkt->beskrivelse); 

}


/**
 *  Sletter ALLE et produkts allokerte data fra minnet.
 *
 *  @param   produkt  - Produktet som fÃ¥r slettet sine allokerte data
 */
void produktSlettData(struct Produkt* produkt) {

    free(produkt->navn);
    free(produkt->beskrivelse);

}


/**
 *  Leser inn en produsents data, inkl initielle produkter.
 *
 *  @param   produsent  - Produsenten som det leses inn data til
 *  @param   navn       - Navnet til produsenten
 *  @see     finnProdukt(...)
 *  @see     produsentNyttProdukt(...)
 */
void produsentLesData(struct Produsent* produsent, const char* navn){
 
    //produsent->navn = (char*) malloc(100 * sizeof(char));
    //produsent->by = (char*) malloc(100 * sizeof(char));

    produsent->navn = navn;
    produsent->by = lagOgLesTekst("Hvilken by holder dere til i");
    produsent->antallProdukter = 0;

}


/**
 *  Legger enn ETT nytt produkt hos en produsent.
 *
 *  @param   produsent  -  Produsenten Ã¥ legge inn nytt produkt hos
 *  @param   navn       -  Nytt produkts navn
 *  @see     produktLesData(...)
 */
void produsentNyttProdukt(struct Produsent* produsent, const char* navn)  {
    char *produktN;
    printf("Hei, %s", navn);
    if(gAntallProdusenter > 0){

        produktN = lagOgLesTekst("\nHva heter produktet deres: ");

        if(!finnProdukt(produsent, produktN)){

            produsent->produktene[produsent->antallProdukter] = (struct Produkt*) malloc(sizeof(struct Produkt));

            produktLesData(produsent->produktene[produsent->antallProdukter], produktN);
            produsent->antallProdukter++;
            printf("\n\ngjennom alt\n\n");
        }else
            printf("Dette produktet finnes allerede!");
    }
}


/**
 *  Skriver ALLE en produsents data ut pÃ¥ skjermen.
 *
 *  @param    produsent  - Produsenten hvis alle data skrives ut.
 *  @see      produktSkrivData(...)
 */
void produsentSkrivData(const struct Produsent* produsent) {

    printf("Navn: %s\nBy: %s\nProdukter: %i\n", produsent->navn, produsent->by, produsent->antallProdukter);

}


/**
 *  Sletter ALLE en produsents allokerte data fra minnet.
 *
 *  @param   produsent  - Produsenten som fÃ¥r slettet sine allokerte data
 *  @see     produktSlettData(...)
 */
void produsentSlettData(struct Produsent* produsent) {

    

    for(int i = 0; i < produsent->antallProdukter; i++){
        produktSlettData(produsent->produktene[i]);
    }

    free(produsent->navn);
    free(produsent->by);
    free(*produsent->produktene);
}


/**
 *  Skriver alt om alle produsenter.
 *
 *  @see   produsentSkrivData(...)
 */
void skrivAbsoluttAlt()  {
    if(gAntallProdusenter > 0){
        printf("\nHerman er feit <3:\n");

        for(int i = 0; i < gAntallProdusenter; i++){

            produsentSkrivData(gProdusentene[i]);

            if(gProdusentene[i]->antallProdukter > 0){
                
                for(int j = 0; j < gProdusentene[i]->antallProdukter; j++)

                    produktSkrivData(gProdusentene[i]->produktene[j], j+1);
                    printf("\n"); //For the good looking program
            }
        }
    }else printf("Det finnes ingen data registrert");
}

/**ls
 * 
 *  Skriver alle kommandoene tilgjengelig i programmet.
 */
void skrivMeny() {
  printf("\nProgrammets kommandoer:");
  printf("\n\tN - Ny  produsent (og produkter)");
  printf("\n\tL - Legg til ett produkt hos en produsent");
  printf("\n\tA - skriv Alle produsenter og alle deres produkter");
  printf("\n\tQ - Quit/avslutt\n");
}