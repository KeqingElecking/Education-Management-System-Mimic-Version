#pragma once

#include "Student.hpp"
#include "Course.hpp"
#include <vector>

class StudentManager {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student& student);
    void removeStudent(const std::string& studentId);
    Student* findStudent(const std::string& studentId);
    void displayAllStudents() const;
    void exportData(const std::string& filename, const std::string& format) const;
};