#include "Course.hpp"
#include <iostream>

Course::Course(std::string name, float midterm, float final)
    : name(name), midtermScore(midterm), finalScore(final) {
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
    float average = (midtermScore*0.4 + finalScore*0.6);
    if (average >= 9.5) {
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
    } else if(average < 4.0 || midtermScore < 3 || finalScore < 3) {
        GPA = 0.0;
        grade = 'F';
    }

}

/**
 * @brief Display course's score.
 * @return void
 */
void Course::display() const {
    std::cout <<"\t\t"<< name << " - Midterm: " << midtermScore << ", Final: " << finalScore
                << ", GPA: " << GPA << ", Grade: " << grade << std::endl;
}

float Course::getMidtermScore() const {
    return midtermScore;
}
float Course::getFinalScore() const {
    return finalScore;
}

float Course::getGPA() const {
    return GPA;
}

std::string Course::getGrade() const {
    return grade;
}