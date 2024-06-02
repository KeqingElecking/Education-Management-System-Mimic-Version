#include "Student.hpp"
#include <iostream>

void Student::addCourse(const Course& course) {
    courses.push_back(course);
}

void Student::editCourse(const std::string& courseName, float midterm, float final) {
    for (auto& course : courses) {
        if (course.getName() == courseName) {
            course.setScores(midterm, final);
            return;
        }
    }
    std::cout << "Course not found.\n";
}

void Student::removeCourse(const std::string& courseName) {
    for (auto it = courses.begin(); it != courses.end(); ++it) {
        if (it->getName() == courseName) {
            courses.erase(it);
            return;
        }
    }
    std::cout << "Course not found.\n";
}

std::string Student::getId() const {
    return id;
}

std::string Student::getName() const {
    return name;
}

void Student::displayCourses() const {
    std::cout << "Courses for " << name << ":\n";
    if(courses.empty()) {
        std::cout << "\tN/A\n";
        return;
    }
    for (const auto& course : courses) {
        course.display();
    }
}