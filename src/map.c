//define Map disini

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "graph.c"

void pindahmap(struct Graph* g, int *currnode, int targetnode){
//ke-trigger klo jalan ke gerbang, nanti bisa cek symbol gerbang di map sama current node aj buat nentuin target nodenya
	boolean adj = cekAdj(g, *currnode, targetnode);
	if (adj){
		*currnode = targetnode;
	}
	else printf("node tidak adj, dunno tpi harusnya ga kepake ini");
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
  	pindahmap(graph, &currnode, 1);
  	printf("saat ini ada di map %d\n", currnode);
}
