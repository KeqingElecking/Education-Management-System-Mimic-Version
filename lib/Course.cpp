#include "Course.hpp"
#include <iostream>

std::string Course::getName() const {
    return name;
}

void Course::setScores(float midterm, float final) {
    midtermScore = midterm;
    finalScore = final;
}

void Course::display() const {
    std::cout << "Course: " << name << ", Midterm: " << midtermScore << ", Final: " << finalScore << std::endl;
}