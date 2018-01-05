//
// Created by viseator on 12/29/17.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <zconf.h>
#include <stdio.h>
#include "Graph.h"

void DFS(Graph *G, int v, void (*visit)(Vex *), bool *visited);

void PushBack(L_NODE *head, int data);

int PopFront(L_NODE *head);

void BFS(Graph *G, int v, void (*visit)(Vex *), bool *visited);

int CreateGraph(Graph **G, const ElemType *vex_data, int vex_size, const int *edge_info, int edge_info_size) {
    NULL_CHECK
    *G = (Graph *) calloc(1, sizeof(Graph));
    (*G)->edge_size = 0;
    (*G)->vex_size = vex_size;
    int i = 0;
    for (; i < vex_size; ++i) {
        (*G)->vexs[i].data = vex_data[i];
        (*G)->vexs[i].first.next = NULL;
    }
    for (i = 0; i < edge_info_size; ++i) {
        int iv = LocateVex(*G, edge_info[i]);
        Edge *e = &(*G)->vexs[iv].first;
        while (e->next != NULL) {
            e = e->next;
        }
        e->next = (Edge *) calloc(1, sizeof(Edge));
        e->next->next = NULL;
        e->next->vex = LocateVex(*G, edge_info[++i]);
        ++(*G)->edge_size;
    }
    return RESULT_OK;
}

int DestroyGraph(Graph **G) {
    NULL_CHECK
    if (*G == NULL) {
        return NULL_PTR_ERROR;
    }

    for (int i = 0; i < (*G)->vex_size; ++i) {
        Edge *e = (*G)->vexs[i].first.next;
        Edge *c;
        while (e != NULL) {
            c = e->next;
            free(e);
            e = c;
        }
        (*G)->vexs[i].first.next = NULL;
    }

    free(*G);
    *G = NULL;
    return RESULT_OK;
}

int LocateVex(Graph *G, ElemType u) {
    NULL_CHECK
    for (int i = 0; i < G->vex_size; ++i) {
        if (G->vexs[i].data == u) {
            return i;
        }
    }
    return -1;
}

Vex *GetVex(Graph *G, int i) {
    if (G == NULL || i < 0 || i > G->vex_size - 1) {
        return NULL;
    }
    return &G->vexs[i];
}

int PutVex(Graph *G, Vex *v, ElemType u) {
    NULL_CHECK
    v->data = u;
    return RESULT_OK;
}

Vex *FirstAdjVex(Graph *G, Vex *v) {
    if (G == NULL) { return NULL; }
    {
        bool contain = false;
        for (int i = 0; i < G->vex_size; ++i) { if (&G->vexs[i] == v) { contain = true; }}
        if (!contain) return NULL;
    }
    if (v->first.next == NULL) {
        return NULL;
    }
    return &G->vexs[v->first.next->vex];
}

Vex *NextAdjVex(Graph *G, Vex *v, Vex *w) {
    if (G == NULL) { return NULL; }
    {
        bool contain = false;
        for (int i = 0; i < G->vex_size; ++i) { if (&G->vexs[i] == v) { contain = true; }}
        if (!contain) return NULL;
    }
    Edge *e = v->first.next;
    while (e != NULL && G->vexs[e->vex].data != w->data) {
        e = e->next;
    }
    if (e == NULL || e->next == NULL) {
        return NULL;
    }
    return &G->vexs[e->next->vex];
}

int InsertVex(Graph *G, Vex *v) {
    NULL_CHECK
    G->vexs[G->vex_size++] = *v;
    return RESULT_OK;
}

