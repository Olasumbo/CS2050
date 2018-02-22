#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
        int number;
        struct node* next;
} node;

node* add_node(node* head, int number);
void print_list(node* head);
void free_list(node* head);
node* delete_node(node* head, int number);

int main( int argc, char *argv[] )
{
	if ( argc != 2)
       	{	
             printf( "Incorrect number of arguments\n");
             return 1;
        }
     node* current = NULL;
     int number;
     //node* list = malloc(sizeof(node));

     FILE* fp = fopen(argv[1], "r");
       if ( fp == NULL)
         {
              printf(" unable to open file\n");
              return 1;
         }
       while(!feof(fp))
	 {
		if( fscanf( fp, "%d\n", &number) <= 0)
		break;
                current = add_node(current, number);// change argv to number
         }

	fclose(fp);

print_list(current);
free_list(current);
int value;
printf(" Enter a number to delete:");
scanf("%d", &value);
delete_node(current,value);
print_list(current);


return 0;
} 

node* add_node(node* head, int number)
{
    node* current = NULL;
    node* prev = NULL;
    prev = head;
    int i, j;

    if (prev == NULL) 
    {
	current = malloc(sizeof(node));
        current->number = number;
	head = current;
    }
    else{i = 0; j =0;
	while( prev != NULL)
		{
			prev = prev->next;
			i++;
		}
	prev = head;
     while (prev != NULL)
    {
        if (i == j+1)
	{
        	current = malloc(sizeof( node));
        	current->number = number;
        	current->next = head->next;
        	current->next = prev->next;
        	prev->next = current;
        }
            prev = prev->next;
            j++;
     }
     }

        return head;
}

void print_list(node* head)
{
    node *temp = NULL;
    temp = head;
    int i = 1;
    while (temp != NULL) 
	{
        	printf("%d\n",temp->number);
        	temp = temp->next;
		i++;
    	}
	printf("\n");
}

void free_list(node* head)
{
    	node *temp = NULL;
        temp = head;
	node *tmp;
	while (temp != NULL)
        {
                tmp = temp;
		temp = temp->next;
                free(tmp);
        }
}

node* delete_node(node* head, int number)
{
        node* current = head;
	node* previous = NULL;

	if (head->number == number) 
	{
		current = head->next;
		free(head);
		return current;
	}
	while (current != NULL) 
	{
		if (current->number == number) 
		{
			if (previous != NULL) 
			{
				previous->next = current->next;
			}
			free(current);
		}
		previous = current;
		current  = current->next;
	}

	return current;

}
