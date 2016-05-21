#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*状态码*/
#define  TRUE         1
#define  FALSE        0
#define  OK           1
#define  YES          1
#define  NO           0
#define  ERROR        0
#define  SUCCESS      1
#define  OVERFLOW    -2



typedef int ElemType;
typedef int Status;

typedef struct DuLNode
{
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode, *DuLinkList;

Status initList();
Status clearList();
void destroyList();
Status ListEmpty();
int ListLength();
Status getElem();
int locateElem();
Status priorElem();
Status nextElem();
DuLinkList getElemPtr();
Status insertList();
Status deleteList();
void showList();

Status compare();


int main()
{
	DuLinkList L;
	int i, size;
	ElemType e, item, count;
	ElemType pre_e, next_e, elem;
	
	initList(&L);
	
	ListEmpty(L) ? printf("链表为空！\n") : printf("链表不为空！\n");
	
	printf("插入元素：\n");
	//insertList(L, 1, 10);
	//printf("%d\n", L->next->data);
	for(i=1; i<=5; i++)
	{
		insertList(L, i, 2*i);
	}
	showList(L);
	
	size = ListLength(L);
	printf("List size:%d\n", size);
	
	getElem(L, 3, &item);
	printf("GetElem:%d\n", item);
	
	count = locateElem(L, 7, &compare);
	printf("Count:%d\n", count);
	
	priorElem(L, 6, &pre_e);
	nextElem(L, 6, &next_e);
	printf("pre_e:%d\tnext_e:%d\n", pre_e, next_e);
	
	deleteList(L, 1, &elem);
	printf("Dalete elememt:%d\n", elem);
	showList(L);
	
	clearList(L);
	showList(L);
	
	return 0;
}

/*1.初始化双向循环链表 */
Status initList(DuLinkList *head)
{
	*head =(DuLinkList)malloc(sizeof(DuLNode));
	if(!(*head))
	    exit(OVERFLOW);
    (*head)->next = (*head)->prior = *head;
    return OK;
}

/*2.清空链表*/
Status clearList(DuLinkList head)
{
	DuLinkList p, q;
	p = head->next;
	
	while(p != head)
	{
		q = p->next;
		free(p);
		p = q;
	}
	head->prior = head->next = head;
	printf("链表已经清空！\n");
	return OK;
}

/*3.销毁链表*/
void destroyList(DuLinkList head)
{
	clearList(head);
	head = NULL;
}

/*4.判断链表是否为空，若是返回TRUE，否则返回FALSE*/
Status ListEmpty(DuLinkList head)
{
	//printf("链表为空？\n");
	if(head && head->next == head && head->prior == head)	
	    return TRUE;
	else
	    return FALSE; 
} 
 
 /*5.返回链表的长度*/
int ListLength(DuLinkList head)
{
 	 int lenght; 
 	 DuLinkList p;
 	 
 	 if(head)
 	 {
 	 	  lenght = 0;
		  p = head;
		  while(p->next != head)	//未到表头 
		  {
		  	lenght++;
		  	p = p->next;
		  }
	 }
	 return lenght;
} 

/*6.获取链表中第i各节点元素的值，并用item返回其值*/ 
Status getElem(DuLinkList head, int i, ElemType *item)
{
	DuLinkList p;
	int n = 0;
	
	if(head)
	{
		n = 1;
		p = head->next;
		
		while(p != head && n < i)
		{
			n++;
			p = p->next;
		}
		
		if(p != head)
		{
			*item = p->data;
			return OK;
		}
	}
	return ERROR;
}

/*7.在链表中查找第一个与e相等的元素*/
int locateElem(DuLinkList head, ElemType e, Status(*compare)(ElemType, ElemType))
{
	int count;
	DuLinkList p;
	
	if(head) 
	{
		count = 1;
		p = head->next;
		
		while(p != head && !compare(e, p->data))
		{
			count++;
			p = p->next;
		}
		if(p != head)
			return count;
	}
	return 0;
}

/*8.获取cur_e元素之前的元素，并用pre_e返回*/
Status priorElem(DuLinkList head, ElemType cur_e, ElemType *pre_e)
{
	DuLinkList p;
	
	if(head)
	{
		p = head->next;
		
		while(p != head && p->data != cur_e)
			p = p->next;
		
		if(p != head && p->prior != head)
		{
			*pre_e = p->prior->data;
			return OK;
		}
	}
	return ERROR;
}

/*9.获取cur_e元素之后的元素，并用next_e返回*/
Status nextElem(DuLinkList head,ElemType cur_e, ElemType *next_e)
{
	DuLinkList p;
	
	if(head)	
	{
		p = head->next;
		
		while(p != head && p->data != cur_e)
			p = p->next;
	
		if(p != head && p->next != head)
		{
			*next_e = p->next->data;
			return OK;
		}	
	}
	return ERROR;
} 

/*10.返回链表中指向第i个节点的指针*/ 
DuLinkList getElemPtr(DuLinkList head, int i) 
{
	int count;
	DuLinkList p;
	
	if(head && i > 0)
	{
		count = 1;
		p = head->next;
		
		while(p != head && count < i)
		{
			count++;
			p = p->next;
		}
		if(p != head)
			return p;
	}
	return NULL;
}

/*11.在第i个节点前插入元素item*/
Status insertList(DuLinkList head, int i, ElemType item)
{
	DuLinkList p, s;
	
	p = getElemPtr(head, i);
	if(!p)
		p = head;
	
	s = (DuLinkList)malloc(sizeof(DuLNode));
	if(!s)
		exit(OVERFLOW);
		
	s->data = item;
	
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s; 
    	
	return OK;		
}

/*12.删除第i个节点元素，并用item返回*/
Status deleteList(DuLinkList head, int i, ElemType *item)
{
	DuLinkList p;
	
	if(!(p = getElemPtr(head, i)))
		return ERROR; 
	
	*item = p->data;

	p->prior->next = p->next;
	p->next->prior = p->prior;
	
	free(p);
	p = NULL;
	
	return OK;
} 

/*13.打印链表*/
void showList(DuLinkList head) 
{
	DuLinkList p;
	p = head->next; 
	
	if(p == head)
		printf("链表的值为: NULL!");
	else
		printf("链表的值为：");
		
	while(p != head)   // 非头结点打印 
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

Status compare(ElemType e, ElemType item)
{
	if(e < item)
		return OK;
	return ERROR;
}
