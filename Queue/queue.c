#ifndef QUEUE_C
#define QUEUE_C

#include"queue.h"

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

#endif
