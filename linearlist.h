//
// Created by viseator on 11/17/17.
//

#ifndef DATASTRUCTURELAB_LINAERLIST_H
#define DATASTRUCTURELAB_LINAERLIST_H

#include <cstdio>
#include <malloc.h>


#define RESULT_OK 0

template<class T>
class LinearList {
public :
    class List {
    private:
    public:
        static const size_t INIT_SIZE = 10;
        T *data = NULL;
        size_t size = INIT_SIZE;
    };

    static int InitialList(List &l);

    static int DestroyList(List &l);

    static int ClearList(List &l);

    static bool ListEmpty(List &l);

    static int ListLength(List &l);

    static int GetElem(List &l, int i, T &e);

    static int LocateElem(List &l, T e, bool (*compare)(T arg1, T arg2));

    static int PriorElem(List &l, T cur_e, T &pre_e);

    static int NextElem(List &l, T cur_e, T &next_e);

    static int ListInsert(List &l, int i, T e);

    static int ListDelete(List &l, int i, T &e);

    static int ListTraverse(List &l, void (*visit)());
};

template<class T>
int LinearList<T>::InitialList(List &l) {
    l.data = (T *) calloc(List::INIT_SIZE, sizeof(T));
    l.size = List::INIT_SIZE;
    return RESULT_OK;
}

template<class T>
int LinearList<T>::DestroyList(List &l) {
    return 0;
}

template<class T>
int LinearList<T>::ClearList(List &l) {
    return 0;
}

template<class T>
bool LinearList<T>::ListEmpty(List &l) {
    return false;
}

template<class T>
int LinearList<T>::ListLength(List &l) {

}

template<class T>
int LinearList<T>::GetElem(List &l, int i, T &e) {
    return 0;
}

template<class T>
int LinearList<T>::LocateElem(List &l, T e, bool (*compare)(T, T)) {
    return 0;
}

template<class T>
int LinearList<T>::PriorElem(List &l, T cur_e, T &pre_e) {
    return 0;
}

template<class T>
int LinearList<T>::NextElem(List &l, T cur_e, T &next_e) {
    return 0;
}

template<class T>
int LinearList<T>::ListInsert(List &l, int i, T e) {
    return 0;
}

template<class T>
int LinearList<T>::ListDelete(List &l, int i, T &e) {
    return 0;
}

template<class T>
int LinearList<T>::ListTraverse(List &l, void (*visit)()) {
    return 0;
}


#endif //DATASTRUCTURELAB_LINAERLIST_H
