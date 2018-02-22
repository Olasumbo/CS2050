#define MAXLINELENGTH 200
#define MAXCARPRICE 1000000

typedef struct node 
{
        char make[25];
        char model[25];
		int price;
        int year;
        char color[25];
        char type[25];
		int mileage;
        struct node* left;
        struct node* right;
} Node;

Node* get_cars(char* filename)
Node* add_to_tree(Node* head, Node* new)
void search_tree(Node* root, int year, int price, int* count)

