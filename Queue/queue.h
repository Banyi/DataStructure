#ifndef QUEUE_H
#define QUEUE_H

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


#endif 
