//
// Created by viseator on 11/24/17.
//

#include <stdio.h>
#include "linkedlist.h"

int InitialList(List **l) {
    *l = (List *) calloc(1, sizeof(List));
    (*l)->size = 0;
    return RESULT_OK;
}

int DestroyList(List *l) {
    NULL_CHECK
    ClearList(l);
    free(l);
    return RESULT_OK;
}

int ClearList(List *l) {
    NULL_CHECK
    Node *p = l->head.next;
    Node *n = NULL;
    while (p != NULL) {
        n = p->next;
        free(p);
        p = n;
    }
    l->size = 0;
    return RESULT_OK;
}

bool ListEmpty(List *l) {
    NULL_CHECK
    return l->size == 0;
}

int ListLength(List *l) {
    NULL_CHECK
    return l->size;
}

int GetElem(List *l, int i, TYPE *e) {
    NULL_CHECK
    RANGE_CHECK
    Node *p = l->head.next;
    while (--i) {
        p = p->next;
    }
    *e = p->data;
    return RESULT_OK;
}

int LocateElem(List *l, TYPE e, bool (*compare)(TYPE arg1, TYPE arg2)) {
    NULL_CHECK
    Node *p = l->head.next;
    int i = 0;
    while (p != NULL) {
        ++i;
        if (compare(p->data, e)) {
            return i;
        }
        p = p->next;
    }
    return RESULT_UNDEFINED_ERROR;
}

int PriorElem(List *l, TYPE cur_e, TYPE *pre_e) {
    NULL_CHECK
    if (ListLength(l) < 2) {
        return RESULT_UNDEFINED_ERROR;
    }
    Node *p = l->head.next;
    Node *n = p->next;
    while (n != NULL) {
        if (cur_e == n->data) {
            *pre_e = p->data;
            return RESULT_OK;
        }
        p = n;
        n = n->next;
    }
    return RESULT_UNDEFINED_ERROR;
}

int NextElem(List *l, TYPE cur_e, TYPE *next_e) {
    NULL_CHECK
    if (ListLength(l) < 2) {
        return RESULT_UNDEFINED_ERROR;
    }
    Node *p = l->head.next;
    while (p != NULL) {
        if (p->data == cur_e) {
            if (p->next == NULL) {
                return RESULT_UNDEFINED_ERROR;
            }
            *next_e = p->next->data;
            return RESULT_OK;
        }
        p = p->next;
    }
    return RESULT_UNDEFINED_ERROR;
}

int ListInsert(List *l, int i, TYPE e) {
    NULL_CHECK
    if (i < 1 || i > ListLength(l) + 1) { return INDEX_RANGE_ERROR; }
    Node *p = &l->head;
    while (--i) {
        p = p->next;
    }
    Node *n = (Node *) calloc(1, sizeof(Node));
    n->data = e;
    n->next = p->next;
    p->next = n;
    ++l->size;
    return RESULT_OK;
}

int ListDelete(List *l, int i, TYPE *e) {
    NULL_CHECK
    RANGE_CHECK
    Node *p = &l->head;
    Node *n = NULL;
    while (--i) {
        p = p->next;
    }
    n = p->next->next;
    *e = p->next->data;
    free(p->next);
    p->next = n;
    --l->size;
    return RESULT_OK;
}

int ListTraverse(List *l, void (*visit)(TYPE)) {
    NULL_CHECK
    Node *p = l->head.next;
    while (p != NULL) {
        visit(p->data);
        p = p->next;
    }
    return RESULT_OK;
}
