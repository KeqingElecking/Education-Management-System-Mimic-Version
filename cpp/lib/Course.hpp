#pragma once

#include <string>

class Course {
    private:
        std::string name;
        float midtermScore;
        float finalScore;
        float GPA;
        float coeff_midterm;
        std::string grade;

    public:
        Course(std::string name, float midterm, float final, float coeff);

        std::string getName() const;
        float getMidtermScore() const;
        float getFinalScore() const;
        float getCoeff() const;
        float getGPA() const;
        std::string getGrade() const;
        void setScores(float midterm, float final);
        void display() const;
        void calculateGPAAndGrade();
};