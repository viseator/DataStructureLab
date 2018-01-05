//
// Created by viseator on 12/29/17.
//

#include "GraphMenu.h"

extern "C" {
#include "datastructure/Graph.h"
}

#include <cstdio>
#include <iostream>

void visit(Vex *v);

void GraphMenu() {
    using namespace std;
    Graph *G;
    int op = 1;
    int vex_data[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int edge_info[] = {1, 2, 1, 4, 2, 3, 2, 5, 2, 7, 3, 6, 5, 1, 5, 4, 5, 7, 6, 2};
    while (op) {
        printf("\n\n");
        printf("      Menu for Graph Test\n");
        printf("-------------------------------------------------\n");
        printf("    	  1. CreateGraph       7. NextAdjVex\n");
        printf("    	  2. DestroyGraph      8. InsertVex\n");
        printf("    	  3. LocateVex         9. DeleteVex \n");
        printf("    	  4. GetVex            10. DFSTraverse\n");
        printf("    	  5. PutVex            11. BFSTraverse\n");
        printf("    	  6. FirstAdjVex       12. ShowAllEdges\n");
        printf("    	  13. InsertArc        14. DeleteArc\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    Please choose your operation[0~12]:");
        std::cin >> op;
        ElemType a;
        ElemType b;
        int i = 0;
        switch (op) {
            case 1:
                if (CreateGraph(&G, vex_data, 8, edge_info, 16) == RESULT_OK) {
                    printf("Graph Created Successfully.\n");
                    ShowAllEdges(G);
                } else {
                    printf("Graph Create Failed. \n");
                }
                break;
            case 2:
                if (DestroyGraph(&G) == RESULT_OK) {
                    printf("Graph Destroyed Successfully.\n");
                } else {
                    printf("LinearList Destroy Failed.\n");
                }
                break;
            case 3: {
                ElemType i;
                cout << "Please Input Data:" << endl;
                cin >> i;
                int result = LocateVex(G, i);
                if (result != -1) {
                    cout << "The Location is " << result << endl;
                } else {
                    cout << "Not Found" << endl;
                }
                break;
            }
            case 4: {
                cout << "Please Input Index:" << endl;
                int i;
                cin >> i;
                Vex *result = GetVex(G, i);
                if (result != NULL) {
                    cout << "The Data is " << result->data << endl;
                } else {
                    cout << "Index Error" << endl;
                }
                break;
            }
            case 5: {
                cout << "Please Input the Vex:" << endl;
                int i;
                cin >> i;
                cout << "Please Input the Vex Data:" << endl;
                ElemType data;
                cin >> data;
                int result = PutVex(G, GetVex(G, i), data);
                if (result == RESULT_OK) {
                    ShowAllEdges(G);
                } else if (result == NULL_PTR_ERROR) {
                    cout << "NULL Pointer Error" << endl;
                } else if (result == INDEX_OUT_OF_RANGE_ERROR) {
                    cout << "Index Out of Range Error" << endl;
                }
                break;
            }
            case 6: {
                cout << "Please Input the Vex:" << endl;
                int i;
                cin >> i;
                i = LocateVex(G, i);
                if (i == -1) {
                    cout << "Not Found!" << endl;
                    break;
                }
                Vex *result = FirstAdjVex(G, GetVex(G, i));
                if (result == NULL) {
                    cout << "Unknown Error!" << endl;
                } else {
                    cout << "The Data is: " << result->data << endl;
                }
                break;
            }
            case 7: {
                cout << "Please Input the Start Vex:" << endl;
                int i;
                cin >> i;
                i = LocateVex(G, i);
                if (i == -1) {
                    cout << "Not Found!" << endl;
                    break;
                }
                cout << "Please Input the Target Vex:" << endl;
                int i1;
                cin >> i1;
                i1 = LocateVex(G, i1);
                if (i1 == -1) {
                    cout << "Not Found!" << endl;
                    break;
                }
                Vex *result = NextAdjVex(G, GetVex(G, i), GetVex(G, i1));
                if (result == NULL) {
                    cout << "NULL" << endl;
                } else {
                    cout << "The Data is: " << result->data << endl;
                }
                break;
            }
            case 8: {
                ElemType data;
                std::cout << "Please Input the Element Data" << std::endl;
                std::cin >> data;
                Vex *new_vex = (Vex *) calloc(1, sizeof(Vex));
                new_vex->data = data;
                new_vex->first.next = NULL;
                if (InsertVex(G, new_vex) == RESULT_OK) {
                    ShowAllEdges(G);
                } else {
                    cout << "Unknown Error!" << endl;
                }
                break;
            }
            case 9: {
                cout << "Please Input the Vex:" << endl;
                int i;
                cin >> i;
                i = LocateVex(G, i);
                if (i == -1) {
                    cout << "Not Found!" << endl;
                    break;
                }
                if (DeleteVex(G, GetVex(G, i)) == RESULT_OK) {
                    ShowAllEdges(G);
                } else {
                    cout << "Unknown Error!" << endl;
                }
                break;
            }
            case 10:
                DFSTraverse(G, &visit);
                break;
            case 11:
                BFSTraverse(G, &visit);
                break;
            case 12:
                ShowAllEdges(G);
                break;
            case 13: {
                cout << "Please Input the Start Vex:" << endl;
                int i;
                cin >> i;
                i = LocateVex(G, i);
                if (i == -1) {
                    cout << "Not Found!" << endl;
                    break;
                }
                cout << "Please Input the End Vex:" << endl;
                int i1;
                cin >> i1;
                i1 = LocateVex(G, i1);
                if (i1 == -1) {
                    cout << "Not Found!" << endl;
                    break;
                }
                if (InsertArc(G, GetVex(G, i), GetVex(G, i1)) == RESULT_OK) {
                    ShowAllEdges(G);
                } else {
                    cout << "Unknown Error" << endl;
                }
                break;
            }
            case 14: {
                cout << "Please Input the Start Vex:" << endl;
                int i;
                cin >> i;
                i = LocateVex(G, i);
                if (i == -1) {
                    cout << "Not Found!" << endl;
                    break;
                }
                cout << "Please Input the End Vex:" << endl;
                int i1;
                cin >> i1;
                i1 = LocateVex(G, i1);
                if (i1 == -1) {
                    cout << "Not Found!" << endl;
                    break;
                }
                if (DeleteArc(G, GetVex(G, i), GetVex(G, i1)) == RESULT_OK) {
                    ShowAllEdges(G);
                } else {
                    cout << "Not Contain Error" << endl;
                }
                break;

            }

            case 0:
                break;
        }//end of switch
    }//end of while
    printf("欢迎下次再使用本系统！\n");
}

void visit(Vex *v) {
    printf("%d ", v->data);
}
