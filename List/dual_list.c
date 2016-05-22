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
Status MakeNode();

/*功能：释放p所指向的节点*/
void FreeNode();

/*功能：初始化一个空链表*/
Status InitList();

/*功能：清空链表*/
void ClearList();

/*功能：销毁链表*/
void DestroyList(); 

/*功能：在头结点h前插入节点s*/ 
void InsFirst();

/*功能：删除链表的第一个节点，并已q返回*/
Status DelFirst();

/*功能：在尾结点后追加结点，并改变链表的尾指针*/
void Append();

/*功能：删除尾结点用q返回，并修改链表的尾指针*/
Status Remove(); 

/*功能：在p前插入结点s*/
Status InsBefore();

/*功能：在p之后插入结点s*/
Status InsAfter();

/*功能：更新结点p中的元素*/
void SetCurElem();

/*功能：返回结点p中的元素*/
ElemType GetCurElem();

/*功能：判断链表是否为空*/ 
Status ListElem();

/*功能：链表长度*/
int ListLength();

/*功能：返回链表头*/
Position GetHead();

/*功能：返回链表尾*/
Position GetLast();

/*功能：返回p所指向结点的前驱*/ 
Position PriorPos();

/*功能：返回p所指向结点的后继*/
Position NextPos();

/*功能：返回链表第i个结点p*/ 
Status LocatePos();

/*功能：返回第一个满足关系的的元素位置*/ 
Position LocateElem(); 

Status Visit();

/*打印链表*/
void showList();

Status compare();

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
	q = GetHead(L, s);
	Visit(q->data);
	printf("\n");
	
	printf("GetLast获取尾结点测试... \n");
	q = GetLast(L, s);
	Visit(q->data);
	printf("\n");
	
	
	
	printf("LocatePos获取结点位置测试... \n");
	i = 2;
	LocatePos(&L, 2, &p) ;
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
	
	
	ClearList(&L);
	DestroyList(&L);
	FreeNode(&p);
	system("PAUSE");
	
	return 0;
}

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
	return OK;
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


