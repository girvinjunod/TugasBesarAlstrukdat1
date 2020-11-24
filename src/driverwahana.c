#include <stdio.h>
#include "mesinkata.h"
#include "wahana.h"
#include "tree.h"

int main() {
    STARTKATA();
    int c = ToInt(CKata);
    ADVKATA();
    Wahana Dummy;
    ID(Dummy) = 0;
    Tree T = Alokasi(Dummy);
    while(!EndKata){
        MakeWahanaTree(&T, c);
    }
    address S = Search(T, 1);
    PrintChild(S);
    return 0;
}