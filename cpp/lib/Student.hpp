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
    void editCourse(const std::string& courseName, float midterm, float final);
    void removeCourse(const std::string& courseName);
    void displayCourses() const;
};