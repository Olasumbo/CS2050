#include <stdio.h>
#include <stdlib.h>

typedef struct student{
	char* name;
	double* homework;
	double* quizes;
	double* tests;
	double hwavg;
	double quizavg;
	double testavg;
	double weightedavg;
} Student;

typedef enum type{
	HW,
	QUIZ,
	TEST,
	WEIGHTED
} Type;

Student* scan_data(char* filename,Student* class,int num_students);
void get_averages(Student* class, int num_students);
Student* find_highest(Student* class, int num, Type search);

int main(int argc, char* argv[]){


	if(argc != 6){
		printf("Imrpoper use of program:\nCorrect use: ./a.out <number_Students> inputfile.txt <num_HW> <num_quiz> <num_tests>\n\nexiting...");
		return 0;
	}

	int i = 0;

	//Get input
	int num_students = atoi(argv[1]);
	char* file_name = argv[2];
	int num_HW = atoi(argv[3]);
	int num_Quiz = atoi(argv[4]);
	int num_Test = atoi(argv[5]);
	printf("You have %d students that each have completed %d Hw's, %d Quizes, and %d Tests\n",num_students,num_HW,num_Quiz,num_Test);
	printf("Your file name is: %s\n\n",file_name);



	//Allocating memory
	Student* class = (Student*) malloc(sizeof(Student)*num_students);
	for(i = 0; i < num_students; i++){
		class[i].name = malloc(sizeof(char)*25);
		class[i].homework = malloc(sizeof(double)*num_HW);
		class[i].quizes = malloc(sizeof(double)*num_Quiz);
		class[i].tests = malloc(sizeof(double)*num_Test);
	}	

	//SCAN IN DATA
	Student* populated_class = scan_data(file_name,class,num_students);
	if(populated_class == NULL){
		printf("MAKE SURE TO FREE ALLOCATED MEMORY HERE, EXIT FOR NOW WITH MEMORY LEAKS");
	}

	//AVERAGES
	get_averages(class,num_students);


	//Menu
	int option = 0;
	while(option != 5){
		printf("-----------Menu-----------\n");
		printf("1.) Highest Homework Average\n");
		printf("2.) Highest Quiz Average\n");
		printf("3.) Highest Test Average\n");
		printf("4.) Highest Weighted Average\n");
		printf("5.) EXIT");
		printf("Please select an option\n");
		scanf("%d",&option);

		while(option < 1 && option > 5){
			printf("Please select a valid option \n");
			scanf("%d",&option);
		}
		
		if(option == 1){
			find_highest(class,num_students,HW);
		}else if(option == 2){
			find_highest(class,num_students,QUIZ);
		}else if(option == 3){
			find_highest(class,num_students,TEST);
		}else if(option == 4){
			find_highest(class,num_students,WEIGHTED);
		}else{
			printf("\n\n.............EXITING ............\n\n\n");
		}
		
	}

	return 1;
}

//Returning a Student* Is absolutely in no way shape or form a typo  on the lab document.
//	As I mentioned in lab, I was going to allow you to switch it to return an int
//      in order to make things easier on you because we have done that before since 1050.
//	I apologize for the misunderstanding.
// 	I started to write this function to demostrate how to use a return value int instead of a student pointer
//      I also didn't finish this program all the way because I expect you to be able to go through and see the general idea
//	and either complete it on your own, or just understand how you would go about solving this lab.
Student* find_highest(Student* class, int num_students, Type search){

	if(class == NULL || num_students <=0){
		printf("Error in find highets\n\n");
		return NULL;
	}

	int i = 0;
	double highest_homework = 0;
	//int index = 0;
	Student* our_student;

	if(search == HW){
	
		for(i = 0; i < num_students; i++){
			if(class[i].hwavg > highest_homework){
				highest_homework = class[i].hwavg;
				//index = i;		
				our_student = &class[i];		
			} 
		}

	}

	if(search == QUIZ){

                for(i = 0; i < num_students; i++){
                        if(class[i].quizavg > highest_homework){
                                highest_homework = class[i].hwavg;
				//index = i;
				our_student = &class[i];
                        }
                }

      	}

	//return index;
	return our_student;
}

void get_averages(Student* class,int num_students){
	if(class == NULL || num_students <= 0){
		printf("Error when entering get averages function\n");
		return;
	}

	int i = 0;
	int j = 0;
	double hw_total = 0;
        double quiz_total = 0;
        double exam_total = 0;

	while(i < num_students){

		//Averages for Homework
		for(j = 0; j<6; j++){
			hw_total += (class[i].homework[j]);	
		}
		class[i].hwavg = (hw_total/6.00);
		//printf("HOMEWORK AVERAGE: %lf\n",class[i].hwavg);
		hw_total = 0;
		
		//Averages for Quizes
		for(j = 0; j<4; j++){
			quiz_total += class[i].quizes[j];
		}
		class[i].quizavg = (quiz_total/4.00);
		//printf("QUIZ AVERAGE: %lf \n",class[i].quizavg);
		quiz_total = 0;		

		//Averages for exams
		for(j = 0; j < 2; j++){
			exam_total += class[i].tests[j];
		}
		class[i].testavg = (exam_total/2.00);
		//printf("EXAM AVERAGE: %lf \n",class[i].testavg);
		exam_total = 0;

		class[i].weightedavg = (.10)*(class[i].hwavg) + (.30)*class[i].quizavg + (.60)*class[i].testavg;
		printf("Weighted Avergage: %.2lf\n",class[i].weightedavg);
		i++;
	}
}

Student* scan_data(char* filename,Student* class ,int num_students){

	if(filename == NULL || num_students <= 0){
		return NULL;
	}

	int i = 0;
	FILE* fp = fopen(filename,"r");
	if(fp == NULL){
		printf("ERROR! UNABLE TO OPEN FILE, EXITING\n\n");
		return NULL;
	}

	for(i=0;i<num_students;i++){	
		fscanf(fp,"%s",class[i].name);
		//printf("NAME: %s\n",class[i].name);
		fscanf(fp,"%lf %lf %lf %lf %lf %lf",&(class[i].homework[0]),&class[i].homework[1],&class[i].homework[2],&class[i].homework[3],&class[i].homework[4],&class[i].homework[5]);
		//printf("TESTS: %lf %lf %lf %lf %lf %lf \n",class->homework[0],class[i].homework[1],class[i].homework[2],class[i].homework[3],class[i].homework[4],class[i].homework[5]);
		fscanf(fp,"%lf %lf %lf %lf",&class[i].quizes[0],&class[i].quizes[1],&class[i].quizes[2],&class[i].quizes[3]);
		//printf("QUIZES: %lf %lf %lf %lf \n",class[i].quizes[0],class[i].quizes[1],class[i].quizes[2],class[i].quizes[3]);
		fscanf(fp,"%lf %lf",&class[i].tests[0],&class[i].tests[1]);
		//printf("TESTS: %lf %lf\n",class[i].tests[0],class[i].tests[1]);
	}
	return class;
}
