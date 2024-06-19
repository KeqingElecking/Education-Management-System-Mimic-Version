#pragma once

#include "Student.hpp"
#include "Course.hpp"
#include <vector>

class StudentManager {
private:
    std::vector<Student> students;
public:
    bool isEmpty() const;
    void addStudent(const Student& student);
    void removeStudent(const std::string& studentId);
    Student* findStudent(const std::string& studentId);
    void displayMenu() const;
    void displayAllStudents() const;
    void importData(const std::string& filename);
    void exportData(const std::string& filename, const std::string& format) const;
    void sort_by_CPA();
};