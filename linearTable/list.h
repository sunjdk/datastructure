#ifndef _LIST_H
#define	_LIST_H

#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 10

typedef struct{
	ElemType * elem;
	int length;
	int size;
}LIST;

LIST *InitList();
void FreeList(LIST *l);
int InsertList(LIST * l,int i,ElemType *e);
int DeleteList(LIST *l,int i);

#endif