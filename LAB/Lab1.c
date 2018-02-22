#include<stdio.h>
#include<stdlib.h>

double *read_file( char* filename, int length);
double find_min( double* array, int length);
double find_max( double *array, int length);
//double median( double *array, int length);
//double mode (double *array, int length);
void write_to_file ( char*filename, double* array, int lenght);


int main(int argc, char *argv[])
{
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
	
/*	double med  = median(array,size);
	printf(" The median is %.2lf\n", med);

	double mod = mode(array,size);
        printf(" The mode is %.2lf\n", mod);
*/
        write_to_file(*(argv + 3),array, size);
 
	return 0;
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
	double min = *(array);

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
/*double median (double *array, int length)
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
	return (((array[length/2])+ (array[length/2 - 1] / 2.0 )));
		else
	return array[length/2];
}
double mode (double *array, int length)
{
	int maxValue = 0, maxCount = 0, i, j;
	for (i = 0; i < length; ++i)
	 {
      		int count = 0;
      
      		for (j = 0; j < length; ++j)
		 {
         		if (array[j] == array[i])
         		++count;
      		 }	
      
      if (count > maxCount) 
	{
         maxCount = count;
         maxValue = array[i];
        } 
   }
   return maxValue;
}
*/
void write_to_file( char *filename, double *array, int length)
{
	FILE* fp = NULL;
        //int i = 0;
        //double* output_array = malloc(sizeof(double)*length);
        fp = fopen(filename, "w");
        if ( fp == NULL)
        {
                printf(" unable to open file\n");
                return;
        }

        /*while( i < length)
        {
                fscanf(fp," %lf", (array +i));
                printf(" print out output file, %.2lf\n", *(array +i));
               // printf(" print out double, %p \n",(input_array +i));
                i++;
        }*/
	
	fprintf(fp, " %.2lf\n", *(array));
	fprintf(fp, "%d\n", (length));


        fclose(fp);
}
