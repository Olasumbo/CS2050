#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROUNDS 3
#define MAX_NAME 25


typedef struct player
{
	char* Full_Name;
	double player_ID;
	double batting_rating;
	double defense_rating;
	double pitching_rating;
}Player;

typedef struct node
{
	Player player;
	struct node* next;
}node_t;

node_t* Generate_draft_list(char* filename, int number_of_players);
node_t* add_node(node_t* head_of_list, Player playa);
void print_list(node_t* head_of_list);
void Draft(node_t** head_a, node_t** head_b, node_t** head_c, node_t** draft_list, char* team_a, char* team_b, char* team_c);
void Free_List(node_t* linked_list);
double computeAverage(node_t* Team_List);
node_t* delete_node(node_t* head_of_list, double key);



int main( int argc, char * argv[])
{
	if ( argc != 6)
	{
		printf( "Incorrect number of arguments\n");
		return 1;
	}
	//All variable names from line 32-37 is just to store the commandline argument in a temp vaariable so it easier to use
	int size = atoi(*(argv + 1));
	char* playerlist = *(argv + 2);
	char* team_a = *(argv + 3);
	char* team_b = *(argv + 4);
	char* team_c = *(argv + 5);
	//variable over
	node_t* head_a = NULL;
	node_t* head_b = NULL;
	node_t* head_c = NULL;

	node_t* draftlist = NULL;
	draftlist = Generate_draft_list( playerlist, size);
	print_list(draftlist);
	Draft( &head_a, &head_b, &head_c, &draftlist, team_a, team_b, team_c);
	//computeAverage(head_a);
	//delete_node(head_a, double key)
	

	return 0;
}

node_t* Generate_draft_list(char* filename, int number_of_players)
{
	node_t* head = NULL;
	head = malloc(sizeof(node_t));
	head->next = NULL;
	Player* temp;
	temp = malloc(sizeof(Player));
	temp->Full_Name = malloc(sizeof(char)*MAX_NAME);
	head->player.Full_Name = malloc(sizeof(char)*MAX_NAME);
	head->player.player_ID = -1;

	int i = 0;
	if(number_of_players < 0 || number_of_players > 50)
	{
		printf("Incorrect amount of players. Please check your argument\n");
	}	

	FILE* fp = fopen(filename, "r");
	if ( fp == NULL)
	{
		printf(" unable to open file\n");
		return NULL;
	}
	while( i < number_of_players)
	{
		fscanf( fp, "%s\n %lf %lf %lf %lf",temp->Full_Name,&(temp->player_ID),&(temp->batting_rating),&(temp->defense_rating),&(temp->pitching_rating));
		head = add_node(head, *temp);
		i++;
	}

	fclose(fp);

	return head;
}
node_t* add_node(node_t* head_of_list, Player playa)
{
	node_t* current = NULL;
	current = malloc(sizeof(node_t));
	current->player.Full_Name = malloc(sizeof(char)*MAX_NAME);

	current = head_of_list;

	if(head_of_list == NULL)
	{
		printf("Head of list is empty \n");
		current = head_of_list;
		return current;
	}
	
	if(current->player.player_ID == -1)
	{	
		strcpy(current->player.Full_Name, playa.Full_Name);
		//head_of_list->player.Full_Name = playa.Full_Name;
		current->player.player_ID = playa.player_ID;
		current->player.batting_rating = playa.batting_rating;
		current->player.defense_rating = playa.defense_rating;
		current->player.pitching_rating = playa.pitching_rating;
	        printf("%lf\n", current->player.player_ID);
		return head_of_list;
	}
	while(current->next != NULL)
	{
		current = current->next;
	}	
	
	current->next = malloc(sizeof(node_t));
	current = current->next;
	
	current->player.Full_Name = malloc(sizeof(char)*MAX_NAME);
	strcpy(current->player.Full_Name, playa.Full_Name);
	//current->player.Full_Name = playa.Full_Name;
	current->player.player_ID = playa.player_ID;
	current->player.batting_rating = playa.batting_rating;
	current->player.defense_rating = playa.defense_rating;
	current->player.pitching_rating = playa.pitching_rating;

	return head_of_list;
}

void print_list(node_t* head_of_list)
{
	node_t* temp = NULL;
	temp = head_of_list;

	//while (temp != NULL)
	//int i;
	//for( i =0;i < 10;i++)
	while (temp != NULL)
		{
		printf("Player ID:%.2lf\n",(temp->player.player_ID));
		printf("Name: %s\n",(temp->player.Full_Name));
		printf("Batting:%.2lf\nDefense:%.2lf\nPitching:%.2lf\n",(temp->player.batting_rating),(temp->player.defense_rating),(temp->player.pitching_rating));
		printf("****************************\n");
		temp = temp->next;
		}
	printf("\n");
} 

