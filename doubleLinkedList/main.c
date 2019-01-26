#include <stdio.h>
#include "list.h"

double d[5]={10.23,34.23,54.65,122,35.5};


void PrintData(void *data){
	double *d=(double *)data;
	printf("d=%lf\n",*d);
}
void main(){
	int i;
	LIST *list=InitList();
	for(i=0;i<5;i++){
		InsertNode(list,&d[i],sizeof(d[i]));
	}
	PrintList(list,2,3,PrintData);
	DestoryList(&list);
	if(list==NULL)
		printf("list is NULL\n");
	else
		printf("list not NULL\n");
}