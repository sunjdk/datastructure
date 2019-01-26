#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��ʼ��˫����
LIST * InitList(){
	//��̬����һ���ڴ��СΪ�б���
	LIST *l=(LIST *)malloc(sizeof(LIST));
	//�ж��б�����Ƿ�Ϊ��
	if(l==NULL) exit(0);
	//����ͷָ��
	l->head=(NODE *)malloc(sizeof(NODE));
	
	if(l->head==NULL) exit(0);
	//��̬����һ���ڴ�ռ䣬������0
	memset(l->head,0,sizeof(NODE));
	
	l->last=(NODE *)malloc(sizeof(NODE));
	
	if(l->last==NULL) exit(0);
	//if(l->head==NULL) exit(0);

	memset(l->last,0,sizeof(NODE));
	//ͷָ�����һ�����Ϊ�б�βԪ��
	l->head->next=l->last;
	//ǰ��Ϊ��
	l->last->pior=l->head;
	//�б���Ϊ0
	l->length=0;
	return l;
}

//˫������Ĳ���
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
	//�����ݸ��Ƶ�Ų�յ�λ��
	memcpy(n->data,data,size);
	n->next=l->last;
	n->pior=l->last->pior;

	l->last->pior->next=n;
	l->last->pior=n;
	l->length++;
	return 1;
}
//˫������ɾ���ƶ�����λ�õ�Ԫ��

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

//��ӡ˫�����Ԫ�ش���ҳ

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

//�������
void ClearList(LIST *l){
	if(l==NULL)
		return;
	while(l->length)
		DeleteNode(l,1);
}

/*
���������2
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

//��������
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
�������������ڵ�
void SwapList(LIST *la,int i,int j);
*/