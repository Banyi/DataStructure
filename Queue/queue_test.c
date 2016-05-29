#include"queue.h"
#include"queue.c"

int main()
{
	QueuePtr p;
	LinkQueue Q;
	QElemType e;

	int length = 0, i;
	
	printf("InitQueue 测试...\n");
	InitQueue(&Q);
	
	printf("EmptyQueue测试...\n");
	EmptyQueue(Q) ? printf("队列为空！\n") : printf("队列不为空！\n");
	
	printf("EnQueue测试...\n");
	for(i=1; i<6; i++)
		EnQueue(&Q, i*2);
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

