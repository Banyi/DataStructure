#ifndef SEQBITREE_H
#define SEQBITREE_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define MAX_TREE_SIZE     10     //最大节点数 


/*状态码*/
#define  OK           1
#define  ERROR        0
#define  TRUE         1
#define  FALSE        0
#define  OVERFOLW    -2


typedef int Status;

typedef char TElemType;
typedef TElemType SqBiTree[MAX_TREE_SIZE];

typedef struct 
{
	int level;     //结点所在层次
	int order;     //结点顺序 
}Position;

/*构造空树*/
void InitTree(SqBiTree T);

/*清除树*/ 
void ClearTree(SqBiTree T);

/*判空*/
Status TreeEmpty(SqBiTree T);

/*结点数*/ 
int TreeLength(SqBiTree T);

/*树高*/ 
int TreeDepth(SqBiTree T); 

/*获取树节点值*/
TElemType Value(SqBiTree T, Position p);

/*各节点赋值*/
Status Assign(SqBiTree T, Position cur_e, TElemType value); 

/*若非根节点返回父节点*/ 
TElemType Parent(SqBiTree T, TElemType e);

/*若结点存在且非叶子结点，返回其左孩子，否则返回空*/
TElemType LiftChild(SqBiTree T, TElemType e);

/*若结点存在且非叶子结点，返回其左孩子，否则返回空*/
TElemType RightChild(SqBiTree T, TElemType e);

/*若结点存在且非叶子结点，如存在左兄弟返回其左兄弟，否则返回空*/
TElemType LiftSibling(SqBiTree T, TElemType e); 
 
/*若结点存在且非叶子结点，如存在右兄弟返回其右兄弟，否则返回空*/
TElemType RightSibling(SqBiTree T, TElemType e);

/*遍历二叉树*/
Status TraverseTree(SqBiTree T, Status(*visit)()) ;

/*前序遍历二叉树*/ 
void PreOrderTraverse(SqBiTree T, Status(*visit)(), int i);

/*中序遍历二叉树*/
void InOrderTraverse(SqBiTree T, Status(*visit)(), int i);

/*后序遍历二叉树*/
void PostOrderTraverse(SqBiTree T, Status(*visit)(TElemType), int i);

#endif 

