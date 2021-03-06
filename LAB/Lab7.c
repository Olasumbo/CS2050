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
node* delete_from_file(char* filename, node* head);
node* search(node *head, int number);


int main( int argc, char *argv[] )
{
	if ( argc != 3)
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
//free_list(current);
delete_from_file( argv[2],current);
print_list(current);

printf(" Bonus\n");
int look;
printf(" Enter a positive number you would like to search for\n");
scanf("%d", &look); 
search(current, look);



free_list(current);

//print_list(current);


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

node* delete_from_file( char* filename, node* head)
{
	node* current = head;
	node* previous = NULL;
	//node* temp = NULL;
	int i = 0;
	FILE* spt = NULL;
 	spt = fopen(filename, "r");
        if ( spt == NULL)
         {
               printf(" unable to open file\n");
               return 0;
         }
     for(i =0; i < 5; i++)
	{
        	int currentnum = fscanf(spt,"%d\n", &currentnum ); 
		
	while (current->next != NULL) 
	{      current = head;
	     if (currentnum == current->number) 
		{
		    if (previous != NULL) 
			{
				previous->next = current->next;
			}
		   free(current);
		}
	 current = current->next;
	}
		previous = current;
		current  = current->next;
	}
 fclose(spt);

	return current;
}

node* search(node *head, int num)
{
    node* temp = head;
    int flag =0;
    while (temp != NULL)
    {
        if (temp->number == num)
        {
            printf("number was found\n");
            //return temp;
            temp  = temp->next;
        }
		temp  = temp->next;
    }
	if (flag == 0)
	{
		printf("not found\n");
	}
return temp;
}
