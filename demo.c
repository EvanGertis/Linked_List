/* hello world program */
#include "stdio.h"
#include "stdlib.h"

struct node{
	int info;
	struct node *link;
};

struct node *createList(struct node *start);
void displayList(struct node *start);
void countNodes(struct node *start);
void search(struct node *start, int x);
struct node *insertInBeginning(struct node *start, int data);
void insertAtEnd(struct node *start, int data);
void insertAfter(struct node *start, int data, int x);
struct node *insertBefore(struct node *start, int data, int x);
struct node *insertAtPosition(struct node *start, int data, int k);
struct node *deleteNode(struct node *start, int data);
struct node *reverseList(struct node *start);

int main()
{
	struct node *start = NULL;
	int choice, data, x, k;
	
	start = createList(start);
	
	while(1)
	{
		printf("\n");
		printf("1. Display list\n");
		printf("2. Count the number of nodes\n");
		printf("3. Search for an element\n");
		printf("4. Add to empty list / Add at beginning\n");
		printf("5. Add a node at the end of the list\n");
		printf("6. Add a node after a specified node\n");
		printf("7. Add a node before a specified node\n");
		printf("8. Add a node at a given position\n");
		printf("9. Delete a node\n");
		printf("10. Reverse the list\n");
		printf("11. Quit\n\n");
		
		printf("\nEnter your choice:"); // print to screen
		scanf("%d", &choice);
		
		if(choice == 11){
			break;
		}
		
		switch(choice){
			case 1:
				displayList(start);
				break;
			case 2: 
				countNodes(start);
				break;
			case 3:
				printf("Enter the element to be searched : ");
				scanf("%d", &data);
				search(start, data);
				break;
			case 4:
				printf("Enter the element to be inserted : ");
				scanf("%d", &data);
				// insert at end.
				break;
			case 6:
				printf("Enter the element to be inserted : ");
				scanf("%d", &data);
				printf("Enter the element after which to insert : ");
				scanf("%d", &x);
				insertAfter(start, data, x);
				break;
			case 7:
				printf("Enter the element to be inserted : ");
				scanf("%d", &data);
				printf("enter the element before which to insert : ");
				scanf("%d", x);
				start = insertBefore(start, data, x);
				break;
			case 8:
				printf("Enter the element to be inserted : ");
				scanf("%d", &data);
				printf("Enter the position at which to insert : ");
				scanf("%d", &k);
				start = insertAtPosition(start, data, k);
				break;
			case 9:
				printf("Enter the element to be deleted : ");
				scanf("%d", &data);
				// delete node.
				break;
			case 10:
				// reverse list.
				break;
			default:
				break;
		}
	}
	
	
	return 0;
	
}/*End of main*/

struct node *insertInBeginning(struct node *start, int data){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	
	temp->link = start;
	start = temp;

	return start;
};/*End of insertInBeginning*/ 

void insertAtEnd(struct node *start, int data){
	struct node *p, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	
	p = start;
	while(p->link  != NULL){
		p=p->link;
	}
	
	p->link = temp;
	temp->link = NULL;
}/*End of insertAtEnd*/

struct node *createList(struct node *start)
{
	int i,n,data;

	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	
	if(n==0)
		return start;

	printf("Enter the first element to be inserted : ");
	scanf("%d",&data);
	start=insertInBeginning(start,data);

	for(i=1; i<n; i++)
	{
		printf("Enter the next element to be inserted : ");
		scanf("%d",&data);
		insertAtEnd(start,data);	
	}
	return start;
};/*End of createList()*/

void displayList(struct node *start){
	struct node *p;
	if(start == NULL){
		printf("List is empty\n");
		return;
	}
	printf("List is : ");
	p = start;
	while(p != NULL)
	{
		printf("%d", p->info);
		p = p->link;
	}
	
}/*End of displayList()*/

struct node *insertAtPosition(struct node *start, int data, int k){
	int n = 0;
	struct node *p, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	
	p = start;
	while(p != NULL && k < n){
		p = p->link;
	}

	temp->link = p->link;
	p->link = temp;
	
	return start; 
}/*End of insertAtPosition*/

void insertAfter(struct node *start, int data, int x){
	struct node *p, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	
	p = start;
	while(p != NULL && p->info != x){
		p = p->link;
	}
	
	temp->link = p->link;
	p->link = temp;
	
}/*End of insert after*/

struct node *insertBefore(struct node *start, int data, int x){
	struct node *p, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	
	p = start;
	while(p->link != NULL){
		if(p->link->info == x){
			break;
		}
		p = p->link;
	}
	
	temp->link = p->link;
	p->link = temp;
	return start;
}/*End of insertBefore()*/

void countNodes(struct node *start){
	int n = 0;
	struct node *p;
	
	if(start == NULL){
		printf("List is empty\n");
		return;
	}
	
	p = start;
	while(p != NULL){
		n++;
		p=p->link;
	}
	printf("Number of nodes =%d\n", n);
}/*End of countNodes()*/

void search(struct node *start, int x){
	int position = 1;
	struct node *p;
	
	if(start == NULL){
		printf("List is empty\n");
		return;
	}
	
	p = start;
	while( p!= NULL)
	{
		if(p->info == x)
			break;
		position++;
		p=p->link;
	}
}/*End search()*/





