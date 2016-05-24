#include "stack.h"
#include "stack.c"
#include<stdio.h>


int main()
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
	
	return 0;
}



