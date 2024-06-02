//Simplified version of the C++ code

#include "lib/student.c"
#include "lib/course.c"
#include <stdio.h>

int main() {
    Student student;
    Course course;

    initStudent(&student, "20220001", "Elon Musk");
    initCourse(&course, "MI3310", 7.5, 8.25);
    addCourse(&student, &course);

    displayStudent(&student);

    return 0;
}
