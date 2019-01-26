#include <stdio.h>
#include "stu.h"
#include "list.h"

ElemType stu[3]={
	{"S101","张三","男",80},
	{"S102","小红","女",75},
	{"S103","王五","男",90}
};
void main(){
	int i;
	LIST * list=NULL;
	list=InitList();
	for(i=0;i<3;i++){
		InsertList(list,1,&stu[i]);
	}
	DeleteList(list,2);
	FreeList(list);
}