#ifndef STACK_H
#define STACK_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define  STACK_INIT_SIZE   100     //存储空间初始分配量 
#define  STACKINCREMENT     10     //存储空间增量 


/*状态码*/
#define  TRUE         1
#define  FALSE        0
#define  OK           1
#define  YES          1
#define  NO           0
#define  ERROR        0
#define  SUCCESS      1
#define  OVERFLOW    -2


typedef int Status;
typedef int SElemType; 

typedef struct
{
	SElemType *base;        //在栈构造之前和销毁之后，base的值为NULL 
	SElemType *top;         //栈顶指针 
	int stacksize;          //当前已分配的存储空间，以元素为单位 
}SqStack;

/*构造空栈*/
Status InitStack(SqStack *S);

/*销毁栈*/ 
Status DestroyStack(SqStack *S);

/*清空栈*/ 
Status ClearStack(SqStack *S);

/*判断栈是否为空*/ 
Status StackEmpty(SqStack S);

/*返回栈的长度*/ 
int StackLength(SqStack S);

/*获取栈顶*/ 
Status GetTop(SqStack S, SElemType *e);

/*插入新元素*/
Status Push(SqStack *S, SElemType e);

/*删除栈顶元素*/ 
Status Pop(SqStack *S, SElemType *e);

Status StackTraverse(SqStack S, Status(*visit)());

Status visit(SElemType e);


#endif 
