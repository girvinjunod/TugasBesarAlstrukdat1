#include <stdio.h>
#include "boolean.h"
#include "tree.h"
#include "prioqueuePengunjung.h"
#include "jam.h"
#include "mainphase.h"

int option;
boolean play;
int nbWahana;
Wahana ActiveWahana[100];
Tree DataWahana;
PrioQueuePengunjung PQ[100];
PrioQueuePengunjung Antrian;
JAM Sekarang;

void showMenu(){
    printf("// Welcome to Willy wangky's fun factory!!//\n");
    printf("// New game / load game / exit? //\n");
    scanf("%d", &option);
    printf("\n", option);
    if(option == 1){
        
    }else if(option == 2){
        STARTKATA();
        int c = ToInt(CKata);
        ADVKATA();
        Wahana Dummy;
        ID(Dummy) = 0;
        DataWahana = AlokasiTree(Dummy);
        while(!EndKata){
            MakeWahanaTree(&DataWahana, c);
        }
        for(int i=0; i<12; i++){
            ActiveWahana[i] = CopyWahanaID(DataWahana, i+1);
            MakeEmptyQ(&PQ[i], 100);
            nbWahana++;
        }
    }else{
        play = false;
        printf("// Thanks for playing!!! //");
    }
}

int main(){
    play = true;
    nbWahana = 0;
    showMenu();
    while(play){
        Sekarang = DetikToJAM(32400);
        MakeEmptyQ(&Antrian, 100);
        generateAntrian();
        PrintPrioQueuePengunjung(Antrian);
        play = false;
    }
}
