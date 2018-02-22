#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int number;
    struct node* next;
}Node;
  
Node* push(Node* head, int number);
Node* pop(Node* head);
void print(Node* head);
void menu();

int main( )
{
	Node* head = NULL;
	int value = 0;
	//int num;
do	
{
	int num;
	menu();
	scanf("%d", &value);

	switch(value)
	{
	//menu();
	case 1:
	printf ("Enter the element to push int stack\n");
        scanf ("%d", &num);
	head = push( head, num);
	print(head);
	break;

	case 2:
	head = pop(head);
	print(head);
	break;

	default:
	break;

	} 
}while(value != -1);

return 0;
}

Node* push(Node* head, int number)
{
    Node* tmp = malloc(sizeof(Node));
    if(tmp == NULL)
    {
        return 0;
    }
    tmp->number = number;
    tmp->next = head;
    head = tmp;

    return head;		
}
Node* pop(Node* head)
{
    Node* tmp = head;
    if( tmp == NULL )
	{
    		printf(" Head of stack is empty\n");
		return NULL;
	}
    Node* del = tmp;
    tmp = tmp->next;
    del->next = NULL;
    free(del);
    //tmp->number -= 1;

    return tmp;
}

void menu()
{
	printf("Enter '1' to push a node into the list\n");
	printf("Enter '2' to pop a node into the list\n");
 	printf("Enter '-1' to exit the list:\n");
}
void print(Node* head)
{
	 Node* temp = NULL;
         temp = head;
         while (temp != NULL)
         {
		 printf("Stack:--> %d\n",temp->number);
                 temp = temp->next;
         }
         printf("\n");
}
