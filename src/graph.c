#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "graph.h"
#include "map.h"

struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  /*newNode->map = map 1;*/
  newNode->tes = v;
  return newNode;
}


struct Graph* createAGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  int i;
  for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}


void addEdge(struct Graph* graph, int s, int d) {
// tambah edge
//nyambungin s ke d
  struct node* newNode = createNode(d);
  newNode->next = graph->adjLists[s];
  graph->adjLists[s] = newNode;

//nyambungin d ke s
  newNode = createNode(s);
  newNode->next = graph->adjLists[d];
  graph->adjLists[d] = newNode;
}

void isimap(struct Graph* graph){
	int v;
	int i;
	int t;
	int angka;
  	for (v = 0; v < 4; v++){
  		struct node* temp = graph->adjLists[v];
  		//tiap simpul/node isi map
  		for(i = 0; i<2;i++){ 
  		printf("isi map %d\n", temp->vertex); //isinya emg harus berkali2 gara2 adj list
  		printf("tes isi awal %d\n", temp->tes); //nanti tes nya apus, ganti sama isi mapnya
  		//misal temp->map = map1;
  		if (temp->vertex == 0) angka = 0;
  		else if (temp->vertex == 1) angka = 1;
  		else if (temp->vertex == 2) angka = 2;
  		else if (temp->vertex == 3) angka = 3;
  		temp->tes = 69 + angka;
  		printf("tes isi abis input %d\n", temp->tes);
  		temp = temp->next;
  		}
	  }
	for (t = 0; t < graph->numVertices; t++) {
    struct node* temp = graph->adjLists[t];
    printf("\n isi tes dari simpul %d\n: ", t);
    while (temp) {
      printf("%d -> ", temp->tes);
      temp = temp->next;
    }
    printf("\n");
  }
	
}

void printGraph(struct Graph* graph) {
//print graf
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

void printGraph1(struct Graph* graph, int v) {
//print semua node yg nyambung ke node v
  struct node* temp = graph->adjLists[v];
  printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
}

boolean cekAdj(struct Graph* g, int a, int b){
	struct node* temp = g->adjLists[a];
	while (temp) {
		if (temp->vertex == b){
			return true;
		}
		temp = temp->next;
	}
	return false;
}


int main() {
  struct Graph* graph = createAGraph(4);
	addEdge(graph, 0, 1);
  	addEdge(graph, 0, 3);
  	addEdge(graph, 1, 2);
  	addEdge(graph, 2, 3);
  printGraph(graph);
  int a = 1;
  int b = 2;
  if (cekAdj(graph, a, b)) printf("a = %d adj b= %d\n", a, b);
  else printf("no\n");
  isimap(graph);
  return 0;
}
