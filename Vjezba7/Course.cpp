#include "Course.h"

Course::Course() : name(""), code(""), ects(0) {}

Course::Course(const std::string& name, const std::string& code, int ects)
    : name(name), code(code), ects(ects) {
}

std::string Course::getName() const { return name; }
std::string Course::getCode() const { return code; }
int Course::getEcts() const { return ects; }

std::ostream& operator<<(std::ostream& os, const Course& course) {
    os << "Course: " << course.name << " (" << course.code << ") - " << course.ects << " ECTS";
    return os;
}

std::istream& operator>>(std::istream& is, Course& course) {
    std::cout << "Enter course name: ";
    std::getline(is, course.name);
    std::cout << "Enter course code: ";
    std::getline(is, course.code);
    std::cout << "Enter ECTS: ";
    is >> course.ects;
    is.ignore();
    return is;
}