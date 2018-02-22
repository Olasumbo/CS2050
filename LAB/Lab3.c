#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int *read_file( char* filename);
void int_to_binary( int number);
int binary_to_decimal( int number);

int main( int argc, char *argv[] ) 
{
         if ( argc != 2)
         {
                 printf( "Incorrect number of arguments\n");
                 return 1;
         }
         	int i =0;
		int*array = read_file(*(argv + 1));
		for( i =0; i <= 4; i++)
		{
			//binary_to_decimal(*(array+i));
			printf("\n%d binary to integer\n ", *(array+i));// This print out the numbers in the array
			binary_to_decimal(*(array+i));//this prints the actual conversion of number

		}
		for(i = 5; i < 10; i++)
		{
			//nclude<stdio.h>
			//  2 #include<stdlib.h>
			//    3 #include<math.h>
			//    int_to_binary(*(array+i));
			printf("\n%d interger to binary\n", *(array+i));// same as above
                        int_to_binary(*(array+i));
		}

 return 0;
}
int *read_file( char* filename)
{
         FILE* fp = NULL;
         int i = 0;
         int* input_array = malloc(sizeof(int)* 10);
         fp = fopen(filename, "r");
         if ( fp == NULL)
         {
                 printf(" unable to open file\n");
                 return NULL;

        }
        while(i < 10)
	{
                 fscanf(fp," %d", (input_array +i));
                 printf(" %d", *(input_array +i));// This test weather my reafile works.
                 i++;
         }

        fclose(fp);
        return input_array;
}
void int_to_binary( int number)
{
         if ( number != 0)
         {
		 int remainder = 0;
                 remainder = number%2;
		 int_to_binary( number/2);// recursion #callitself
                 printf("%d", remainder);
		 //int_to_binary( number/2);// recursion #callitself 
	 }
}
int binary_to_decimal( int number)
{
    int remainder;
    int decimal = 0;
    int i =0; 
    while(number != 0) 
    {
        remainder = number % 10;
        number = number/10;
	decimal = decimal+( remainder*pow(2,i));
	i++;
        //printf("%d", decimal);
	//binary_to_decimal( number*2);
    }
printf("%d", decimal);

    return decimal;
}
