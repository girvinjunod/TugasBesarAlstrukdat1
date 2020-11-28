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

struct node* createNode(int v);

struct Graph* createAGraph(int vertices);

void addEdge(struct Graph* graph, int s, int d);

void printGraph(struct Graph* graph);

void printGraph1(struct Graph* graph, int v);

boolean cekAdj(struct Graph* g, int a, int b);
