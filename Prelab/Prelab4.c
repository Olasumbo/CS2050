#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct car
{
     char *color;
     int seats;
     int mileage;
}Car;

Car* import_cars(char* filename, int length);
void bubble_sort_mileage(Car* garage, int length);
void Insertion_sort_mileage(Car* garage, int length);
//void printArray(Car* garage, int length);



int main(int argc, char* argv[])
{
  
          if ( argc != 3)
          {
                  printf( "Incorrect number of arguments\n");
                  return 1;
          }
          int size = atoi(*(argv + 1));

          Car* array = malloc(sizeof(Car)*size);
	  //array = import_cars(*(argv + 2), size);
	  
	  int i;
	  /*for(i =0;i < 15; i++)
		{
			printf("%s %d %d\n", (array+i)->color, (array+i)->seats, (array+i)->mileage);
       		}*/
		
	bubble_sort_mileage(array, size);
	clock_t time;
	time = clock();
	time = clock() - time;
	printf("Bubble sort took %f seconds\n", ((float)time)/CLOCKS_PER_SEC);
	
	/*for(i = 10;i < 25; i++)
                 {
                         printf("%s %d %d\n", (array+i)->color, (array+i)->seats, (array+i)->mileage);
	      }*/

         //Insertion_sort_mileage(array, size);
         /*clock_t time;
         time = clock();
         time = clock() - time;
         printf("Insertion sort took %f seconds\n", ((float)time)/CLOCKS_PER_SEC);*/

	  FILE* fp = NULL; 
          Car* garage = malloc(sizeof(Car)*size);// This created a garage space for all the cars

          fp = fopen(*(argv +2), "r");
          if ( fp == NULL)
                 {
                          printf(" unable to open file\n");
                          return 1;
                 }
  
         while( i < size)
          {
                (garage+i)->color = malloc(sizeof(char)*6);  
		fscanf(fp, "%s %d %d", (garage+i)->color, &(garage+i)->seats, &(garage+i)->mileage);
                 i++;
          }


	for(i = 2; i < 15; i++)
              {
                           printf("car #%d %s %d %d\n", i ,(garage+i)->color, (garage+i)->seats, (garage+i)->mileage);
              }
          fclose(fp);

return 0;
}

/*Car* import_cars(char* filename, int length)
{
	 FILE* fp = NULL;
         int i=0;
	 //char temp = malloc(sizeof(char)*50);

         Car* garage = malloc(sizeof(Car)*length);// This created a garage space for all the cars
        
         fp = fopen(filename, "r");
         if ( fp == NULL)
        	{
                	 printf(" unable to open file\n");
                 	 return NULL;
         	}
	
                 i =0;
        while( i < length)
         {
                 fscanf(fp, "%s %d %d", (garage+i)->color, &(garage+i)->seats, &(garage+i)->mileage);
                 //printf("%s %d %d\n", (garage+i)->color, (garage+i)->seats, (garage+i)->mileage);
		 i++;
         }

         fclose(fp);
         return garage;
      
}*/

void bubble_sort_mileage(Car* garage, int length)
{
	Car hold;// change car to int// specific the the thing you are sorting from....
        int i,j;

        for(i = 0; i < length; i++)
        {
         for(j = 1; j < length-i; j++)
          {
             if((garage+(j-1))->mileage> (garage + j)->mileage) 
             { 
                 //hold = (garage+(j-1));
                 //(garage+(j-1)) = (garage + j);
		 //(garage + j) = (hold);
		 hold = garage[j-1];
		garage[j-1] = garage[j];
		garage[j] = hold;
             }
           }
        }
	//printf("%s %d %d" hold);
}

/*void Insertion_sort_mileage(Car* garage, int length)
// Insertion sort compares the first 2 value an see if the first one is greater than the second one, if yes it swaps then does the same for 2 and 3 then checks with 2 and 1 to make sure everything is orting ahead.
{
    int i,j;
    Car key;
    for (i = 1; i < length; i++) 
	{
        	key = (garage + i)->mileage;
		j = i-1;
        	while( (j >= 0) && ((garage + j)->mileage > key))
			{
            			(garage+(j+1)) = (garage+j);
				j = j-1;
        		}	
        (garage+(j+1)) = key;
    }
}
*/
