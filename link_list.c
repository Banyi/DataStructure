#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef int elemType;

typedef struct Node
{
	elemType  data;
	struct Node *next;
}Node, *LinkList;


/*申明函数*/ 
void initList();
void createList();
void showList();
void clearList();
void destroyList();
bool isEmptyList(); 
int listLenght();
int getElem();


int main()
{
	LinkList a, pList;
	int len = 0;
	int item = 0;
	
	initList(&a);
	
	printf("Input:");
	scanf("%d", &len);
	
	createList(a, len);   
	showList(a);
	
	//destroyList(a);
	isEmptyList(a);
	listLenght(a);
	showList(a);
	item = getElem(a, 3);
	printf("Element:%d", item);
	
	//clearList(a);
	return 0;
}


/*1.初始化链表，使得单链表表头指针为空*/
void initList(LinkList *head)
{
	*head = (LinkList)malloc(sizeof(Node));  //申请分配空间
	if (*head == NULL)
	{
		perror("malloc error");
		printf("内存分配失败！");
		exit(1);
	}
	(*head)->next = NULL;              //初始化为空 
}

/*2.创建线性表，并初始化把i赋值给第i个节点的data*/ 
void createList(LinkList head, int n)   
{
	LinkList p;
	
	while (n--)
	{
		p = (LinkList)malloc(sizeof(Node));
	    if (p == NULL)
	    {
		    perror("malloc");
		    printf("内存分配失败！");
		    exit(1);
	    }
	    
		p->data = n + 1;     //给完成的新节点赋值
		p->next = head->next;
		head->next = p;
	}
	//return head;
	
}

/*3.打印线性表*/ 
void showList(LinkList head)
{
	printf("链表的值为：");
	while (head->next)  // tem != NULL
	{
		printf("%d\t", head->next->data);
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
		// printf("Len:%d\t", size);
	}
	printf("链表长度为：%d\n", size);
	return size;
}


/*8.获取第i个数据元素的值*/
int getElem(LinkList head, int n) 
{
	int i=0;
	
	if(head == NULL)
	{
		printf("空链表！\n");
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
		printf("n值超过链表长度\n");
		return 0;
	}
	return head->data;
	system("PAUSE"); 
}

