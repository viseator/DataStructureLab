//
// Created by viseator on 12/17/17.
//

#include <stdio.h>
#include "tri_tree_menu.h"
#include "datastructure/BinaryTree.h"

void visit(Tree_Node *n);

int tri_tree_menu() {
    BinaryTree *T;
    char *s = "1 2 3 4     5     6     7 8 9     10     11     ";
    InitBiTree(&T);
    CreateBiTree(T, s);
    LevelOrderTraverse(T, &visit);
//    PreOrderTraverse(T, &visit);
//    PostOrderTraverse(T, &visit);
//    Tree_Node *node = T->root->r_child;
//    printf("%d", Value(T, node));
//    L_NODE head;
//    head.next = NULL;
//    Tree_Node node1, node2;
//    node1.data = 1;
//    node2.data = 2;
//    PushBack(&head, &node1);
//    PushBack(&head, &node2);
//    Tree_Node *node1_p, *node2_p, *node3_p;
//    node1_p = PopFront(&head);
//    node2_p = PopFront(&head);
//    node3_p = PopFront(&head);

}

void visit(Tree_Node *n) {
    printf("%d ", n->data);
}
