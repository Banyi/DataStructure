#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef int elemType;

typedef struct Node
{
	elemType  data;
	struct Node *next;
}Node, *LinkList;


/*��������*/ 
void initList();
void createList();
void showList();
void clearList();
void destroyList();
bool isEmptyList(); 
int listLenght();
int getElem();
void insertList();
void deleteElem();
bool findElem();
void mergeList();


int main()
{
	LinkList a, Lb, pList;
	int len = 0;
	int item = 0;
	
	initList(&a);
	
	printf("Input:");
	scanf("%d", &len);
	
	createList(a, len);   
	showList(a);
	
	//destroyList(a);
	//isEmptyList(a);
	//listLenght(a);
	//showList(a);
	//item = getElem(a, 3);
	//printf("Element:%d", item);
	
	//insertList(a, 2, 20);
	//showList(a);
	
	//deleteElem(a, 4);
	//showList(a);
	
	//findElem(a,7);
	
	
	initList(&Lb);
	printf("Input:");
	scanf("%d", &len);
	createList(Lb, len);
	showList(Lb);
	mergeList(a, Lb, pList);
	showList(pList);
	
	
	//clearList(a);
	return 0;
}


/*1.��ʼ������ʹ�õ������ͷָ��Ϊ��*/
void initList(LinkList *head)
{
	*head = (LinkList)malloc(sizeof(Node));  //�������ռ�
	if (*head == NULL)
	{
		perror("malloc error");
		printf("�ڴ����ʧ�ܣ�");
		exit(1);
	}
	(*head)->next = NULL;              //��ʼ��Ϊ�� 
}

/*2.�������Ա�����ʼ����i��ֵ����i���ڵ��data*/ 
void createList(LinkList head, int n)   
{
	LinkList p;
	
	while (n--)
	{
		p = (LinkList)malloc(sizeof(Node));
	    if (p == NULL)
	    {
		    perror("malloc");
		    printf("�ڴ����ʧ�ܣ�");
		    exit(1);
	    }
	    
		p->data = n + 1;     //����ɵ��½ڵ㸳ֵ
		p->next = head->next;
		head->next = p;
	}
	//return head;
	
}

/*3.��ӡ���Ա�*/ 
void showList(LinkList head)
{
	printf("�����ֵΪ��");
	while (head->next)  // tem != NULL
	{
		printf("%d\t", head->next->data);
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
}

/*6.�ж����Ա��Ƿ�Ϊ�գ���Ϊ�շ���True�����򷵻�False*/
bool isEmptyList(LinkList head) 
{
	if(head)
	{
	    printf("����Ϊ�գ�\n");
		return true;	
	}
	    
	else return false;
}

/*7.�ó����Ա�ĳ���*/
int listLenght(LinkList head) 
{
	int size=0;

	while(head)
	{
		++size;
		head = head->next;
		// printf("Len:%d\t", size);
	}
	printf("������Ϊ��%d\n", size);
	return size;
}


/*8.��ȡ��i������Ԫ�ص�ֵ*/
int getElem(LinkList head, int n) 
{
	int i=0;
	
	if(head == NULL)
	{
		printf("������\n");
		return 0;
	}
	    
	while(head != NULL)
	{
		++i;
		if(i==n)
		    break;
		printf("I=%d \n", i);
		head = head->next;
	}
	if(i<n)
	{
		printf("nֵ����������\n");
		return 0;
	}
	return head->data;
	system("PAUSE"); 
}

/*9.�������еĵ�i���ڵ����Ԫ��ֵitem*/
void insertList(LinkList head, int n, int item)
{
	int i=0;
	LinkList p1 = malloc(sizeof(Node));;
	if(!p1)
	    return;
	    
	p1->data = item;
	p1->next = NULL;
	if(!head)
	{
		head = p1;
		return;
	}
	
	while(head)
	{
		i++;
		if(i == n+1)
		{
			p1->next = head->next;
			head->next = p1; 
		}
		head = head->next;
	}
}

/*10.ɾ�������е�i���ڵ�*/
void deleteElem(LinkList head, int n, int item) 
{
	int i = 0;
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
}

/*11.�����������Ƿ����Ԫ��item*/
bool findElem(LinkList head, int item)
{
	while(head->next)
	{
		if(head->next->data == item)
		{
			printf("Ԫ��%d��������\n", item);
			return true;
		}   
		head = head->next;
	}
	printf("Ԫ��%d����������\n");
	return false;
}

/*12.�ϲ���������*/
void mergeList(LinkList La, LinkList Lb, LinkList Lc)
{
	int i = 1;
	int j = 1;
	int k = 0;
	int a, b;
	int La_len, Lb_len;
	La_len = listLenght(La);
	Lb_len = listLenght(Lb);
	Lc = (LinkList)malloc(sizeof(Node));
	if(!Lc)
	    return;
	
	while((i<La_len) && (j<Lb_len))
	{
		a = getElem(La, i);
		b = getElem(Lb, j);
		if(a<b)
		 {
		 	insertList(Lc, ++k, a);
		 	i++;
		 }   
		else
		{
			insertList(Lc, ++k, b);
			j++;
		}
	}
	
	while(i<La_len)
	{
		a = getElem(La, ++i);
		insertList(Lc, ++k, a);
	}
	while(j<Lb_len)
	{
		b = getElem(Lb, ++j);
		insertList(Lc, ++k, b);
	}
}

