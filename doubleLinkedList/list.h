#ifndef _LIST_H		
#define _LIST_H

//����ڵ�Ľṹ
typedef struct _node{
	void *data;				//������
	struct _node *pior;		//ǰ��
	struct _node *next;		//���
}NODE;
//��������Ľṹ
typedef struct{			
	NODE *head;				//ͷָ��
	NODE *last;				//βָ��
	int length;				//����
}LIST;


//����������
LIST * InitList();
int DeleteNode(LIST *l,int n);
int InsertNode(LIST *l,void *data,int size);
void PrintList(LIST *l,int page,int preP,void (*printNode)(void *));
void ClearList(LIST *l);
void DestoryList(LIST **l);


#endif