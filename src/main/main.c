#include <stdio.h>
#include <string.h>
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
char NamaPlayer[40];
int DuitPlayer;

void LoadWahanaTree(){
    STARTKATAFILE("../wahana/wahana.txt");
    int c = ToInt(CKata);
    ADVKATA();
    Wahana Dummy;
    ID(Dummy) = 0;
    DataWahana = AlokasiTree(Dummy);
    MakeWahanaTree(&DataWahana, c);
}

void LoadWahana(){
    nbWahana = 0;
    int i;
    for(i=0; i<12; i++){
        printf("test\n");
        ActiveWahana[i] = CopyWahanaID(DataWahana, i+1);
        printf("test2\n");
        PosX(ActiveWahana[i]) = 0;
        printf("test3\n");
        PosY(ActiveWahana[i]) = 0;
        printf("test4\n");
        TotalRide(ActiveWahana[i]) = 0;
        printf("test5\n");
        TotalGold(ActiveWahana[i]) = 0;
        printf("test6\n");
        DayRide(ActiveWahana[i]) = 0;
        printf("test7\n");
        DayGold(ActiveWahana[i]) = 0;
        printf("test8\n");
        MakeEmptyQ(&PQ[i], 100);
        nbWahana++;
    }
}

void InitGame(){
    printf("Masukkan nama pemain:\n$ ");
    STARTKATAKEYBOARD();
    strcpy(NamaPlayer,CKata.TabKata);
    /* printf("udah input nama\n"); */
    LoadWahanaTree();
    /* printf("udah load tree wahana\n"); */
    LoadWahana();
    /* printf("udah init active wahana\n"); */
    CreateGraphMap(&GraphMap);
    /* printf("udah load map\n"); */
    STARTKATAFILE("../material/material.txt");
    generateShop(&Shop);
    /* printf("udah load shop\n"); */
    DuitPlayer = 10000;
    setInvenAwal(&Inventory,Shop);
}

void showMenu(){
    printf("// Welcome to Willy wangky's fun factory!!//\n");
    printf("// New game / load game / exit? //\n");
    scanf("%d", &option);
    if(option == 1){
        InitGame();
    }else if(option == 2){

    }else{
        play = false;
        printf("// Thanks for playing!!! //");
    }
}

int main(){
    play = true;
    int day = 1;
    showMenu();
    while(play){
        PrepPhase(day);
        MainPhase(day);
        day++;
    }
    return 0;
}
