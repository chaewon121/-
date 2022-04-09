#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)

typedef struct {
	char name[100];
} element;

typedef struct ListNode { 
	// 노드 타입
	element data;
	struct ListNode* link;
} ListNode;
// 오류 처리 함수

void error(char* message)
{
	printf(stderr, "%s\n", message);
	exit(1);
}
//헤드노드 생성
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1)
	p->data = value; // (2)
	p->link = head; // 헤드 포인터의 값을 복사 //(3)
	head = p; // 헤드 포인터 변경 //(4)
	return head;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s->", p->data.name);
	printf("NULL \n");
}

ListNode* search_list(ListNode* head, element x)
{
	ListNode* p = head;
	while (p != NULL) {
		if (strcmp(p->data.name,x.name)==0) 
			return p;
		p = p->link;
	}
	return NULL; // 탐색 실패
}

//두개의 리스트 연결

ListNode* concat_list(ListNode* head1, ListNode* head2) {
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else {
		ListNode* p;
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}

}

ListNode* reverse(ListNode* head)
{
	ListNode* p, * q, * r;

	p = head;
	q = NULL;

	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}

void main(void)
{
	ListNode* head = NULL;
	ListNode* head2 = NULL;
	ListNode* concat = NULL;
	ListNode* reverse_list = NULL;
	element data;

	strcpy(data.name, "APPLE");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "KIWI");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "BANANA");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "추가1");
	head2 = insert_first(head2, data);
	print_list(head);

	strcpy(data.name, "추가2");
	head2 = insert_first(head2, data);
	print_list(head);

	printf("찾기시스템 \n");
	strcpy(data.name, "KIWI");
	if (search_list(head, data) != NULL)
		printf("리스트에서 KIWI을 찾았습니다. \n");
	else
		printf("리스트에서 KIWI을 찾지 못했습니다. \n");

	printf("두노드 연결하기 \n");
	if (search_list(head, data) != NULL)
		printf("리스트에서 KIWI을 찾았습니다. \n");
	else
		printf("리스트에서 KIWI을 찾지 못했습니다. \n");
	concat=concat_list(head, head2);
	print_list(concat);

	reverse_list = reverse(concat);
	print_list(reverse_list);

	return 0;
}

