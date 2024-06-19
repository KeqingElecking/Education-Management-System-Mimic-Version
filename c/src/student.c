#include "../lib/student.h"
#include <stdio.h>
#include <string.h>

void initStudent(Student *student, const char *id, const char *name) {
    strcpy(student->id, id);
    strcpy(student->name, name);
    student->courseCount = 0;
}

void addCourse(Student *student, const Course *course) {
    if (student->courseCount < MAX_COURSES) {
        student->courses[student->courseCount++] = *course;
    }
}

void displayStudent(const Student *student) {
    printf("Student ID: %s, Name: %s\n", student->id, student->name);
    for (int i = 0; i < student->courseCount; i++) {
        displayCourse(&student->courses[i]);
    }
}
