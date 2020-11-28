// Adjascency List representation in C

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

struct node {
  int vertex;
  struct node* next;
};
struct node* createNode(int);

struct Graph {
  int numVertices;
  struct node** adjLists;
};

struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
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
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 1, 2);
  tes(graph);
  printGraph1(graph, 2);
  int a = 1;
  int b = 2;
  if (cekAdj(graph, a, b)) printf("a = %d adj b= %d", a, b);
  else printf("no");

  return 0;
}
