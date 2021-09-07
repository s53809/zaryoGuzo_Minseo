#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
int main() {
	ArrayListType* list;
	list = (ArrayListType*)malloc(sizeof(ArrayListType));
	initArrayList(list);
	add(list, 10); printList(list);
	add(list, 20); printList(list);
	add(list, 30); printList(list);
	add(list, 40); printList(list);
	add(list, 50); printList(list);
	insert(list, 100, 1); printList(list);
	insert(list, 500, 5); printList(list);
	removeAt(list, 3); printList(list);
	removeItem(list, 100); printList(list);
	int index = 2;
	printf("%d ¹øÂ° °ª = %d\n", index, getAt(list, index));
	printf("ArrayList size is %d\n", count(list));
	return 0;
}