#pragma once

typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

ListNode* addFirst(ListNode* head, int item);

void printLinkedList(ListNode* head);

ListNode* add(ListNode* head, int item);

int size(ListNode* head);

ListNode* findNode(ListNode* head, int item);

ListNode* insert(ListNode* head, int target, int data);

ListNode* deleteFirstNode(ListNode* head);

ListNode* deleteNode(ListNode* head, int target);

ListNode* reverseNode(ListNode* head);