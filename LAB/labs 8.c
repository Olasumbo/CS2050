#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    
    char* word;
    struct node* next;
    
} Node;

Node* push(char* word, Node* head);
void print(Node* head);
void menu();
Node* pop(Node* head);
Node* enqueue(Node* queue, char* word);
Node* dequeue(Node* head);
Node* get_last(Node* head);

int main(int argc, char** argv) {
   	Node* temp;
	Node* undo = NULL;
	Node* redo = NULL;
	char* word = malloc(sizeof(char) * 25);

    if(argc != 1) {

	printf("incorrect usage\n correct usage ./a.out\n");
	return 0;
    }
    
	int choice = 0;


	while(choice != -1) {

		menu();
		scanf("%d", &choice);

	
		// adding a word to the redo list
		if(choice == 1) {

			printf("Enter a word to add to the document: ");
			scanf("%s", word);

			redo = enqueue(redo, word);
		}

	
		// taking an element off of the redo (sentece)
		// and adding it to the undo list
		else if(choice == 2) {

		temp = get_last(redo);
		undo = push(temp->word, undo);
		redo = dequeue(redo);
			
		}

		// Taing an element off of the undo list and adding it back onto the redo list
		else if(choice == 3) {

			redo = enqueue(redo, undo->word);
			undo = pop(undo);
		}

		else if (choice == -1) {
			return 0;
		}

		
                print(redo);
                //printf("undo = ");
                //print(undo);
                //printf("redo ");
                //print(redo);
	}

	return 0;
}
Node* push(char* word, Node* head) {
    
    Node* temp = malloc(sizeof(Node));
    temp->word = malloc(sizeof(char)*25);
    if(head == NULL) {
        
        head = temp;
        strcpy(temp->word, word);
        head->next = NULL;
	return head;
       }
	strcpy(temp->word, word);
	temp->next = head;
	head = temp;
	return head;
}
	

void print(Node* head) {
    
    if(head == NULL) {
        printf("The stack is empty\n");
        return;
    }
    
    Node* temp = head;
    
    while(temp != NULL) {
        
        printf("%s ", temp->word);
        temp = temp->next;
    }
    
    printf("\n");
    
}

void menu() {
    
    printf("Enter '1' to add a word to the sentence\n");
    printf("Enter '2' to undo\n");
    printf("Enter '3' to redo\n");
    printf("Enter '-1' to exit: ");
    
}

Node* pop(Node* head) {
   if(head->next == NULL) {
		free(head->word);
		free(head);
		head = NULL;
		return head;
	
    } 
    Node* temp = head;
    head = head->next;
    free(temp->word);
    free(temp);
    return head;
}

Node* enqueue(Node* queue, char* word) {

	Node* temp = malloc(sizeof(Node));
	temp->word = malloc(sizeof(char) * 25);
	Node* node = queue;

	if(queue == NULL) {

		strcpy(temp->word, word);
		temp->next = NULL;
		return temp;
	}

	else {

		while(node->next != NULL) {

			node = node->next;

		}


		node->next = temp;
		temp->next = NULL;
		strcpy(temp->word, word);
		return queue;
	}

}

Node* dequeue(Node* head) {

	if(head == NULL) {
		printf("The queue is empty\n");

		return head;
	}

	if(head->next == NULL) {
		free(head);
		head = NULL;
		return head;
	}

	Node* temp = head->next;
	Node* prev = head;
	while(temp->next != NULL) {

		temp = temp->next;
		prev = prev->next;

	}
	prev->next = NULL;


	free(temp->word);
	free(temp);

	return head;
}

Node* get_last(Node* head) {

	Node* temp = head;

	while(temp->next != NULL) {

		temp = temp->next;

	}

	return temp;
}