void Draft(node_t** head_a, node_t** head_b, node_t** head_c, node_t** draft_list, char* team_a, char* team_b, char* team_c)
{
	printf("Welcome to Draft Night Fellas, Let play ball\n");
	
	double id_a = 0;
	double id_b = 0;
	double id_c = 0;

	FILE* aptr = fopen(team_a, "r");//opeing of all my files
	if( aptr == NULL)
		{
                         printf(" This file is unable to open\n");
                }

	FILE* bptr = fopen(team_b, "r");
	if( bptr == NULL)
		{
			printf(" Cant open\n");
		}
       
	FILE* cptr = fopen(team_c, "r");
	if( cptr == NULL)
		{
			printf("This file cant open\n");
		}

	node_t* current = *(draft_list);// this points to the begining of the entire draftlist
	int i;

	for( i = 0; i < ROUNDS; i++)// round robin picks
  	{

	fscanf( aptr,"%lf", &id_a);
	fscanf( bptr,"%lf", &id_b);
	fscanf( cptr,"%lf",&id_c); 

	while(id_a == id_b)//Making each teams doesnt pick the same player
		{
			fscanf(bptr,"%lf", &id_b);
		}
	while(id_a == id_c)
                 {
                         fscanf(cptr,"%lf", &id_c);
                 }
	while(id_b == id_c)
                 {
                         fscanf(cptr,"%lf", &id_c);
                 }

	printf(" *************Round %d**************\n",i+1);// just to make sure there are player id in each id's
	printf("Team A player ID is %.2lf\n", id_a);
	printf("Team B player ID is %.2lf\n", id_b);
	printf("Team C player ID is %.2lf\n", id_c);
	

	while(current != NULL && current->player.player_ID != id_a)
		{			
			current = current->next;
		}
	
	*head_a = malloc(sizeof(node_t));
        (*head_a)->player.Full_Name = malloc(sizeof(char)*MAX_NAME);
	
	*head_b = malloc(sizeof(node_t));
        (*head_b)->player.Full_Name = malloc(sizeof(char)*MAX_NAME);

	*head_c = malloc(sizeof(node_t));
		(*head_c)->player.Full_Name = malloc(sizeof(char)*MAX_NAME);

	*head_a = add_node(*head_a,current->player);// add the player into the head_a node that will store the 3 players 
	*head_a = (*head_a)->next; // we will set the next position so that but currently doesn't work why?? 
	delete_node(*draft_list,id_a); // delete's player from draft list which is the big player list
	
	while(current != NULL && current->player.player_ID != id_b)
                 {
                         current = current->next;
                 }
       *head_b = add_node( *head_b,current->player);
        *head_b = (*head_b)->next;
        delete_node(*draft_list,id_b);

	while(current != NULL && current->player.player_ID != id_c)
                 {
                         current = current->next;
                 }
        *head_c = add_node(*head_c, current->player);
 		*head_c = (*head_c)->next;
        delete_node(*draft_list,id_c);

	}
	printf("TEAM A\n");
        print_list(*head_a);

	printf("TEAM B\n");
        print_list(*head_b);

	printf("TEAM C\n");
        print_list(*head_c);

	fclose(aptr);
	fclose(bptr);
	fclose(cptr);

}
double computeAverage(node_t* Team_List)
{
	double average = 0;
	double sum = 0;
	node_t* current;
	current = Team_List;
	int i;
	for( i = 0; i <= 3; i++)
	{
		double batting = current->player.batting_rating;
        	double defense = current->player.defense_rating;
        	double pitching = current->player.pitching_rating;
		sum += batting + defense + pitching;
		current = current->next;
	}
		average = ( sum/3 );
		printf(" The average is %.lf\n", average);

return average;
}

node_t* delete_node(node_t* head_of_list, double key )
{
         node_t* current = head_of_list;
         node_t* previous = NULL;
         node_t* last = NULL;
         int i = 0;
	 
    if(key == 0)
        printf("\n ERROR!!!(Node not found)");
    else if( key == 1)
    {
        head_of_list = current->next;
        free(current);
        printf("\n Head node successfully deleted.");
    }
    else
    {
        for(i = 1;i <= key;i++)
        {
            if(i == key)
            {
                if( current == last)
                {
                    previous->next = NULL;
                    last = previous;
                    free(current);
                    printf("\n Tail Node succesfully deleted.");
                }
                else
                {
                    previous->next = current->next;
                    free(current);
                    printf("\n Node succesfully deleted.");
                }
            }
            previous = current;
            current  = current->next;
        }
    }        
         
return current;
}

void Free_List(node_t* linked_list)
{
	node_t* temp = NULL;
	temp = linked_list;

	while (temp != NULL)
	{
		temp = temp->next;
		temp->next = temp;
		free(temp);
	}
}
