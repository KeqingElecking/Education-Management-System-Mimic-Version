#ifndef COURSE_H
#define COURSE_H

typedef struct {
    char name[100];
    float midtermScore;
    float finalScore;
    float gpa;
    float coeff_midterm;
    char grade;
} Course;

void initCourse(Course *course, const char *name, float midterm, float final, float coeff_midterm);
void setScores(Course *course, float midterm, float final);
void calculateGPAAndGrade(Course *course);
void displayCourse(const Course *course);

#endif
