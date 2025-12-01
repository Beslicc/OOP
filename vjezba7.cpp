#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
	int id;
	string name;
	string study_program;
	int year;
public:
	Student(int id, string& name, string& study_program, int year) : id(id), name(name), study_program(study_program), year(year) {};
	void print()const {
		cout << id << " " << name << " " << study_program << " " << year << endl;
	}
};

int main() {
	vector<Student>students;
	students.push_back(Student(1, "Ana Anic", "Racunarstvo", 1));
	students.push_back(Student(2, "Marko Maric", "Matematika", 1));
	students.push_back(Student(3, "Iva Ivic", "Fizika", 1));
	cout << "Svi studenti: " << endl;
	for (const Student& s : students) {
		s.print();
	}
	return 0;
}