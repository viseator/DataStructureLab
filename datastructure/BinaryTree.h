//
// Created by viseator on 12/15/17.
//

#ifndef DATASTRUCTURELAB_BINARYTREE_H
#define DATASTRUCTURELAB_BINARYTREE_H

#include <stdbool.h>

#define ElemType int
#define RESULT_OK 0x0
#define NULL_PTR_ERROR (-1)
#define RESULT_UNDEFINED_ERROR (-2)
#define DO_NOT_CONTAIN (-3)

#define TREE_NULL_CHECK if (t == NULL) { return NULL_PTR_ERROR; }

#define CONTAIN_CHECK if (!Contains(t->root, e)) { return DO_NOT_CONTAIN; }

typedef struct NODE {
    ElemType data;
    struct NODE *l_child;
    struct NODE *r_child;
} Tree_Node;

typedef struct BINARY_TREE {
    Tree_Node *root;
    int size;
} BinaryTree;

typedef struct LIST_NODE {
    Tree_Node *data;
    struct LIST_NODE *next;
} L_NODE;

int InitBiTree(BinaryTree **t);

int DestroyBitTree(BinaryTree **t);

int CreateBiTree(BinaryTree *t, char *def);

int ClearBitTree(BinaryTree *t);

bool BiTreeEmpty(BinaryTree *t);

int BiTreeDepth(BinaryTree *t);

Tree_Node *Root(BinaryTree *t);

Tree_Node *Value(BinaryTree *t, int i);

int Assign(BinaryTree *t, Tree_Node *e, ElemType value);

Tree_Node *Parent(BinaryTree *t, Tree_Node *e);

Tree_Node *LeftChild(BinaryTree *t, Tree_Node *e);

Tree_Node *RightChild(BinaryTree *t, Tree_Node *e);

Tree_Node *LeftSibling(BinaryTree *t, Tree_Node *e);

Tree_Node *RightSibling(BinaryTree *t, Tree_Node *e);

int InsertChild(BinaryTree *t, Tree_Node *e, int LR, BinaryTree *c);

int DeleteChild(BinaryTree *t, Tree_Node *e, int LR);

int PreOrderTraverse(BinaryTree *t, void (Visit)(Tree_Node *n));

int InOrderTraverse(BinaryTree *t, void (Visit)(Tree_Node *n));

int PostOrderTraverse(BinaryTree *t, void (Visit)(Tree_Node *n));

int LevelOrderTraverse(BinaryTree *t, void (Visit)(Tree_Node *n));

void PushBack(L_NODE *head, Tree_Node *data);

Tree_Node *PopFront(L_NODE *head);

#endif; //DATASTRUCTURELAB_BINARYTREE_H
