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
		
		printf("%d", choice);
		break;
	}
	
	
	return 0;
}
