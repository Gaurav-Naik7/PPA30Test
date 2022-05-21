#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int main()
{
	// Static memory allocation
	NODE obj;
	
	//Dynamic memory allocation
	PNODE ptr=(PNODE)malloc(sizeof(NODE));
	
	obj.data =11;  //Direct accessing operator .
	obj.next =NULL;
	
	ptr->data=11;  //Indirect accessing operator ->
	ptr->next=NULL;
	
	return 0;
}