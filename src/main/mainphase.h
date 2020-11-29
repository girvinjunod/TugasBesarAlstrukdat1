/* include-inlude */
#include "../jam/jam.h"
#include "../tree/tree.h"
#include "../queue/prioqueuePengunjung.h"

/* variabel yang harusnya ada di main.c */
extern int nbWahana;
extern Wahana ActiveWahana[100];
extern PrioQueuePengunjung PQ[100];
extern PrioQueuePengunjung Antrian;
extern JAM Sekarang;

/* fungsi/prosedur yang ada di prepphase.c */
void MinuteUpdate();
void SERVE(Kata K);
void generateAntrian();
