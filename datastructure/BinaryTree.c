//
// Created by viseator on 12/15/17.
//

#include "BinaryTree.h"
#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Tree_Node *CreateNode(char *s);

void FreeNode(Tree_Node **n);

int PostOrderDeleteNode(Tree_Node **n);

int PostOrderTraverseNode(Tree_Node *n, void (*Visit)(Tree_Node *));

int BiTreeHeight(Tree_Node *n);

bool Contains(Tree_Node *root, Tree_Node *n);

Tree_Node *ParentNode(Tree_Node *n, Tree_Node *e);

Tree_Node *LeftSiblingNode(Tree_Node *n, Tree_Node *e);

Tree_Node *RightSiblingNode(Tree_Node *n, Tree_Node *e);

int PreOrderTraverseNode(Tree_Node *n, void (*Visit)(Tree_Node *));

int InOrderTraverseNode(Tree_Node *n, void (*Visit)(Tree_Node *));

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
    TREE_NULL_CHECK
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
    TREE_NULL_CHECK
    PostOrderDeleteNode(&t->root);
    t->size = 0;
    return RESULT_OK;
}

bool BiTreeEmpty(BinaryTree *t) {
    return t->size == 0;
}

int BiTreeDepth(BinaryTree *t) {
    TREE_NULL_CHECK
    return BiTreeHeight(t->root);
}

Tree_Node *Root(BinaryTree *t) {
    if (t == NULL) {
        return NULL;
    }
    return t->root;
}

ElemType Value(BinaryTree *t, Tree_Node *e) {
    TREE_NULL_CHECK
    CONTAIN_CHECK
    return e->data;
}

int Assign(BinaryTree *t, Tree_Node *e, ElemType value) {
    TREE_NULL_CHECK
    CONTAIN_CHECK
    e->data = value;
    return RESULT_OK;
}

Tree_Node *Parent(BinaryTree *t, Tree_Node *e) {
    if (t == NULL) {
        return NULL;
    }
    if (!Contains(t->root, e)) {
        return NULL;
    }
    if (t->root == e) {
        return NULL;
    }
    return ParentNode(t->root, e);
}

Tree_Node *LeftChild(BinaryTree *t, Tree_Node *e) {
    if (t == NULL) {
        return NULL;
    }
    CONTAIN_CHECK
    return e->l_child;
}

Tree_Node *RightChild(BinaryTree *t, Tree_Node *e) {
    if (t == NULL) {
        return NULL;
    }
    CONTAIN_CHECK
    return e->r_child;
}

Tree_Node *LeftSibling(BinaryTree *t, Tree_Node *e) {
    if (t == NULL) {
        return NULL;
    }
    if (!Contains(t->root, e)) {
        return NULL;
    }
    if (t->root == e) {
        return NULL;
    }
    return LeftSiblingNode(t->root, e);
}

Tree_Node *RightSibling(BinaryTree *t, Tree_Node *e) {
    if (t == NULL) {
        return NULL;
    }
    if (!Contains(t->root, e)) {
        return NULL;
    }
    if (t->root == e) {
        return NULL;
    }
    return RightSiblingNode(t->root, e);
}

int InsertChild(BinaryTree *t, Tree_Node *e, int LR, BinaryTree *c) {
    TREE_NULL_CHECK
    CONTAIN_CHECK
    if (c->root->r_child != NULL) {
        return NULL;
    }
    Tree_Node *old;
    if (LR) {
        old = e->r_child;
        e->r_child = c->root;
        c->root->r_child = old;
    } else {
        old = e->l_child;
        e->l_child = c->root;
        c->root->r_child = old;
    }
    return RESULT_OK;
}

int DeleteChild(BinaryTree *t, Tree_Node *e, int LR) {
    TREE_NULL_CHECK
    CONTAIN_CHECK
    if (LR) {
        PostOrderDeleteNode(&e->r_child);
    } else {
        PostOrderDeleteNode(&e->l_child);
    }
    return RESULT_OK;
}

int PreOrderTraverse(BinaryTree *t, void (*Visit)(Tree_Node *)) {
    TREE_NULL_CHECK
    return PreOrderTraverseNode(t->root, Visit);
}

int InOrderTraverse(BinaryTree *t, void (*Visit)(Tree_Node *)) {
    TREE_NULL_CHECK
    return InOrderTraverseNode(t->root, Visit);
}

int PostOrderTraverse(BinaryTree *t, void (*Visit)(Tree_Node *)) {
    TREE_NULL_CHECK
    return PostOrderTraverseNode(t->root, Visit);
}

