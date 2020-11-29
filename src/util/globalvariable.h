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

extern boolean play;
extern int nbWahana = 3;
extern Wahana ActiveWahana[100];
extern Tree DataWahana;
extern PrioQueuePengunjung PQ[100];
extern PrioQueuePengunjung Antrian;
extern Material Inventory, Shop;
extern JAM Sekarang;
extern int option;
extern Graph GraphMap;
extern char* NamaPlayer;
extern int DuitPlayer;

#endif
