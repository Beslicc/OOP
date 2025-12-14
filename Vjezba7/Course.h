#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

class Course {
private:
    std::string name;
    std::string code;
    int ects;
public:
    Course();
    Course(const std::string& name, const std::string& code, int ects);

    std::string getName() const;
    std::string getCode() const;
    int getEcts() const;

    friend std::ostream& operator<<(std::ostream& os, const Course& course);
    friend std::istream& operator>>(std::istream& is, Course& course);
};

#endif