int LevelOrderTraverse(BinaryTree *t, void (*Visit)(Tree_Node *)) {
    TREE_NULL_CHECK
    L_NODE head;
    head.next = NULL;
    PushBack(&head, t->root);
    Tree_Node *c_node;
    while ((c_node = PopFront(&head))) {
        Visit(c_node);
        PushBack(&head, c_node->l_child);
        PushBack(&head, c_node->r_child);
    }
    return RESULT_OK;
}

int PreOrderTraverseNode(Tree_Node *n, void (*Visit)(Tree_Node *)) {
    if (n == NULL) {
        return RESULT_OK;
    }
    Visit(n);
    PreOrderTraverseNode(n->l_child, Visit);
    PreOrderTraverseNode(n->r_child, Visit);
    return RESULT_OK;
}

int InOrderTraverseNode(Tree_Node *n, void (*Visit)(Tree_Node *)) {
    if (n == NULL) {
        return RESULT_OK;
    }
    InOrderTraverseNode(n->l_child, Visit);
    Visit(n);
    InOrderTraverseNode(n->r_child, Visit);
    return RESULT_OK;
}

int PostOrderTraverseNode(Tree_Node *n, void (*Visit)(Tree_Node *)) {
    if (n == NULL) {
        return RESULT_OK;
    }
    PostOrderTraverseNode(n->l_child, Visit);
    PostOrderTraverseNode(n->r_child, Visit);
    Visit(n);
    return RESULT_OK;
}


Tree_Node *CreateNode(char *s) {
    if (s[CREATE_TREE_INDEX] == '\0') {
        return NULL;
    }

    if (s[CREATE_TREE_INDEX] == ' ') {
        CREATE_TREE_INDEX += 2;
        return NULL;
    }
    Tree_Node *n = (Tree_Node *) calloc(sizeof(Tree_Node), 1);
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

int PostOrderDeleteNode(Tree_Node **n) {
    if (*n == NULL) {
        return RESULT_OK;
    }
    PostOrderDeleteNode(&(*n)->l_child);
    PostOrderDeleteNode(&(*n)->r_child);
    FreeNode(n);
    return RESULT_OK;
}

bool Contains(Tree_Node *root, Tree_Node *n) {
    if (root == NULL) {
        return false;
    }
    if (root == n) {
        return true;
    }
    return Contains(root->l_child, n) | Contains(root->r_child, n);
}

void FreeNode(Tree_Node **n) {
    free(*n);
    *n = NULL;
}

int BiTreeHeight(Tree_Node *n) {
    if (n == NULL) {
        return 0;
    }
    int l = BiTreeHeight(n->l_child);
    int r = BiTreeHeight(n->r_child);
    return l > r ? l + 1 : r + 1;
}

Tree_Node *ParentNode(Tree_Node *n, Tree_Node *e) {
    if (n == NULL) {
        return NULL;
    }

    if (n->l_child == e || n->r_child == e) {
        return n;
    }

    Tree_Node *l_result = ParentNode(n->l_child, e);
    Tree_Node *r_result = ParentNode(n->r_child, e);
    return l_result == NULL ? r_result : l_result;
}

Tree_Node *LeftSiblingNode(Tree_Node *n, Tree_Node *e) {
    if (n == NULL || e == n->l_child) {
        return NULL;
    }

    if (e == n->r_child) {
        return n->l_child;
    }

    Tree_Node *l_result = LeftSiblingNode(n->l_child, e);
    Tree_Node *r_result = LeftSiblingNode(n->r_child, e);
    return l_result == NULL ? r_result : l_result;
}


Tree_Node *RightSiblingNode(Tree_Node *n, Tree_Node *e) {
    if (n == NULL || e == n->r_child) {
        return NULL;
    }

    if (e == n->l_child) {
        return n->r_child;
    }

    Tree_Node *l_result = RightSiblingNode(n->l_child, e);
    Tree_Node *r_result = RightSiblingNode(n->r_child, e);
    return l_result == NULL ? r_result : l_result;
}

void PushBack(L_NODE *head, Tree_Node *data) {
    if (data == NULL) {
        return;
    }
    while (head->next != NULL) {
        head = head->next;
    }
    L_NODE *n = (L_NODE *) calloc(sizeof(L_NODE), 1);
    n->next = NULL;
    n->data = data;
    head->next = n;
}

Tree_Node *PopFront(L_NODE *head) {
    if (head->next == NULL) {
        return NULL;
    }
    Tree_Node *e = head->next->data;
    head->next = head->next->next;
    return e;
}
