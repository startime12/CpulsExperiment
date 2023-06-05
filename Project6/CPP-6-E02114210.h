#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Person {//学校的人员
public:
	Person(string _name) :name(_name) {};
	Person(const Person &p) :name(p.name) {};
	const string& getName();
	virtual const void show() = 0;
private:
	string name;// 表示姓名
};
class Student :public Person{//学生
public:
	Student(string _name, string _subject, int _grade) :Person(_name), subject(_subject), grade(_grade) {};
	Student(const Student& s) :Person(s),subject(s.subject), grade(s.grade), courses(s.courses) {};
	const string& getSubject();
	const int getGrade();
	void enrollCourse(string course);
	virtual const void show();
private:
	string subject;// 表示专业名称; 
	int grade;// 表示年级
	vector<string> courses;// 表示该学生所选的课程列表。
};
class Professor :public Person {//教授
public:
	Professor(string _name, string _department, float _salary) :Person(_name), department(_department), salary(_salary) {};
	Professor(const Professor& p) :Person(p), department(p.department), salary(p.salary) {};
	const string& getDepartment();
	const float& getSalary();
	void teachCourse(string course); 
	virtual const void show();
private:
	string department;// 表示教授所在院系名称
	float salary; //表示工资
	vector<string> courses;// 表示该教授所教课程列表
};