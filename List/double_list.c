#ifndef DOUBLE_LIST_C
#define DOUBLE_LIST_C
#include<stdio.h>
#include "double_list.h"


/*1.分配由p指向的值为e的节点，并返回OK；若分配失败则返回ERROR*/
Status MakeNode(Link *p, ElemType e)
{
	*p = (Link)malloc(sizeof(LNode));
	if(!(*p))
		exit(OVERFLOW);
		
	(*p)->data = e;
	(*p)->next = NULL;
	
	return OK;
}

/*2.释放p所指向的节点*/
void FreeNode(Link *p)
{
	free(*p);
	*p = NULL;
	printf("所有节点已释放！\n");
	
	return;
} 

/*3.初始化链表为空*/
Status InitList(LinkList *L)
{
	Link p = malloc(sizeof(LNode));
	if(!p)
		exit(OVERFLOW);
	
	p->next = NULL;
	
	(*L).head = (*L).tail = p;
	(*L).len = 0;
	
	return OK;
}

/*4.清空链表*/
void ClearList(LinkList *L)
{
	Link p, s;
	
	p = (*L).head->next;
	
	while(p)
	{
		s = p->next;
		free(p);
		p = s;
	}
	(*L).head->next = NULL;
	(*L).tail = (*L).head;  //头尾节点相接 
	(*L).len = 0;           //长度为0 
	
	printf("链表已清空！\n");
	return;
}

/*5.销毁链表*/
void DestroyList(LinkList *L)
{
	ClearList(L);
	
	free((*L).head);
	(*L).head = (*L).tail;
} 

/*6.头结点h,在第一个结点前插入s所指向的结点*/
void InsFirst(LinkList *L, Link h, Link s)
{
	s->next = h->next;
	h->next = s;
	
	if(h == (*L).tail)
		(*L).tail = h->next;
	
	(*L).len++;	
}

/*7.删除链表中的第一个结点，用q返回*/
Status DelFirst(LinkList *L, Link h, Link *q)
{
	*q = h->next;
	
	if(*q) 
	{
		h->next = (*q)->next;
		if(!h->next)
			(*L).tail = h;
			
		(*L).len--;
	return OK;
	}
	
	return ERROR;
}

/*8.将指针s所指的一串结点接到链表L的最后一个结点之后，并改变链表L的尾指针*/
void Append(LinkList *L, Link s)
{
	int count = 0;
	
	(*L).tail->next = s;
	
	while(s)
	{
		(*L).tail = s;
		s = s->next;
		count++;
	}
	
	(*L).len += count;
}

/*9.删除链表L的尾结点用q返回，并修改链表的尾指针指向新的尾结点*/
Status Remove(LinkList *L, Link *q)
{
	Link s;
	
	//L中没有元素 
	if(!(*L).len)
	{
		*q = NULL;
		return ERROR;
	}
	
	*q = (*L).tail;
	s = (*L).head;
	while(s->next != (*L).tail)    
		s = s->next;                        //把指针s移动到尾结点
	
	//此时s为尾结点 
	s->next = NULL;
	(*L).tail = s;
	
	(*L).len--;
	
	return OK;
}

/*10.在结点p之前，将s所指的结点插入，并修改指针p指向新插入的结点*/
Status InsBefore(LinkList *L, Link *p, Link s) 
{
	Link q;
	
	q = PriorPos(*L, *p);
	if(!q)
		q = (*L).head;
	
	q->next = s;
	s->next = *p;
	*p = s;
	(*L).len++;

	return OK;
}

/*11.在结点p之后，将s所指的结点插入，并修改指针p指向新插入的结点*/
Status InsAfter(LinkList *L, Link *p, Link s) 
{	
	if(*p == (*L).tail)
		(*L).tail = s;
	
	s->next = (*p)->next;
	(*p)->next = s;
	*p = s;
	
	(*L).len++;
	
	return OK;
}

/*12.用e更新p所指向结点元素的值*/
void SetCurElem(Link *p, ElemType e)
{
	(*p)->data = e; 
}

/*13.获取结点p的元素的值*/
ElemType GetCurElem(Link p)
{
	return p->data;
}

