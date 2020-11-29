#include "material.h"
#include <stdio.h>

Material inventory;
Material shop;

int main(){
    STARTKATAKEYBOARD();
    MakeEmpty(&shop);
    MakeEmpty(&inventory);
    generateShop(&shop);
    setInvenAwal(&inventory, shop);
    printShop(shop);
    printInven(inventory);
    return 0;
}