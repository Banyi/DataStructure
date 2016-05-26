#include<stdio.h>
#include "list.c"
#include "list.h"


int main(void)
{
	LinkList a, b, Lb, pList;
	int len = 0;
	int i = 0;
	ElemType e, item, count;
	initList(&a);
	
	printf("Input:");
	scanf("%d", &len);
	
	createList(a, len);   
	showList(a);
	
	ListEmpty(a);
	listLength(a);
	showList(a);
	
	getElem(a, 3, &e);
	printf("item:%d\n", e);
		
	insertList(a, 3, 3);
	showList(a);
	
	deleteList(a, 4, &item);
	showList(a);
	
	
	initList(&Lb);
	printf("Input Lb:");
	scanf("%d", &len);
	createList(Lb, len);
	showList(Lb);
	mergeList(a, Lb, &pList);
	printf("合并后的链表：");
	showList(pList);
	
	showList(a);
	
	
	count = locateElem(a, 4, &compare);
	printf("Count = %d\n", count);
	showList(a);
	
	clearList(a);
	return 0;
}

