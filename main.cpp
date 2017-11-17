#include <iostream>
#include "linearlist.h"

typedef int ElemType;

int main() {
    auto list = LinearList<ElemType>::List();
    LinearList<ElemType>::InitialList(list);
    for (int i = 0; i < list.size; i++) {
        std::cout << list.data[i];
    }
    return 0;
}