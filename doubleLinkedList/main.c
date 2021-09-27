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
	printReverseList(head);
	printLinkedList(head);

	printf("\nAfter deleteNode(15)\n");
	head = deleteNode(head, 15);
	printReverseList(head);
	printLinkedList(head);

	printf("\nAfter deleteNode(95)\n");
	head = deleteNode(head, 95);
	printReverseList(head);
	printLinkedList(head);

	printf("\nAfter deleteNode(95)\n");
	head = deleteNode(head, 95);
	printReverseList(head);
	printLinkedList(head);

	printf("\ninsertNum(2,12)\n");
	head = insertNum(head, 2, 12);
	printReverseList(head);
	printLinkedList(head);

	printf("\ndeleteNumNode(3)\n");
	head = deleteNumNode(head, 3);
	printReverseList(head);
	printLinkedList(head);
	return 0;
}