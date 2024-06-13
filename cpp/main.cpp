/*Nhóm 13 - Hệ thống quản lý đào tạo Hust - Phân hệ nhập điểm cho sinh viên
Sinh viên:
    1. Đặng Nhật Minh - 20224444
    2. Đỗ Đặng Hoàng Linh - 20224410
    3. Phạm Việt Tùng - 20224415
    4. Trần Nhật Quang - 20224456
*/
#include <iostream>
#include "lib/StudentManager.cpp"
#include "lib/Student.cpp"
#include "lib/Course.cpp"

/** @brief Display the main menu for user input.
 *  @return void*/
void displayMenu() {
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

int main() {
    StudentManager manager;
    int choice;
    std::string studentId, studentName, courseName;
    float midterm, final, coeff_midterm;
    
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
                system("cls");
                break;
            case 2: {
                system("cls");
                std::cout << "Enter student ID (ex: 20220001): ";
                std::cin >> studentId;
                std::cout << "Enter student name (ex: Elon Musk): ";
                std::cin.ignore();
                std::getline(std::cin, studentName);
                manager.addStudent(Student(studentId, studentName));
                std::cout << "\tStudent added!\n";
                break;
            }
            case 3: {
                system("cls");
                manager.displayAllStudents();
                if(manager.isEmpty()) break;
                std::cout << "--------------------------------\n";
                std::cout << "Enter student ID: ";
                std::cin >> studentId;
                Student* student = manager.findStudent(studentId);
                if (student) {
                    std::cout << "Enter course name (ex: KTLT): ";
                    std::cin.ignore();
                    std::getline(std::cin, courseName);
                    std::cout << "Enter midterm coefficient (ex: 0.5)";
                    do{
                        std::cin >> coeff_midterm;
                        if (coeff_midterm < 0 || coeff_midterm > 1) std::cout << "Coefficient out of range [0, 1]\nRe-enter midterm coefficient (ex: 0.5)";
                    }
                    while (coeff_midterm < 0 || coeff_midterm > 1);
                    std::cout << "Enter midterm score (ex: 9.5): ";
                    do{
                        std::cin >> midterm;
                        if (midterm < 0 || midterm > 10) std::cout << "Score out of range [0, 10]\nRe-enter midterm score (ex: 9.5): ";
                    }
                    while (midterm < 0 || midterm > 10);
                    std::cout << "Enter final score (ex: 9.5): ";
                    do{
                        std::cin >> final;
                        if (final < 0 || final > 10) std::cout << "Score out of range [0, 10]\nRe-enter final score (ex: 9.5): ";
                    }
                    while (final < 0 || final > 10);
                    student->addCourse(Course(courseName, midterm, final, coeff_midterm));
                    std::cout<<"\tCourse added!\n";
                } else {
                    std::cout << "Student not found.\n";
                }
                break;
            }
            case 4: {
                system("cls");
                if(manager.isEmpty()){
                    std::cout << "No student found.\n";
                    break;
                }
                std::cout << "What do you want to edit?\n";
                std::cout << "1. Edit student's information\n";
                std::cout << "2. Edit student's course scores\n";
                std::cout << "Enter your choice: ";
                int editChoice;
                std::cin >> editChoice;
                switch (editChoice) {
                    case 1: { 
                        manager.displayAllStudents();
                        if(manager.isEmpty()) break;
                        std::cout << "--------------------------------\n";
                        std::cout << "Enter student ID: ";
                        std::cin >> studentId;
                        Student* student = manager.findStudent(studentId);
                        if (student) {
                            std::cout << "Enter new student id: ";
                            std::cin >> studentId;
                            student->setId(studentId);
                            std::cout << "Enter new student name: ";
                            std::cin.ignore();
                            std::getline(std::cin, studentName);
                            student->setName(studentName);
                            std::cout<<"\tStudent edited!\n";
                        } else {
                            std::cout << "Student not found.\n";
                        }
                        break;
                    }
                    case 2: {
                        manager.displayAllStudents();
                        if(manager.isEmpty()) break;
                        std::cout << "--------------------------------\n";
                        std::cout << "Enter student ID: ";
                        std::cin >> studentId;
                        Student* student = manager.findStudent(studentId);
                        if (student) {
                            student->displayCourses();
                        } else {
                            std::cout << "Student not found.\n";
                        }
                        break;
                    }
                    default:
                        std::cout << "Invalid choice. Please try again.\n";
                }
                break;
            }
            case 5: {
                std::cout << "Enter student ID to remove: ";
                std::cin >> studentId;
                manager.removeStudent(studentId);
                break;
            }
            case 6:{
                std::cout << "Enter filename (including extension): ";
                std::cin >> filename;
                std::cout << "Enter format (txt or csv): ";
                std::cin >> format;
                manager.exportData(filename, format);
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