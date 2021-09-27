#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"

ListNode* addFirst(ListNode* head, int item) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	if (head != NULL) {
		head->prevlink = p;
	}
	p->data = item;
	p->link = head;
	p->prevlink = NULL; //+
	head = p;
	
	return head;
}

void printLinkedList(ListNode* head) {
	ListNode* tmp = head;
	while (tmp != NULL) {
		printf("%d -> ", tmp->data);
		tmp = tmp->link;
	}
	printf("NULL \n");
}

void printReverseList(ListNode* head) {
	ListNode* tmp = head;
	while (tmp->link != NULL) {
		tmp = tmp->link;
	}
	while (tmp != NULL) {
		printf("%d -> ", tmp->data);
		tmp = tmp->prevlink;
	}
	printf("NULL \n");
}

ListNode* add(ListNode* head, int item) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	p->link = NULL;
	if (head != NULL) {
		ListNode* tmp = head;

		while (tmp->link != NULL) {
			tmp = tmp->link;
		}

		tmp->link = p;
		p->prevlink = tmp;
	}
	else {
		head = p;
		p->prevlink = NULL;
	}
	return head;
}

int size(ListNode* head) {
	ListNode* tmp = head;
	int count = 0;
	while (tmp != NULL) {
		count++;
		tmp = tmp->link;
	}
	return count;
}

ListNode* findNode(ListNode* head, int item) {
	ListNode* tmp = head;
	while (tmp != NULL) {
		if (tmp->data == item) {
			break;
		}
		else {
			tmp = tmp->link;
		}
	}
	return tmp;
}

ListNode* insert(ListNode* head, int target, int data) {
	ListNode* prev = findNode(head, target);
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = data;
	p->link = NULL;
	if (prev != NULL) {
		p->link = prev->link;
		prev->link->prevlink = p;
		p->prevlink = prev;
		prev->link = p;
	}
	else {
		p->link = head;
		p->prevlink = NULL;
		head->prevlink = p;
		head = p;
	}
	return head;
}

ListNode* insertNum(ListNode* head, int N, int data) {
	ListNode* prev = head;
	for (int i = 0; i < N - 2; i++) {
		prev = prev->link;
	}
	if (prev == NULL) {
		printf("List Overflow.\n");
		return head;
	}
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = data;
	p->link = prev->link;
	p->prevlink = prev;
	prev->link = p;
	p->link->prevlink = p;
	return head;
}

ListNode* deleteFirstNode(ListNode* head) {
	if (head->link == NULL) {
		printf("List is Empty\n");
		return head;
	}
	ListNode* tmp = head;
	ListNode* trash = head->link;
	tmp->data = head->link->data;
	tmp->link = head->link->link;
	tmp->prevlink = NULL;
	head->link->prevlink = head;
	free(trash);
	return head;
}

ListNode* deleteNode(ListNode* head, int target) {
	if (head->link == NULL) {
		printf("List is Empty\n");
		return head;
	}
	ListNode* prev = findNode(head, target);
	if (prev == NULL) {
		printf("target(%d) not found.\n", target);
		return head;
	}
	ListNode* tmp = head;
	if (tmp == prev) {
		return deleteFirstNode(head);
		
	}
	prev->prevlink->link = prev->link;
	prev->link->prevlink = prev->prevlink;
	free(prev);
	return head;
}

ListNode* deleteNumNode(ListNode* head, int N) {
	if (head->link == NULL) {
		printf("List is Empty\n");
		return head;
	}
	if (N == 1) { // 삽입하려는 값이 첫번째일때 예외처리
		head = deleteFirstNode(head);
		return head;
	}
	ListNode* prev = head;
	for (int i = 0; i < N - 2; i++) {
		prev = prev->link;
	}
	if (N == size(head)) {// 삽입하려는 값이 마지막일때 예외처리
		ListNode* trash = prev->link;
		prev->link = NULL;
		free(trash);
		return head;
	}
	ListNode* trash = prev->link;
	prev->link = trash->link;
	trash->link->prevlink = prev;
	free(trash);
	return head;
}