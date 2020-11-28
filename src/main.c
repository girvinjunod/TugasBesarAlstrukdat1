#include <stdio.h>
#include "boolean.h"
#include "tree.h"

int option;
boolean play;
Wahana activeWahana[100];
Tree DataWahana;

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
        Wahana W = CopyWahanaID(DataWahana, 1);
        PrintInfoWahana(W);
    }else{
        play = false;
        printf("// Thanks for playing!!! //");
    }
}

int main(){
    play = true;
    showMenu();
    while(play){

    }
}
