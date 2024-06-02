#ifndef COURSE_H
#define COURSE_H

typedef struct {
    char name[100];
    float midtermScore;
    float finalScore;
    float gpa;
    char grade;
} Course;

void initCourse(Course *course, const char *name, float midterm, float final);
void setScores(Course *course, float midterm, float final);
void calculateGPAAndGrade(Course *course);
void displayCourse(const Course *course);

#endif
