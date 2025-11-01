// Program: Grade Manager System for Schools
// Author: Ugochukwu Odinjor
// Purpose: Give Teachers and Schools the ability to efficiently manage and keep track of their student's grades


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 50
#define MAX_GRADES 5

// ***** Structure for storing Students *****
typedef struct student {
         char name[50]; // Stores Student's names
         int StudentID; // Stores Student's unique roll number(in this class)
         float grades[MAX_GRADES]; // To store an array of grades for five different assignments
         float avgGrade; // Stores Student's average grade in the class
         char letterGrade;  // To store the student's letter grade in the class
} Student;

// ***** Structure for storing courses *****
typedef struct course{
	int courseNum;    // Store course number here 
	char courseName[MAX_INPUT];  // Store the name of the course
	int numStudents; // Number of students
	Student *roster;
} Course;


char input[MAX_INPUT];

void grade_students(); // Prototype

void student_roster() {
	Course myCourse;
	printf("Enter the course number: \n:> ");
	if (fgets(input, sizeof(input), stdin) != NULL) {
		myCourse.courseNum = atoi(input);
	}
	
	printf("Enter the course name: \n:> ");
	if (fgets(myCourse.courseName, sizeof(myCourse.courseName), stdin) != NULL) {
		// Remove Newline
		myCourse.courseName[strcspn(myCourse.courseName, "\n")] = '\0';
	}
	
	printf("Enter the number of students in your course: \n:>");
	if (fgets(input, sizeof(input) , stdin) != NULL) {
		myCourse.numStudents = atoi(input);
	}	
	
	// Allocate memory for student roster
	myCourse.roster = malloc(myCourse.numStudents * sizeof(Student));
	if (myCourse.roster == NULL) { 
		printf("Memory allocation for student roster failed.\n");
		return;	
	}	
	
	// Populate student roster
	for (int i = 0; i < myCourse.numStudents; ++i) {
		printf("Enter Student %d Details\n", i + 1);
		printf("Enter Student ID: \n:>");
		if (fgets(input, sizeof(input), stdin) != NULL) {
			myCourse.roster[i].StudentID = atoi(input);
		}
		printf("Enter Student's Name: \n:>");
		if (fgets(myCourse.roster[i].name, sizeof(myCourse.roster[i].name), stdin) != NULL) {
			myCourse.roster[i].name[strcspn(myCourse.roster[i].name, "\n")] = '\0';
		}		
	
		// Poplate Student grades
		printf("Enter Grades %s:\n:>", myCourse.roster[i].name);
		for (int j = 0; j < MAX_GRADES; ++j) {
			printf("Assignment %d: \n:> ", j + 1); 
			if (fgets(input, sizeof(input), stdin) != NULL) {
				myCourse.roster[i].grades[j] = atoi(input);
			} 
		}
		// Calculate average
		float sum = 0;
		for (int j = 0; j < MAX_GRADES; ++j) {
			sum += myCourse.roster[i].grades[j];
		}
 		myCourse.roster[i].avgGrade = sum / MAX_GRADES;
	
		// Assign letter grade 	
 		if (myCourse.roster[i].avgGrade >= 90)
			myCourse.roster[i].letterGrade = 'A';
		else if (myCourse.roster[i].avgGrade >= 80)
                	myCourse.roster[i].letterGrade = 'B';
		else if (myCourse.roster[i].avgGrade >= 70)
                	myCourse.roster[i].letterGrade = 'C';
		else if (myCourse.roster[i].avgGrade >= 60)
                	myCourse.roster[i].letterGrade = 'D';
		else 
                	myCourse.roster[i].letterGrade = 'F';
	}
	printf("Course #: %d\n", myCourse.courseNum);
	printf("Course Name: %s\n", myCourse.courseName);
	printf("# of students: %d\n", myCourse.numStudents);
	printf("Name            StudentID       Assignment 1    Assignment 2    Assihnment 3    Assigment 4     Assignment 5    Avg     Letter\n");
       	printf("-------------------------------------\n");
	for (int i = 0; i < myCourse.numStudents; ++i) {
			printf("%s		%d	%.2f	%.2f	%.2f	%.2f	%.2f	%.2f	%c\n", 
	myCourse.roster[i].name, 
	myCourse.roster[i].StudentID, 
	myCourse.roster[i].grades[0],  
	myCourse.roster[i].grades[1],  
	myCourse.roster[i].grades[2],  
	myCourse.roster[i].grades[3], 
	myCourse.roster[i].grades[4], 
	myCourse.roster[i].avgGrade, 
	myCourse.roster[i].letterGrade);	
	} 	 	
}

int main() {

	// Prompt user to enter the number of people in a class
	student_roster();
	return 1;
}
