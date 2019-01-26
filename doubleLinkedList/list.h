#ifndef _LIST_H		
#define _LIST_H

//定义节点的结构
typedef struct _node{
	void *data;				//数据域
	struct _node *pior;		//前驱
	struct _node *next;		//后继
}NODE;
//定义链表的结构
typedef struct{			
	NODE *head;				//头指针
	NODE *last;				//尾指针
	int length;				//长度
}LIST;


//声明函数体
LIST * InitList();
int DeleteNode(LIST *l,int n);
int InsertNode(LIST *l,void *data,int size);
void PrintList(LIST *l,int page,int preP,void (*printNode)(void *));
void ClearList(LIST *l);
void DestoryList(LIST **l);


#endif