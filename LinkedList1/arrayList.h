#pragma once
#define MAX_LIST_SIZE 10

typedef struct list {
	int	 array[MAX_LIST_SIZE];
	int size;
}ArrayListType;

void error(char* message);
void initArrayList(ArrayListType* l);
int isEmpty(ArrayListType* l);
int isFull(ArrayListType* l);

int getAt(ArrayListType* l, int index);

int add(ArrayListType* l, int item);
int insert(ArrayListType* l, int item, int index);
int indexOf(ArrayListType* l, int item);
int removeItem(ArrayListType* l, int item);
int removeAt(ArrayListType* l, int index);
int removeAll(ArrayListType* l);
int count(ArrayListType* l);
void printList(ArrayListType* l);