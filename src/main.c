#include <stdio.h>
#include "boolean.h"
#include "stack.h"
#include "map.h"

char option[];
Map map;
boolean play;

void showMenu(){
    printf("// Welcome to Willy wangky's fun factory!!//");
    printf("// New game / load game / exit? //");
    scanf("%s", option);
    if(option == "new"){
        map.init();
    }else if(option == "load"){
        map.load();
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
