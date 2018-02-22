#include<stdio.h>
#include<stdlib.h>

double average(double* array, int length);
double weighted_average(double hw, double quiz, double test);

#define NAMELENGTH 20

typedef struct Student
{
    char *name;
    double* homework;
    double* quizzes;
    double* tests;
	double weightedaverage;
}student;

int main(void)
{
	printf("Welcome to my Grade Calculator\n");
	student *array = malloc(sizeof(student)); // create space for the entire student
	(student+i)->name = malloc(sizeof(char))*NAMELENGTH); // malloc space for the name
	printf(" Please enter the student's name:\n");
	scanf("%s",&(student+i)-> name);
	
	// userinput commands for how many of each they have
	int hwcount = 0;// how many ...
	int testcount =0;
	int quizcount =0;
	int i;
	
	printf(" Enter the number of homework assignments:\n");
	scanf("%d",&hwcount);
	printf(" Enter the number of quizzes:\n");
	scanf("%d", &quizcount);
	printf(" Enter the number of tests:\n");
	scanf("%d",&testcount);
	
	double tempArr[hwcount] = {};
	double tempArr2[quizcount] = {};
	double tempArr3[testcount] = {};
	
	for (i = 0; i < hwcount; i++)
		{
			printf(" Please enter %s grade for homework i:", *student+i)->name);
			scanf("%d",&tempArr);
		}
	for (i = 0; i < testcount; i++)
		{
			printf(" Please enter %s grade for test i:",*(student+i)->name);
			scanf("%d",&tempArr3);
		}
	for (i = 0; i < quizcount; i++)
		{
			printf(" Please enter %s grade for quiz i:",*(student+i)->name);
			scanf("%d",&tempArr2);
		}
	
	array->homework = average(tempArr, hwcount);
	printf(" %s homework average is:",*(student+i)-> name, *(array->homework));
	array->quizzes = average(tempArr2, quizcount);
	printf(" %s quiz average is:",*(student+i)-> name, *(array->quizzes));
	array->tests= average(tempArr3, testcount);
	printf(" %s test average is:",*(student+i)-> name, *(array->tests));
	array->weightedaverage = weighted_average// figure this out.
	printf(" %s weighted average is:",*(student+i)-> name, *(array->weightedaverage));
	
}
double average(double* array, int length)
{
	int i;
	float hold;
	float average;
	for( i = 0; i < length; i++)
		{
				hold += *(array+i);
		}
	average = hold/(float)length;
	return array
}
double weighted_average(double hw, double quiz, double test)
{
	double homework, quizz, tests, weightedav;
	homework = ( hw * .10);
	quizz = (quiz * .30);
	tests = (test * .60);
	weightedav = (homework + quizz + tests );
	
	return weightedav;
}