//
// Created by viseator on 12/15/17.
//

#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *CreateNode(char *s);

int CREATE_TREE_INDEX = 0;

int InitBiTree(BinaryTree **t) {
    *t = (BinaryTree *) calloc(sizeof(ElemType), 1);
    (*t)->root = NULL;
    return RESULT_OK;
}

int DestroyBitTree(BinaryTree **t) {
    if (*t == NULL) {
        return NULL_PTR_ERROR;
    }
    ClearBitTree(*t);
    free(*t);
    *t = NULL;
    return RESULT_OK;
}

int CreateBiTree(BinaryTree *t, char *def) {
    CREATE_TREE_INDEX = 0;
    t->root = CreateNode(def);
    return 0;
}

int ClearBitTree(BinaryTree *t) {
    return 0;
}

bool BiTreeEmpty(BinaryTree *t) {
    return 0;
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
    return 0;
}

int LevelOrderTraverse(BinaryTree *t, void (*Visit)(Node *)) {
    return 0;
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
    n->l_child = CreateNode(s);
    n->r_child = CreateNode(s);
    return n;
}
