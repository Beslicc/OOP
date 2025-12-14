#include <iostream>
#include <vector>
#include "Student.h"
#include "Course.h"
#include "UniversityConstants.h"
#include "StudentOffice.h"

void test1() {
    std::cout << "=== Test 1: Basic Student class ===\n";
    std::vector<Student> students;

    Student s1(1, "Ana Anic", "Informatika", 1);
    Student s2(2, "Ivo Ivic", "Matematika", 2);

    students.push_back(s1);
    students.push_back(s2);

    for (const auto& s : students) {
        std::cout << s << "\n";
    }
}

void test2() {
    std::cout << "\n=== Test 2: Static member ===\n";
    std::cout << "Total students: " << Student::get_total_students() << "\n";
}

void test3() {
    std::cout << "\n=== Test 3: UniversityConstants ===\n";
    UniversityConstants::print_university_rules();
}

void test4() {
    std::cout << "\n=== Test 4: Course class ===\n";
    Course c1("Programiranje", "INF101", 5);
    Course c2("Baze podataka", "INF102", 6);

    std::cout << c1 << "\n";
    std::cout << c2 << "\n";
}

void test5() {
    std::cout << "\n=== Test 5: Rule of Five and enrollment ===\n";
    Student s(3, "Marko Maric", "Informatika", 1);

    Course c1("Programiranje", "INF101", 5);
    Course c2("Baze podataka", "INF102", 6);

    s.enrollCourse(c1);
    s.enrollCourse(c2);

    std::cout << s << "\n";

    s.completeCourse("INF101");
    std::cout << "After completing INF101:\n" << s << "\n";
}

void test6() {
    std::cout << "\n=== Test 6: Operators ===\n";
    Student s(4, "Jana Janic", "Informatika", 1);
    Course c("Web programiranje", "INF103", 5);

    s += c;
    std::cout << s << "\n";

    s.completeCourse("INF103");
    ++s;
    std::cout << "After completing and ++:\n" << s << "\n";
}

void test7() {
    std::cout << "\n=== Test 7: StudentOffice ===\n";
    StudentOffice office;

    Student* s1 = new Student(5, "Petar Peric", "Informatika", 1);
    Student* s2 = new Student(6, "Maja Majic", "Matematika", 2);

    office.addStudent(s1);
    office.addStudent(s2);

    Course c("Algoritmi", "INF104", 5);
    office.enroll_student(s1, c);
    office.process_exam_results(s1, "INF104");

    office.moveStudent(s1, "Softversko inženjerstvo");

    office.update_student_years();

    office.printAllStudents();

    delete s1;
    delete s2;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    return 0;
}