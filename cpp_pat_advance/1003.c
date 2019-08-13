#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define Inf INT_MAX

typedef struct Vertex *Vertex, *Vertexes;
typedef struct Adj *Adj, *Adjs;
typedef struct Graph *Graph;

struct Vertex{  
    int id;             //id of a Vertex
    int known;          //If the Vertex has been traversed
    int dist;           //The distance along the path from the start point
    int numRescue;      //The number of rescue teams in this city
    int totalRescue;    //Total rescue teams along the path
    int npath;          //Length of the path
    Adj adj;            //
};

struct Adj
{
    int id;         //The city's it is connected to
    int length;     //The length of the edge
    Adj iter;       //pointer to thr next adjacent city
};

struct Graph{
    Vertexes vs;
    Adjs es;        //边数组的指针
    int numVertex;
    int numAdj;
};

//Read the graph
void Read(Graph g){
    int numRescue;
    for (int i=0; i<g->numVertex; i++){
        Vertex v = g->vs + i;
        scanf("%d", &numRescue);
        v->id           = i;
        v->known        = 0;
        v->dist         = Inf;
        v->numRescue    = numRescue;
        v->totalRescue  = numRescue;
        v->npath        = 0;
        v->adj          = NULL;
    }

    int id1, id2, length;
    for (int i=0; i < g->numAdj; i++){
        scanf("%d %d %d", &id1, &id2, &length);

        Adj e = g->es + i;
        e->id       = id2;
        e->length   = length;
        e->iter     = g->vs[id1].adj;
        g->vs[id1].adj = e;

        e++, i++;
        e->id       = id1;
        e->length   = length;
        e->iter     = g->vs[id2].adj;
        g->vs[id2].adj = e;
    }
}
int main()
{
    printf("Hello world\n");
    return 0;
}

