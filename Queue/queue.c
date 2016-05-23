#include<stdio.h> 
#include<stdlib.h>
#include<stdbool.h>


//状态码
#define OK           1
#define ERROR        0
#define TRUE         1
#define FALSE        0
#define OVERFLOW    -2


typedef int QElemType;
typedef int Status;

typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;     //队头 
	QueuePtr rear;      //队尾 
}LinkQueue;


//---------基本操作的函数原型说明---------
//构造空队列 
Status InitQueue(LinkQueue *Q);

//销毁队列
Status DestroyQueue(LinkQueue *Q);

//清空队列
Status ClearQueue(LinkQueue *Q);

//判空
Status QueueEmpty(LinkQueue *Q);

//队列长度 
Status QueueLength(LinkQueue Q);

//获取队头
Status GetHead(LinkQueue Q, QElemType *e);

//在队尾插入元素
Status EnQueue(LinkQueue *Q, QElemType e);

//删除队头元素
Status DeQueue(LinkQueue *Q, QElemType *e);

Status QueueTraverse(LinkQueue Q, Status(*visit)());

Status visit(QElemType e);


int main()
{
	QueuePtr p;
	LinkQueue Q;
	QElemType e;

	int length = 0, i;
	
	//printf("InitQueue 测试...\n");
	InitQueue(&Q);
	
	printf("EmptyQueue测试...\n");
	EmptyQueue(Q) ? printf("队列为空！\n") : printf("队列不为空！\n");
	
	printf("EnQueue测试...\n");
	for(i=1; i<6; i++)
		EnQueue(&Q, i*2);
	//EnQueue(&Q, 2);
	//EnQueue(&Q, 4);
	QueueTraverse(Q, visit);
	
	printf("QueueLength测试...\n");
	length = QueueLength(Q);
	printf("length:%d\n", length);
	
	printf("GetHead测试...\n");
	GetHead(Q, &e);
	printf("e:%d\n", e);
	
	printf("DeQueue测试...\n");
	DeQueue(&Q, &e);
	printf("The delete elem:%d\n", e);
	QueueTraverse(Q, visit);
	
	ClearQueue(&Q);
	DestroyQueue(&Q);
	
	return 0;
}


/*1.初始化队列*/ 
Status InitQueue(LinkQueue *Q)
{
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if(!(*Q).front)
		exit(OVERFLOW);
		
	(*Q).front->next = NULL; 
	
	return OK;
} 

/*2.清空队列*/
Status ClearQueue(LinkQueue *Q) 
{
	(*Q).front = (*Q).rear;
	(*Q).front->next = 0;
	
	printf("队列已清空！\n");
	
	return OK;
}

/*3.销毁队列*/
Status DestroyQueue(LinkQueue *Q) 
{
	while((*Q).front)
	{
		(*Q).rear = (*Q).front->next;
		free((*Q).front);
		(*Q).front = (*Q).rear;
	}
	printf("队列已销毁！\n");
	
	return OK;
}

/*4.判空若队列为空返回TRUE；否则返回FALSE*/
Status EmptyQueue(LinkQueue Q)
{
	if(Q.front == Q.rear)
		return TRUE;
	
	return FALSE;
}

/*5.获取队列长度*/
int QueueLength(LinkQueue Q) 
{
	int i = 0;
	while(Q.front != Q.rear)
	{
		i++;
		Q.front = Q.front->next;
	}
	
	return i;		
}

/*6.获取队列头*/
Status GetHead(LinkQueue Q, QElemType *e) 
{
	if(Q.front == Q.rear)
	{
		*e = 0;	
		return ERROR;
	}
	
	*e = Q.front->next->data;
	
	
	return OK;
}

/*7.在队列尾部添加元素*/
Status EnQueue(LinkQueue *Q, QElemType e) 
{
	QueuePtr p = malloc(sizeof(QNode));
	if(!p)
		exit(OVERFLOW);
	
	p->data = e;
	p->next = NULL;
	
	(*Q).rear->next = p;
	(*Q).rear = p;
	
	return OK;
}

/*8.在表头删除元素*/
Status DeQueue(LinkQueue *Q, QElemType *e) 
{
	QueuePtr p = malloc(sizeof(QNode));
	if(!p)
		exit(OVERFLOW);
	
	if((*Q).front == (*Q).rear)
		return ERROR;
		
	p = (*Q).front->next;
	*e = p->data;
	
	(*Q).front->next = p->next;
	if((*Q).rear == p)
		(*Q).front = (*Q).rear;
	
	free(p);
	
	return OK;
}

/*9.*/
Status QueueTraverse(LinkQueue Q, Status(*visit)(QElemType))
{
	QueuePtr p;
	
	p = Q.front->next;
	
	printf("队列为：\n");
	while(p != Q.rear)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	
	return OK;
}

Status visit(QElemType e)
{
	printf("%d\t", e);
	
	return OK;
}
