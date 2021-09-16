#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

ListNode* addFirst(ListNode* head, int item) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	p->link = head;
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
	}
	else {
		head = p;
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
		prev->link = p;
	}
	else {
		p->link = head;
		head = p;
	}
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
		deleteFirstNode(head);
	}
	while (tmp != NULL) {
		if (tmp->link == prev) {
			tmp->link = prev->link;
			free(prev);
			break;
		}
		tmp = tmp->link;
	}
	return head;
}

ListNode* reverseNode(ListNode* head) {
	ListNode* start = head;
	ListNode* box = NULL;
	ListNode* box2 = NULL;
	while (start != NULL) {
		box = start->link;
		start->link = box2;
		box2 = start;
		start = box;
	}
	head = box2;
}