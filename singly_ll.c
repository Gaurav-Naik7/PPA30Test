#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE head,int no)
{
	PNODE newn=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=no;
	newn->next=NULL;
	
	if(*head==NULL)
	{
		*head=newn;
	}
	else
	{
		newn->next=*head;
		*head=newn;
	}
}

void InsertLast(PPNODE head,int no)
{
	PNODE newn=NULL;
	PNODE temp=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=no;
	newn->next=NULL;
	
	if(*head==NULL)
	{
		*head=newn;
	}
	else
	{
		temp=*head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
}

void DeleteFirst(PPNODE head)
{
	PNODE temp=NULL;
	
	if(*head==NULL)
	{
		return;
	}
	else
	{
		temp=*head;
		*head=temp->next;
		free(temp);
	}
}

void DeleteLast(PPNODE head)
{
	PNODE temp=NULL;
	
	if(*head==NULL)
	{
		return;
	}
	else if((*head)->next==NULL)
	{
		free(*head);
		*head=NULL;
	}
	else
	{
		temp=*head;
		while(temp->next->next)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}
}

void Display(PNODE head)
{

	while(head!=NULL)
	{
		printf("|%d|->",head->data);
		head=head->next;
	}
	printf("NULL\n");
}

int Count(PNODE head)
{
	int iCnt=0;
	
	while(head!=NULL)
	{
		iCnt++;
		head=head->next;
	}
	return iCnt;
}

void InsertAtPos(PPNODE head,int no,int pos)
{
	printf("Inside InsertAtPos\n");
	PNODE newn=NULL;
	PNODE temp=NULL;
	int size=0,iCnt=0;
	
	size=Count(*head);
	
	
	
	if((pos<1)||(pos>(size+1)))
	{
		printf("Invalid Input\n");
		return;
	}
	
	if(*head==NULL)
	{
		printf("Inside empty\n");
		InsertFirst(head,no);
	}
	
	else if(pos==(size+1))
	{
		printf("Inside Last\n");
		InsertLast(head,no);
	}
	else
	{
		newn=(PNODE)malloc(sizeof(NODE));
	
		newn->data=no;
		newn->next=NULL;
		
		temp=*head;
		for(iCnt=1;iCnt<(pos-1);iCnt++)
		{
			printf("Inside for\n");
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
	}
}

void DeleteAtPos(PPNODE head,int pos)
{
	PNODE temp=NULL;
	PNODE tempDel=NULL;
	int size=0,iCnt=0;
	
	size=Count(*head);

	if((pos<1)||(pos>size))
	{
		printf("Invalid Input\n");
		return;
	}
	
	if(pos==1)
	{
		DeleteFirst(head);
	}
	
	else if(pos==size)
	{
		DeleteLast(head);
	}
	else
	{
		temp=*head;
		tempDel=NULL;
		
		for(iCnt=1;iCnt<(pos-1);iCnt++)
		{
			printf("Inside for\n");
			temp=temp->next;
		}
		tempDel=temp->next;
		temp->next=temp->next->next;
		free(tempDel);
	}
}

int main()
{
	PNODE first=NULL;
	int ret=0;
	
	InsertFirst(&first,151);
	InsertFirst(&first,111);
	InsertFirst(&first,21);
	InsertFirst(&first,11);
	//InsertLast(&first,51);
	InsertAtPos(&first,4775,3);
	DeleteAtPos(&first,3);
	//DeleteFirst(&first);
	//DeleteLast(&first);
	
	Display(first);
	ret=Count(first);
	printf("Number of elements : %d",ret);
	
	return 0;
}
