#pragma once
#define MAX_DEQUE_SIZE 10

typedef struct {
	int data[MAX_DEQUE_SIZE];
	int front;
	int rear;
}DequeType;

void de_error(char* message);
void initDeque(DequeType* q);
int de_isFull(DequeType* q);
int de_isEmpty(DequeType* q);
void addFront(DequeType* q, int item);
void addRear(DequeType* q, int item);
int deleteRear(DequeType* q);
int deleteFront(DequeType* q);
void displayDeque(DequeType* q);