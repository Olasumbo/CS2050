#include "Homework3.h"

int main(int argc, char** argv)
{
	 if ( argc != 2)
         {
              printf( "Incorrect number of arguments\n");
              return 1;
         }

	int key;
  do    
  {
	//int key;
	printf(" To search for a vehicle newer than a specific year enter '1'\n");
	printf(" To search for a vehicle that costs less than a certain price enter '2'\n");
	printf(" To search for a vehilce with both of the above parameters enter '3'\n");
	printf(" To exit enter '-1'");
	scanf("%d", &key);
	while( key < -1 || key > 3)
        {
        	printf("Incorrect input value\n");
                scanf("%d", &key);
        }
	int year;
	int price;

	switch( key )
	{
		case 1:
		printf("Enter the year you would like the vehicles to be newer than:\n");
		scanf("%d", &year);

		break;

		case 2:
		printf("Enter the price you would like the vehicles to be less than:\n");
		scanf("%d", &price);

		break;

		case 3:
		printf("Enter the year you would like the vehicles to be newer than:\n");
		scanf("%d", &year);
		printf("Enter the price you would like the vehicles to be less than:\n");
		scanf("%d", &price);

		break;

		default:
		break;

	}
  }while( key != -1);

return 0;
}
