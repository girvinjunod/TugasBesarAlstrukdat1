#ifndef globalvariable_H
#define globalvariable_H

#include "boolean.h"
#include "../graph/graph.h"
#include "../jam/jam.h"
#include "../listarray/listarray.h"
#include "../listlinier/listlinier.h"
#include "../main/mainphase.h"
#include "../map/map.h"
//#include "matriks.h"
#include "../mesinkata/mesinkar.h"
#include "../mesinkata/mesinkata.h"
#include "../pengunjung/pengunjung.h"
#include "../point/point.h"
#include "../main/prepphase.h"
#include "../queue/prioqueuePengunjung.h"
#include "../stack/stack.h"
#include "../tree/tree.h"
#include "../wahana/wahana.h"

boolean play;
int nbWahana = 3;
Wahana ActiveWahana[100];
Tree DataWahana;
PrioQueuePengunjung PQ[100];
PrioQueuePengunjung Antrian;
JAM Sekarang;
int option;


#endif
