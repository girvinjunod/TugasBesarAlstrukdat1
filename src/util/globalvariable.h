#ifndef globalvariable_H
#define globalvariable_H

#include "boolean.h"
#include "../graph/graph.c"
#include "../jam/jam.c"
#include "../listarray/listarray.c"
#include "../listlinier/listlinier.h"
#include "../main/mainphase.c"
#include "../map/map.c"
#include "../mesinkata/mesinkar.c"
#include "../mesinkata/mesinkata.c"
#include "../pengunjung/pengunjung.c"
#include "../point/point.c"
#include "../main/prepphase.c"
#include "../queue/prioqueuePengunjung.c"
#include "../stack/stack.c"
#include "../tree/tree.c"
#include "../wahana/wahana.c"

boolean play;
int nbWahana = 3;
Wahana ActiveWahana[100];
Tree DataWahana;
PrioQueuePengunjung PQ[100];
PrioQueuePengunjung Antrian;
Material Inventory, Shop;
JAM Sekarang;
int option;


#endif
