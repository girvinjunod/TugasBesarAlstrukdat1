/* include-inlude */
#include "../stack/stack.h"
#include "../material/material.h"
#include "../util/globalvariable.h"

/* global variable */
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

/* fungsi/prosedur yang ada di prepphase.c */
void PrepPhase(int day);
