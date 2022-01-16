#include <stdio.h>
#include <stdlib.h>

struct Course {
    int code;
    char name[30];
    char instructor[30];
    char term[6];
    int year;
    struct Course *next;
};

struct Student {
    int id;
    char name[15];
    char surname[15];
    char department[15];
    char class[5];
    char faculty[15];
    int gpa;
    int year;
    struct Student *next;
    struct Course *next;
};

typedef struct Course course;
typedef struct Student student;

typedef course* coursePtr;
typedef student* studentPtr;

void insertCourse(coursePtr cr, coursePtr inscr, char* code);	// Prevent same course twice
char* deleteCourse(coursePtr cr, coursePtr inscr, char* code);

void insertStudent(FILE* filePtr, studentPtr cr, int id);	// Prevent same student twice
void deleteStudent(FILE* filePtr, studentPtr cr, int id);

void displayStudent(FILE* filePtr, int id);
void displayClassNumbers(FILE* filePtr, int id);
void displayRecvCourse(FILE* filePtr, char* code, char* term, int year);

void registration(FILE* filePtr); // Use insertStudent and insertCourse functions

void menu();

int main()
{
	FILE* filePtr;

	menu();
	return 0;
}

void menu()
{
	puts("Please choose one of the options below...");
	puts("1. Enter Student");
	puts("2. Delete Student");
	puts("3. Enter Course");
	puts("4. Delete Course");
	puts("5. Show Student Info");
	puts("6. Show Lecture Info");
	puts("7. Show Class Info");
}
