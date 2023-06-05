#include"CPP-6-E02114210.h"

const string& Person::getName() {
	return name;
}
const string& Student::getSubject() {
	return subject;
}
const int Student::getGrade() {
	return grade;
}

void Student::enrollCourse(string course) {
	courses.push_back(course);
}

//输出学生的姓名、年级、专业、以及所选课程
const void Student::show() {
	cout << "Name:" << getName() << ",Subject:" << subject << ",Grade:" << grade << endl << "Courses:" << endl;
	for (int i = 0; i < courses.size(); i++) {
		cout << courses[i] << endl;
	}
}

const string& Professor::getDepartment() {
	return department;
}
const float& Professor::getSalary() {
	return salary;
}

void Professor::teachCourse(string course) {
	courses.push_back(course);
}

//输出教授的姓名、院系、工资、以及所教课程
const void Professor::show() {
	cout << "Prof." << getName() << ",Department:" << department << ",Salary:" << salary << endl << "Courses:" << endl;
	for (int i = 0; i < courses.size(); i++) {
		cout << courses[i] << endl;
	}
}

int main() {
	cout << "E02114210 江茜妮" << endl;
	vector<Person*> persons;
	persons.push_back( new Student("Bill Gates", "Computer Science", 2));
	persons.push_back( new Student("Rose", "Math", 2));
	persons.push_back( new Professor("Tayor", "Physics", 20000));
	persons.push_back( new Professor("Chenning Yang", "Physics", 24200));
	for (int i = 0; i < 4; i++) {
		cout << "=============================================" << endl;
		if (dynamic_cast<Student*>(persons[i]) != NULL) {
			Student* s = dynamic_cast<Student*>(persons[i]);
			if (s->getName() == "Bill Gates") {
				s->enrollCourse("Compiler");
				s->enrollCourse("Operating System");
			}
			else if (s->getName() == "Rose") {
				s->enrollCourse("Real Analysis");
				s->enrollCourse("Algebra");
			}
		}
		if (dynamic_cast<Professor*>(persons[i]) != NULL) {
			Professor* p = dynamic_cast<Professor*>(persons[i]);
			if (p->getName() == "Tayor") {
				p->teachCourse("Quantumn Physics");
			}
			else if (p->getName() == "Chenning Yang") {
				p->teachCourse("Particle Physics");
			}
		}
		persons[i]->show();
	}

	return 0;
}