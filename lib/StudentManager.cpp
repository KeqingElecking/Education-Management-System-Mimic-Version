#include "StudentManager.hpp"
#include <iostream>
#include <fstream>

/**
 * @brief Display all students.
 * @return void
 */
void StudentManager::displayAllStudents() const {
    if (students.empty()) {
        std::cout << "No students available.\n";
        return;
    }
    for (const auto& student : students) {
        std::cout << "Student ID: " << student.getId() << ", Name: " << student.getName() << std::endl;
        student.displayCourses();
    }
}

/**
 * @brief Add student to student manager.
 * @param student
 * @return void
 */
void StudentManager::addStudent(const Student& student) {
    students.push_back(student);
}

/**
 * @brief Remove student from student manager.
 * @param studentId
 * @return void
 */
void StudentManager::removeStudent(const std::string& studentId) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getId() == studentId) {
            students.erase(it);
            return;
        }
    }
    std::cout << "Student not found.\n";
}

/**
 * @brief Find student by student ID.
 * @param studentId
 * @return Student*
 */
Student* StudentManager::findStudent(const std::string& studentId) {
    for (auto& student : students) {
        if (student.getId() == studentId) {
            return &student;
        }
    }
    return nullptr;
}

/**
 * @brief Export data to file.
 * @param filename
 * @param format
 * @return void
 */
void StudentManager::exportData(const std::string& filename, const std::string& format) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file.\n";
        return;
    }

    if (format == "csv") {
        for (const auto& student : students) {
            file << student.getId() << "," << student.getName();
            for (const auto& course : student.getCourses()) {
                file << "," << course.getName() << "," << course.getMidtermScore() << "," << course.getFinalScore();
            }
            file << "\n";
        }
    } else if (format == "txt") {
        for (const auto& student : students) {
            file << "Student ID: " << student.getId() << ", Name: " << student.getName() << "\n";
            for (const auto& course : student.getCourses()) {
                file << "  Course: " << course.getName() << ", Midterm: " << course.getMidtermScore() << ", Final: " << course.getFinalScore() << "\n";
            }
            file << "\n";
        }
    }

    file.close();
    std::cout << "Data exported successfully to " << filename << std::endl;
}