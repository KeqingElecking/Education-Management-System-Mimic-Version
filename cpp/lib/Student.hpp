#pragma once

#include <string>
#include <vector>
#include "Course.hpp"

class Student {
private:
    std::string id;
    std::string name;
    std::vector<Course> courses;

public:
    Student(std::string id, std::string name) : id(id), name(name) {}

    std::string getId() const;
    std::string getName() const;
    std::vector<Course> getCourses() const;
    std::string setName(const std::string& name);
    std::string setId(const std::string& id);
    

    void addCourse(const Course& course);
    int findCourse(const std::string& courseName) const;
    void editCourse(const std::string& courseName, float midterm, float final);
    void removeCourse(const std::string& courseName);
    float totalCPA() const;
    void displayCourses() const;
    bool operator<(const Student& student_2) const;
};