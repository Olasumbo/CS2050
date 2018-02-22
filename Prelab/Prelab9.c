#include <stdio.h>
#include <stdlib.h>

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
int calcPrint(Node* root, int is_left, int offset, int depth, char s[20][255]);
void printTree(Node* root);

int main ( int argc, char* argv[])
{
	if ( argc != 2)
             {
                  printf( "Incorrect number of arguments\n");
                  return 1;
             }
	Node* Body = Build_Tree(argv[1]);
	Node* root = NULL;
	root = insert(root,12);
	root  = insert(root,19);
	root  = insert(root,24);
	Print_Tree(root);
	Print_Tree(Body);
	Free_Tree( Body);
	Free_Tree(root);

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

Node* insert(Node* root, int key)
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
//Call the bottom function printTree(root);
//Don’t forget prototypes

//DON'T TOUCH UNLESS YOU WANT TO EXPERIMENT
int calcPrint(Node* root, int is_left, int offset, int depth, char s[20][255])
{
	char b[20];
    int width = 5;
	
 	if (!root) return 0;
    sprintf(b, "(%03d)", root->value);
	int left  = calcPrint(root->left,  1, offset, depth + 1, s);
    int right = calcPrint(root->right, 0, offset + left + width, depth + 1, s);

	int i;
    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {
        for (i = 0; i < width + right; i++)
	       s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }

	return left + width + right;
}

//SAME AS THE FUNCTION ABOVE
void printTree(Node* root)
{
	char s[20][255];
	int i;
	for(i = 0; i < 20; i++)
		sprintf(s[i], "%80s", " ");
	
	calcPrint(root, 0, 0, 0, s);
	for(i = 0; i < 20; i++)
	{
		printf("%s\n", s[i]);
	}
}
