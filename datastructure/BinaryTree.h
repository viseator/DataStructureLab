//
// Created by viseator on 12/15/17.
//

#ifndef DATASTRUCTURELAB_BINARYTREE_H
#define DATASTRUCTURELAB_BINARYTREE_H

#include <stdbool.h>

#define ElemType int
#define RESULT_OK 0x0
#define NULL_PTR_ERROR 0x1
#define RESULT_UNDEFINED_ERROR 0x2

#define NULL_CHECK if (t == NULL) { return NULL_PTR_ERROR; }


typedef struct NODE {
    ElemType data;
    struct NODE *l_child;
    struct NODE *r_child;
} Node;

typedef struct BINARY_TREE {
    Node *root;
    int size;
} BinaryTree;

int InitBiTree(BinaryTree **t);

int DestroyBitTree(BinaryTree **t);

int CreateBiTree(BinaryTree *t, char *def);

int ClearBitTree(BinaryTree *t);

bool BiTreeEmpty(BinaryTree *t);

int BiTreeDepth(BinaryTree *t);

Node *Root(BinaryTree *t);

ElemType Value(BinaryTree *t, Node *e);

int Assign(BinaryTree *t, Node *e, ElemType value);

Node *Parent(BinaryTree *t, Node *e);

Node *LeftChild(BinaryTree *t, Node *e);

Node *rightChild(BinaryTree *t, Node *e);

Node *leftSibling(BinaryTree *t, Node *e);

Node *rightSibling(BinaryTree *t, Node *e);

int InsertChild(BinaryTree *t, Node *p, int LR, BinaryTree *c);

int DeleteChild(BinaryTree *t, Node *p, int LR);

int PreOrderTraverse(BinaryTree *t, void (Visit)(Node *n));

int InOrderTraverse(BinaryTree *t, void (Visit)(Node *n));

int PostOrderTraverse(BinaryTree *t, void (Visit)(Node *n));

int LevelOrderTraverse(BinaryTree *t, void (Visit)(Node *n));

int PreOrderTraverseNode(Node *n, void (Visit)(Node *n));

int InOrderTraverseNode(Node *n, void (Visit)(Node *n));

int PostOrderTraverseNode(Node *n, void (Visit)(Node *n));

int LevelOrderTraverseNode(Node *n, void (Visit)(Node *n));

#endif; //DATASTRUCTURELAB_BINARYTREE_H
