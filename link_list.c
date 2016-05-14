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
#define UNDEFLOW    -3

typedef int Status; 
typedef int ElemType;

typedef struct LNode
{
	ElemType  data;
	struct LNode *next;
}LNode, *LinkList;


/*申明函数*/ 
Status initList();
void createList();
void createList_L();
void showList();
void clearList();
void destroyList();
bool isEmptyList(); 
int listLenght();
Status getElem();
Status insertList();
Status deleteList();
bool findElem();
void mergeList();



int main(void)
{
	LinkList a, b, Lb, pList;
	int len = 0;
	ElemType e, item;
	initList(&a);
	
	printf("Input:");
	scanf("%d", &len);
	
	createList(a, len);   
	showList(a);
	
	//destroyList(a);
	//isEmptyList(a);
	//listLenght(a);
	//showList(a);
	//getElem(a, 3, &e);
	//printf("item:%d\n", e);
	
	//insertList(a, 2, 20);
	//showList(a);
	
	//deleteList(a, 4, &item);
	//showList(a);
	
	//逆向建立链表
	//printf("逆向链表\n");
	//createList_L(b, 5); 
	//showList(b);
	
	//findElem(a,7);
	
	
	initList(&Lb);
	printf("Input Lb:");
	scanf("%d", &len);
	createList(Lb, len);
	showList(Lb);
	mergeList(a, Lb, &pList);
	printf("合并后的链表：");
	showList(*pList);
	
	
	clearList(a);
	return 0;
}

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
	//ElemType tem;
	
	//head = (LinkList)malloc(sizeof(LNode));
	//if(!head)
	  //  exit(OVERFLOW);
	//head->next = NULL;

	
	while(n--)
	{
		p = (LinkList)malloc(sizeof(LNode));
		if(!p)
	        exit(OVERFLOW);
	    
	    p->data = n + 1;      //tem;
	    p->next = head->next;
	    head->next = p;
	    //printf("data:%d\t", p->data);
	}
	return;
}

/*从表头到表尾逆向建立单链表*/
void createList_L(LinkList head, int n)
{
	int i;
	ElemType item; 
	LinkList p;
	
	head = (LinkList)malloc(sizeof(LNode));
	if(!head)    
	    exit(OVERFLOW);
	head->next = NULL;
	
	printf("逆向链表：");
	for(i=n; i>0; --i)
	{
		p = (LinkList)malloc(sizeof(LNode));
		if(!p)
		    exit(OVERFLOW);
		scanf("%d",&item);
		p->data = item;
		p->next = head->next;
		head->next = p;
	}
}

/*3.打印线性表*/ 
void showList(LinkList head)
{
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
}

/*6.判断线性表是否为空，若为空返回True，否则返回False*/
bool isEmptyList(LinkList head) 
{
	if(head)
	{
	    printf("链表不为空！\n");
		return true;	
	}
	    
	else return false;
}

/*7.得出线性表的长度*/
int listLenght(LinkList head) 
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
	
	free(p1);
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
	/*
	if(!head)
	    return;
	
	while(head)
	{
		i++;
		if(i==n)
		{
			head->next = head->next->next;
		}
		head = head->next;
	}
	return;
	*/
}

/*.查找链表中是否存在元素item*/
bool findElem(LinkList head, int item)
{
	while(head->next)
	{
		if(head->next->data == item)
		{
			printf("元素%d在链表中\n", item);
			return true;
		}   
		head = head->next;
	}
	printf("元素%d不在链表中\n");
	return false;
}

/*11.合并两个链表*/
void mergeList(LinkList La, LinkList Lb, LinkList *Lc)
{
	LinkList pa, pb, pc;
	pa = La->next;
	pb = Lb->next;
	*Lc = pc = La;
	
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
		printf("pc:%d\t", pc->data);
	}
	pc->next = pa ? pa : pb;
	/*
	while((*Lc)->next)
	{
		printf("Lc:%d\t", (*Lc)->next->data);
		(*Lc) = (*Lc)->next;
	}
	 */
	 
	//showList(Lc);
	free(Lb);
}


