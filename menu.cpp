#include <iostream>
#include "datastructure/linearlist.h"

extern "C" {
#include "datastructure/linkedlist.h"
}

typedef int ElemType;
typedef LinearList<ElemType>::List *LIST;

void print_list(LIST l);

void print_linked_list(List l);

int linear_table_menu() {
    LIST L;
    int op = 1;
    while (op) {
        printf("\n\n");
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. InitialList       7. LocateElem\n");
        printf("    	  2. DestroyList     8. PriorElem\n");
        printf("    	  3. ClearList       9. NextElem \n");
        printf("    	  4. ListEmpty     10. ListInsert\n");
        printf("    	  5. ListLength     11. ListDelete\n");
        printf("    	  6. GetElem       12. ListTraverse\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    Please choose your operation[0~12]:");
        std::cin >> op;
        ElemType a;
        ElemType b;
        int i = 0;
        switch (op) {
            case 1:
                if (LinearList<ElemType>::InitialList(&L) == RESULT_OK) {
                    printf("LinearList Created Successfully.\n");
                } else {
                    printf("LinearList Create Failed. \n");
                }
                break;
            case 2:
                if (LinearList<ElemType>::DestroyList(&L) == RESULT_OK) {
                    printf("LinearList Destroyed Successfully.\n");
                } else {
                    printf("LinearList Destroy Failed.\n");
                }
                break;
            case 3:
                if (LinearList<ElemType>::ClearList(L) == RESULT_OK) {
                    printf("LinearList Cleared Successfully.\n");
                    print_list(L);
                } else {
                    printf("LinearList Cleared Failed.\n");
                }
                break;
            case 4:
                if (LinearList<ElemType>::ListEmpty(L)) {
                    printf("List Is Empty.\n");
                } else {
                    printf("List Is Not Empty.\n");
                }
                break;
            case 5:
                printf("List Length Is %zd.\n", LinearList<ElemType>::ListLength(L));
                break;
            case 6:
                std::cout << "Please Input The i" << std::endl;
                std::cin >> i;
                LinearList<ElemType>::GetElem(L, i, a);
                std::cout << "The  Elem Is: " << a << std::endl;
                break;
            case 7:
                std::cout << "Please Input The Elem" << std::endl;
                std::cin >> a;
                std::cout << "The Elem Index Is: "
                          << LinearList<ElemType>::LocateElem(L, a, [](ElemType a1, ElemType a2) {
                              return a1 == a2;
                          }) << std::endl;
                break;
            case 8:
                std::cout << "Please Input The Elem" << std::endl;
                std::cin >> a;
                if (LinearList<ElemType>::PriorElem(L, a, b) == RESULT_OK) {
                    std::cout << "The Piror Elem Is: " << b << std::endl;
                }
                break;
            case 9:
                std::cout << "Please Input The Elem" << std::endl;
                std::cin >> a;
                if (LinearList<ElemType>::PriorElem(L, a, b) == RESULT_OK) {
                    LinearList<ElemType>::NextElem(L, a, b);
                }
                std::cout << "The Next Elem Is: " << b << std::endl;
                break;
            case 10:
                std::cout << "Please Input The i" << std::endl;
                std::cin >> i;
                std::cout << "Please Input The Elem" << std::endl;
                std::cin >> a;
                if (LinearList<ElemType>::ListInsert(L, i, a) == RESULT_OK) {
                    print_list(L);
                }
                break;
            case 11:
                std::cout << "Please Input The i" << std::endl;
                std::cin >> i;
                std::cout << "The Deleted Elem Is" << LinearList<ElemType>::ListDelete(L, i, a) << std::endl;
                break;
            case 12:
                print_list(L);
                break;
            case 0:
                break;
        }//end of switch
    }//end of while
    printf("欢迎下次再使用本系统！\n");
    return 0;
}//end of main()

int linked_list_menu() {
    List *L;
    int op = 1;
    while (op) {
        printf("\n\n");
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. InitialList       7. LocateElem\n");
        printf("    	  2. DestroyList     8. PriorElem\n");
        printf("    	  3. ClearList       9. NextElem \n");
        printf("    	  4. ListEmpty     10. ListInsert\n");
        printf("    	  5. ListLength     11. ListDelete\n");
        printf("    	  6. GetElem       12. ListTraverse\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    Please choose your operation[0~12]:");
        std::cin >> op;
        ElemType a;
        ElemType b;
        int i = 0;
        switch (op) {
            case 1:
                if (InitialList(&L) == RESULT_OK) {
                    printf("LinearList Created Successfully.\n");
                } else {
                    printf("LinearList Create Failed. \n");
                }
                break;
            case 2:
                if (DestroyList(L) == RESULT_OK) {
                    printf("LinearList Destroyed Successfully.\n");
                } else {
                    printf("LinearList Destroy Failed.\n");
                }
                break;
            case 3:
                if (ClearList(L) == RESULT_OK) {
                    printf("LinearList Cleared Successfully.\n");
                    print_linked_list(*L);
                } else {
                    printf("LinearList Cleared Failed.\n");
                }
                break;
            case 4:
                if (ListEmpty(L)) {
                    printf("List Is Empty.\n");
                } else {
                    printf("List Is Not Empty.\n");
                }
                break;
            case 5:
                printf("List Length Is %d.\n", ListLength(L));
                break;
            case 6:
                std::cout << "Please Input The i" << std::endl;
                std::cin >> i;
                if (GetElem(L, i, &a) == RESULT_OK) {
                    std::cout << "The  Elem Is: " << a << std::endl;
                }
                break;
            case 7:
                std::cout << "Please Input The Elem" << std::endl;
                std::cin >> a;
                std::cout << "The Elem Index Is: "
                          << LocateElem(L, a, [](ElemType a1, ElemType a2) {
                              return a1 == a2;
                          }) << std::endl;
                break;
            case 8:
                std::cout << "Please Input The Elem" << std::endl;
                std::cin >> a;
                if (PriorElem(L, a, &b) == RESULT_OK) {
                    std::cout << "The Piror Elem Is: " << b << std::endl;
                }
                break;
            case 9:
                std::cout << "Please Input The Elem" << std::endl;
                std::cin >> a;
                if (PriorElem(L, a, &b) == RESULT_OK) {
                    NextElem(L, a, &b);
                }
                std::cout << "The Next Elem Is: " << b << std::endl;
                break;
            case 10:
                std::cout << "Please Input The i" << std::endl;
                std::cin >> i;
                std::cout << "Please Input The Elem" << std::endl;
                std::cin >> a;
                if (ListInsert(L, i, a) == RESULT_OK) {
                    print_linked_list(*L);
                }
                break;
            case 11:
                std::cout << "Please Input The i" << std::endl;
                std::cin >> i;
                if (ListDelete(L, i, &a) == RESULT_OK) {
                    std::cout << "The Deleted Elem Is" << a << std::endl;
                }
                break;
            case 12:
                print_linked_list(*L);
                break;
            case 0:
                break;
        }//end of switch
    }//end of while
    printf("欢迎下次再使用本系统！\n");
    return 0;
}//end of main()

void print_list(LIST l) {
    printf("The List Content now:\n");
    LinearList<ElemType>::ListTraverse(l, [](ElemType data) -> void {
        std::cout << data;
        std::cout << " ";
    });
    printf("\n");
}

void print_linked_list(List l) {
    printf("The List Content now:\n");
    ListTraverse(&l, [](ElemType data) -> void {
        std::cout << data;
        std::cout << " ";
    });
    printf("\n");
}



