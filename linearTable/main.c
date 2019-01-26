#include <stdio.h>
#include "stu.h"
#include "list.h"

ElemType stu[3]={
	{"S101","����","��",80},
	{"S102","С��","Ů",75},
	{"S103","����","��",90}
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