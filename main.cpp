#include <iostream>
#include "lib/StudentManager.cpp"
#include "lib/Student.cpp"
#include "lib/Course.cpp"

void displayMenu() {
    std::cout << "1. Display all students\n";
    std::cout << "2. Add a student\n";
    std::cout << "3. Add a course and scores for a student\n";
    std::cout << "4. Edit a student's course scores\n";
    std::cout << "5. Remove a student\n";
    std::cout << "6. Export data to file\n";
    std::cout << "0. Exit\n";
}

int main() {
    StudentManager manager;
    int choice;
    std::string studentId, studentName, courseName;
    float midterm, final;
    
    std::string filename, format;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                system("cls");
                manager.displayAllStudents();
                system("pause");
                break;
            case 2: {
                system("cls");
                std::cout << "Enter student ID: ";
                std::cin >> studentId;
                std::cout << "Enter student name: ";
                std::cin.ignore();
                std::getline(std::cin, studentName);
                manager.addStudent(Student(studentId, studentName));
                break;
            }
            case 3: {
                std::cout << "Enter student ID: ";
                std::cin >> studentId;
                Student* student = manager.findStudent(studentId);
                if (student) {
                    std::cout << "Enter course name: ";
                    std::cin.ignore();
                    std::getline(std::cin, courseName);
                    std::cout << "Enter midterm score: ";
                    std::cin >> midterm;
                    std::cout << "Enter final score: ";
                    std::cin >> final;
                    student->addCourse(Course(courseName, midterm, final));
                } else {
                    std::cout << "Student not found.\n";
                }
                break;
            }
            case 4: {
                std::cout << "Enter student ID: ";
                std::cin >> studentId;
                Student* student = manager.findStudent(studentId);
                if (student) {
                    std::cout << "Enter course name: ";
                    std::cin.ignore();
                    std::getline(std::cin, courseName);
                    std::cout << "Enter new midterm score: ";
                    std::cin >> midterm;
                    std::cout << "Enter new final score: ";
                    std::cin >> final;
                    student->editCourse(courseName, midterm, final);
                } else {
                    std::cout << "Student not found.\n";
                }
                break;
            }
            case 5: {
                std::cout << "Enter student ID to remove: ";
                std::cin >> studentId;
                manager.removeStudent(studentId);
                break;
            }
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}