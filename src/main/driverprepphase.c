#include <stdio.h>
#include "../util/globalvariable.h"

boolean play;
int nbWahana = 3;
Wahana ActiveWahana[100];
Tree DataWahana;
PrioQueuePengunjung PQ[100];
PrioQueuePengunjung Antrian;
Material Inventory, Shop;
JAM Sekarang;
int option;
Graph GraphMap;
char* NamaPlayer;
int DuitPlayer;

void LoadWahanaTree(){
    int c = ToInt(CKata);
    ADVKATA();
    Wahana Dummy;
    ID(Dummy) = 0;
	DataWahana = AlokasiTree(Dummy);
    while(!EndKata){
        MakeWahanaTree(&DataWahana, c);
    }
}

void LoadWahana(){
    nbWahana = 0;
    int i;
    for(i=0; i<12; i++){
        ActiveWahana[i] = CopyWahanaID(DataWahana, i+1);
        PosX(ActiveWahana[i]) = 0;
        PosY(ActiveWahana[i]) = 0;
        TotalRide(ActiveWahana[i]) = 0;
        TotalGold(ActiveWahana[i]) = 0;
        DayRide(ActiveWahana[i]) = 0;
        DayGold(ActiveWahana[i]) = 0;
        MakeEmptyQ(&PQ[i], 100);
        nbWahana++;
    }
}

void showMenu(){
    printf("// Welcome to Willy wangky's fun factory!!//\n");
    printf("// New game / load game / exit? //\n");
    STARTKATAKEYBOARD();
    int option = ToInt(CKata);
    ADVKATA();
    if(option == 1){
        
    }else if(option == 2){
        LoadWahanaTree();
        LoadWahana();
    }else{
        play = false;
        printf("// Thanks for playing!!! //");
    }
}

int main(){
    play = true;
    showMenu();
    while(play){
    	PrepPhase(1);
    }
    return 0;
}
