//
// Created by viseator on 12/29/17.
//

#ifndef DATASTRUCTURELAB_GRAPH_H
#define DATASTRUCTURELAB_GRAPH_H

#define ElemType int
#define MAX_VEX 80
#define RESULT_OK 0
#define NULL_PTR_ERROR -1
#define NOT_CONTAIN_ERROR -2
#define INDEX_OUT_OF_RANGE_ERROR -3


#define NULL_CHECK if (G == NULL) { return NULL_PTR_ERROR; }
#define CONTAIN_CHECK {bool contain = false; for (int i = 0; i < G->vex_size; ++i) { if (&G->vexs[i] == v) { contain = true; } } if (!contain) return NOT_CONTAIN_ERROR;}

typedef struct LIST_NODE {
    int data;
    struct LIST_NODE *next;
} L_NODE;

typedef struct EDGE {
    int vex;
    struct EDGE *next;
} Edge;

typedef struct VEX {
    ElemType data;
    struct EDGE first;
} Vex;

typedef struct GRAPH {
    int vex_size;
    int edge_size;
    struct VEX vexs[MAX_VEX];
} Graph;

int CreateGraph(Graph **G, const ElemType *vex_data, int vex_size, const int *edge_info, int edge_info_size);

int DestroyGraph(Graph **G);

int LocateVex(Graph *G, ElemType u);

Vex *GetVex(Graph *G, int i);

int PutVex(Graph *G, Vex *v, ElemType u);

Vex *FirstAdjVex(Graph *G, Vex *v);

Vex *NextAdjVex(Graph *G, Vex *v, Vex *w);

int InsertVex(Graph *G, Vex *v);

int DeleteVex(Graph *G, Vex *v);

int DFSTraverse(Graph *G, void (*visit)(Vex *v));

int BFSTraverse(Graph *G, void (*visit)(Vex *v));

int ShowAllEdges(Graph *G);

int InsertArc(Graph *G, Vex *v, Vex *w);

int DeleteArc(Graph *G, Vex *v, Vex *w);

#endif //DATASTRUCTURELAB_GRAPH_H
