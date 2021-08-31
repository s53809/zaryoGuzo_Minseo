#include <stdio.h>
#include "deque.h"

void de_error(char* message) {
	printf("%s\n", message);
	return;
}
void initDeque(DequeType* q) {
	q->front = q->rear = 0;
}
int de_isFull(DequeType* q) {
	return (q->front == (q->rear + 1) % MAX_DEQUE_SIZE);
}
int de_isEmpty(DequeType* q) {
	return (q->front == q->rear);
}
void addFront(DequeType* q, int item) {
	if (de_isFull(q)) {
		error("Deque is Full!\n");
		return;
	}
	if (q->front == 0) {
		q->front = MAX_DEQUE_SIZE - 1;
		q->data[q->front] = item;
	}
	else {
		q->data[--q->front] = item;
	}
}
void addRear(DequeType* q, int item) {
	if (de_isFull(q)) {
		error("Deque is Full!\n");
		return;
	}
	q->data[q->rear++] = item;
	if (q->rear == MAX_DEQUE_SIZE) {
		q->rear = 0;
	}
}
int deleteRear(DequeType* q) {
	if (de_isEmpty(q)) {
		error("Deque is Empty!\n");
		return;
	}
	if (q->rear == 0) {
		int box = q->rear;
		q->rear = MAX_DEQUE_SIZE - 1;
		return q->data[box];
	}
	else {
		return q->data[--q->rear];
	}
}
int deleteFront(DequeType* q) {
	if (de_isEmpty(q)) {
		error("Deque is Empty!\n");
		return;
	}
	if (q->front == MAX_DEQUE_SIZE - 1) {
		int box = q->front;
		q->front = 0;
		return q->data[box];
	}
	else {
		return q->data[q->front++];
	}
}
void displayDeque(DequeType* q) {
	if (de_isEmpty(q)) {
		error("Deque is Empty!\n");
		return;
	}
	printf("Deque - [front = %d, rear = %d]\t", q->front, q->rear);
	int start = q->front, end = q->rear;
	while (start != end) {
		printf("%d | ", q->data[start]);
		if (start + 1 == MAX_DEQUE_SIZE) {
			start = 0;
		}
		else {
			start++;
		}
	}
	printf("\n");
}