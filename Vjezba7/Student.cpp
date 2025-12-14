#include "Student.h"
#include <algorithm>
#include <iostream>

int Student::total_students = 0;

Student::Student()
    : id(0), name(""), study_program(""), year(1),
    enrolled_courses(nullptr), enrolled_count(0),
    completed_courses(nullptr), completed_count(0) {
    total_students++;
}

Student::Student(int id, const std::string& name, const std::string& study_program, int year)
    : id(id), name(name), study_program(study_program), year(year),
    enrolled_courses(nullptr), enrolled_count(0),
    completed_courses(nullptr), completed_count(0) {
    total_students++;
}

Student::Student(const Student& other)
    : id(other.id), name(other.name), study_program(other.study_program), year(other.year),
    enrolled_count(other.enrolled_count), completed_count(other.completed_count) {

    enrolled_courses = new Course[enrolled_count];
    for (size_t i = 0; i < enrolled_count; i++) {
        enrolled_courses[i] = other.enrolled_courses[i];
    }

    completed_courses = new Course[completed_count];
    for (size_t i = 0; i < completed_count; i++) {
        completed_courses[i] = other.completed_courses[i];
    }

    total_students++;
}

Student::Student(Student&& other) noexcept
    : id(other.id), name(std::move(other.name)), study_program(std::move(other.study_program)),
    year(other.year), enrolled_courses(other.enrolled_courses), enrolled_count(other.enrolled_count),
    completed_courses(other.completed_courses), completed_count(other.completed_count) {

    other.enrolled_courses = nullptr;
    other.enrolled_count = 0;
    other.completed_courses = nullptr;
    other.completed_count = 0;

    total_students++;
}

Student& Student::operator=(const Student& other) {
    if (this == &other) return *this;

    delete[] enrolled_courses;
    delete[] completed_courses;

    id = other.id;
    name = other.name;
    study_program = other.study_program;
    year = other.year;
    enrolled_count = other.enrolled_count;
    completed_count = other.completed_count;

    enrolled_courses = new Course[enrolled_count];
    for (size_t i = 0; i < enrolled_count; i++) {
        enrolled_courses[i] = other.enrolled_courses[i];
    }

    completed_courses = new Course[completed_count];
    for (size_t i = 0; i < completed_count; i++) {
        completed_courses[i] = other.completed_courses[i];
    }

    return *this;
}

Student& Student::operator=(Student&& other) noexcept {
    if (this == &other) return *this;

    delete[] enrolled_courses;
    delete[] completed_courses;

    id = other.id;
    name = std::move(other.name);
    study_program = std::move(other.study_program);
    year = other.year;
    enrolled_courses = other.enrolled_courses;
    enrolled_count = other.enrolled_count;
    completed_courses = other.completed_courses;
    completed_count = other.completed_count;

    other.enrolled_courses = nullptr;
    other.enrolled_count = 0;
    other.completed_courses = nullptr;
    other.completed_count = 0;

    return *this;
}

Student::~Student() {
    delete[] enrolled_courses;
    delete[] completed_courses;
    total_students--;
}

int Student::getId() const { return id; }
std::string Student::getName() const { return name; }
std::string Student::getStudyProgram() const { return study_program; }
int Student::getYear() const { return year; }

int Student::getTotalEctsEnrolled() const {
    int total = 0;
    for (size_t i = 0; i < enrolled_count; i++) {
        total += enrolled_courses[i].getEcts();
    }
    return total;
}

int Student::getTotalEctsCompleted() const {
    int total = 0;
    for (size_t i = 0; i < completed_count; i++) {
        total += completed_courses[i].getEcts();
    }
    return total;
}

void Student::setStudyProgram(const std::string& program) {
    study_program = program;
}

void Student::resizeEnrolled() {
    Course* newArr = new Course[enrolled_count + 1];
    for (size_t i = 0; i < enrolled_count; i++) {
        newArr[i] = enrolled_courses[i];
    }
    delete[] enrolled_courses;
    enrolled_courses = newArr;
}

void Student::resizeCompleted() {
    Course* newArr = new Course[completed_count + 1];
    for (size_t i = 0; i < completed_count; i++) {
        newArr[i] = completed_courses[i];
    }
    delete[] completed_courses;
    completed_courses = newArr;
}

bool Student::enrollCourse(const Course& course) {
    if (getTotalEctsEnrolled() + course.getEcts() > UniversityConstants::MAX_ETCS_PER_YEAR) {
        return false;
    }
    resizeEnrolled();
    enrolled_courses[enrolled_count] = course;
    enrolled_count++;
    return true;
}

bool Student::completeCourse(const std::string& courseCode) {
    for (size_t i = 0; i < enrolled_count; i++) {
        if (enrolled_courses[i].getCode() == courseCode) {
            resizeCompleted();
            completed_courses[completed_count] = enrolled_courses[i];
            completed_count++;

            // remove from enrolled
            for (size_t j = i; j < enrolled_count - 1; j++) {
                enrolled_courses[j] = enrolled_courses[j + 1];
            }
            enrolled_count--;
            return true;
        }
    }
    return false;
}

Student& Student::operator+=(const Course& course) {
    enrollCourse(course);
    return *this;
}

Student& Student::operator++() {
    if (getTotalEctsCompleted() >= UniversityConstants::REQUIRED_ECTS_PER_YEAR) {
        year++;
    }
    return *this;
}

Student Student::operator++(int) {
    Student temp = *this;
    ++(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "Student ID: " << student.id << "\n";
    os << "Name: " << student.name << "\n";
    os << "Study Program: " << student.study_program << "\n";
    os << "Year: " << student.year << "\n";
    os << "Enrolled courses (" << student.enrolled_count << "):\n";
    for (size_t i = 0; i < student.enrolled_count; i++) {
        os << "  " << student.enrolled_courses[i] << "\n";
    }
    os << "Completed courses (" << student.completed_count << "):\n";
    for (size_t i = 0; i < student.completed_count; i++) {
        os << "  " << student.completed_courses[i] << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Student& student) {
    std::cout << "Enter student ID: ";
    is >> student.id;
    is.ignore();
    std::cout << "Enter student name: ";
    std::getline(is, student.name);
    std::cout << "Enter study program: ";
    std::getline(is, student.study_program);
    std::cout << "Enter year: ";
    is >> student.year;
    is.ignore();
    return is;
}

int Student::get_total_students() {
    return total_students;
}