#include"dual_circular_list.h"
#include"dual_circular_list.c"

int main()
{
	DuLinkList L;
	int i, size;
	ElemType e, item, count;
	ElemType pre_e, next_e, elem;
	
	initList(&L);
	
	ListEmpty(L) ? printf("链表为空！\n") : printf("链表不为空！\n");
	
	printf("插入元素：\n");
	for(i=1; i<=5; i++)
	{
		insertList(L, i, 2*i);
	}
	showList(L);
	
	size = ListLenght(L);
	printf("List size:%d\n", size);
	
	getElem(L, 3, &item);
	printf("GetElem:%d\n", item);
	
	count = locateElem(L, 7, &compare);
	printf("Count:%d\n", count);
	
	priorElem(L, 6, &pre_e);
	nextElem(L, 6, &next_e);
	printf("pre_e:%d     \tnext_e:%d\n", pre_e, next_e);
	
	deleteList(L, 1, &elem);
	printf("Dalete elememt:%d\n", elem);
	showList(L);
	
	clearList(L);
	showList(L);
	
	return 0;
}

