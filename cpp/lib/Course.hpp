#pragma once

#include <string>

class Course {
    private:
        std::string name;
        float midtermScore;
        float finalScore;
        float GPA;
        float coeff_midterm;
        int credits;
        std::string grade;

    public:
        Course(std::string name, float midterm, float final, float coeff, int credits);
        std::string getName() const;
        float getMidtermScore() const;
        float getFinalScore() const;
        float getCoeff() const;
        float getGPA() const;
        int getcredits() const;
        std::string getGrade() const;
        void setScores(float midterm, float final);
        void display() const;
        void calculateGPAAndGrade();
};