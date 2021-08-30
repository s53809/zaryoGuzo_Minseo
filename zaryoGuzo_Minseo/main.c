#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "circularQueue.h"

void N1();
void N2();

int main() {
	printf("1. ��������1 2. ��������2\n");
	int num;
	scanf("%d", &num);
	switch (num) {
	case 1:
		N1();
	case 2:
		N2();
	}
}

void N1() {
	QueueType* q;
	q = (QueueType*)malloc(sizeof(QueueType));
	initQueue(q);

	int item = 0;
	srand(time(NULL));

	for (int i = 0; i < MAX_QUEUE_SIZE - 1; i++) {
		item = rand() % 50 + 1;
		printf("������ item = %d\n", item);
		enQueue(q, item);
		displayQueue(q);
	}
	printf("\n\n");
	for (int i = 0; i < MAX_QUEUE_SIZE - 1; i++) {
		item = deQueue(q);
		printf("������ item = %d\n", item);
		displayQueue(q);
	}
	printf("\n\n");
	for (int i = 0; i < MAX_QUEUE_SIZE - 1; i++) {
		item = rand() % 50 + 1;
		printf("������ item = %d\n", item);
		enQueue(q, item);
		displayQueue(q);
	}
}

void N2() {
	QueueType* q;
	q = (QueueType*)malloc(sizeof(QueueType));
	initQueue(q);
	int item, cnt = 0;
	printf("�ƹ�Ű�� �����ּ���. Ctrl+z ������ ����˴ϴ�.\n");
	char ch = 'A';
	getchar();
	getchar(); //�Է¹��� ����
	srand(time(NULL));
	do {
		if (rand() % 5 == 0) {
			item = rand() % 100;
			printf("������ data = %d\n", item);
			enQueue(q, item);
			displayQueue(q);
			cnt = 1;
		}
		if (rand() % 10 == 0) {
			int data = deQueue(q);
			printf("�Һ��� data = %d\n", data);
			displayQueue(q);
			cnt = 1;
		}
		if (cnt == 0) {
			printf("�ƹ��ϵ� �Ͼ�� �ʾҴ�.\n");
		}
		else {
			cnt = 0;
		}
		Sleep(500);
	} while (ch = getchar() != EOF);
}