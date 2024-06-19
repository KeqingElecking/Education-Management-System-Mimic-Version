#include "StudentManager.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

/**
 * @brief Check if student list is empty.
 * @return bool
 */
bool StudentManager::isEmpty() const {
    return students.empty();
}

/** @brief Display the main menu for user input.
 *  @return void*/
void StudentManager::displayMenu() const {
    std::cout   << "*************************\n"
                << "Student Management System\n"
                << "*************************\n"
                << "1. Display all students\n"
                << "2. Add a student\n"
                << "3. Add a course and scores for a student\n"
                << "4. Edit a student's course scores\n"
                << "5. Remove a student\n"
                << "6. Export data to file\n"
                << "0. Exit\n";
}

/**
 * @brief Display all students and their courses' details.
 * @return void
 */
void StudentManager::displayAllStudents() const {
    std::cout << std::string(115, '-') << std::endl;
    std::cout << std::string(50, ' ') << "Students List" << std::endl;
    std::cout << std::string(115, '-') << std::endl;
    std::cout << std::left << std::setw(10) << "ID" << std::setw(20) << "Name" << std::setw(20) << "Courses" << std::setw(10) << "Midterm" << std::setw(10) << "Final" << std::setw(10) << "GPA" << std::setw(10) << "Grade" << std::setw(10) << "Credits" << std::endl;
    std::cout << std::string(115, '-') << std::endl;
    if (students.empty()) {
        std::cout << "No students available.\n";
        return;
    }
    for (const auto& student : students) {
        std::cout << std::left << std::setw(10) << student.getId() << std::setw(20) << student.getName();
        student.displayCourses();
    }
    std::cout << std::string(115, '-') << std::endl;
}

/**
 * @brief Add a new student to list.
 * @param student
 * @return void
 */
void StudentManager::addStudent(const Student& student) {
    students.push_back(student);
}

/**
 * @brief Remove a student from list.
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
 * @brief Import data from file (.txt or .csv).
 * @param filename
 * @return void
 */
void StudentManager::importData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() >= 2) { 
            std::string studentId = tokens[0];
            std::string studentName = tokens[1];
            Student student(studentId, studentName);
            for (size_t i = 2; i < tokens.size(); i += 5) {
                Course course(tokens[i], std::stof(tokens[i + 1]), std::stof(tokens[i + 2]), std::stof(tokens[i + 3]), std::stof(tokens[i + 4]));
                student.addCourse(course);
            }
            
            
            students.push_back(student);
        }
    }

    file.close();
    std::cout << "Data imported successfully from " << filename << '!' << std::endl;
}

/**
 * @brief Export data to file (.txt or .csv).
 * @param filename
 * @param format
 * @return void
 */
void StudentManager::exportData(const std::string& filename, const std::string& format) const {
    std::ofstream file("../data/" + filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file.\n";
        return;
    }

    if (format == "csv") {
        for (const auto& student : students) {
            file << student.getId() << "," << student.getName();
            for (const auto& course : student.getCourses()) {
                file << "," << course.getName() << "," << course.getMidtermScore() << "," << course.getFinalScore() << "," << course.getCoeff() << "," << course.getcredits();
            }
            file << "\n";
        }
    } else if (format == "txt") {
        for (const auto& student : students) {
            file << "Student ID: " << student.getId() << ", Name: " << student.getName() << "\n";
            for (const auto& course : student.getCourses()) {
                file << "  Course: " << course.getName() << ", Midterm: " << course.getMidtermScore() << ", Final: " << course.getFinalScore() 
                                << ", GPA: " << course.getGPA() << ", Grade: " << course.getGrade() << ", Credits: " << course.getcredits() << "\n";
            }
            file << "  ------------------------------------------Total CPA: " << std::fixed << std::setprecision(2) << student.totalCPA() << "\n";
            file << "\n";
        }
    }

    file.close();
    std::cout << "Data exported successfully to " << filename << '!' << std::endl;
}
void StudentManager::sort_by_CPA() {
    std::vector<Student>::iterator p;
    for (p = std::next(students.begin()); p < students.end(); p++) {
        Student key = *p;
        std::vector<Student>::iterator j = p;
        while (j != students.begin() && (key < *(std::prev(j)))) {
            *j = *(std::prev(j));
            --j;
        }
        *j = key;
    }
}