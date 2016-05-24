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
Status InitStack();

/*销毁栈*/ 
Status DestroyStack();

/*清空栈*/ 
Status ClearStack();

/*判断栈是否为空*/ 
Status StackEmpty();

/*返回栈的长度*/ 
int StackLength();

/*获取栈顶*/ 
Status GetTop();

/*插入新元素*/
Status Push();

/*删除栈顶元素*/ 
Status Pop();

Status StackTraverse();

Status visit();

void test();

int main()
{
    int n = 1234;
    printf("%d\n", n%10);
	
	return 0;
}

void test()
{
	SqStack S;
	SElemType e, h;
	
	//初始化栈
	InitStack(&S);
	
	//判空
	StackEmpty(S) ? printf("栈为空栈！\n") : printf("栈不为空栈！\n");
	
	//将e压入栈
	e = 10;
	h = 12;
	Push(&S, e);
	Push(&S, h);
	StackTraverse(S, visit);
	StackEmpty(S) ? printf("栈为空栈！\n") : printf("栈不为空栈！\n");
	
	//获取栈顶元素
	GetTop(S, &e);
	printf("栈顶元素为：%d\n", e);
	Push(&S, 15);
	GetTop(S, &e);
	printf("栈顶元素为：%d\n", e);
	printf("栈长度为：%d\n", StackLength(S));
	
	Push(&S, 16);
	StackTraverse(S, visit);
	
	//把栈顶弹出
	Pop(&S, &e);
	printf("弹出栈的元素为：%d\n", e);
	StackTraverse(S, visit);	
}

/*1.构造空栈*/
Status InitStack(SqStack *S) 
{
	(*S).base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!(*S).base)
		exit(OVERFLOW);
		
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	
	return OK;
}

/*2.销毁栈*/ 
Status DestroyStack(SqStack *S) 
{
	free((*S).base);
	(*S).base = NULL;
	(*S).top = NULL;
	(*S).stacksize = 0;
	printf("栈已销毁！\n");
	
	return OK;
}

/*3.把栈置空*/
Status  ClearStack(SqStack *S)
{
	(*S).base = (*S).top;
	
	printf("栈已清空！\n");
	
	return OK;
}

/*4.判断栈是否为空，是则返回TRUE；否则返回FALSE*/
Status StackEmpty(SqStack S)
{
	if(S.base == S.top)
		return TRUE;
		
	return FALSE;
}

/*5.返回栈的长度*/
int StackLength(SqStack S)
{
	return S.top - S.base;
}

/*6.获取栈顶元素, 并用e返回*/
Status GetTop(SqStack S, SElemType *e) 
{
	if(S.base == S.top)
		return ERROR;
	
	*e = *(S.top - 1);
	
	return OK;
}

/*7.在栈顶插入元素e*/
Status Push(SqStack *S, SElemType e) 
{
	if(((*S).top - (*S).base) >= (*S).stacksize)  //栈满了，追加存储空间 
	{
		(*S).base = (SElemType *)realloc((*S).base, 
						((*S).stacksize + STACKINCREMENT)*sizeof(SElemType));
		if(!(*S).base)
			exit(OVERFLOW);
		
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	
	*(S->top) = e;
	*(S->top)++;
	
	return OK;
}

/*8.若栈不为空弹出栈顶元素，并用e返回其值，返回OK；否则返回ERROR*/
Status Pop(SqStack *S, SElemType *e)
{
	if((*S).top == (*S).base)
		return ERROR;
	
	(*S).top--;	
	*e =*((*S).top);
	
	return OK;
}

Status StackTraverse(SqStack S, Status(*visit)()) 
{
	SElemType *p = S.base;
	
	while(p<S.top)
		visit(*p++);
		
	printf("\n");
		
	return OK;
}


Status visit(SElemType e)
{
	printf("%d\t", e);
	
	return OK;
	
}
