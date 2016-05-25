#ifndef LIST_C
#define LIST_C

#include<stdio.h>
#include<stdlib.h>
#include "list.h"


/*1.初始化链表，使得单链表表头指针为空*/
Status initList(LinkList *head)
{
	(*head) = (LinkList)malloc(sizeof(LNode));  //申请分配空间
	if (!(*head))
		exit(OVERFLOW);
	(*head)->next = NULL;              //初始化为空 
	return OK;
}

/*2.创建线性表，并初始化把i赋值给第i个节点的data*/ 
void createList(LinkList head, int n)   
{
	LinkList p;
	
	while(n--)
	{
		p = (LinkList)malloc(sizeof(LNode));
		if(!p)
	        exit(OVERFLOW);
	    
	    p->data = n + 1;      //tem;
	    p->next = head->next;
	    head->next = p;
	}
	
	return;
}

/*3.打印线性表*/ 
void showList(LinkList head)
{
	if(head == NULL)
	{
		printf("链表值为：NULL!");
		return;
	}
	
	printf("链表的值为：");
	while (head->next)  // tem != NULL
	{
		printf("%d\t", head->next->data);   //
		head = head->next;   // tem = tem->next
	}
	printf("\n");
	system("PAUSE");
}

/*4.清除线性表中的所有元素，释放单链表中的所有节点，使之成空表*/
void clearList(LinkList head)
{
	LinkList p;
	while(head)
	{
		p = head->next;
		free(head);
		head = p;
	}
	printf("表已清空！\n");
}

/*5.销毁线性表，跟clearList()一样*/
void destroyList(LinkList head)
{
	LinkList p;
	while(head)
	{
		p = head->next;
		free(head);
		head = p;
	}
	printf("表已销毁！\n");
	return;
}

/*6.判断线性表是否为空，若为空返回True，否则返回False*/
Status ListEmpty(LinkList head) 
{
	if(head)
	{
	    printf("链表不为空！\n");
		return TRUE;	
	}
	    
	return FALSE;
}

/*7.得出线性表的长度*/
int listLength(LinkList head) 
{
	int size=0;

	while(head)
	{
		++size;
		head = head->next;
	}
	printf("链表长度为：%d\n", size);
	return size;
}

/*8.获取第i个数据元素的值,若存在赋值给e并返回OK，否则返回ERROR*/
Status getElem(LinkList head, int n, ElemType *item) 
{
	int i = 0;
	LinkList p = head->next;
	
	i = 1;
	p = head->next;
	
	while(p && i < n)
	{
		p = p->next;
		i++;
	}
	
	if(!p || i > n)
	    return ERROR;   //元素不存在
	*item = p->data;
	
	return OK; 
}

/*9.在链表中的第i个节点前插入元素item*/
Status insertList(LinkList head, int n, ElemType item)
{
	int i = 0;
	LinkList p1 = malloc(sizeof(LNode));;
	if(!p1)
	    exit(OVERFLOW);
	p1 = head;
	while(p1 && (i < (n - 1)))
	{
		p1 = p1->next;
		i++;
	}
	if(!p1 || (i > (n - 1)))
	    return ERROR;
	
	LinkList s = malloc(sizeof(LNode));
	if(!s)
	    exit(OVERFLOW);
	s->data = item;
	s->next = p1->next;
	p1->next = s;
	
	//free(p1);
	return OK;
}

/*10.删除链表中第i个节点,并由item返回其值*/
Status deleteList(LinkList head, int n, ElemType *item) 
{
	int i = 0;
	LinkList p = head;
	LinkList q = malloc(sizeof(LNode));
	while(p->next && i < (n - 1))
	{                        //移动指针 
		p = p->next;
		i++;
	}
	if(!p && i > (n - 1))
	    return ERROR;
	
	q = p->next;
	p->next = q->next;
	
	*item = q->data;
	free(q);
	
	return OK;
}

/*11.合并两个链表*/
void mergeList(const LinkList La, LinkList Lb, LinkList *Lc)
{
	LinkList pa, pb, pc;
	pa = La->next;
	pb = Lb->next;
	pc = La;
	*Lc = pc;
	
	while(pa && pb)
	{
		if(pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;  //移动指针指向下一个 
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	
	pc->next = pa ? pa : pb;
	free(Lb);
	//*Lb = NULL;
	
	return;
}

/*12.在线性表中第一个与e相等的元素的位序*/
int locateElem(LinkList head, ElemType e, Status(*compare)(ElemType, ElemType)) 
{
	int i;
	LinkList p;
	
	i = -1;
	if(head)
	{
		i = 0;
		p = head->next;
		while(p)
		{
			i++;
			if(!compare(e, p->data))
			    p = p->next;
			else
			    break;
		}
	}
	return i;
}

/*如果item大于e 返回OK，否则返回FALSE */
Status compare(ElemType e, ElemType item)
{     
	if(e <= item)
	   return OK;
	return ERROR;
}


#endif
