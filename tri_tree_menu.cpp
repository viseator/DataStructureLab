//
// Created by viseator on 12/17/17.
//

#include <iostream>
#include <cstdio>
#include "tri_tree_menu.h"

extern "C" {
#include "datastructure/BinaryTree.h"
}

void visit(Tree_Node *n);

void printBiTree(BinaryTree *T) {
    LevelOrderTraverse(T, &visit);
    printf("\n");
}

int tri_tree_menu() {
    using namespace std;
    BinaryTree *T;
    char *s = "1 2 3 4     5     6     7 8 9     10     11     ";
    char *ss = "12 13       ";

    int op = 1;
    while (op) {
        printf("\n\n");
        printf("              Menu for BiTree Test\n");
        printf("-------------------------------------------------\n");
        printf("    	  1. InitialBiTree       11. LeftChild\n");
        printf("    	  2. DestroyBiTree       12. RightChild\n");
        printf("    	  3. CreateBiTree        13. LeftSibling \n");
        printf("    	  4. ClearBiTree         14. RightSibling\n");
        printf("    	  5. BiTreeEmpty         15. InsertChild\n");
        printf("    	  6. BiTreeDepth         16. DeleteChild\n");
        printf("    	  7. Root                17. PreOrderTraverse\n");
        printf("    	  8. Value               18. InOrderTraverse\n");
        printf("    	  9. Assign              19. PostOrderTraverse\n");
        printf("    	  10.Parent              20. LevelOrderTraverse\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    Please choose your operation[0~20]:");
        std::cin >> op;
        ElemType a;
        ElemType b;
        int i = 0;
        switch (op) {
            case 1:
                if (InitBiTree(&T) == RESULT_OK) {
                    printf("BiTree Created Successfully.\n");
                } else {
                    printf("BiTree Create Failed. \n");
                }
                break;
            case 2:
                if (DestroyBitTree(&T) == RESULT_OK) {
                    printf("BiTree Destroyed Successfully.\n");
                } else {
                    printf("BiTree Destroy Failed.\n");
                }
                break;
            case 3:
                if (CreateBiTree(T, s) == RESULT_OK) {
                    printf("BiTree Created Successfully.\n");
                    printBiTree(T);
                } else {
                    printf("BiTree Created Failed.\n");
                }
                break;
            case 4:
                if (ClearBitTree(T) == RESULT_OK) {
                    printf("BiTree Cleared Successfully.\n");
                } else {
                    printf("BiTree Cleared Failed.\n");
                }
                break;
            case 5:
                if (BiTreeEmpty(T)) {
                    printf("BiTree Is Empty.\n");
                } else {
                    printf("BiTree Is Not Empty.\n");
                }
                break;
            case 6: {

                int depth = BiTreeDepth(T);
                if (depth <= 0) {
                    printf("Error!\n");
                } else {
                    printf("Tree Depth Is %d.\n", depth);
                }
            }
                break;
            case 7: {

                Tree_Node *root = Root(T);
                std::cout << "The Root Value Is: " << root->data << std::endl;
            }
                break;
            case 8: {
                cout << "Please input the index:" << endl;
                cin >> i;
                Tree_Node *e = Value(T, i);
                if (e == NULL) {
                    cout << "Index Out of Range Error" << endl;
                } else {
                    cout << "The Value is:" << e->data << endl;
                }
            }
                break;
            case 9: {
                int value;
                cout << "Please input the index:" << endl;
                cin >> i;
                cout << "Please input the value:" << endl;
                cin >> value;
                Tree_Node *e = Value(T, i);
                if (e == NULL) {
                    cout << "Index Out of Range Error" << endl;
                } else {
                    Assign(T, e, value);
                    printBiTree(T);
                }
            }
                break;
            case 10: {
                cout << "Please input the index:" << endl;
                cin >> i;
                Tree_Node *e = Value(T, i);
                if (e == NULL) {
                    cout << "Index Out of Range Error" << endl;
                }
                Tree_Node *p = Parent(T, e);
                if (p == NULL) {
                    cout << "No parent" << endl;
                } else {
                    cout << "The parent value is:" << p->data << endl;
                }
            }
                break;
            case 11: {
                cout << "Please input the index:" << endl;
                cin >> i;
                Tree_Node *e = Value(T, i);
                if (e == NULL) {
                    cout << "Index Out of Range Error" << endl;
                }
                Tree_Node *l = LeftChild(T, e);
                if (l == NULL) {
                    cout << "No left child" << endl;
                } else {
                    cout << "The left child value is:" << l->data << endl;
                }
            }
                break;
            case 12: {
                cout << "Please input the index:" << endl;
                cin >> i;
                Tree_Node *e = Value(T, i);
                if (e == NULL) {
                    cout << "Index Out of Range Error" << endl;
                }
                Tree_Node *l = RightChild(T, e);
                if (l == NULL) {
                    cout << "No right child" << endl;
                } else {
                    cout << "The right child value is:" << l->data << endl;
                }
            }
                break;
            case 13: {
                cout << "Please input the index:" << endl;
                cin >> i;
                Tree_Node *e = Value(T, i);
                if (e == NULL) {
                    cout << "Index Out of Range Error" << endl;
                }
                Tree_Node *l = LeftSibling(T, e);
                if (l == NULL) {
                    cout << "No left sibling" << endl;
                } else {
                    cout << "The left sibling value is:" << l->data << endl;
                }
            }
                break;
            case 14: {
                cout << "Please input the index:" << endl;
                cin >> i;
                Tree_Node *e = Value(T, i);
                if (e == NULL) {
                    cout << "Index Out of Range Error" << endl;
                }
                Tree_Node *l = RightSibling(T, e);
                if (l == NULL) {
                    cout << "No right sibling" << endl;
                } else {
                    cout << "The right sibling value is:" << l->data << endl;
                }
            }
                break;
            case 15: {
                int lr;
                cout << "Please input the index:" << endl;
                cin >> i;
                cout << "Please input the LR:" << endl;
                cin >> lr;
                Tree_Node *e = Value(T, i);
                if (e == NULL) {
                    cout << "Index Out of Range Error" << endl;
                }
                BinaryTree *TT;
                InitBiTree(&TT);
                CreateBiTree(TT, ss);
                if (InsertChild(T, e, lr, TT) == RESULT_OK) {
                    cout << "Insert Done" << endl;
                    printBiTree(T);
                } else {
                    cout << "Insert Error" << endl;
                }
            }
                break;
            case 16: {
                int lr;
                cout << "Please input the index:" << endl;
                cin >> i;
                cout << "Please input the LR:" << endl;
                cin >> lr;
                Tree_Node *e = Value(T, i);
                if (e == NULL) {
                    cout << "Index Out of Range Error" << endl;
                }
                if (DeleteChild(T, e, lr) == RESULT_OK) {
                    cout << "Delete Done" << endl;
                    printBiTree(T);
                } else {
                    cout << "Delete Error";
                }
            }
                break;
            case 17: {
                PreOrderTraverse(T, &visit);
            }
                break;
            case 18: {
                InOrderTraverse(T, &visit);
            }
                break;
            case 19: {
                PostOrderTraverse(T, &visit);
            }
                break;
            case 20: {
                LevelOrderTraverse(T, &visit);
            }
                break;
            case 0:
                break;
            default:
                break;
        }//end of switch
    }//end of while
    printf("欢迎下次再使用本系统！\n");
    return 0;
}

void visit(Tree_Node *n) {
    printf("%d ", n->data);
}

