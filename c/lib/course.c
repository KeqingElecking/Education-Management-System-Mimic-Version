#include "course.h"
#include <stdio.h>

void initCourse(Course *course, const char *name, float midterm, float final) {
    strcpy(course->name, name);
    course->midtermScore = midterm;
    course->finalScore = final;
    calculateGPAAndGrade(course);
}

void setScores(Course *course, float midterm, float final) {
    course->midtermScore = midterm;
    course->finalScore = final;
    calculateGPAAndGrade(course);
}

void calculateGPAAndGrade(Course *course) {
    float average = (course->midtermScore * 0.4) + (course->finalScore * 0.6);
    if (average >= 8.5) {
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
    printf("\t\t%s - Midterm: %.2f, Final: %.2f, GPA: %.2f, Grade: %c\n",
           course->name, course->midtermScore, course->finalScore, course->gpa, course->grade);
}
