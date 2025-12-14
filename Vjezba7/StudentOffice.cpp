#include "StudentOffice.h"
#include <iostream>

void StudentOffice::addStudent(Student* student) {
    students.push_back(student);
}

void StudentOffice::moveStudent(Student* student, const std::string& newProgram) {
    student->setStudyProgram(newProgram);
}

bool StudentOffice::enroll_student(Student* student, const Course& course) {
    return student->enrollCourse(course);
}

void StudentOffice::process_exam_results(Student* student, const std::string& courseCode) {
    student->completeCourse(courseCode);
}

void StudentOffice::update_student_years() {
    for (auto* student : students) {
        (*student)++;
    }
}

void StudentOffice::printAllStudents() const {
    for (const auto* student : students) {
        std::cout << *student << "\n";
    }
}