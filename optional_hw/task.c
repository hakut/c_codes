#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Course {
    char code[6];
    char name[30];
    char instructor[30];
    char term[6];
    int year;
    struct Course *coursePtr;
};

struct Student {
    int id;
    char name[15];
    char surname[15];
    char department[15];
    char class[6];
    char faculty[15];
    float gpa;
    int year;
    struct Student *studentPtr;
    struct Course *coursePtr;
};

typedef struct Course course;
typedef struct Student student;

typedef course* coursePtr;
typedef student* studentPtr;

void insertCourse(coursePtr* cr, coursePtr* inscr, char* code);	// Prevent same course twice
char* deleteCourse(coursePtr* cr, coursePtr* inscr, char* code);

void insertStudent(FILE* filePtr, studentPtr* cr, int id);	// Prevent same student twice
void deleteStudent(FILE* filePtr, studentPtr* cr, int id);

void displayStudent(FILE* filePtr, int id);
void displayClassNumbers(FILE* filePtr, int id);
void displayRecvCourse(FILE* filePtr, char* code, char* term, int year);

void registration(FILE* filePtr); // Use insertStudent and insertCourse functions

studentPtr readFromFile(FILE* filePtr);

int menu();



int main()
{
	FILE* filePtr;
	filePtr = fopen("student_info.txt","ab+");
	fclose(filePtr);
	coursePtr *cr = NULL;
	int choice,id,year;
	char* code[6] = {0};
	while(1) {
		choice = menu();
		switch(choice) {
			case 1:
				registration(filePtr);
				break;
			case 2:
				registration(filePtr);
				break;
			// case 3:
			// 	insertCourse(cr,inscr,&code);
			// 	break;
			// case 4:
			// 	deleteCourse(cr,inscr,&code);
			// 	break;
			// case 5:
			// 	displayStudent(filePtr,id);
			// 	break;
			// case 6:
			// 	displayClassNumbers(filePtr,id);
			// 	break;
			// case 7:
			// 	displayRecvCourse(filePtr,&code,&term,year);
			// 	break;
			default:
				break;
	}
	return 0;
}
}

int menu()
{
	int choice;
	puts("Please choose one of the options below...");
	puts("1. Enter Student");
	puts("2. Delete Student");
	puts("3. Enter Course");
	puts("4. Delete Course");
	puts("5. Show Student Info");
	puts("6. Show Student Numbers for Each Class");
	puts("7. Show Class Info");
	scanf("%d",&choice);
	return choice;
}

void registration(FILE* filePtr)
{
	int choice,id;
	studentPtr cr;
	cr = readFromFile(filePtr);
	while(cr != NULL) {
		printf("%d", cr->id);
		cr = cr->studentPtr;
	}
	puts("1 - Student Registration");
	puts("2 - Student deletion");
	scanf("%d",&choice);
	printf("Enter student id : ");
	scanf("%d",&id);
	switch (choice)	{
	case 1:
		insertStudent(filePtr,&cr,id);
		break;
	case 2:
		deleteStudent(filePtr,&cr,id);
		break;
	default:
		break;
	}
}

studentPtr readFromFile(FILE* filePtr)
{
	studentPtr head = NULL;
	studentPtr last = NULL;
	studentPtr temp = malloc(sizeof(student));
	filePtr = fopen("student_info.txt", "r");
	if (filePtr == NULL)
    {
        fprintf(stderr, "\nCouldn't Open File'\n");
        exit (1);
    }
	printf("%s %d\n",__func__,__LINE__);
    while(fread(temp, sizeof(student), 1, filePtr))
    {
	    if(head == NULL) {
		    head = last = malloc(sizeof(student));
	    }
	    else {
		    last->studentPtr = malloc(sizeof(student));
		    last->coursePtr = malloc(sizeof(course));
		    last = last->studentPtr;
	    }
	    last->id = temp->id;
	    strcpy(last->name, temp->name);
	    strcpy(last->surname, temp->surname);
	    strcpy(last->department, temp->department);
	    strcpy(last->faculty, temp->faculty);
	    strcpy(last->class, temp->class);
	    last->gpa = temp->gpa;
	    last->year = temp->year;
	    last->studentPtr = NULL;
	    last->coursePtr = NULL;
    }

    fclose(filePtr);
    return head;
}

void insertStudent(FILE* filePtr, studentPtr* cr, int id)
{
	studentPtr new;
	studentPtr current = *cr;
	studentPtr previous = NULL;
	studentPtr temp;

	new = malloc(sizeof(student));
	if(new != NULL){
		printf("%d\n",id);
		new->id = id;
		printf("Enter name : ");
		fflush(stdin);
		scanf("%s",new->name);
		printf("Enter surname : ");
		scanf("%s",new->surname);
		printf("Enter department : ");
		scanf("%s",new->department);
		printf("Enter faculty : ");
		scanf("%s",new->faculty);
		printf("Enter class : ");
		scanf("%s",new->class);
		printf("Enter gpa : ");
		scanf("%f",&(new->gpa));
		printf("Enter year : ");
		scanf("%d",&(new->year));
		new->studentPtr = NULL;
	}


	while(current != NULL && new->id > current->id) {
		temp = current;
		previous = current;
		current = current->studentPtr;
	}
	if( previous == NULL ) {
		new->studentPtr = *cr;
		*cr = new;
		temp = *cr;
	}
	else if(new->id != current->id)	{
		previous->studentPtr = new;
		new->studentPtr = current;
	}

	filePtr = fopen("student_info.txt","a");
	if(filePtr == NULL) {
		printf("Error! Couldn't open file");
	}
	else {
		while(temp != NULL) {
			printf("%s %d\n",__func__,__LINE__);
			fprintf( filePtr, "%d\t%s\t%s\t%s\t%s\t%s\t%f\t%d\n",
					temp->id, temp->name, temp->surname, temp->department, 
					temp->class, temp->faculty, temp->gpa, temp->year );
			temp = temp->studentPtr;
		}
	}
	fclose(filePtr);
}

void deleteStudent(FILE* filePtr, studentPtr* cr, int id)
{
	studentPtr temp;
	studentPtr current = *cr;
	studentPtr previous = NULL;

	while(current != NULL && id > current->id) {
		previous = current;
		current = current->studentPtr;
	}
	
	
}
void insertCourse(coursePtr* cr, coursePtr* inscr, char* code)
{
	coursePtr new;
	coursePtr previous = NULL;
	coursePtr current = *cr;

	new = malloc(sizeof(course));
	if(new != NULL) {
		new = *inscr;
	}
	while(current != NULL && strcmp(new->code,code) > 0) {
		previous = current;
		current = current->coursePtr;
	}
	if(previous == NULL) {
		new->coursePtr = *cr;
		*cr = new;
	}
	else if(strcmp(new->code, code) != 0) {
		previous->coursePtr = new;
		new->coursePtr = current;
	}
}
