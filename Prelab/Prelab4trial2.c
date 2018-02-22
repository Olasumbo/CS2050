#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct car
{
      char *color;
      int seats;
      int mileage;
}Car;

void bubble_sort_mileage(Car* garage, int length);
void Insertion_sort_mileage(Car* garage, int length);

int main(int argc, char* argv[])
 {

           if ( argc != 3)
           {
                   printf( "Incorrect number of arguments\n");
                  return 1;
           }
           
     int size = atoi(*(argv + 1));

     int i ;
     FILE* fp = fopen(*(argv +2), "r");
     Car* garage = malloc(sizeof(Car)*size);
         
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

          fclose(fp);

clock_t start_t, end_t;
//clock_t start,end;

	float total_t;
	start_t = clock();
bubble_sort_mileage( garage, size);
	end_t = clock();
        total_t = (float)(end_t - start_t)/CLOCKS_PER_SEC;

	printf(" **********bubble sort************\n");
	for(i = 2;i < 15; i++)
           {
                  printf("%s %d %d\n", (garage+i)->color, (garage+i)->seats, (garage+i)->mileage);
           }
printf("Bubble sort took %f seconds\n", total_t);

	start_t = clock();
Insertion_sort_mileage( garage, size);
	end_t = clock();
 total_t = (float)(end_t - start_t)/CLOCKS_PER_SEC;

printf(" ************Insertion sort*********\n");
         for(i = 2;i < 15; i++)
           {
                 printf("%s %d %d\n", (garage+i)->color, (garage+i)->seats, (garage+i)->mileage);
           }
printf("Insertion sort took %f seconds\n", total_t);

return 0;

}
void bubble_sort_mileage(Car* garage, int length)
{
         Car hold;// change car to int// specific the the thing you are sorting from....
         int i,j;

         for(i = 0; i < length; i++)
       {
          for(j = 1; j < length-i; j++)
         {
              if((garage+(j-1))->mileage > (garage + j)->mileage)
           {
                 hold = garage[j-1];
		 garage[j-1] = garage[j];
                 garage[j] = hold;
           }
         }	
       }
	
}

void Insertion_sort_mileage(Car* garage, int length)
{
    int key;
    int i,j;
    for (i = 1; i < length; i++)
    {
               key = (garage + i)->mileage;
               j = i-1;

              while( (j >= 0) && ((garage + j)->mileage > key))
                {
                        (garage+(j+1))->mileage = (garage+j)->mileage;
                        j = j-1;
                }
        (garage+(j+1))->mileage = key;
    }
}


