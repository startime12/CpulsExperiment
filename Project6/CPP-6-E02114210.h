#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Person {//ѧУ����Ա
public:
	Person(string _name) :name(_name) {};
	Person(const Person &p) :name(p.name) {};
	const string& getName();
	virtual const void show() = 0;
private:
	string name;// ��ʾ����
};
class Student :public Person{//ѧ��
public:
	Student(string _name, string _subject, int _grade) :Person(_name), subject(_subject), grade(_grade) {};
	Student(const Student& s) :Person(s),subject(s.subject), grade(s.grade), courses(s.courses) {};
	const string& getSubject();
	const int getGrade();
	void enrollCourse(string course);
	virtual const void show();
private:
	string subject;// ��ʾרҵ����; 
	int grade;// ��ʾ�꼶
	vector<string> courses;// ��ʾ��ѧ����ѡ�Ŀγ��б�
};
class Professor :public Person {//����
public:
	Professor(string _name, string _department, float _salary) :Person(_name), department(_department), salary(_salary) {};
	Professor(const Professor& p) :Person(p), department(p.department), salary(p.salary) {};
	const string& getDepartment();
	const float& getSalary();
	void teachCourse(string course); 
	virtual const void show();
private:
	string department;// ��ʾ��������Ժϵ����
	float salary; //��ʾ����
	vector<string> courses;// ��ʾ�ý������̿γ��б�
};