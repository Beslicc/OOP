#ifndef STUDENTOFFICE_H
#define STUDENTOFFICE_H

#include "Student.h"
#include <vector>

class StudentOffice {
private:
    std::vector<Student*> students;
public:
    void addStudent(Student* student);
    void moveStudent(Student* student, const std::string& newProgram);
    bool enroll_student(Student* student, const Course& course);
    void process_exam_results(Student* student, const std::string& courseCode);
    void update_student_years();
    void printAllStudents() const;
};

#endif