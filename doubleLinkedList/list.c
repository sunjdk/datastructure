#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//初始化双链表
LIST * InitList(){
	//动态开辟一块内存大小为列表长度
	LIST *l=(LIST *)malloc(sizeof(LIST));
	//判断列表对象是否为空
	if(l==NULL) exit(0);
	//设置头指针
	l->head=(NODE *)malloc(sizeof(NODE));
	
	if(l->head==NULL) exit(0);
	//动态开辟一块内存空间，内容清0
	memset(l->head,0,sizeof(NODE));
	
	l->last=(NODE *)malloc(sizeof(NODE));
	
	if(l->last==NULL) exit(0);
	//if(l->head==NULL) exit(0);

	memset(l->last,0,sizeof(NODE));
	//头指针的下一个结点为列表尾元素
	l->head->next=l->last;
	//前驱为空
	l->last->pior=l->head;
	//列表长度为0
	l->length=0;
	return l;
}

//双向链表的插入
int InsertNode(LIST *l,void *data,int size){
	NODE *n=NULL;
	if(l==NULL || data==NULL || size<=0)
		return 0;
	n=(NODE *)malloc(sizeof(NODE));
	if(n==NULL) return 0;
	n->data=malloc(size);
	if(n->data==NULL){
		free(n);
		return 0;
	}
	//把数据复制到挪空的位置
	memcpy(n->data,data,size);
	n->next=l->last;
	n->pior=l->last->pior;

	l->last->pior->next=n;
	l->last->pior=n;
	l->length++;
	return 1;
}
//双向链表删除制定索引位置的元素

int DeleteNode(LIST *l,int n){
	int i=0;
	NODE *p=NULL;
	if(l==NULL || n<1 || n >l->length)
		return 0;
	p=l->head->next;
	while(i<l->length){
		i++;
		if(i==n)
			break;
		p=p->next;	
	}
	p->pior->next=p->next;
	p->next->pior=p->pior;
	free(p->data);
	free(p);
	l->length--;
	return 1;
}

//打印双链表的元素带分页

void PrintList(LIST *l,int page,int preP,void (*printNode)(void *)){
	int start,end,i;
	NODE *p=NULL;
	if(l==NULL||printNode==NULL)
		return;
	start=(page-1)*preP+1;
	end=page*preP;
	p=l->head->next;
	i=0;
	while(i<l->length&&p->next!=NULL){
		i++;
		if(i==start) break;
		p=p->next;
	}
	for(;i<=end&&p->next!=NULL;i++){
		printNode(p->data);
		p=p->next;
	}
}

//清空链表
void ClearList(LIST *l){
	if(l==NULL)
		return;
	while(l->length)
		DeleteNode(l,1);
}

/*
清空链表方法2
void ClearList(LIST *l){
	NODE *p=NULL;
	if(l==NULL)
		return;
	while(l->length){
		p=l->head->next;
		l->head->next=p->next;
		free(p->data);
		free(p);
		l->length--;
	}
}
*/

//销毁链表
void DestoryList(LIST **l){
	if(l==NULL||*l==NULL)
		return;
	ClearList(*l);
	free((*l)->head);
	free((*l)->last);
	free(*l);
	*l=NULL;
}
/*
void DestoryList(LIST *l){
	LIST *p=l;
	if(p==NULL) return;
	ClearList(p);
	free(p->head);
	free(p->last);
	free(p);
	p=NULL;
}
*/

/*
交换链表两个节点
void SwapList(LIST *la,int i,int j);
*/