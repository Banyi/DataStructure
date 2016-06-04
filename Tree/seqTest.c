#include "seqBiTree.h"
#include "seqBiTree.c"
#include<stdio.h>


int main()
{
	TElemType T[MAX_TREE_SIZE];
	Position cur_e = {2, 1}; 
	Position p = {3, 1};
	TElemType e;
	
	InitTree(T);
	//ABCDEFGHIJ
	CreatTree(T);
	
	TreeEmpty(T) ? printf("树为空！\n") : printf("树不为空！\n"); 
	
	printf("结点赋值测试...\n");
	Assign(T, cur_e, 'x');
	printf("T:%s\n", T);
	
	printf("获取节点值测试...\n");
	e = Value(T, p);
	printf("节点值为：%c\n", e);

    printf("获取父节点值测试...\n"); 
    e = Parent(T, 'x');
    printf("'B'的父节点为：%c\n", e);
    
    printf("获取左孩子测试...\n");
    e = LiftChild(T, 'C');
    printf("'C'的左孩子为：%c\n", e);
    
    printf("获取右孩子测试...\n");
    e = RightChild(T, 'C');
    printf("'C'的右孩子为：%c\n", e);
    
    printf("获取左兄弟测试...\n");
    e = LiftSibling(T, 'G');
    printf("'G'的左兄弟为：%c\n", e);
    
    printf("获取右兄弟测试...\n");
    e = RightSibling(T, 'F');
    printf("'F'的右兄弟为：%c\n", e);
    
    printf("顺序遍历二叉树结点...\n");
    TraverseTree(T, visit);
    
    printf("前序遍历二叉树结点...\n");
    PreOrderTraverse(T, visit, 3);
    printf("\n"); 
    
    printf("中序遍历二叉树结点...\n");
    InOrderTraverse(T, visit, 1);
    printf("\n"); 
    
    printf("后序遍历二叉树结点...\n");
    PostOrderTraverse(T, visit, 1);
    printf("\n"); 
    
    return 0;
}



