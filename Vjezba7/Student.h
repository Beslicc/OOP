#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "Course.h"
#include "UniversityConstants.h"

class StudentOffice; // forward declaration

class Student {
private:
    int id;
    std::string name;
    std::string study_program;
    int year;

    Course* enrolled_courses;
    size_t enrolled_count;
    Course* completed_courses;
    size_t completed_count;

    static int total_students;

    void resizeEnrolled();
    void resizeCompleted();

public:
    Student();
    Student(int id, const std::string& name, const std::string& study_program, int year);
    Student(const Student& other);
    Student(Student&& other) noexcept;
    Student& operator=(const Student& other);
    Student& operator=(Student&& other) noexcept;
    ~Student();

    int getId() const;
    std::string getName() const;
    std::string getStudyProgram() const;
    int getYear() const;
    int getTotalEctsEnrolled() const;
    int getTotalEctsCompleted() const;

    void setStudyProgram(const std::string& program);

    bool enrollCourse(const Course& course);
    bool completeCourse(const std::string& courseCode);

    Student& operator+=(const Course& course);
    Student& operator++();       
    Student operator++(int);      

    friend std::ostream& operator<<(std::ostream& os, const Student& student);
    friend std::istream& operator>>(std::istream& is, Student& student);
    friend class StudentOffice;

    static int get_total_students();
};

#endif