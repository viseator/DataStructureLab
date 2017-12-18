//
// Created by viseator on 12/15/17.
//

#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *CreateNode(char *s);

void FreeNode(Node **n);

int PostOrderDeleteNode(Node **n);

int CREATE_TREE_INDEX = 0;
int SIZE_COUNT = 0;


int InitBiTree(BinaryTree **t) {
    if (t == NULL) {
        return NULL_PTR_ERROR;
    }
    *t = (BinaryTree *) calloc(sizeof(ElemType), 1);
    (*t)->root = NULL;
    (*t)->size = 0;
    return RESULT_OK;
}

int DestroyBitTree(BinaryTree **t) {
    if (t == NULL) {
        return NULL_PTR_ERROR;
    }
    if (*t == NULL) {
        return NULL_PTR_ERROR;
    }
    ClearBitTree(*t);
    free(*t);
    *t = NULL;
    return RESULT_OK;
}

int CreateBiTree(BinaryTree *t, char *def) {
    NULL_CHECK
    if (def == NULL) {
        return NULL_PTR_ERROR;
    }
    CREATE_TREE_INDEX = 0;
    SIZE_COUNT = 0;
    t->root = CreateNode(def);
    t->size = SIZE_COUNT;
    return RESULT_OK;
}

int ClearBitTree(BinaryTree *t) {
    NULL_CHECK
    PostOrderDeleteNode(&t->root);
    t->size = 0;
    return RESULT_OK;
}

bool BiTreeEmpty(BinaryTree *t) {
    return t->size == 0;
}

int BiTreeDepth(BinaryTree *t) {
    return 0;
}

Node *Root(BinaryTree *t) {
    return NULL;
}

ElemType Value(BinaryTree *t, Node *e) {
    return 0;
}

int Assign(BinaryTree *t, Node *e, ElemType value) {
    return 0;
}

Node *Parent(BinaryTree *t, Node *e) {
    return NULL;
}

Node *LeftChild(BinaryTree *t, Node *e) {
    return NULL;
}

Node *rightChild(BinaryTree *t, Node *e) {
    return NULL;
}

Node *leftSibling(BinaryTree *t, Node *e) {
    return NULL;
}

Node *rightSibling(BinaryTree *t, Node *e) {
    return NULL;
}

int InsertChild(BinaryTree *t, Node *p, int LR, BinaryTree *c) {
    return 0;
}

int DeleteChild(BinaryTree *t, Node *p, int LR) {
    return 0;
}

int PreOrderTraverse(BinaryTree *t, void (*Visit)(Node *)) {
    return 0;
}

int InOrderTraverse(BinaryTree *t, void (*Visit)(Node *)) {
    return 0;
}

int PostOrderTraverse(BinaryTree *t, void (*Visit)(Node *)) {
    NULL_CHECK
    PostOrderTraverseNode(t->root, Visit);
    return RESULT_OK;
}

int LevelOrderTraverse(BinaryTree *t, void (*Visit)(Node *)) {
    return 0;
}

int PreOrderTraverseNode(Node *n, void (*Visit)(Node *)) {
    return 0;
}

int InOrderTraverseNode(Node *n, void (*Visit)(Node *)) {
    return 0;
}

int PostOrderTraverseNode(Node *n, void (*Visit)(Node *)) {
    if (n == NULL) {
        return RESULT_OK;
    }
    PostOrderTraverseNode(n->l_child, Visit);
    PostOrderTraverseNode(n->r_child, Visit);
    Visit(n);
    return RESULT_OK;
}


Node *CreateNode(char *s) {
    if (s[CREATE_TREE_INDEX] == '\0') {
        return NULL;
    }

    if (s[CREATE_TREE_INDEX] == ' ') {
        CREATE_TREE_INDEX += 2;
        return NULL;
    }
    Node *n = (Node *) calloc(sizeof(Node), 1);
    char temp[32];
    int i = 0;
    while (s[CREATE_TREE_INDEX] != ' ') {
        temp[i++] = s[CREATE_TREE_INDEX++];
    }
    ++CREATE_TREE_INDEX;
    temp[i] = '\0';
    n->data = atoi(temp);
    ++SIZE_COUNT;
    n->l_child = CreateNode(s);
    n->r_child = CreateNode(s);
    return n;
}

int PostOrderDeleteNode(Node **n) {
    if (*n == NULL) {
        return RESULT_OK;
    }
    PostOrderDeleteNode(&(*n)->l_child);
    PostOrderDeleteNode(&(*n)->r_child);
    FreeNode(n);
    return RESULT_OK;
}

void FreeNode(Node **n) {
    free(*n);
    *n = NULL;
}
