#include "Student.hpp"
#include <iostream>
#include <iomanip>

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
 * @brief Find course in student.
 * @param courseName
 * @return int
 */
int Student::findCourse(const std::string& courseName) const {
    for (size_t i = 0; i < courses.size(); ++i) {
        if (courses[i].getName() == courseName) {
            return i;
        }
    }
    return -1;
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
    if(courses.empty()) {
        std::cout << "N/A\n";
        return;
    }
    for (const auto& course : courses) {
        course.display();
        if(&course != &courses.back()) {
            std::cout << std::setw(30) << ' ';
        }
    }
    std::cout << std::setw(100) << ' ' << "Total CPA: " 
              << std::fixed << std::setprecision(2) << totalCPA() 
              << std::endl;
}
float Student::totalCPA() const {
    float S = 0;
    int total_credits = 0;
    std::vector<Course>::const_iterator p;
    for (p = courses.begin(); p < courses.end(); p++) {
        S += p->getGPA() * p->getcredits();
        total_credits += p->getcredits();
    }
    return (total_credits > 0) ? (S / total_credits) : 0.0f;
}
bool Student::operator<(const Student& student_2) const {
    if (totalCPA() < student_2.totalCPA()) return true;
    return false;
}