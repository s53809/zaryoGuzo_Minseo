#pragma once
#define MAX_QUEUE_SIZE 10
typedef struct queue {
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
}QueueType;

void error(char* message);

void initQueue(QueueType* q);

int isEmpty(QueueType* q);

int isFull(QueueType* q);

void displayQueue(QueueType* q);

void enQueue(QueueType* q, int item);

int deQueue(QueueType* q);

int size(QueueType* q);