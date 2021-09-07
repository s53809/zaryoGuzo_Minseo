#include <stdio.h>
#include "arrayList.h"

void error(char* message) {
	fprintf(stderr, "%s\n", message);
}
void initArrayList(ArrayListType* l) {
	l->size = 0;
}
int isEmpty(ArrayListType* l) {
	return (l->size == 0);
}
int isFull(ArrayListType* l) {
	return (l->size == MAX_LIST_SIZE);
}

int getAt(ArrayListType* l, int index) {
	if (index < 0 || index >= l->size) {
		error("위치 오류");
	}
	return l->array[index];
}

int add(ArrayListType* l, int item) {
	if (isFull(l))
		error("ArrayList overflow");
	l->array[l->size++] = item;
	return 1;
}
int insert(ArrayListType* l, int item, int index) {
	if (isFull(l)) {
		error("ArrayList overflow");
		return -1;
	}
	l->size++;
	for (int i = l->size; i > index; i--) {
		l->array[i] = l->array[i - 1];
	}
	l->array[index] = item;
	return 0;
}
int indexOf(ArrayListType* l, int item) {
	for (int i = 0; i < l->size; i++) {
		if (l->array[i] == item) {
			return i;
		}
	}
	error("item is not found");
	return 0;
}
int removeItem(ArrayListType* l, int item) {
	if (isEmpty(l)) {
		error("ArrayList is empty");
		return -1;
	}
	int eraseIndex = -1;
	for (int i = 0; i < l->size; i++) {
		if (l->array[i] == item) {
			eraseIndex = i;
		}
	}
	if (eraseIndex == -1) {
		error("item is not found");
		return -1;
	}
	for (int i = eraseIndex; i < l->size; i++) {
		l->array[i] = l->array[i + 1];
	}
	l->size--;
	return 0;
}

int removeAt(ArrayListType* l, int index) {
	if (l->size == 0) {
		error("ArrayList is empty");
		return -1;
	}
	for (int i = index; i < l->size; i++) {
		l->array[i] = l->array[i + 1];
	}
	l->size--;
	return 0;
}
int removeAll(ArrayListType* l) {
	if (l->size == 0) {
		error("ArrayList is empty");
		return -1;
	}
	l->size = 0;
	return 0;
}
int count(ArrayListType* l) {
	return l->size;
}
void printList(ArrayListType* l) {
	for (int i = 0; i < l->size; i++) {
		printf("%d -> ", l->array[i]);
	}
	printf("\n");
}