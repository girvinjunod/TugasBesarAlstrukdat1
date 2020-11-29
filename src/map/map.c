#include <stdio.h>
#include <stdlib.h>
#include "../util/boolean.h"
#include "map.h"
#include "../point/point.h"


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

        if (cc=='1') {currMap=M1; cc=getc(fileMap); cc = getc(fileMap); NBarEff(*currMap)=1; NColEff(*currMap)=0;i=0;j=0;}
        else if (cc=='2') {currMap=M2; cc=getc(fileMap); cc = getc(fileMap); NBarEff(*currMap)=1; NColEff(*currMap)=0;i=0;j=0;}
        else if (cc=='3') {currMap=M3; cc=getc(fileMap); cc = getc(fileMap); NBarEff(*currMap)=1; NColEff(*currMap)=0;i=0;j=0;}
        else if (cc=='4') {currMap=M4; cc=getc(fileMap); cc = getc(fileMap); NBarEff(*currMap)=1; NColEff(*currMap)=0;i=0;j=0;}
		else if (cc=='.') {cc = getc(fileMap);cc = getc(fileMap);}
		else if(cc != EOF){
			if (cc=='\n') {i++;j=0;NBarEff(*currMap)++;NColEff(*currMap)=0;}
			else{
				Legend(*currMap,i,j) = cc;
				if (cc=='P') PosPlayer(*currMap)=MakePOINT(j,i);
				else if (cc=='V'||cc=='^'||cc=='v') VGate(*currMap)=MakePOINT(j,i);
				else if (cc=='<'||cc=='>') HGate(*currMap)=MakePOINT(j,i);
				j++;
				NColEff(*currMap)++;
			}
		}
    }while (cc != EOF);
}

/* Check jika point di Current MAP occupied */
boolean checkPoint(MAP M,POINT P){
	return Legend(M,Ordinat(P),Absis(P)) == '-';
}
/* Check jika point P di MAP M menuju ke Map sebelahnya */
boolean checkSwitchVertical(MAP M,POINT P){
	legend L = Legend(M,Ordinat(P),Absis(P));
	return L=='^'||L=='v'||L=='V';
}
boolean checkSwitchHorizontal(MAP M,POINT P){
	legend L = Legend(M,Ordinat(P),Absis(P));
	return L=='<'||L=='>';
}
boolean checkPosOffice(MAP M,POINT P){
	legend L = Legend(M,Ordinat(P),Absis(P));
	return L=='O';
}
boolean checkPosAntrian(MAP M,POINT P){
	legend L = Legend(M,Ordinat(P),Absis(P));
	return L=='A';
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
	int i,j;
	for (i = IdxMin; i < NBarEff(M); i++){
        for (j = IdxMin; j < NColEff(M); j++){
            if (j != NColEff(M)-1) printf("%c", Legend(M,i,j));
            else printf("%c\n", Legend(M,i,j));
        }
    }
}
