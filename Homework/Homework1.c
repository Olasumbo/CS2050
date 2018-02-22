#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct car
{
    char *license_plate;
    int parking_spot;
    int num_tickets;
    int time_left;
}Car;


Car* import_cars(char* filename, int numCars);
void adjust_cars(Car* garage, int numCars);
int  find_car(Car* garage, int spot, int numCars);
void add_time(Car* garage, int numCars);
void free_garage(Car* garage, int numCars);
void check_car(Car* garage, int numCars);
void print_to_file(char* filename, Car* garage, int numCars);

#define LICENSEPLATELENGTH 10// maximum number of plates

int  main(int argc, char*argv[])
{
	if ( argc != 3)
        {
                printf( "Incorrect number of arguments\n");
                return 1;
        }
        int size = atoi(*(argv + 1));
        Car* array = import_cars(*(argv + 2), size);
        //printf("%s\n",(array)->license_plate);// This is just to use the array name that i defined above 
        //
	int request;
do
{

 		printf("\nOption List\nkey in 1 to add time to your car\n");
                printf("key in 2 to check remaining time on your car\n");
                printf("key in -1 to Exit this program\n");
                printf("Pick your option\n");

        scanf("%d",&request);
	if( request == 0)
	request = 100;

        while(request <  -1 || request > 2)

	{ 
		printf("Incorrect choice. Please enter a valid choice\n");  
		printf("Pick a valued option\n");
		scanf("%d",&request);
	}
//while(request == 1|| request == 2);

		switch ( request)
		{	

			case 1:
			add_time(array,size);

			break;

			case 2:
			check_car( array, size);

			break;

			case -1:
	
			printf(" Thank you for using our garage. We hope to see you soon");
			adjust_cars(array,size);
			print_to_file(*(argv + 2), array, size);
			free_garage(array, size);
			break;
		}	
} while(request == 1|| request == 2);

return 0;
}

Car* import_cars(char* filename, int numCars)
{
	FILE* fp = NULL;
        int i=0;
        Car* garage = malloc(sizeof(Car)*numCars);// This created a garage space for all the cars
	while( i < numCars)
	{
		(garage+i)->license_plate = malloc(sizeof(char)*LICENSEPLATELENGTH);// Malloc space for the licese plates in garage
		i++;
	}	
        fp = fopen(filename, "r");
        if ( fp == NULL)
        {
                printf(" unable to open file\n");
                return NULL;

        }
		i =0;
        while( i < numCars)
        {
        	fscanf(fp, "%s", (garage+i)->license_plate);
		fscanf(fp, "%d %d %d", &((garage+i)->parking_spot), &((garage+i)->num_tickets), &((garage+i)->time_left));        
                printf(" \nprint out cars %s\n%d %d %d\n",(garage +i)->license_plate,(garage +i)->parking_spot,(garage +i)->num_tickets,(garage +i)->time_left);
                i++;
	}

        fclose(fp);
        return garage;
}
void adjust_cars(Car* garage, int numCars)
{
	int i;
	for(i = 0; i < numCars; i++)
	{
		(garage+i)->time_left = (garage+i)->time_left - 30; 
	if ((garage+i)->time_left <= 0)
		{	
			(garage+i)->time_left = 60;
			((garage+i)->num_tickets)++;
		}
	printf(" \n ajusted file  %s\n%d %d %d\n",(garage +i)->license_plate,(garage +i)->parking_spot,(garage +i)->num_tickets,(garage +i)->time_left);//This is to test if my adjust function works. which it does...
	}

}
int find_car (Car* garage, int spot, int numCars)
{
	 int i;
         for(i = 0; i < numCars; i++)
	         {
	                 if ((garage+i)->parking_spot == spot)
	                  {	
	                         printf(" Car was found at spot %d\n", i+1 );
	                         return i;
	                  }
	         }
 return -1;
}
void add_time(Car* garage, int numCars)
{
	int spot = 0;
	int time = 0;
	int carindex;
	
		printf("Enter the parking spot of your car:\n");
		scanf("%d",&spot);
        	carindex = find_car( garage, spot, numCars);
			if ( carindex == -1)
			return;

	printf(" YOU ARE ONLY ALLOWED TO ADD FROM 0 - 60 MINUTES.......\n");
	printf("Enter the amount of time you would like to add:\n");
	scanf("%d", &time);
	while( time < 0 || time > 60)
         {
                 printf("Time must be in minutes. Please enter a valid minute:\n");   
                 scanf("%d",&time);
         }
	(garage+ carindex)->time_left = (garage+ carindex)->time_left + time;
        		
}

void free_garage(Car* garage, int numCars)
{
	int i;
          for(i = 0; i < numCars; i++)
	{
		free((garage+i)->license_plate);
	}
        	free(garage);
	
}
void check_car(Car* garage, int numCars)
{
	 int spot = 0;
         int checkcar;

                 printf("Enter the parking spot of your car:\n");
                 scanf("%d",&spot);
                 checkcar = find_car( garage, spot, numCars);
			if ( checkcar == -1)
                        return;

                 printf("license Plate %s\n",(garage + checkcar)->license_plate);
		 printf("Parking spot %d\n",( garage +checkcar)->parking_spot);
		 printf("Number of tickets %d\n", (garage + checkcar)->num_tickets);
		 printf("Number of time left %d\n", (garage + checkcar)->time_left);
}
void print_to_file(char* filename, Car* garage, int numCars)
{
	 int i;
	 FILE* fp = NULL;
         fp = fopen(filename, "w");
         if ( fp == NULL)
         {
                 printf(" unable to open file\n");
                return;
         }

         	for(i = 0; i < numCars; i++)
	 	{	
	 		fprintf(fp, "%s\n%d %d %d\n",(garage +i)->license_plate,(garage +i)->parking_spot,(garage +i)->num_tickets,(garage +i)->time_left);
		}
			//printf("%d",(garage +i)->time_left);
	
	printf("\n");
	fclose(fp);
}
