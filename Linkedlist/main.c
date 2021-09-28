#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include <time.h>

int main() {
	srand(time(NULL));
	ListNode* head = NULL;
	int random, max, least;
	random = rand() % 100 + 1;
	head = addFirst(head, random);
	max = random;
	least = random;
	for (int i = 0; i < 19; i++) {
		random = rand() % 100 + 1;
		head = add(head, random);
		if (max < random) {
			max = random;
		}
		if (least > random) {
			least = random;
		}
	}
	printf("1�� ����\n");
	printf("�ִ� : %d\n�ּڰ� : %d\n", max, least);
	printLinkedList(head);
	head = deleteNode(head, max);
	head = deleteNode(head, least);
	printLinkedList(head);
	printf("2�� ����\n");
	ListNode* prev = head;
	while (prev != NULL) {
		if (prev->data % 2 == 1) {
			int deleteData = prev->data;
			if (prev != head) {
				prev = prev->link;
			}
			head = deleteNode(head, deleteData);
		}
		else {
			prev = prev->link;
		}
	}
	printLinkedList(head);
	printf("3�� ����\n");
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	head1 = add(head1, 10);
	head1 = add(head1, 15);
	head2 = add(head2, 10);
	head2 = add(head2, 15);
	printf("���� ��\nhead 1 : ");
	printLinkedList(head1);
	printf("head 2 : ");
	printLinkedList(head2);
	ListNode* hapHead = NULL;
	int Num = 0;
	ListNode* ping = head1;
	ListNode* pong = head2;
	while (ping != NULL || pong != NULL) {
		if (Num % 2) {
			hapHead = add(hapHead, ping->data);
			ping = ping->link;
		}
		else {
			hapHead = add(hapHead, pong->data);
			pong = pong->link;
		}
		Num++;
	}
	printf("���� ��\nhapHead : ");
	printLinkedList(hapHead);
	return 0;
}