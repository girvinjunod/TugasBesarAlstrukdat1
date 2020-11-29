/* file material.h */

#ifndef MATERIAL_H
#define MATERIAL_H

#include "../listarray/listarray.h"
#include "../mesinkata/mesinkata.h"


#define Material TabInt

extern Material inventory;
extern Material shop;

void generateShop(Material *S);
void setInvenAwal(Material *I, Material S);
void printShop(Material S);
void printInven(Material I);
void updateInvenPlus(Material *I, const char X[], int jumlah);
void updateInvenMinus(Material *I, const char X[], int jumlah);

#endif
