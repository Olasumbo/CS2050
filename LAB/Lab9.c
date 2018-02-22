#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdint.h>

#define FILESIZE 100000

typedef struct node{
        int value;
        struct node* left;
        struct node* right;
}Node;

Node* Build_Tree(char* input_file);
Node* Add_Node(Node* root, Node* new_node);
Node* insert(Node* root, int key);
void Print_Tree(Node* root);
void Free_Tree(Node* root);
int Search_Tree( Node* root, int key);
int Linear_Search( int* array, int value);
int* Build_linear_Structure(char* input_file);


int main ( int argc, char* argv[])
{
	if ( argc != 2)
             {
                  printf( "Incorrect number of arguments\n");
                  return 1;
             }
	Node* Body = Build_Tree(argv[1]);
	int* array = Build_linear_Structure(argv[1]);
	/*Node* root = NULL;
	root = insert(root,12);
	root  = insert(root,19);
	root  = insert(root,24);
	Print_Tree(root)*/
	

	printf("Proof of concept using array: %d\n",*array);
	Print_Tree(Body);
//	Free_Tree( Body);
	//Free_Tree(root);
	
	 int value = 0;
	 printf(" Please enter a value to search between 1 - 10001:\n");
	 scanf("%d", &value);
	 while( value < 1 || value > 10001)
	 { 	
		printf(" Please enter a value to search between 1 - 10001:\n");
          	scanf("%d", &value);
	 }
	 int  search = 0; 
	 search = Search_Tree( Body, value);
	 //search = Linear_Search( array, value);

	if(search == 1){
		printf("used");
	}

	struct timespec t,t2;
	uint64_t t3;

	clock_gettime( CLOCK_MONOTONIC_RAW, &t);
	int success = Linear_Search( array, value);
	clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
	t3 =(t2.tv_sec-t.tv_sec)*1000000 +(t2.tv_nsec)/1000;
	if (success == 1)
	{
	   printf(" YOUR LINEAR SEARCH WAS SUCCESSFUL, AND IT TOOK %lf MILLISECONDS\n",(double)t3);
	}
	else
	{
		printf(" YOUR LINEAR SEARCH WAS UNSUCCESSFUL, AND IT TOOK %lf MILLISECONDS\n",(double)t3);
	}

	struct timespec s, s2;
        uint64_t s3;
      
	clock_gettime( CLOCK_MONOTONIC_RAW, &s);
        int successful = Search_Tree( Body, value);
        clock_gettime(CLOCK_MONOTONIC_RAW, &s2);
        s3 =(s2.tv_sec-t.tv_sec)*1000000 +(s2.tv_nsec)/1000;
        if (successful == 1)
        {
          printf(" YOUR binary SEARCH WAS UNSUCCESSFUL, AND IT TOOK %lf MILLISECONDS\n",(double)s3);
        }
	else
	{
		 printf(" YOUR binary SEARCH WAS UNSUCCESSFUL, AND IT TOOK %lf MILLISECONDS\n",(double)s3);
	}
	
       Free_Tree( Body);
	
return 0;
}

Node* Build_Tree(char* input_file)
{
	  FILE* fp = NULL;
          fp = fopen(input_file, "r");
          if ( fp == NULL)
          {
              printf(" unable to open file\n");
                   return NULL;
          }
	 int i;
         int space = 0;
	 Node* root = NULL;
 
	 while(i < 10)
          {
                  fscanf(fp, "%d", &space);// scaning in all the value into space.
                  i++;

	  Node * newnode = malloc(sizeof(Node));// making the box for the node
	  newnode->value = space;// the number it self
	  newnode->left = NULL;//left node
	  newnode->right = NULL;//right node
	 
	  root = Add_Node( root, newnode);

	  }

         fclose(fp);
         return root;
}

Node* Add_Node(Node* root, Node* new_node)
{
	if ( root ==  NULL)//error cecking
	{	
		return new_node; 
	}
	else if (new_node->value < root->value)// checking if the node your adding is smaller than the root which is the head
	{
		root->left = Add_Node( root->left , new_node); 
	}
	else if (new_node->value > root->value)// checking if the node your adding is greater than the root which is the head
        {
               root->right = Add_Node( root->right, new_node);
        }
	return root;//this returns the head
}

/*Node* insert(Node* root, int key)
{
	//int item = 0;
        Node* newnode = malloc(sizeof(Node));
        newnode->value = key;
        newnode->left = NULL;
        newnode->right = NULL;

	if ( root == NULL) 
	{
    		return newnode;
	}
	if (key < root->value)
	{
        	root->left = insert(root->left, key);
	}
    	else if (key > root->value)
        {
		root->right = insert(root->right, key);   
 	}
return root;

}
*/
int Search_Tree( Node* root, int key)
{
	if (root != NULL)
	{
		if( key == root->value)  
       		{	
			return 1;
		}
		else if (key < root->value)//check if key is
       		{
			return Search_Tree(root->left, key);
		}
		else
		{
			return Search_Tree( root->right,key);
		}
	}	 
	else {
		return 0;
	}	
}
int Linear_Search( int* array, int value)
{
	int i;
	for( i = 0; i < FILESIZE; i++)
	{
		if (*(array+i) == value) 
		{
			printf(" Successfully\n ");
			return 1;
		}
	}
		return 0;
}
int* Build_linear_Structure(char* input_file)
{
	int* array = malloc(sizeof(int)* FILESIZE);
	FILE* fp = NULL;
        fp = fopen(input_file, "r");
          if ( fp == NULL)
          {
              printf(" unable to open file\n");
              return NULL;
          }
          int i;
	  while(i < FILESIZE)
 	  {
                 fscanf(fp, "%d", (array+i));
		 i++;
	  }	
	fclose(fp);
	return array;
}
void Print_Tree(Node* root)
{
       if (root == NULL)//error checking
	{
		return;
	} 
       if (root != NULL)
            {
                Print_Tree(root->left);
                printf("%d\n", root->value);
                Print_Tree(root->right);
            }
}
void Free_Tree(Node* root)
{
	if (root == NULL)
        {
                return;
        }
	Free_Tree(root->left);
	Free_Tree(root->right);
	free(root);
}
