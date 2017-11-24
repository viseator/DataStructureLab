//
// Created by viseator on 11/17/17.
//

#ifndef DATASTRUCTURELAB_LINAERLIST_H
#define DATASTRUCTURELAB_LINAERLIST_H

#include <cstdio>
#include <malloc.h>


#define RESULT_OK 0x0
#define NULL_PTR_ERROR 0x1
#define RESULT_UNDEFINED_ERROR 0x2

/**
 * Linear List Data Structure
 * @tparam T  the type stores in the list
 */
template<class T>
class LinearList {
public :
    class List {
    private:
    public:
        static const size_t INIT_SIZE = 100;
        T *data = NULL;
        size_t size = 0;
        size_t capacity = INIT_SIZE;
    };

    static int EnsureCapacity(List *l, size_t new_capacity);

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

/**
 * Init the list, alloc space for the data
 * @tparam T the type store in the list
 * @param l the pointer to the pointer of list
 * @return result code
 */
template<class T>
int LinearList<T>::InitialList(List **l) {
    *l = new List();
    (*l)->data = (T *) calloc(List::INIT_SIZE, sizeof(T));
    return RESULT_OK;
}

/**
 * Destroy the list, free the space allocated the data
 * @tparam T the type store in the list
 * @param l the pointer to the pointer of list
 * @return result code
 */
template<class T>
int LinearList<T>::DestroyList(List **l) {
    if ((*l)->data != nullptr) {
        free((*l)->data);
    }
    delete (*l);
    *l = nullptr;
    return RESULT_OK;
}

/**
 * Clear the data stores in the list, reset the state of the list
 * @tparam T the type store in the list
 * @param l the pointer to the list
 * @return result code
 */
template<class T>
int LinearList<T>::ClearList(List *l) {
    if (l == nullptr) {
        std::cout << "Null Pointer" << std::endl;
        return NULL_PTR_ERROR;
    }
    delete l->data;
    l->data = (T *) calloc(List::INIT_SIZE, sizeof(T));
    l->capacity = List::INIT_SIZE;
    l->size = 0;
    return RESULT_OK;
}

/**
 * check whether the list is empty
 * @tparam T the type store in the list
 * @param l the pointer to the list
 * @return result code
 */
template<class T>
bool LinearList<T>::ListEmpty(List *l) {
    return l->size == 0;
}

/**
 * the length of the list
 * @tparam T the type store in the list
 * @param l the pointer to the list
 * @return result code
 */
template<class T>
size_t LinearList<T>::ListLength(List *l) {
    return l->size;
}

/**
 *  get the element at the position i, stores in the param e
 * @tparam T the type store in the list
 * @param l the pointer to the list
 * @param e the reference stores result
 * @return result code
 */
template<class T>
int LinearList<T>::GetElem(List *l, int i, T &e) {
    if (l == nullptr) {
        std::cout << "Null Pointer" << std::endl;
        return NULL_PTR_ERROR;
    }
    if (i < 1 || i > l->size + 1) {
        std::cout << "Invalid i" << std::endl;
        return RESULT_UNDEFINED_ERROR;
    }
    e = l->data[i];
    return RESULT_OK;
}

/**
 * Locate the specific element by compare function
 * @tparam T the type store in the list
 * @param l the pointer to the list
 * @param e the specific element
 * @param compare the compare function, return 0 means equal
 * @return result code
 */
template<class T>
int LinearList<T>::LocateElem(List *l, T e, bool (*compare)(T, T)) {
    if (l == nullptr) {
        std::cout << "Null Pointer" << std::endl;
        return NULL_PTR_ERROR;
    }
    for (int i = 0; i < l->size; ++i) {
        if (compare(l->data[i], e)) {
            return i + 1;
        }
    }
    return 0;
}

/**
 * get the prior element of the specific element
 * @tparam T the type store in the list
 * @param l the pointer to the list
 * @param  cur_e current element
 * @param pre_e the reference store the previous element of current element
 * @return result code
 */
template<class T>
int LinearList<T>::PriorElem(List *l, T cur_e, T &pre_e) {
    if (l == nullptr) {
        std::cout << "Null Pointer" << std::endl;
        return NULL_PTR_ERROR;
    }
    for (int i = 1; i < l->size; ++i) {
        if (l->data[i] == cur_e) {
            pre_e = l->data[i - 1];
            return RESULT_OK;
        }
    }
    return RESULT_UNDEFINED_ERROR;
}

/**
 * get the next element of the specific element
 * @tparam T the type store in the list
 * @param l the pointer to the list
 * @param  cur_e current element
 * @param next_e the reference store the next element of current element
 * @return result code
 */
template<class T>
int LinearList<T>::NextElem(List *l, T cur_e, T &next_e) {
    if (l == nullptr) {
        std::cout << "Null Pointer" << std::endl;
        return NULL_PTR_ERROR;
    }
    for (int i = 0; i < l->size - 1; ++i) {
        if (l->data[i] == cur_e) {
            next_e = l->data[i + 1];
            return RESULT_OK;
        }
    }
    return RESULT_UNDEFINED_ERROR;
}

/**
 * insert element to the specific position in the list
 * @tparam T the type store in the list
 * @param l the pointer to the list
 * @param i the insertion position
 * @param e the element
 * @return result code
 */
template<class T>
int LinearList<T>::ListInsert(List *l, int i, T e) {
    if (l == nullptr) {
        std::cout << "Null Pointer" << std::endl;
        return NULL_PTR_ERROR;
    }
    if (i < 1 || i > l->size + 1) {
        std::cout << "Invalid i" << std::endl;
        return RESULT_UNDEFINED_ERROR;
    }
    EnsureCapacity(l, ++l->size);
    for (size_t j = l->size; j >= i; --j) {
        l->data[j] = l->data[j - 1];
    }
    l->data[i - 1] = e;
    return RESULT_OK;
}

/**
 * delete the specific element at the position
 * @tparam T the type store in the list
 * @param l the pointer to the list
 * @param i the index of the deleted element
 * @param e the reference to store the deleted element
 * @return result code
 */
template<class T>
int LinearList<T>::ListDelete(List *l, size_t i, T &e) {
    if (l == nullptr) {
        return NULL_PTR_ERROR;
    }
    if (i < 1 || i > l->size + 1) {
        std::cout << "Invalid i" << std::endl;
        return RESULT_UNDEFINED_ERROR;
    }
    T data = l->data[i - 1];
    for (size_t j = i - 1; j < l->size - 1; j++) {
        l->data[j] = l->data[j + 1];
    }
    EnsureCapacity(l, --l->size);
    return data;
}

/**
 * Traverse the list, apply visit function to each element
 * @tparam T the type store in the list
 * @param l the pointer to the list
 * @param visit visit function apply to each element
 * @return  result code
 */
template<class T>
int LinearList<T>::ListTraverse(List *l, void (*visit)(T)) {
    if (l == nullptr) {
        return NULL_PTR_ERROR;
    }
    for (size_t i = 0; i < l->size; i++) {
        visit(l->data[i]);
    }
    return RESULT_OK;
}

/**
 * ensure the capacity of the list, double the space allocated for the data or reduce to half
 * @tparam T the type store in the list
 * @param l the pointer to the list
 * @param new_capacity required new capacity
 * @return result code
 */
template<class T>
int LinearList<T>::EnsureCapacity(LinearList::List *l, size_t new_capacity) {
    if (new_capacity > l->capacity) {
        l->data = (T *) realloc(l->data, l->capacity * 2);
        return RESULT_OK;
    }

    if (new_capacity <= l->capacity / 4 && l->capacity >= List::INIT_SIZE) {
        l->data = (T *) realloc(l->data, l->capacity / 2);
        return RESULT_OK;
    }
    return RESULT_UNDEFINED_ERROR;
}


#endif //DATASTRUCTURELAB_LINAERLIST_H
