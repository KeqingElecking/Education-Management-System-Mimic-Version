#include "Course.hpp"
#include <iostream>
#include <iomanip>

Course::Course(std::string name, float midterm, float final, float coeff)
    : name(name), midtermScore(midterm), finalScore(final), coeff_midterm(coeff) {
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
    std::cout << std::left << std::setw(20) << name << std::setw(20) << midtermScore << std::setw(20) << finalScore << std::setw(20)
                << GPA << std::setw(20) << grade << std::endl;
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
std::string Course::getGrade() const {
    return grade;
}