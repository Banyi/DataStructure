#include "double_list.h"
#include "double_list.c"
#include<stdio.h>

int main()
{
	LinkList L, Lb, Lc;
	Link p, p1, q, h, s, s1, p2;
	
	int i, j;
	ElemType e;
	
	
	printf("InitList测试... \n");
	InitList(&L);
	InitList(&Lb);
	InitList(&Lc); 
	
	
	printf("ListEmpty测试...\n ");
	ListEmpty(L) ? printf("L为空！\n") : printf("L不为空！\n");
	
	
	printf("InsertList插入元素测试...\n ");
	InsertList(&L, 1, 12);
	InsertList(&L, 2, 13);
	ListTraverse(L, Visit);
	
	h = L.head;  // 链表头结点
	 
	
	printf("MakeNode分配新结点测试...\n ");
	MakeNode(&p, 10);
	printf("新分配结点元素值：%d\n\n", p->data);
	
	
	printf("InsFirst在第一个结点前插入测试...\n ");	
	InsFirst(&L, h, p);
	ListTraverse(L, Visit);
	
	/*
	printf("DelFirst删除第一个结点测试... \n");
	DelFirst(&L, h, &q);
	printf("删除的元素值：%d\n", q->data);
	printf("删除后的链表：\n");
	ListTraverse(L, Visit);
	*/ 
	
	printf("追加后：\n");
	printf("Append在链表尾部追加结点测试... \n");
	MakeNode(&s, 14) ;
	Append(&L, s);
	ListTraverse(L, Visit);
	
	printf("Remove在链表尾部删除结点测试... \n");
	Remove(&L, &q);
	Visit(q->data);
	printf("\n");
	
	printf("InsBefore在结点s前插入测试... \n");
	MakeNode(&s1, 100);
	MakeNode(&s, 1);
	Append(&L, s1);
	InsBefore(&L, &s1, s);
	ListTraverse(L, Visit);
	
	//Remove(&L, s);
	//ListTraverse(L, Visit);
	
	printf("InsAfter在结点后插入测试... \n ");
	MakeNode(&p2, 5);
	InsAfter(&L, &s, p2);
	ListTraverse(L, Visit);
	
	
	printf("GetCurElem获取元素测试... \n ");
	GetCurElem(s); 
	Visit(s->data);
	printf("\n");
	
	printf("SetCurElem更新元素测试... \n ");
	SetCurElem(&s, 200); 
	ListTraverse(L, Visit);
	
	printf("GetHead获取头结点测试... \n");
	q = GetHead(L);
	Visit(q->data);
	printf("\n");
	
	printf("GetLast获取尾结点测试... \n");
	q = GetLast(L);
	Visit(q->data);
	printf("\n");
	
	
	
	printf("LocatePos获取结点位置测试... \n");
	i = 2;
	LocatePos(L, 2, &p) ;
	printf("第%d个位置为:", i);
	Visit(p->data);
	printf("\n");
	
	printf("PriorPos获取结点p的前驱结点测试... \n");
	q = PriorPos(L, s);
	Visit(q->data);
	printf("\n");
	
	printf("NextPos获取结点p的后继结点测试... \n");
	q = NextPos(L, s);
	Visit(q->data);
	printf("\n");
	
	printf("LocateElem返回第一个与e满足关系的结点测试... \n");
	s = LocateElem(L, 14, compare); 
	Visit(s->data);
	printf("\n");
	
	
	InsertList(&Lb, 1, 2);
	InsertList(&Lb, 2, 2*2);
	printf("Lb:");
	ListTraverse(Lb, Visit);
	
	//printf("MergeList合并链表测试...");
	//MergeList(L, Lb, &Lc, compare);
	//ListTraverse(Lc, Visit);
	
	ClearList(&L);
	DestroyList(&L);
	FreeNode(&p);
	system("PAUSE");
	
	return 0;
}

