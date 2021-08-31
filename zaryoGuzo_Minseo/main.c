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
	printf("1. 예제문제1 / 2. 예제문제2 / 3. 연습문제5(size() 구현) / 4. 연습문제6(피보나치 수열)\n5.Deque Test / 6.연습문제7(palindrome)\n");
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
		printf("삽입할 item = %d\n", item);
		enQueue(q, item);
		displayQueue(q);
	}
	printf("\n\n");
	for (int i = 0; i < MAX_QUEUE_SIZE - 1; i++) {
		item = deQueue(q);
		printf("삭제할 item = %d\n", item);
		displayQueue(q);
	}
	printf("\n\n");
	for (int i = 0; i < MAX_QUEUE_SIZE - 1; i++) {
		item = rand() % 50 + 1;
		printf("삽입할 item = %d\n", item);
		enQueue(q, item);
		displayQueue(q);
	}
}

void N2() {
	QueueType* q;
	q = (QueueType*)malloc(sizeof(QueueType));
	initQueue(q);
	int item, cnt = 0;
	printf("아무키나 눌러주세요. Ctrl+z 누르면 종료됩니다.\n");
	char ch = 'A';
	getchar();
	getchar(); //입력버퍼 비우기
	srand(time(NULL));
	do {
		if (rand() % 5 == 0) {
			item = rand() % 100;
			printf("생산자 data = %d\n", item);
			enQueue(q, item);
			displayQueue(q);
			cnt = 1;
		}
		if (rand() % 10 == 0) {
			int data = deQueue(q);
			printf("소비자 data = %d\n", data);
			displayQueue(q);
			cnt = 1;
		}
		if (cnt == 0) {
			printf("아무일도 일어나지 않았다.\n");
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
		printf("펠린드롬이 아닙니다.\n");
	}
	else {
		printf("펠린드롬 입니다.\n");
	}
}