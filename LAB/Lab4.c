#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct car
{
       char *color;
       int seats;
       int mileage;
}Car;

void print_to_file(char* filename, Car* garage, int length);
void Insertion_sort_seats(Car* garage, int length);
void scan_garage(Car* garage, int length);
void free_garage(Car* garage, int length);


int main(int argc, char* argv[])
 {

            if ( argc != 4)
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
		  //printf("%s %d %d\n", (garage+i)->color, (garage+i)->seats, (garage+i)->mileage);
                  i++;
           }

           fclose(fp);
	
Insertion_sort_seats(garage, size);
printf(" ************Insertion sort*********\n");
          for(i = 2; i < 35; i++)
           {
                  printf("%s %d %d\n", (garage+i)->color, (garage+i)->seats, (garage+i)->mileage);
           }
print_to_file(*(argv + 3), garage, size);
free_garage(garage, size);

return 0;

}
void Insertion_sort_seats(Car* garage, int length)
{
   int key;
	int count2 =0, count5 =0, count6 =0, count7 =0, count8 =0, count9 =0;
	int count3 =0;
	int count4 =0;
        
   int i,j;
   for (i = 1; i < length; i++)
    {
               key = (garage + i)->seats;// key points to the first seat in my array
               j = i-1;
             while( (j >= 0) && ((garage + j)->seats > key))
                {
                      (garage+(j+1))->seats = (garage+j)->seats;
                      j = j-1;
                }
        (garage+(j+1))->seats = key;
    }
	for( i =0; i< length; i++)
	{
		if( garage[i].seats == 2)
		count2++;
		if( garage[i].seats == 3)
                count3++;
		if( garage[i].seats == 4)
                count4++;
                if( garage[i].seats == 5)
                count5++;
		if( garage[i].seats == 6)
                count6++;
                if( garage[i].seats == 7)
                count7++;
		if( garage[i].seats == 8)
                count8++;
                if( garage[i].seats == 9)
                count9++;

	}
}
/*void selecton_sort(Car* garage, int length)
{
 	int i, j, temp;
	for (i = 0; i < length; i++)
	{
		//min_idx = i;
        	for (j = i+1; j < length; j++)
		{
          if (garage[i].seats < garage[j].seats)
		{
			temp = garage[i].seats;
            		garage[i].seats = garage[j].seats;
			garage[j].seats = temp;
		}
		}
	}
}*/
void print_to_file(char* filename, Car* garage, int length)
{
         int i;
         FILE* fp = NULL;
         fp = fopen(filename, "w");
         if ( fp == NULL)
         {
                printf(" unable to open file\n");
                return;
         }
                for(i = 0; i < length; i++)
                {
			//(garage+i)->color = malloc(sizeof(char)*6);
			fscanf(fp, "%s %d %d", (garage+i)->color, &(garage+i)->seats, &(garage+i)->mileage);
			fprintf(fp,"%s %d %d\n",(garage+i)->color, (garage+i)->seats, (garage+i)->mileage);                   
		}
	fclose(fp);
}
/*Car* sort_mileage( Car* garage, int length)
{
	int count = 0;
	while( count

}*/
void free_garage(Car* garage, int length)
{
        int i;
          for(i = 0; i < length; i++)
        {
                free((garage+i)->color);
        }
               free(garage);
}

