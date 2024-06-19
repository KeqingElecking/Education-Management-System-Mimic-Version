//Simplified version of the C++ code

#include "src/student.c"
#include "src/course.c"
#include <stdio.h>

int main() {
    Student student;
    Course course;

    initStudent(&student, "20220001", "Elon Musk");
    initCourse(&course, "MI3310", 7.5, 8.25, 0.3);
    addCourse(&student, &course);

    displayStudent(&student);

    return 0;
}
