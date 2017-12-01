//
// Created by viseator on 11/24/17.
//

#ifndef DATASTRUCTURELAB_LINKEDLIST_H
#define DATASTRUCTURELAB_LINKEDLIST_H

#include <cstddef>

template<class T>
class LinkedList {
public :
    class List {
    };

    static int InitialList(List **l);

    static int DestroyList(List **l);

    static int ClearList(List *l);

    static bool ListEmpty(List *l);

    static size_t ListLength(List *l);

    static int GetElem(List *l, int i, T &e);

    static int LocateElem(List *l, T e, bool (*compare)(T arg1, T arg2));

    static int PriorElem(List *l, T cur_e, T &pre_e);

    static int NextElem(List *l, T cur_e, T &next_e);

    static int ListInsert(List *l, int i, T e);

    static int ListDelete(List *l, size_t i, T &e);

    static int ListTraverse(List *l, void (*visit)(T));
};

int LinkedList::InitialList(LinkedList::List **l) {
    return 0;
}

int LinkedList::DestroyList(LinkedList::List **l) {
    return 0;
}

int LinkedList::ClearList(LinkedList::List *l) {
    return 0;
}

bool LinkedList::ListEmpty(LinkedList::List *l) {
    return false;
}

size_t LinkedList::ListLength(LinkedList::List *l) {
    return 0;
}

int LinkedList::GetElem(LinkedList::List *l, int i, T &e) {
    return 0;
}

int LinkedList::LocateElem(LinkedList::List *l, T e, bool (*compare)(T, T)) {
    return 0;
}

int LinkedList::PriorElem(LinkedList::List *l, T cur_e, T &pre_e) {
    return 0;
}

int LinkedList::NextElem(LinkedList::List *l, T cur_e, T &next_e) {
    return 0;
}

int LinkedList::ListInsert(LinkedList::List *l, int i, T e) {
    return 0;
}

int LinkedList::ListDelete(LinkedList::List *l, size_t i, T &e) {
    return 0;
}

int LinkedList::ListTraverse(LinkedList::List *l, void (*visit)(T)) {
    return 0;
}

#endif //DATASTRUCTURELAB_LINKEDLIST_H