int DeleteVex(Graph *G, Vex *v) {
    NULL_CHECK
    CONTAIN_CHECK
    int pos = LocateVex(G, v->data);
    for (int i = 0; i < G->vex_size; ++i) {
        if (&G->vexs[i] == v) {
            Edge *e = v->first.next;
            Edge *c;
            while (e != NULL) {
                --G->edge_size;
                c = e->next;
                free(e);
                e = c;
            }
        } else {
            Edge *pre = &G->vexs[i].first;
            Edge *e = pre->next;
            while (e != NULL) {
                if (e->vex == pos) {
                    pre->next = e->next;
                    free(e);
                    e = pre->next;
                    --G->edge_size;
                } else {
                    if (e->vex > pos) {
                        --e->vex;
                    }
                    pre = e;
                    e = e->next;
                }
            }
        }
    }

    for (int i = pos; i < G->vex_size - 1; ++i) {
        G->vexs[i].data = G->vexs[i + 1].data;
        G->vexs[i].first.next = G->vexs[i + 1].first.next;
    }
    --G->vex_size;
    return RESULT_OK;
}

int DFSTraverse(Graph *G, void (*visit)(Vex *)) {
    bool visited[G->vex_size];
    for (int i = 0; i < G->vex_size; ++i) {
        visited[i] = false;
    }

    for (int i = 0; i < G->vex_size; ++i) {
        if (visited[i] == false) {
            DFS(G, i, visit, visited);
        }
    }
    return RESULT_OK;
}

void DFS(Graph *G, int v, void (*visit)(Vex *), bool *visited) {
    visit(&G->vexs[v]);
    visited[v] = true;
    Edge *e = G->vexs[v].first.next;
    while (e != NULL) {
        if (visited[e->vex] == false) {
            DFS(G, e->vex, visit, visited);
        }
        e = e->next;
    }
}

int BFSTraverse(Graph *G, void (*visit)(Vex *)) {
    bool visited[G->vex_size];
    for (int i = 0; i < G->vex_size; ++i) {
        visited[i] = false;
    }

    for (int i = 0; i < G->vex_size; ++i) {
        if (visited[i] == false) {
            BFS(G, i, visit, visited);
        }
    }
    return RESULT_OK;
}

void BFS(Graph *G, int v, void (*visit)(Vex *), bool *visited) {
    L_NODE head;
    head.next = NULL;
    PushBack(&head, v);
    int current;
    while ((current = PopFront(&head)) != INT_MAX) {
        if (visited[current] == true) {
            continue;
        }
        visit(&G->vexs[current]);
        visited[current] = true;
        Edge *e = G->vexs[current].first.next;
        while (e != NULL) {
            if (visited[e->vex] == false) {
                PushBack(&head, e->vex);
            }
            e = e->next;
        }
    }
}


void PushBack(L_NODE *head, int data) {
    while (head->next != NULL) {
        head = head->next;
    }
    L_NODE *n = (L_NODE *) calloc(sizeof(L_NODE), 1);
    n->next = NULL;
    n->data = data;
    head->next = n;
}

int PopFront(L_NODE *head) {
    if (head->next == NULL) {
        return INT_MAX;
    }
    int e = head->next->data;
    L_NODE *n = head->next->next;
    free(head->next);
    head->next = n;
    return e;
}

int ShowAllEdges(Graph *G) {
    NULL_CHECK
    for (int i = 0; i < G->vex_size; ++i) {
        Edge *e = G->vexs[i].first.next;
        while (e != NULL) {
            printf("%d - > %d\n", G->vexs[i].data, G->vexs[e->vex].data);
            e = e->next;
        }
    }
    return RESULT_OK;
}

int InsertArc(Graph *G, Vex *v, Vex *w) {
    NULL_CHECK
    Edge *e = &v->first;
    while (e->next != NULL) {
        e = e->next;
    }
    Edge *new_edge = (Edge *) calloc(1, sizeof(Edge));
    new_edge->next = NULL;
    new_edge->vex = LocateVex(G, w->data);
    e->next = new_edge;
    ++G->edge_size;
    return RESULT_OK;
}

int DeleteArc(Graph *G, Vex *v, Vex *w) {
    NULL_CHECK
    Edge *e = &v->first;
    while (e->next != NULL && G->vexs[e->next->vex].data != w->data) {
        e = e->next;
    }
    if (e->next == NULL) {
        return NOT_CONTAIN_ERROR;
    }

    Edge *next = e->next->next;
    free(e->next);
    e->next = next;
    --G->edge_size;
    return RESULT_OK;
}
