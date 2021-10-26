#pragma once

typedef struct {
	int data;
	struct StackListNode* link;
}StackListNode;

StackListNode* top;

int isEmpty();
void makeFree();
void push(int item);
int pop();
int peek();
void displayStack();