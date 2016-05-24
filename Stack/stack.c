#ifndef STACK_C
#define STACK_C
#include "stack.h"

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

#endif
