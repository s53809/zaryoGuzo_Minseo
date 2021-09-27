#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"

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

	printf("Reverse\n");
	printReverseList(head);

	printf("\nAfter deleteFirstNode()\n");
	head = deleteFirstNode(head);
	printLinkedList(head);
	printReverseList(head);

	printf("\nAfter deleteNode(15)\n");
	head = deleteNode(head, 15);
	printLinkedList(head);
	printReverseList(head);

	printf("\nAfter deleteNode(95)\n");
	head = deleteNode(head, 95);
	printLinkedList(head);
	printReverseList(head);

	printf("\nAfter deleteNode(95)\n");
	head = deleteNode(head, 95);
	printLinkedList(head);
	printReverseList(head);

	printf("\nAfter insertNum(2,12)\n");
	head = insertNum(head, 2, 12);
	printLinkedList(head);
	printReverseList(head);

	printf("\nAfter deleteNumNode(3)\n");
	head = deleteNumNode(head, 3);
	printLinkedList(head);
	printReverseList(head);
	return 0;
}