/*14.链表是否为真，是返回TRUE；否则返回FALSE*/
Status ListEmpty(LinkList L)
{
	if(L.len)
		return FALSE;
	return TRUE;
}

/*15.返回链表的长度*/
int ListLength(LinkList L) 
{
	return L.len;
}

/*16.返回链表头指针*/
Position GetHead(LinkList L)
{
	return L.head;
}

/*17.返回链表尾指针*/
Position GetLast(LinkList L)
{
	return L.tail;
}

/*18.返回p所指向结点的直接前驱的位置，若无前驱则返回NULL*/
Position PriorPos(LinkList L, Link p)
{
	Link s;
	
	s = L.head->next;
	if(s==p)
		return NULL;
	else
	{
		while(s->next != p)
			s = s->next;
		return s;
	}	
}

/*19.返回p所指向结点的直接后继的位置，若无后继则返回NULL*/
Position NextPos(LinkList L, Link p)
{
	if(p == L.tail)
		return NULL;

	return p->next;
}

/*20.返回链表第i个结点的位置p，并返回OK；i值不合法返回ERROR*/
Status LocatePos(LinkList L, int i, Link *p) 
{
	int count = 0;
	
	*p = L.head;
	if(i < 0 || i > L.len)  //i值不合法 
	{
		*p = NULL;
		return ERROR;
	}
	
	while(count < i)
	{
		count++;
		*p = (*p)->next;
	}
	
	return OK;	
}

/*21.返回链表中第一个与e满足compare()关系的位置，不存在返回ERROR*/
Position LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	Link s = L.head->next; 
	
	while(s && !(compare(e, s->data)))
		s = s->next;
		
	return s;
}

/*22.依次对链表调用Visit()，一旦visit()失败，则操作结束*/
Status ListTraverse(LinkList L, Status(*Visit)())
{
	//Link p;
	int i = 1;
	
	//p = L.head->next;
	while(i <= L.len)
	{
		i++;
		Visit(L.head->next->data);
		L.head = L.head->next;
	}
	printf("\n");
	
	return OK;
}

/*23.在带头结点的单链表的第i个元素之前插入元素e*/
Status InsertList(LinkList *L, int i, ElemType e)
{
	Link h, s;
	
	if(!LocatePos(*L, i-1, &h))  //i值不合法
		return ERROR;
	
	if(!MakeNode(&s, e))   // 结点分配失败 
		return ERROR;
		
	InsFirst(L, h, s);
	
	return OK;
}

/*24.把两个La、Lb值非递减排列的线性表合并为一个Lc，Lc的元素也按值非递减排列*/
Status MergeList(LinkList La, LinkList Lb, LinkList *Lc, int(*compare(ElemType, ElemType))) 
{
	ElemType a, b;
	Link ha, hb, pa, pb, q;
	
	
	if(!InitList(Lc))
		return ERROR;
	
	ha = GetHead(La);
	hb = GetHead(Lb);
	pa = NextPos(La, ha);
	pb = NextPos(Lb, hb);
	
	while(!ListEmpty(La) && !ListEmpty(Lb))
	{
		a = GetCurElem(pa);
		b = GetCurElem(pb);
		
		if(compare(a, b) <= 0)
		{
			DelFirst(&La, ha, &q);
			//Append(&Lc, q);
			InsFirst(Lc, (*Lc).tail, q);
			pa = NextPos(La, ha);
		}
		else
		{
			DelFirst(&Lb, hb, &q);
			//Append(Lc, q);
			InsFirst(Lc, (*Lc).tail, q);
			pb = NextPos(Lb, hb);
		}
		break;
	}
	if(!ListEmpty(La))
		Append(Lc, pa);
	else 
		Append(Lc, pb);
		
	FreeNode(&ha);
	FreeNode(&hb);
	
	return OK;
}

Status Visit(ElemType e)
{
	printf("%d\t", e);
	//return OK;
}

/*打印链表*/
void showList(Link p) 
{
	if(p == NULL)
	{
		printf("链表值为: NULL!\n");
		return; 
	}
	
	printf("链表值为：");
	while(p != NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

Status compare(ElemType e, ElemType item)
{
	if(item > e)
		return OK;
	return ERROR;
}


#endif
