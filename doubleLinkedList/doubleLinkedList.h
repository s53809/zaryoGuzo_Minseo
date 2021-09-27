#pragma once

typedef struct ListNode {
	int data;
	struct ListNode* link;
	struct ListNode* prevlink;	
}ListNode;

ListNode* addFirst(ListNode* head, int item);

void printLinkedList(ListNode* head);

void printReverseList(ListNode* head);

ListNode* add(ListNode* head, int item);

int size(ListNode* head);

ListNode* findNode(ListNode* head, int item);

ListNode* insert(ListNode* head, int target, int data);

ListNode* insertNum(ListNode* head, int N, int data);

ListNode* deleteFirstNode(ListNode* head);

ListNode* deleteNode(ListNode* head, int target);

ListNode* deleteNumNode(ListNode* head, int target);