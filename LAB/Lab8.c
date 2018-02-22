#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 25

typedef struct node
{
	char* letter;
	struct node* next;
}Node;

Node* add_to_front(Node* head, char* word);
Node* remove_from_front(Node* head);
Node* remove_from_back(Node* head);
Node* add_to_back(Node* head, char* word);
void print(Node* head);
void menu();

int main( )
{
	Node* head = NULL;
	int value = 0;// This is what they pic for their option
	char* digit = malloc(sizeof(char)* MAX);
	


	head = add_to_front(head,"Jeremy");
	head = add_to_front(head,"oombcp");
	head = add_to_front(head,"Steven");
	print(head);


	head = remove_from_front(head); 
	print(head);
	head = remove_from_front(head);
        print(head);
	head = remove_from_front(head);
        print(head);
	

	head = remove_from_back(head);
	head = remove_from_back(head);
	print(head);	


	head = add_to_back(head,"oombcp");
        head = add_to_back(head,"Steven");
	print(head);


	




	//int num;
	/*do	
	{
		menu();
		scanf("%d", &value);
		while( value < -1 || value > 3)
		{
			printf("Incorrect input value\n");
			scanf("%d", &value);
		}

		switch(value)
		{
			//menu();
			case 1:
				printf ("Enter the word you want to add\n");
				scanf ("%s", digit);
				//head = add_to_front(head, digit);
				head = add_to_front(head, digit);
				print(head);
				break;

			case 2:
				head = remove_from_front(head);
				print(head);
				break;
			case 3:

				break;

			default:
				break;

		} 
	}while(value != -1);
	*/
	return 0;
}

Node* add_to_front(Node* head, char* word)
{
	Node* tmp = malloc(sizeof(Node));
	tmp->letter = malloc(sizeof(Node));
	if(tmp == NULL)
	{
		return 0;
	}

	strcpy(tmp->letter,word);
	//head = tmp->next;
	tmp->next = head;
	head = tmp;

	return head;		
}
Node* remove_from_front(Node* head)
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

Node* remove_from_back(Node* head)
{
	
	Node* tmp = head;
	Node* delete;
	///delete = NULL;
	if( tmp == NULL )
        {
                printf(" Head of stack is empty\n");
		return NULL;
        }
	
	if(head->next == NULL){
		free(head->letter);
		free(head);
		return NULL;
	}
	
	Node* previous = NULL;

	while(tmp->next != NULL){
		previous = tmp;
		tmp = tmp->next;
	}
	
	if(previous != NULL){
		previous->next = NULL;
	}

	free(tmp->letter);
	free(tmp);
	
 return head;
/*
         if(head == NULL) {
                 printf("The queue is empty\n");

                 return head;
         }

         if(head->next == NULL) {      
	         free(head);
                 head = NULL;
                 return head;
         }

         Node* temp = head;
         Node* prev = NULL;
         while(temp->next != NULL) {

		 prev = temp;
                 temp = temp->next;

         }
         prev->next = NULL;


         free(temp->letter);
         free(temp);

         return head;

*/
}


Node* add_to_back(Node* head, char* word)
{
	if(head == NULL || word == NULL)
	{
			printf(" Incorrect input");
			return NULL;
	}	

	Node* tmp = head;

	while(tmp->next != NULL){
		tmp = tmp->next;
	}

	
	tmp->next = malloc(sizeof(Node));
	tmp = tmp->next;
	tmp->letter = malloc(sizeof(Node));

	if(tmp == NULL || tmp->letter == NULL)
        {                
		return NULL;
        }
        strcpy(tmp->letter,word);
        tmp->next = NULL;


        return head;
}
void menu()
{
	printf("Enter '1' to add a word \n");
	printf("Enter '2' to undo \n");
	printf("Enter '3' to redo\n");
	printf("Enter '-1' to exit the list:\n");
}
void print(Node* head)
{
	Node* temp = NULL;
	temp = head;
	while (temp != NULL)
	{
		printf("%s--->",temp->letter);
		temp = temp->next;
	}
	printf("\n");
}
