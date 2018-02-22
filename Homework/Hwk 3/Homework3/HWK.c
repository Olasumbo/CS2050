#include "Homework3.h"

int help (char* string)
{
	if(strcmp( string,"price") == 0)
	{
		return 1;
	}
	else if (strcmp(string,"mileage") == 0)
        {
		return 2;
	}

}
Node* get_cars(char* filename)
{
     FILE* fp = NULL;
     fp = fopen(filename, "r");
     if ( fp == NULL)
       {
                 printf("unable to open file\n");
                 return NULL;
       }
       char line[MAXLINELENGTH];
       Node* space = malloc(sizeof(Node));

       while(fget(line, MAXLINELENGTH,fp))
	{
		char* value = strtok( line,"|");
		char* key;// first string
		char* pair;// key pair value
		key = strcpy( key, value);
		value = strtok( NULL,"|");
		pair = strcpy( pair, value);
		printf("%s", key);		
	}
	fclose(fp);
}

Node* add_to_tree(Node* head, Node* new)
{
	 if ( head ==  NULL)//error cecking
         {
                 return new;
         }
         else if (new->price < head->price)// checking if the node your adding is smaller than the root which is the head
         {
                 head->left = add_to_tree( head->left, new);
         }
         else if (new->price > head->price)// checking if the node your adding is greater than the root which is the head
         {
                 head->right = add_to_tree( head->right, new);
         }
         return head;//this returns the head
}

void search_tree(Node* root, int year, int price, int* count)
{

}

