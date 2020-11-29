#ifndef globalvariable_H
#define globalvariable_H

#include "boolean.h"
#include "../graph/graph.h"
#include "../jam/jam.h"
#include "../listarray/listarray.h"
#include "../listlinier/listlinier.h"
#include "../main/mainphase.h"
#include "../map/map.h"
#include "../mesinkata/mesinkar.h"
#include "../mesinkata/mesinkata.h"
#include "../pengunjung/pengunjung.h"
#include "../point/point.h"
#include "../main/prepphase.h"
#include "../queue/prioqueuePengunjung.h"
#include "../stack/stack.h"
#include "../tree/tree.h"
#include "../wahana/wahana.h"
#include "../material/material.h"
extern boolean play;
extern int nbWahana;
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
