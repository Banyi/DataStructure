#ifndef DUAL_CIRCULAR_LIST_H
#define DUAL_CIRCULAR_LIST_H


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

Status initList(DuLinkList *head);
Status clearList(DuLinkList head);
void destroyList(DuLinkList head);
Status ListEmpty(DuLinkList head);
int ListLength(DuLinkList head);
Status getElem(DuLinkList head, int i, ElemType *item);
int locateElem(DuLinkList head, ElemType e, Status(*compare)(ElemType, ElemType));
Status priorElem(DuLinkList head, ElemType cur_e, ElemType *pre_e);
Status nextElem(DuLinkList head,ElemType cur_e, ElemType *next_e);
DuLinkList getElemPtr(DuLinkList head, int i);
Status insertList(DuLinkList head, int i, ElemType item);
Status deleteList(DuLinkList head, int i, ElemType *item);
void showList(DuLinkList head);

Status compare(ElemType e, ElemType item);



#endif
