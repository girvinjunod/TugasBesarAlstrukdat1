#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "map.h"
#include "point.h"
//#include "graph.h"



/* Baca MAP dari file map.txt */
void readMap(MAP *M1,MAP *M2,MAP *M3, MAP *M4){
// Membaca keempat MAP pada file map.txt, tiap map dipisah dengan line kosong
    FILE *fileMap;
    fileMap = fopen("map.txt","r");

    MAP *currMap;
    indeks i,j;

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
				j++;
				NKolEff(*currMap)++;
			}
		}
    }while (cc != EOF);
}

/* Check jika point di Current MAP occupied */
boolean checkPoint(MAP M,POINT P){
	return Legend(M,Absis(P),Ordinat(P)) == '-';
}

/* Check Movement */
void move(char input){
	/*POINT temp;
	if (input=='w') MakePOINT(PosX,PosY+1);
	else if (input=='a') MakePOINT(PosX-1,PosY);
	else if (input=='s') MakePOINT(PosX,PosY-1);
	else if (input=='d') MakePOINT(PosX+1,PosY);

	if checkPoint(M)*/
	print("test");
}
/*
void pindahmap(struct Graph* g, int *currnode, int targetnode){
	boolean adj = cekAdj(g, *currnode, targetnode);
	if (adj){
		*currnode = targetnode;
	}
	else printf("node tidak adj, dunno tpi harusnya ga kepake ini");
}
int cektargetnode(char* gerbang, int currnode){*/
/*
anggap map nya itu
 
 111  222
 111><222 
 111  222
  v    v
  ^    ^
 000  333
 000><333
 000  333

	if (currnode == 0 && gerbang == "^") return 1;
	if (currnode == 0 && gerbang == ">") return 3;
	if (currnode == 1 && gerbang == ">") return 2;
	if (currnode == 1 && gerbang == "v") return 0;
	if (currnode == 2 && gerbang == "<") return 1;
	if (currnode == 2 && gerbang == "v") return 3;
	if (currnode == 3 && gerbang == "^") return 2;
	if (currnode == 3 && gerbang == "<") return 0;
}

struct Graph* makegerbang() {
	struct Graph* graph = createAGraph(4);
	addEdge(graph, 0, 1);
  	addEdge(graph, 0, 3);
  	addEdge(graph, 1, 2);
  	addEdge(graph, 2, 3);
  	return graph;
}*/

void printMap(MAP M){
	for (int i = IdxMin; i < NBrsEff(M); i++){
        for (int j = IdxMin; j < NKolEff(M); j++){
            if (j != NKolEff(M)-1) printf("%c", Legend(M,i,j));
            else printf("%c\n", Legend(M,i,j));
        }
    }
}
