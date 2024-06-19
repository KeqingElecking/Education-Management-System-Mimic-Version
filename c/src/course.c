#include "../lib/course.h"
#include <stdio.h>
#include <string.h>

void initCourse(Course *course, const char *name, float midterm, float final, float coeff_midterm) {
    strcpy(course->name, name);
    course->midtermScore = midterm;
    course->finalScore = final;
    course->coeff_midterm = coeff_midterm;
    calculateGPAAndGrade(course);
}

void setScores(Course *course, float midterm, float final) {
    course->midtermScore = midterm;
    course->finalScore = final;
    calculateGPAAndGrade(course);
}

void calculateGPAAndGrade(Course *course) {
    float average = (course->midtermScore * course->coeff_midterm) + (course->finalScore * (1 - course->coeff_midterm));
    if (course->midtermScore < 3 || course->finalScore < 3){
        course->gpa = 0.0;
        course->grade = 'F';
    } else if (average >= 8.5) {
        course->gpa = 4.0;
        course->grade = 'A';
    } else if (average >= 7.0) {
        course->gpa = 3.0;
        course->grade = 'B';
    } else if (average >= 5.5) {
        course->gpa = 2.0;
        course->grade = 'C';
    } else if (average >= 4.0) {
        course->gpa = 1.0;
        course->grade = 'D';
    } else {
        course->gpa = 0.0;
        course->grade = 'F';
    }
}

void displayCourse(const Course *course) {
    printf("\t\t%s - Midterm: %.2f, Final: %.2f, Coeff: %.2f:%.2f, GPA: %.2f, Grade: %c\n",
           course->name, course->midtermScore, course->finalScore, course->coeff_midterm, 1 - course->coeff_midterm, course->gpa, course->grade);
}
