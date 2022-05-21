//Singly Linear Linked List

/*
 InsertFirst
 InsertLast
 InsertAtPosition
 
 DeleteFirst
 DeleteLast
 DeleteAtPosition
 
 Display
 Count 
*/

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

void InsertFirst(PPNODE Head,int iNo)
{
	PNODE newn=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=iNo;
	newn->next=NULL;
	
	if(*Head==NULL)
	{
		*Head=newn;
	}
	else
	{
		newn->next=*Head;
		*Head=newn;
	}
}

int main()
{
	PNODE First=NULL;      // struct node * First=NULL;
	
	InsertFirst(&First,101);
	InsertFirst(&First,51);
	InsertFirst(&First,21);
	InsertFirst(&First,11);
	
	return 0;
}