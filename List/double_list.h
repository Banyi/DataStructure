#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

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

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *Link, *Position;

typedef struct
{
	Link head, tail;  // 头结点和尾节点
	int len;          //元素的个数 
}LinkList;

/*功能：分配由p指向的值为e的节点，并返回OK；若分配失败则返回ERROR*/
Status MakeNode(Link *p, ElemType e);

/*功能：释放p所指向的节点*/
void FreeNode(Link *p);

/*功能：初始化一个空链表*/
Status InitList(LinkList *L);

/*功能：清空链表*/
void ClearList(LinkList *L);

/*功能：销毁链表*/
void DestroyList(LinkList *L); 

/*功能：在头结点h前插入节点s*/ 
void InsFirst(LinkList *L, Link h, Link s);

/*功能：删除链表的第一个节点，并已q返回*/
Status DelFirst(LinkList *L, Link h, Link *q);

/*功能：在尾结点后追加结点，并改变链表的尾指针*/
void Append(LinkList *L, Link s);

/*功能：删除尾结点用q返回，并修改链表的尾指针*/
Status Remove(LinkList *L, Link *q); 

/*功能：在p前插入结点s*/
Status InsBefore(LinkList *L, Link *p, Link s);

/*功能：在p之后插入结点s*/
Status InsAfter(LinkList *L, Link *p, Link s);

/*功能：更新结点p中的元素*/
void SetCurElem(Link *p, ElemType e);

/*功能：返回结点p中的元素*/
ElemType GetCurElem(Link p);

/*功能：判断链表是否为空*/ 
Status ListEmpty(LinkList L);

/*功能：链表长度*/
int ListLength(LinkList L);

/*功能：返回链表头*/
Position GetHead(LinkList L);

/*功能：返回链表尾*/
Position GetLast(LinkList L);

/*功能：返回p所指向结点的前驱*/ 
Position PriorPos(LinkList L, Link p);

/*功能：返回p所指向结点的后继*/
Position NextPos(LinkList L, Link p);

/*功能：返回链表第i个结点p*/ 
Status LocatePos(LinkList L, int i, Link *p);

/*功能：返回第一个满足关系的的元素位置*/ 
Position LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType)); 

Status ListTraverse(LinkList L, Status(*Visit)());

/*功能：在带头结点的单链表的第i个元素之前插入元素e*/
Status InsertList(LinkList *L, int i, ElemType e);

Status MergeList(LinkList La, LinkList Lb, LinkList *Lc, int(*compare(ElemType, ElemType))); 


Status Visit(ElemType e);

/*打印链表*/
void showList(Link p);

Status compare(ElemType e, ElemType item);




#endif
