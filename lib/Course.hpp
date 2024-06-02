#pragma once

#include <string>

class Course {
private:
        std::string name;
        float midtermScore;
        float finalScore;

    public:
        Course(std::string name, float midterm, float final) : name(name), midtermScore(midterm), finalScore(final) {}

        std::string getName() const;
        float getMidtermScore() const;
        float getFinalScore() const;

        void setScores(float midterm, float final);
        void display() const;
};