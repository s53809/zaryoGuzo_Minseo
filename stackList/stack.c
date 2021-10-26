#include <stdio.h>
#include "stack.h"

int isEmpty() {
	return (top == NULL);
}
void makeFree() {
	StackListNode* temp;
	while (top != NULL) {
		temp = top;
		top = top->link;
		free(temp);
	}
}
void push(int item) {
	StackListNode* temp = (StackListNode*)malloc(sizeof(StackListNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}
int pop() {
	int deleteData = 0;
	deleteData = top->data;
	StackListNode* deleteNode = top;
	top = top->link;
	free(deleteNode);
	return deleteData;
}
int peek() {
	return top->data;
}
void displayStack() {
	if (isEmpty()) {
		printf("\n Stack is empty ! \n");
		return;
	}
	StackListNode* temp = top;
	while (temp != NULL) {
		printf("%c ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}