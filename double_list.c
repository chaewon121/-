#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)

//리스트 구조체 선언

typedef struct ListNode {
    struct ListNode* llink;
    char data[4];
    struct ListNode* rlink;
}listNode;

typedef struct {
    listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* DL);
void insertNode(linkedList_h* DL, listNode* pre, char* x);
void deleteNode(linkedList_h* DL, listNode* old);
listNode* searchNode(linkedList_h* DL, char* x);


int main(void) {
    linkedList_h* DL;
    listNode* p;

    DL = createLinkedList_h();
    printf("(1) 이중 연결 리스트 생성하기!\n");
    printList(DL);
    
    printf("(2) 이중 연결 리스트에 [월] 노드 삽입하기! !\n");
    insertNode(DL, NULL, "월");
    printList(DL);

    printf("(3) 이중 연결 리스트에 [월] 노드 뒤에 [수] 노드 삽입하기! !\n");
    p = searchNode(DL, "월");
    insertNode(DL,p, "수");
    printList(DL);
    
    printf("(4) 이중 연결 리스트에 [수] 노드 뒤에 [금] 노드 삽입하기! !\n");
    p = searchNode(DL, "수");
    insertNode(DL, p, "금");
    printList(DL);

    printf("(5) 이중 연결 리스트에 [수] 노드 삭제하기! !\n");
    p = searchNode(DL, "수");
    deleteNode(DL, p);
    printList(DL);
    
    return 0;


}
linkedList_h* createLinkedList_h(void) {
    linkedList_h* DL;
    DL = (linkedList_h*)malloc(sizeof(linkedList_h));
    DL->head = NULL;
    return DL;
}

void printList(linkedList_h* DL) {
    listNode* p;
    printf(" DL=( ");
    p = DL->head;
    while (p != NULL) {
        printf("%s", p->data);
        p = p->rlink; //오른쪽 방향으로 탐색
        if (p != NULL)
            printf(",");
    }
    printf(")\n");
}
void deleteNode(linkedList_h* DL, listNode* old) {
    if (DL->head == NULL)// 리스트가 비어있으면
        return;
    else if (old == NULL)// 삭제할 노드가 없는경우
        return;
    else {
        old->llink->rlink = old->rlink;
        old->rlink->llink = old->llink;
        free(old);
    }
}
void insertNode(linkedList_h* DL, listNode* pre, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    if (DL->head == NULL) {  //리스트가 비어있으면
        newNode->rlink = NULL;
        newNode->llink = NULL;
        DL->head = newNode;
    }

    else {// 리스트가 비어있지 않으면
        newNode->rlink = pre->rlink;
        pre->rlink = newNode;
        newNode->llink = pre;
        if (newNode->rlink != NULL)
            newNode->rlink->llink = newNode;
    }
}
listNode* searchNode(linkedList_h* DL, char* x) {
    listNode* temp;
    temp = DL->head;
    while (temp != NULL) {
        if (strcmp(temp->data, x) == 0)
            return temp;
        else
            temp = temp->rlink;
    }
    return temp;
}




/*
9
A 1 D
A 2 a
A 3 y
D 1
P
G 3
A 1 S
P
G 3
*/


