//
// Created by viseator on 12/17/17.
//

#include <stdio.h>
#include "tri_tree_menu.h"
#include "datastructure/BinaryTree.h"

void visit(Node *n);

int tri_tree_menu() {
    BinaryTree *T;
    char *s = "1 2 3 4     5     6     7 8 9     10     11     ";
    InitBiTree(&T);
    CreateBiTree(T, s);
//    PostOrderTraverse(T, &visit);
    ClearBitTree(T);
    PostOrderTraverse(T, &visit);
}

void visit(Node *n){
    printf("%d ", n->data);
}
