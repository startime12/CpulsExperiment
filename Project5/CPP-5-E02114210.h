#pragma once
#include<iostream>
#include<cstring>
using namespace std;
class Employee {
public:
	//带参数的构造函数，参数为name和salary的初始值。其中，salary参数有一个默认值为10000
	Employee(string _name, float _salary = 10000) :name(_name), salary(_salary) {};
	//拷贝构造函数
	Employee(Employee& emp) :name(emp.name), salary(emp.salary) {};
	//一个公有成员函数raiseSalary，用于为职工加薪，该函数的参数为加薪百分比percent
	void raiseSalary(float percent);
	//编写一个公有成员函数show()，输出员工的姓名与工资信息。
	void show();
	//公有的访问函数:getSalary, getName。注意哪些函数应该写为const成员函数，哪些参数应该用const 引用。
	float getSalary();
	const string& getName();
	void setSalary(float _salary);
	void setName(string _name);
private:
	string name;//员工的姓名
	float salary;//员工的工资
};

class Manager :public Employee {
public:
	//带参数的构造函数，其中，salary和bonus对应的参数分别设置以下默认值：salary = 20000, bonus = 0.1。
	Manager(string _name, string _position, float _salary = 20000, float _bonus = 0.1) :Employee(_name, _salary), position(_position), bonus(_bonus) {};
	float getBonus();
	const string& getPosition();
	void raiseSalary(float percent);
	void show();//输出经理的姓名、职位以及工资信息
private:
	string position;//经理的职位
	float bonus;//奖金比例
};
