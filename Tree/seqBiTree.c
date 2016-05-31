#ifndef SEQBITREE_C
#define SEQBITREE_C


#include "seqBiTree.h"


/*1.构造空树*/
void InitTree(SqBiTree T) 
{
	int i = 0;
	for(i=0; i<MAX_TREE_SIZE; i++)
		T[i] = '\0';
	
	return;
}

/*2.清空树*/
void ClearTree(SqBiTree T) 
{
	int i = 0;
	for(i=0; i<MAX_TREE_SIZE; i++)
		T[i] = '\0';
	
	return;
}

/*3.判空*/
Status TreeEmpty(SqBiTree T)
{
	if(T[0] == '\0')
		return TRUE;
	
	return FALSE;
}

/*4.获取树的结点数*/
int TreeLength(SqBiTree T) 
{
	int len = 0;
	int i = 0;
	
	for(i=0; i<MAX_TREE_SIZE; i++)
	{
		if(T[i] != '\0')
			len++;
	}
		
	
	return len;
}

/*5.获取树深度*/
int TreeDepth(SqBiTree T) 
{
	int level = 0;
	while(pow(2, level) -1<TreeLength(T))
		level++;
		
	return level;
}

/*6.获取树的根*/ 
Status Root(SqBiTree T, TElemType *e)
{
	if(TreeEmpty(T))
		return ERROR;
	
	*e = T[0];
	
	return OK;
}

/*7.获取树中某个cur_e结点节点，返回结点值*/
TElemType Value(SqBiTree T, Position cur_e) 
{
	int i = 0;
	if(cur_e.order<0 | cur_e.order>(int)pow(2, cur_e.level-1))
		return ERROR;
	i = (int)pow(2, cur_e.level-1) + cur_e.order-2;
	
	return T[i];
}

/*8.给树中结点赋值*/
Status Assign(SqBiTree T, Position cur_e, TElemType value) 
{
	int i = 0;
	i = (int)pow(2, cur_e.level-1) + cur_e.order-2;           
	
	//printf("T[i]:...%s\n", T);
	
	if(value=='\0'&& (T[2*i+1]!='\0' || T[2*i+2]!='\0'))    //结点为空 
		return ERROR;
	else if(value!='\0' && T[(i+1)/2-1]=='\0')               //父节点存在 
		return ERROR;
	else
		T[i] = value;
	
	printf("ASSign T[i]:...%s\n", T);
		
	return OK; 
}

/*9.若非根节点返回其父节点*/ 
TElemType Parent(SqBiTree T, TElemType e)
{
	int i;
	if(T[i] != '\0')
	{
		for(i=0; i<MAX_TREE_SIZE; i++)
		{
			if(T[i] == e)
				return T[(i+1)/2-1];
		}
	}
	
	return '\0';
} 

/*10.若结点存在且非叶子结点，如存在左孩子返回其左孩子，否则返回空*/
TElemType LiftChild(SqBiTree T, TElemType e)
{
	int i;
	if(T[i] == '\0')
		return '\0';
		
	for(i=0; i<MAX_TREE_SIZE; i++) 
	{
		if(T[i] == e)
			return T[2*i+1];
	}
	
	return '\0';
}

/*11.若结点存在且非叶子结点，如存在右孩子返回其右孩子，否则返回空*/
TElemType RightChild(SqBiTree T, TElemType e)
{
	int i; 
	if(T[i] == '\0')
		return '\0';
	
	for(i=0; i<MAX_TREE_SIZE; i++)
	{
		if(T[i] == e)
			return T[2*i+2];
	}
	
	return '\0';
} 

/*12.若结点存在且非叶子结点，如存在左兄弟返回其左兄弟，否则返回空*/
TElemType LiftSibling(SqBiTree T, TElemType e)
{
	int i;
	if(T[i] == '\0')
		return '\0';
		
	for(i=0; i<MAX_TREE_SIZE; i++) 
	{
		if(T[i] == e && i%2 == 0)	
			return T[i-1];
	}
	
	return '\0';
}

/*12.若结点存在且非叶子结点，如存在右兄弟返回其右兄弟，否则返回空*/
TElemType RightSibling(SqBiTree T, TElemType e)
{
	int i;
	if(T[i] == '\0')
		return '\0';
		
	for(i=0; i<MAX_TREE_SIZE; i++) 
	{
		if(T[i] == e && i%2 != 0)	
			return T[i+1];
	}
	
	return '\0';
} 

/*13.顺序遍历二叉树*/
Status TraverseTree(SqBiTree T, Status(*visit)()) 
{
	int i = 0;
	while(T[i] != '\0')
	{
		visit(T[i]);
		i++;
	}
	
	return OK;
}

/*14.前序遍历某个节点二叉树*/ 
void PreOrderTraverse(SqBiTree T, Status(*visit)(), int i)
{
	if(T[i] != '\0')
	{
		visit(T[i]);
		PreOrderTraverse(T, visit, 2*i+1);
		PreOrderTraverse(T, visit, 2*i+2);
		//visit(T[i]); 
		//return ERROR;
	} 	
	return ;
}

/*15.中序遍历某个节点二叉树*/
void InOrderTraverse(SqBiTree T, Status(*visit)(), int i)
{
	if(T[i] != '\0')
	{
		InOrderTraverse(T, visit, 2*i+1);
		visit(T[i]);
		InOrderTraverse(T, visit, 2*i+2);
	}
}

/*16.后序遍历某个节点二叉树*/
void PostOrderTraverse(SqBiTree T, Status(*visit)(TElemType), int i) 
{
	if(T[i] != '\0')
	{
		PostOrderTraverse(T, visit, 2*i+1);
		PostOrderTraverse(T, visit, 2*i+2);
		visit(T[i]);
	}
}

Status CreatTree(SqBiTree T)
{
	int i = 0;
	//srand((int)time(NULL));
	printf("Input:");
	for(i=0; i<10; i++)
	{
		//T[i] = 'A' + rand() % 26; 
		scanf("%c", &T[i]);
	}
	
	return OK;
}

Status visit(TElemType e)
{
	if(e != '\0')
		printf("%c\t", e);
	
	return OK;
}

#endif
