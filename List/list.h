#ifndef LIST_H
#define LIST_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



/*状态码*/
#define TRUE         1
#define FALSE        0
#define OK           1
#define YES          1
#define NO           0
#define ERROR        0
#define SUCCESS      1
#define FAIL         0
#define OVERFLOW    -2


typedef int Status; 
typedef int ElemType;

typedef struct LNode
{
	ElemType  data;
	struct LNode *next;
}LNode, *LinkList;


/*申明函数*/ 
Status initList(LinkList *head);
void createList(LinkList head, int n);
void showList(LinkList head);
void clearList(LinkList head);
void destroyList(LinkList head);
Status ListEmpty(LinkList head); 
int listLength(LinkList head);
Status getElem(LinkList head, int n, ElemType *item);
Status insertList(LinkList head, int n, ElemType item);
Status deleteList(LinkList head, int n, ElemType *item);
void mergeList(const LinkList La, LinkList Lb, LinkList *Lc);
int locateElem(LinkList head, ElemType e, Status(*compare)(ElemType, ElemType));

Status compare(ElemType e, ElemType item);




#endif 
