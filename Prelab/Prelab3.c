#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void int_to_binary( int number);

int main()
{
	int input;
	printf("Hey you, Enter a positive number to be converted to binary\n");
	scanf("%d",&input);
	while( input < 0)
	{
		printf("Seriously, Enter a positive number to be converted to binary\n");
 	        scanf("%d",&input);
	}
	int_to_binary(input);
return 0;
}  

void int_to_binary( int number)
{
	//char* storage = malloc(sizeof(Char)*number);
	int remainder;
	int binary = 0;
	int i = 1;
	
	while( number != 0)
	{
		remainder = number%2;
		number = number/2;
		binary = binary + ( remainder*i);
		i = i*10;
	}
	

}
