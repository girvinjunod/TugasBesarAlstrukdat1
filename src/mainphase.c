#include <stdio.h>
#include <stdlib.h>
#include "mainphase.h"
#include "prioqueuePengunjung.h"

void MinuteUpdate(){
    Sekarang = NextNDetik(Sekarang, 60);
    int Detik = JAMToDetik(Sekarang);
    //Tentang antrian, belum dirandom

    //Ngecek tiap wahana
    for(int i=0; i<nbWahana; i++){
        if(!IsEmptyQ(PQ[i])){
            while(Detik == Prio(InfoHeadQ(PQ[i]))){
                infotypeQ Q;
                Dequeue(&PQ[i], &Q);
                ServeWahana(&(Q.info), ID(ActiveWahana[i]));
                Q.prio = Q.info.kesabaran;
                Enqueue(&Antrian, Q);
            }
        }
    }
}

void SERVE(Kata K){
    boolean notfound = true;
    int i=-1;
    int Detik = JAMToDetik(Sekarang);
    while(i<nbWahana && notfound){
        i++;
        if(NbElmtQ(PQ[i])<Capacity(ActiveWahana[i]) && IsKataSama(Name(ActiveWahana[i]), K)){
            notfound = false;
        }
    }
    if(notfound){
        printf("Semua wahana dengan nama tersebut penuh/rusak/bahkan tidak ada\n");
    }else{
        infotypeQ Q;
        Dequeue(&Antrian, &Q);
        Q.prio = Duration(ActiveWahana[i])*60;
        Enqueue(&PQ[i], Q);
        for(int j=0; j<10; j++){
            MinuteUpdate();
        }
    }
}

void generateAntrian(){
    int BanyakAntrian = (rand() % 100) + 1;
    for(int i=0; i<BanyakAntrian; i++){
        Pengunjung P = generatePengunjung();
        infotypeQ Q;
        Q.info = P;
        Q.prio = P.kesabaran;
        Enqueue(&Antrian, Q);
    }
}