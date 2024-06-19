#include "Course.hpp"
#include <iostream>
#include <iomanip>

Course::Course(std::string name, float midterm, float final, float coeff, int credits)
    : name(name), midtermScore(midterm), finalScore(final), coeff_midterm(coeff), credits(credits) {
    calculateGPAAndGrade();
}

std::string Course::getName() const {
    return name;
}

void Course::setScores(float midterm, float final) {
    midtermScore = midterm;
    finalScore = final;
    calculateGPAAndGrade();
}
/**
 * @brief Calculate GPA and grade based on midterm and final score.
 * @return void
 */

void Course::calculateGPAAndGrade() {
    float average = (midtermScore * coeff_midterm + finalScore*(1 - coeff_midterm));
    if (midtermScore < 3 || finalScore < 3){
        GPA = 0.0;
        grade = "F";
    }
    else if (average >= 9.5) {
        GPA = 4.0;
        grade = "A+";
    } else if (average >= 8.5) {
        GPA = 4.0;
        grade = 'A';
    } else if (average >= 8.0) {
        GPA = 3.5;
        grade = "B+";
    } else if (average >= 7.0) {
        GPA = 3.0;
        grade = 'B';
    } else if (average >= 6.5) {
        GPA = 2.5;
        grade = "C+";
    } else if (average >= 5.5) {
        GPA = 2.0;
        grade = 'C';
    } else if (average >= 5.0) {
        GPA = 1.5;
        grade = "D+";
    } else if (average >= 4.0) {
        GPA = 1.0;
        grade = 'D';
    } else if(average < 4.0) {
        GPA = 0.0;
        grade = 'F';
    }

}

/**
 * @brief Display course's score.
 * @return void
 */
void Course::display() const {
    std::cout << std::left << std::setw(20) << name << std::setw(10) << midtermScore << std::setw(10) << finalScore << std::setw(10)
                << GPA << std::setw(10) << grade << std::setw(10) << credits << std::endl;
}

float Course::getMidtermScore() const {
    return midtermScore;
}
float Course::getFinalScore() const {
    return finalScore;
}
float Course::getCoeff() const {
    return coeff_midterm;
}
float Course::getGPA() const {
    return GPA;
}
int Course::getcredits() const {
    return credits;
}
std::string Course::getGrade() const {
    return grade;
}