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
    Tree T = AlokasiTree(Dummy);
    while(!EndKata){
        MakeWahanaTree(&T, c);
    }
    addrNode S = SearchTree(T, 4);
    PrintHistory(S);
    return 0;
}