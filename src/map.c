//define Map disini

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "graph.c"

void pindahmap(struct Graph* g, int *currnode, int targetnode){
	boolean adj = cekAdj(g, *currnode, targetnode);
	if (adj){
		*currnode = targetnode;
	}
	else printf("node tidak adj, dunno tpi harusnya ga kepake ini");
}
int cektargetnode(char* gerbang, int currnode){
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
*/
	if (currnode == 0 && gerbang == "^") return 1;
	if (currnode == 0 && gerbang == ">") return 3;
	if (currnode == 1 && gerbang == ">") return 2;
	if (currnode == 1 && gerbang == "v") return 0;
	if (currnode == 2 && gerbang == "<") return 1;
	if (currnode == 2 && gerbang == "v") return 3;
	if (currnode == 3 && gerbang == "^") return 2;
	if (currnode == 3 && gerbang == "<") return 0;
}

void displaymap(int currnode){
	if (currnode == 0){
		printf("placeholder map 1");
	}
	else if (currnode == 1){
		printf("placeholder map 2");
	}
	else if (currnode == 1){
		printf("placeholder map 3");
	}
	else if (currnode == 1){
		printf("placeholder map 4");
	}
	else printf("nyasar mas");
}

int main(){
	struct Graph* graph = createAGraph(4);
	addEdge(graph, 0, 1);
  	addEdge(graph, 0, 3);
  	addEdge(graph, 1, 2);
  	addEdge(graph, 2, 3);
  	int currnode = 0;
  	printf("saat ini ada di map %d\n", currnode);
  	pindahmap(graph, &currnode, cektargetnode("^", currnode));
  	printf("saat ini ada di map %d\n", currnode);
  	
}
