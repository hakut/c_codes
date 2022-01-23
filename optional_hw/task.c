#include <stdio.h>
#include <stdlib.h>

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
    char class[5];
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

studentPtr* readFromFile(FILE* filePtr, studentPtr *cr);

int menu();



int main()
{
	FILE* filePtr;
	filePtr = fopen("student_info.txt","w+");
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
	studentPtr cr = NULL;
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

studentPtr* readFromFile(FILE* filePtr, studentPtr *cr)
{
	studentPtr current = *cr;
	studentPtr previous = NULL;
	studentPtr new = malloc(sizeof(studentPtr));
	filePtr = fopen("student_info.txt", "r+");
	if (filePtr == NULL)
    {
        fprintf(stderr, "\nCouldn't Open File'\n");
        exit (1);
    }
	printf("%s %d\n",__func__,__LINE__);
    while(fread(new, sizeof(student), 1, filePtr))
    {
		while( current != NULL && new->id > current->id ) {
			previous = current;
			current = current->studentPtr;
		}
		if( previous == NULL ) {
			new->studentPtr = *cr;
			*cr = new;
		}
		else {
			previous->studentPtr = new;
			new->studentPtr = current;
		}
    }
    fclose(filePtr);
	return cr;
}

void insertStudent(FILE* filePtr, studentPtr* cr, int id)
{
	cr = readFromFile(filePtr, cr);
	studentPtr current = *cr;
	studentPtr start;
	studentPtr previous = NULL;
	studentPtr new = malloc(sizeof(studentPtr));
	printf("%s %d\n",__func__,__LINE__);

	if(new != NULL) {
		new->id = id;
		new->studentPtr = NULL;
		new->coursePtr = NULL;
		printf("Enter name, surname, department, class, faculty, gpa, year information\n");
		// gets(new->name);
		// gets(new->surname);
		// gets(new->department);
		// gets(new->class);
		// gets(new->faculty);
		// scanf("%f",&new->gpa);
		// scanf("%d",&new->year);
	}

    while( current != NULL && new->id > current->id ) {
        previous = current;
        current = current->studentPtr;
    }
    if( previous == NULL ) {
        new->studentPtr = *cr;
        *cr = new;
		start = *cr;
    }
    else if(current->id != new->id) {
        previous->studentPtr = new;
        new->studentPtr = current;
    }
	printf("%s %d\n",__func__,__LINE__);

	filePtr = fopen ("student_info.txt", "w+");
    if (filePtr == NULL) {
        fprintf(stderr, "\nCouldn't Open File'\n");
        exit (1);
    }
	printf("%s %d\n",__func__,__LINE__);
    
    while(start != NULL) {
        fwrite(start, sizeof(studentPtr), 1, filePtr);
        start = start->studentPtr;
    }
    
    if(fwrite != 0) {
        printf("Linked List stored in the file successfully\n");
    } else {
           printf("Error While Writing\n");
    }
    fclose(filePtr);

}

void deleteStudent(FILE* filePtr, studentPtr* cr, int id)
{
	
}
// void insertCourse(coursePtr* cr, coursePtr* inscr, char* code)
// {
// 	coursePtr new;
// 	coursePtr previous = NULL;
// 	coursePtr current = cr;

// 	new = malloc(sizeof(coursePtr));
// 	if(new != NULL) {
// 		new = inscr;
// 	}

// }
