//driver tree#include "globalvariable.h"
#include "../util/boolean.h"
#include "../util/globalvariable.h"

boolean play;
int nbWahana = 3;
Wahana ActiveWahana[100];
Tree DataWahana;
PrioQueuePengunjung PQ[100];
PrioQueuePengunjung Antrian;
Material Inventory, Shop;
JAM Sekarang;
int option;
Graph GraphMap;
char* NamaPlayer;
int DuitPlayer;


int main(){
    Tree T;
    printf("CreateTreeEmpty(&T);\n");
    CreateTreeEmpty(&T);
    printf("IsTreeEmpty(T) = %d\n",IsTreeEmpty(T));
    printf("IsTreeOneElmt(T) = %d\n",IsTreeOneElmt(T));
    Wahana W;
    printf("ID(W) = ");scanf("%d",&ID(W));
    printf("T = AlokasiTree(W);\n");
    T = AlokasiTree(W);

    PrintHistory(T);
    return 0;
}