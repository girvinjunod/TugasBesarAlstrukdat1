#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "map.h"
#include "point.h"


/* Baca MAP dari file map.txt */
void readMap(MAP *M1,MAP *M2,MAP *M3, MAP *M4){
// Membaca keempat MAP pada file map.txt, tiap map dipisah dengan line kosong
    FILE *fileMap;
    fileMap = fopen("map.txt","r");

    MAP *currMap;
    indeks i,j;

	PosXPlayer(*M1)=pointUndef;PosYPlayer(*M1)=pointUndef;
	PosXPlayer(*M2)=pointUndef;PosYPlayer(*M2)=pointUndef;
	PosXPlayer(*M3)=pointUndef;PosYPlayer(*M3)=pointUndef;
	PosXPlayer(*M4)=pointUndef;PosYPlayer(*M4)=pointUndef;

    legend cc;
    do{
		cc = getc(fileMap);

        if (cc=='1') {currMap=M1; cc=getc(fileMap); cc = getc(fileMap); NBrsEff(*currMap)=1; NKolEff(*currMap)=0;i=0;j=0;}
        else if (cc=='2') {currMap=M2; cc=getc(fileMap); cc = getc(fileMap); NBrsEff(*currMap)=1; NKolEff(*currMap)=0;i=0;j=0;}
        else if (cc=='3') {currMap=M3; cc=getc(fileMap); cc = getc(fileMap); NBrsEff(*currMap)=1; NKolEff(*currMap)=0;i=0;j=0;}
        else if (cc=='4') {currMap=M4; cc=getc(fileMap); cc = getc(fileMap); NBrsEff(*currMap)=1; NKolEff(*currMap)=0;i=0;j=0;}
		else if (cc=='.') {cc = getc(fileMap);cc = getc(fileMap);}
		else if(cc != EOF){
			if (cc=='\n') {i++;j=0;NBrsEff(*currMap)++;NKolEff(*currMap)=0;}
			else{
				Legend(*currMap,i,j) = cc;
				if (cc=='P') PosPlayer(*currMap)=MakePOINT(j,i);
				j++;
				NKolEff(*currMap)++;
			}
		}
    }while (cc != EOF);
}

/* Check jika point di Current MAP occupied */
boolean checkPoint(MAP M,POINT P){
	return Legend(M,Ordinat(P),Absis(P)) == '-';
}

/* Cari Map yang ada player */
boolean isPlayerHere(MAP M){
    return PosXPlayer(M)!=pointUndef && PosYPlayer(M)!=pointUndef;
}

/* Mengubah titik di Map */
void setPoint(MAP *M,char cc,POINT P){
	Legend(*M,Ordinat(P),Absis(P)) = cc;
}

void printMap(MAP M){
	for (int i = IdxMin; i < NBrsEff(M); i++){
        for (int j = IdxMin; j < NKolEff(M); j++){
            if (j != NKolEff(M)-1) printf("%c", Legend(M,i,j));
            else printf("%c\n", Legend(M,i,j));
        }
    }
}
