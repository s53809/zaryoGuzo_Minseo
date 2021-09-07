#include <stdio.h>
#include "circularQueue.h"

void error(char* message) {
	printf("%s\n", message);
	return;
}

void initQueue(QueueType* q) {
	q->front = q->rear = 0;
}

int isEmpty(QueueType* q) {
	return (q->front == q->rear);
}

int isFull(QueueType* q) {
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

void displayQueue(QueueType* q) {
	if (isEmpty(q)) {
		error("Queue is Empty!\n");
		return;
	}
	printf("Circulator Queue - [front = %d, rear = %d]\t", q->front, q->rear);
	int start = q->front, end = q->rear;
	while (start != end) {
		printf("%d | ", q->data[start]);
		if (start + 1 == MAX_QUEUE_SIZE) {
			start = 0;
		}
		else {
			start++;
		}
	}
	printf("\n");
}

void enQueue(QueueType* q, int item) {
	if (isFull(q)) {
		error("Queue is Full!\n");
		return;
	}
	q->data[q->rear++] = item;
	if (q->rear == MAX_QUEUE_SIZE) {
		q->rear = 0;
	}
}

int deQueue(QueueType* q) {
	if (isEmpty(q)) {
		error("Queue is Empty!\n");
		return;
	}
	if (q->front == MAX_QUEUE_SIZE - 1) {
		int box = q->front;
		q->front = 0;
		return q->data[box];
	}
	else {
		return q->data[q->front++];
	}
}
int size(QueueType* q) {
	int start = q->front;
	int cnt = 0;
	while (start != q->rear) {
		cnt++;
		start++;
		if (start == MAX_QUEUE_SIZE) {
			start = 0;
		}
	}
	return cnt;
}