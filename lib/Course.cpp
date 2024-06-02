#include "Course.hpp"
#include <iostream>

/**
 * @brief Get name of course.
 * @return std::string
 */
std::string Course::getName() const {
    return name;
}

/**
 * @brief Set scores of course.
 * @param midterm
 * @param final
 * @return void
 */
void Course::setScores(float midterm, float final) {
    midtermScore = midterm;
    finalScore = final;
}

/**
 * @brief Display course.
 * @return void
 */
void Course::display() const {
    std::cout <<"\t\t"<< name << "- Midterm: " << midtermScore << ", Final: " << finalScore << std::endl;
}

float Course::getMidtermScore() const {
    return midtermScore;
}
float Course::getFinalScore() const {
    return finalScore;
}