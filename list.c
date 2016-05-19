#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



/*״̬��*/
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


/*��������*/ 
Status initList();
void createList();
void createList_L();
void showList();
void clearList();
void destroyList();
Status ListEmpty(); 
int listLenght();
Status getElem();
Status insertList();
Status deleteList();
void mergeList();
int locateElem();

Status compare();


int main(void)
{
	LinkList a, b, Lb, pList;
	int len = 0;
	int i = 0;
	ElemType e, item, count;
	initList(&a);
	
	printf("Input:");
	scanf("%d", &len);
	
	createList(a, len);   
	showList(a);
	
	ListEmpty(a);
	listLenght(a);
	showList(a);
	
	getElem(a, 3, &e);
	printf("item:%d\n", e);
		
	insertList(a, 3, 3);
	showList(a);
	
	deleteList(a, 4, &item);
	showList(a);
	
	
	initList(&Lb);
	printf("Input Lb:");
	scanf("%d", &len);
	createList(Lb, len);
	showList(Lb);
	mergeList(a, Lb, &pList);
	printf("�ϲ��������");
	showList(*pList);
	
	showList(a);
	
	
	count = locateElem(a, 4, &compare);
	printf("Count = %d\n", count);
	showList(a);
	
	clearList(a);
	return 0;
}

/*1.��ʼ������ʹ�õ������ͷָ��Ϊ��*/
Status initList(LinkList *head)
{
	(*head) = (LinkList)malloc(sizeof(LNode));  //�������ռ�
	if (!(*head))
		exit(OVERFLOW);
	(*head)->next = NULL;              //��ʼ��Ϊ�� 
	return OK;
}

/*2.�������Ա�����ʼ����i��ֵ����i���ڵ��data*/ 
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

/*3.��ӡ���Ա�*/ 
void showList(LinkList head)
{
	if(head == NULL)
	{
		printf("����ֵΪ��NULL!");
		return;
	}
	
	printf("�����ֵΪ��");
	while (head->next)  // tem != NULL
	{
		printf("%d\t", head->next->data);   //
		head = head->next;   // tem = tem->next
	}
	printf("\n");
	system("PAUSE");
}

/*4.������Ա��е�����Ԫ�أ��ͷŵ������е����нڵ㣬ʹ֮�ɿձ�*/
void clearList(LinkList head)
{
	LinkList p;
	while(head)
	{
		p = head->next;
		free(head);
		head = p;
	}
	printf("������գ�\n");
}

/*5.�������Ա���clearList()һ��*/
void destroyList(LinkList head)
{
	LinkList p;
	while(head)
	{
		p = head->next;
		free(head);
		head = p;
	}
	printf("�������٣�\n");
	return;
}

/*6.�ж����Ա��Ƿ�Ϊ�գ���Ϊ�շ���True�����򷵻�False*/
Status ListEmpty(LinkList head) 
{
	if(head)
	{
	    printf("����Ϊ�գ�\n");
		return TRUE;	
	}
	    
	return FALSE;
}

/*7.�ó����Ա�ĳ���*/
int listLenght(LinkList head) 
{
	int size=0;

	while(head)
	{
		++size;
		head = head->next;
	}
	printf("������Ϊ��%d\n", size);
	return size;
}

/*8.��ȡ��i������Ԫ�ص�ֵ,�����ڸ�ֵ��e������OK�����򷵻�ERROR*/
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
	    return ERROR;   //Ԫ�ز�����
	*item = p->data;
	
	return OK; 
}

/*9.�������еĵ�i���ڵ�ǰ����Ԫ��item*/
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

/*10.ɾ�������е�i���ڵ�,����item������ֵ*/
Status deleteList(LinkList head, int n, ElemType *item) 
{
	int i = 0;
	LinkList p = head;
	LinkList q = malloc(sizeof(LNode));
	while(p->next && i < (n - 1))
	{                        //�ƶ�ָ�� 
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

/*11.�ϲ���������*/
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
			pa = pa->next;  //�ƶ�ָ��ָ����һ�� 
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

/*12.�����Ա��е�һ����e��ȵ�Ԫ�ص�λ��*/
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

/*���item����e ����OK�����򷵻�FALSE */
Status compare(ElemType e, ElemType item)
{     
	if(e <= item)
	   return OK;
	return ERROR;
}

