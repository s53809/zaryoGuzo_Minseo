#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include "circularQueue.h"
#include "deque.h"

void N1();
void N2();
void N3();
void N4();
void N5();
void N6();

int main() {
	printf("1. ��������1 / 2. ��������2 / 3. ��������5(size() ����) / 4. ��������6(�Ǻ���ġ ����)\n5.Deque Test / 6.��������7(palindrome)\n");
	int num;
	scanf("%d", &num);
	switch (num) {
	case 1:
		N1();
		break;
	case 2:
		N2();
		break;
	case 3:
		N3();
		break;
	case 4:
		N4();
		break;
	case 5:
		N5();
	case 6:
		N6();
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

void N3() {
	QueueType* q;
	q = (QueueType*)malloc(sizeof(QueueType));
	initQueue(q);
	enQueue(q, 3);
	enQueue(q, 4);
	enQueue(q, 5);
	enQueue(q, 6);
	deQueue(q);
	enQueue(q, 7);
	printf("Size is %d\n", size(q));
}

void N4() {
	QueueType* q;
	q = (QueueType*)malloc(sizeof(QueueType));
	initQueue(q);
	enQueue(q, 0);
	enQueue(q, 1);
	int N;
	scanf("%d", &N);
	if (N == 1) {
		printf("F(1) = 0");
		return;
	}
	for (int i = 0; i < N - 2; i++) {
		if (q->rear != 0) {
			enQueue(q, q->data[q->front] + q->data[q->rear - 1]);
		}
		else {
			enQueue(q, q->data[q->front] + q->data[MAX_QUEUE_SIZE - 1]);
		}
		deQueue(q);
	}
	deQueue(q);
	printf("F(%d) = %d", N, deQueue(q));
}

void N5() {
	DequeType* q;
	q = (DequeType*)malloc(sizeof(DequeType));
	initDeque(q);
	addRear(q, 10);
	displayDeque(q);
	addRear(q, 20);
	displayDeque(q);
	addFront(q, 30);
	displayDeque(q);
}

void N6() {
	DequeType* q;
	q = (DequeType*)malloc(sizeof(DequeType));
	initDeque(q);
	char x[1000];
	scanf("%s", x);
	for (int i = 0; i < strlen(x); i++) {
		addRear(q, x[i]);
	}
	int isNotPalin = 0;
	while (1) {
		int first = deleteFront(q);
		if (de_isEmpty(q)) {
			break;
		}
		int last = deleteRear(q);
		if (first == last) {
			continue;
		}
		else {
			isNotPalin = 1;
			break;
		}
	}
	if (isNotPalin == 1) {
		printf("�縰����� �ƴմϴ�.\n");
	}
	else {
		printf("�縰��� �Դϴ�.\n");
	}
}