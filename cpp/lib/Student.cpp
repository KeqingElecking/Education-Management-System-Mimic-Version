#include "Student.hpp"
#include <iostream>

std::string Student::getId() const {
    return id;
}
std::string Student::getName() const {
    return name;
}
std::vector<Course> Student::getCourses() const {
    return courses;
}
std::string Student::setName(const std::string& name) {
    this->name = name;
    return this->name;
}
std::string Student::setId(const std::string& id) {
    this->id = id;
    return this->id;
}

/**
 * @brief Add course to student.
 * @param course
 * @return void
 */
void Student::addCourse(const Course& course) {
    courses.push_back(course);
}

/**
 * @brief Edit course of student.
 * @param courseName
 * @param midterm
 * @param final
 * @return void
 */
void Student::editCourse(const std::string& courseName, float midterm, float final) {
    for (auto& course : courses) {
        if (course.getName() == courseName) {
            course.setScores(midterm, final);
            return;
        }
    }
    std::cout << "Course not found.\n";
}

/**
 * @brief Remove course from student.
 * @param courseName
 * @return void
 */
void Student::removeCourse(const std::string& courseName) {
    for (auto it = courses.begin(); it != courses.end(); ++it) {
        if (it->getName() == courseName) {
            courses.erase(it);
            return;
        }
    }
    std::cout << "Course not found.\n";
}

/**
 * @brief Display all courses of that student.
 * @return void
 */
void Student::displayCourses() const {
    std::cout << "\tCourses for " << name << ":\n";
    if(courses.empty()) {
        std::cout << "\tN/A\n";
        return;
    }
    for (const auto& course : courses) {
        course.display();
    }
}