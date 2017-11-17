#include <iostream>
#include "linearlist.h"

typedef int ElemType;
typedef LinearList<ElemType>::List *L;

int main() {
    L list = nullptr;
    LinearList<ElemType>::InitialList(&list);
    for (int i = 0; i < (*list).size; i++) {
        std::cout << (*list).data[i];
    }
    LinearList<ElemType>::ClearList(*list);


    return 0;
}