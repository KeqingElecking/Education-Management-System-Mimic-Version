/*Nhóm 13 - Hệ thống quản lý đào tạo Hust - Phân hệ nhập điểm cho sinh viên
Sinh viên:
    1. Đặng Nhật Minh - 20224444
    2. Đỗ Đặng Hoàng Linh - 20224410
    3. Phạm Việt Tùng - 20224415
    4. Trần Nhật Quang - 20224456
*/
#include <iostream>
#include "../lib/StudentManager.cpp"
#include "../lib/Student.cpp"
#include "../lib/Course.cpp"

int main() {
    StudentManager manager; // Create a Student Manager object.
    
    int choice;
    std::string studentId, studentName, courseName; // Declare variables to store user input.
    
    float midterm, final, coeff_midterm;
    int credits;

    std::string filename, format;
    // Import data from file (only CSV format is supported for now)
    manager.importData("../data/danhsach1.csv");

    do {
        manager.displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                system("cls");
                manager.sort_by_CPA();
                manager.displayAllStudents();
                system("pause");
                system("cls");
                break;
            case 2: {
                system("cls");
                std::cout << "Enter student ID (ex: 20220001): ";
                do
                {
                    std::cin >> studentId;
                    while (stoi(studentId) < 20170000 || stoi(studentId) > 20239999){
                        std::cout << "studentId out of a range [20170000; 20239999]\nEnter student ID (ex: 20220001): ";
                        std::cin >> studentId;
                    }
                    if (manager.findStudent(studentId)) std::cout << "Student already added. Try again!\nEnter student ID (ex: 20220001): ";
                } while (manager.findStudent(studentId));
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
                std::cout << "Enter student ID: ";
                std::cin >> studentId;
                Student* student = manager.findStudent(studentId);
                if (student) {
                    std::cout << "Enter course name (ex: KTLT): ";
                    std::cin.ignore();
                    std::getline(std::cin, courseName);
                    if(student->findCourse(courseName) != -1){
                        std::cout << "Course already added. Try again!\n";
                        break;
                    }
                    std::cout << "Enter credits: ";
                    do{
                        std::cin >> credits;
                        if (credits <= 0) std::cout << "No such course with zero or negative credits\nRe-enter credits: ";
                    }
                    while (credits <= 0);
                    std::cout << "Enter midterm coefficient (ex: 0.5): ";
                    do{
                        std::cin >> coeff_midterm;
                        if (coeff_midterm <= 0 || coeff_midterm >= 1) std::cout << "Coefficient out of range (0, 1)\nRe-enter midterm coefficient [0.1 - 0.9] (ex: 0.4)";
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
                    student->addCourse(Course(courseName, midterm, final, coeff_midterm, credits));
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
                        std::cout << "Enter student ID: ";
                        std::cin >> studentId;
                        Student* student = manager.findStudent(studentId);
                        if (student) {
                            if(student->getCourses().empty()){
                                std::cout << "No course found.\n";
                                break;
                            }
                            std::cout << "Enter course name: ";
                            std::cin.ignore();
                            std::getline(std::cin, courseName);
                            if(student->findCourse(courseName) == -1){
                                std::cout << "Course not found.\n";
                                break;
                            }
                            else{
                                std::cout << "Enter new midterm score: ";
                                std::cin >> midterm;
                                std::cout << "Enter new final score: ";
                                std::cin >> final;
                                student->editCourse(courseName, midterm, final);
                                std::cout<<"\tCourse edited!\n";
                            }
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
                manager.sort_by_CPA();
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