//
// Created by viseator on 11/24/17.
//

#ifndef DATASTRUCTURELAB_LINKEDLIST_H
#define DATASTRUCTURELAB_LINKEDLIST_H

#include <stdbool.h>
#include <stdlib.h>

#define RESULT_UNDEFINED_ERROR -1;
#define RESULT_OK 0x0
#define NULL_PTR_ERROR 0x1
#define INDEX_RANGE_ERROR 0x2
#define TYPE int

#define NULL_CHECK if(l == NULL){ printf("NULL_PTR_ERROR"); return NULL_PTR_ERROR; }
#define RANGE_CHECK if (i < 1 || i > ListLength(l)) { printf("INDEX_RANGE_ERROR");return INDEX_RANGE_ERROR; }

typedef struct node {
    TYPE data;
    struct node *next;
} Node;

typedef struct {
    Node head;
    int size;
} List;


int InitialList(List **l);

int DestroyList(List *l);

int ClearList(List *l);

bool ListEmpty(List *l);

int ListLength(List *l);

int GetElem(List *l, int i, TYPE *e);

int LocateElem(List *l, TYPE e, bool (*compare)(TYPE arg1, TYPE arg2));

int PriorElem(List *l, TYPE cur_e, TYPE *pre_e);

int NextElem(List *l, TYPE cur_e, TYPE *next_e);

int ListInsert(List *l, int i, TYPE e);

int ListDelete(List *l, int i, TYPE *e);

int ListTraverse(List *l, void (*visit)(TYPE));


#endif //DATASTRUCTURELAB_LINKEDLIST_H
