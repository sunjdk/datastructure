#include <stdlib.h>
#include <stdio.h>
#include "stu.h"
#include "list.h"

LIST * InitList(){
	//从堆区域开辟内存空间
	LIST *l=(LIST *)malloc(sizeof(LIST));
	if(l==NULL){
		exit(0);
	}
	//开辟数据内存
	l->elem=(ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(l->elem==NULL){
		free(l);
		exit(0);
	}
	l->length=0;
	l->size=LIST_INIT_SIZE;
	return l;
}
//释放堆区内存
void FreeList(LIST *l){
	//先释放成员内存
	free(l->elem);
	//再释放自己
	free(l);
}
//插入线性表元素
int InsertList(LIST * l,int i,ElemType *e){
	ElemType *p=NULL,*q=NULL,*newElem=NULL;
	if(l==NULL || e==NULL){
		return 0;
	}
	
	if(i<1 || i>l->length+1){
		return 0;
	}
	if(l->length>=l->size){
		newElem=realloc(l->elem,(l->size+LIST_INCREMENT)*sizeof(ElemType));
		if(newElem==NULL)
			return 0;
		l->elem=newElem;
		l->size+=LIST_INCREMENT;
	}
	q=&l->elem[i-1];
	
	for(p=&(l->elem[l->length-1]);p>=q;p--){
		*(p+1)=*p;
	}
	*q=*e;
	++l ->length;
	return 1;	
}
int DeleteList(LIST *l,int i){
	ElemType *p=NULL,*q=NULL;
	if(l==NULL)
		return 0;
	if(i<1||i>l->length)
		return 0;
	p=&l->elem[i-1];
	q=&l->elem[l->length-1];
	for(;p<q;p++)
		*p=*(p+1);
	--l->length;
	return 1;
}