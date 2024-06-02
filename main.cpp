/*Nhóm 13 - Hệ thống quản lý đào tạo Hust - Phân hệ nhập điểm cho sinh viên
Sinh viên:
    1. Đặng Nhật Minh - 20224444
    2. Đỗ Đặng Hoàng Linh - 2022
    3. Phạm Việt Tùng - 2022
    4. Trần Nhật Quang - 2022
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
                system("cls");
                break;
            case 2: {
                system("cls");
                std::cout << "Enter student ID: ";
                std::cin >> studentId;
                std::cout << "Enter student name: ";
                std::cin.ignore();
                std::getline(std::cin, studentName);
                manager.addStudent(Student(studentId, studentName));
                std::cout << "\tStudent added!\n";
                break;
            }
            case 3: {
                system("cls");
                manager.displayAllStudents();
                std::cout << "--------------------------------\n";
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
                    std::cout<<"\tCourse added!\n";
                } else {
                    std::cout << "Student not found.\n";
                }
                break;
            }
            case 4: {
                system("cls");
                manager.displayAllStudents();
                std::cout << "--------------------------------\n";
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
                    std::cout<<"\tCourse edited!\n";
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