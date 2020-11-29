#include <stdio.h>
#include <stdlib.h>
#include "../main/mainphase.h"
#include "../queue/prioqueuePengunjung.h"

void MinuteUpdate(){
    Sekarang = NextNDetik(Sekarang, 60);
    int Detik = JAMToDetik(Sekarang);
    //Tentang antrian, belum dirandom

    //Ngecek tiap wahana
    int i;
    for(i=0; i<nbWahana; i++){
        if(!IsEmptyQ(PQ[i])){
            while(Detik == Prio(InfoHeadQ(PQ[i]))){
                infotypeQ Q;
                Dequeue(&PQ[i], &Q);
                ServeWahana(&(Q.info), i);
                Q.prio = Q.info.kesabaran;
                Enqueue(&Antrian, Q);
                //Update Laporan Wahana
                TotalGold(ActiveWahana[i]) += Price(ActiveWahana[i]);
                TotalRide(ActiveWahana[i])++;
                DayGold(ActiveWahana[i]) += Price(ActiveWahana[i]);
                DayRide(ActiveWahana[i])++;
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
        boolean foundonlist = false;
        int j;
        for(j=0; j<Q.info.nbListWahana; j++){
            if(Q.info.wahana[j] == i && !Q.info.done[j]){
                foundonlist = true;
            }
        }
        if(foundonlist){
            Q.prio = Duration(ActiveWahana[i])*60 + JAMToDetik(Sekarang);
            Enqueue(&PQ[i], Q);
            for(j=0; j<5; j++){
                MinuteUpdate();
            }
        }else{
            Enqueue(&Antrian, Q);
            printf("Wahana tersebut tidak ada dalam list wahana pengunjung anda\n");
        }
    }
}

void generateAntrian(){
    int BanyakAntrian = (rand() % 25) + 1;
    int i;
    for(i=0; i<BanyakAntrian; i++){
        Pengunjung P = generatePengunjung();
        infotypeQ Q;
        Q.info = P;
        Q.prio = P.kesabaran;
        Enqueue(&Antrian, Q);
    }
}
