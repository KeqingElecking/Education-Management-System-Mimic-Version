#ifndef STUDENT_H
#define STUDENT_H

#include "course.h"

#define MAX_COURSES 10

typedef struct {
    char id[20];
    char name[100];
    Course courses[MAX_COURSES];
    int courseCount;
} Student;

void initStudent(Student *student, const char *id, const char *name);
void addCourse(Student *student, const Course *course);
void displayStudent(const Student *student);

#endif
