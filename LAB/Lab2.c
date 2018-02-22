#include<stdio.h>
#include<stdlib.h>
#include<time.h>


double *read_file( char* filename, int length);
double find_min( double* array, int length);
double find_max( double *array, int length);
double median( double *array, int length);
double mode (double *array, int length);
void write_to_file ( char* filename, double* min, double *max, double *median, double *mode, int *array, int length);
void print_array (int *array, int length);
int errorCheck (int x);
void initialize_array(int *array, int length);
void bubble_sort( int length, int *array);
void find_number(int *array, int length, int number);


int main(int argc, char *argv[])
{
	
	srand(time(NULL));
	if ( argc != 4)
	{
		printf( "Incorrect number of arguments\n");
		return 1;
	}
	int size = atoi(*(argv + 1));
	double* array = read_file(*(argv + 2), size);

	//int size = atoi( argv[2]);
	double minimum =  find_min ( array, size);
	printf(" Actual Minimum is %.2lf\n",(minimum));

	double maximum = find_max( array, size);
	printf(" Actual Maximum is %.2lf\n",(maximum));
	
	double med  = median(array,size);
	printf(" The median is %.2lf\n", med);

	double mod = mode(array,size);
        printf(" The mode is %.2lf\n\n\n", mod);

	int userinput = 0;
	 	 while ( errorCheck(userinput) == 0)
	{	
		printf(" Enter a number between 1 and 100\n");
		scanf("%d", &userinput);
	}
	
	//srand(time(NULL));
        int *Array = malloc(sizeof(int)*userinput);
	initialize_array( Array,userinput);
	print_array(Array,userinput);
        bubble_sort( userinput, Array);
	printf(" The sorted array:\n");
	print_array(Array, userinput);

	int findnum;
	printf("What number would you like to find in your array\n");
	scanf(" %d", &findnum);
	find_number( Array,userinput,findnum);

	//argv[3]
	write_to_file(argv[3], &minimum, &maximum, &med, &mod, Array, userinput);

        return 0;

}
int errorCheck(int x)
{    
	if ( x  <= 0 ||  x  > 100)
		return 0;
	else
		return 1;
}
double *read_file( char* filename, int length)
{
	FILE* fp = NULL;
	int i = 0;
	double* input_array = malloc(sizeof(double)*length);
	fp = fopen(filename, "r");
	if ( fp == NULL)
	{
		printf(" unable to open file\n");
		return NULL;

	}
	while( i < length)
	{
		fscanf(fp," %lf", (input_array +i));
		printf(" print out double, %.2lf", *(input_array +i));
		printf(" print out double, %p \n",(input_array +i));
		i++;
	}
	fclose(fp);
	return input_array;
}

double find_min( double* array, int length)
{
	int i;
	double min =*(array);

	for( i= 0; i < length; i++)
	{
		if( min > *(array + i))
		{
			min = *(array + i);
		}
		//printf (" The minimum is, %.2lf",(min));
	}
	return min;
}
double find_max ( double *array, int length)
{
	int i;
	double max = *(array);
	for ( i = 0; i < length; i++)
	{
		if ( max < *(array + i))
		{
			max = *(array + i);
		}
	}
	return max;
}
double median (double *array, int length)
{
	int i, j, temp;
	for( i = 0; i < length-1; i++)
	{
		for( j = i+1; j < length; j++)
		{
	 		if(*(array+j) < *(array+i))
			{	
				temp = *(array+i);
				*(array+i) = *(array+j);
				*(array+j) = temp;
			}
		}
	}
	
	if ( length % 2 == 0)
	return (((array[length/2])+ (array[length/2 - 1])) / 2.0);
		else
	return array[length/2];
}
double mode (double *array, int length)
{
      int t = 0;
      int i,j;
       for(i = 0; i < length; i++)
	{
        for(j = 1; j < length-i; j++)
	  {
            if(array[j-1] > array[j])
	    {
                t = array[j-1];
                array[j-1] = array[j];
                array[j] = t;
            }
          } 
        }
    double mode = array[0];
    int count = 1;
    int count2 = 1;

    for(i = 1;i < length;i++)
    {
        if(array[i-1] == array[i])
	{
            count++;
        }
        if(count  > count2)
	{
            mode = array[i];
            count2 = count;
        }
    }
    return mode;
}
void initialize_array(int *array, int length)
{
	int i;
	for(i =0; i < length; i++)
		*(array + i)= (rand() % 101);
}
void print_array (int *array, int length)
{
	int i;
	for(i =0; i < length; i++)
		printf("%d ", *(array + i));
	
	printf("\n");
}
void bubble_sort(int length, int *array)
{
	int i, j, temp;
        for( i = 0; i < length-1; i++)
        {
                for( j = i+1; j < length; j++)
                {
                        if(*(array+j) < *(array+i))
                        {
                                temp = *(array+i);
                                *(array+i) = *(array+j);
                                *(array+j) = temp;
                        }
                }
        }	
}
void find_number(int *array, int length, int number)
{
	//int counter = 0;
	int i;
	for( i = 0; i < length; i++)
	{	
		if ( *(array+i) == number)
		 {  
			//++counter;
			printf(" Number was found at index %d\n", i-1);
			return;
		 }	
	}

		printf(" Number not found\n");

}
void write_to_file( char *filename, double *min, double *max, double* median, double *mode, int *array, int length)
{
	FILE* fp = NULL;
                
        fp = fopen(filename, "w");
        if ( fp == NULL)
        {
                printf(" unable to open file\n");
                return;
        }
	
	fprintf(fp, "Min: %.2lf\n", *(min));
	fprintf(fp, "Max: %.2lf\n", *(max));
	fprintf(fp, "Median: %.2lf\n", *(median));
	fprintf(fp, "Mode: %.2lf\n", *(mode));
	int i;
        for(i =0; i < length; i++)
                fprintf(fp, "sorted array;%d\n ", *(array + i));

        printf("\n");

        fclose(fp);
}


