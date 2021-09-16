#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main() {
	ListNode* head = NULL;
	head = addFirst(head, 10);
	printLinkedList(head);
	head = add(head, 20);
	printLinkedList(head);
	head = insert(head, 10, 15);
	printLinkedList(head);
	head = insert(head, 90, 95);
	printLinkedList(head);
	head = insert(head, 100, 110);
	head = add(head, 15);
	printLinkedList(head);
	printf("\nAfter deleteFirstNode()\n");
	head = deleteFirstNode(head);
	printLinkedList(head);
	printf("\nAfter deleteNode(15)\n");
	head = deleteNode(head, 15);
	printLinkedList(head);
	printf("\nAfter deleteNode(95)\n");
	head = deleteNode(head, 95);
	printLinkedList(head);
	printf("\nAfter deleteNode(95)\n");
	head = deleteNode(head, 95);
	printLinkedList(head);
	printf("\nReverseNode \n");
	head = reverseNode(head);
	printLinkedList(head);
	return 0;
}