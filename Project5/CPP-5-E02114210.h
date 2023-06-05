#pragma once
#include<iostream>
#include<cstring>
using namespace std;
class Employee {
public:
	//�������Ĺ��캯��������Ϊname��salary�ĳ�ʼֵ�����У�salary������һ��Ĭ��ֵΪ10000
	Employee(string _name, float _salary = 10000) :name(_name), salary(_salary) {};
	//�������캯��
	Employee(Employee& emp) :name(emp.name), salary(emp.salary) {};
	//һ�����г�Ա����raiseSalary������Ϊְ����н���ú����Ĳ���Ϊ��н�ٷֱ�percent
	void raiseSalary(float percent);
	//��дһ�����г�Ա����show()�����Ա���������빤����Ϣ��
	void show();
	//���еķ��ʺ���:getSalary, getName��ע����Щ����Ӧ��дΪconst��Ա��������Щ����Ӧ����const ���á�
	float getSalary();
	const string& getName();
	void setSalary(float _salary);
	void setName(string _name);
private:
	string name;//Ա��������
	float salary;//Ա���Ĺ���
};

class Manager :public Employee {
public:
	//�������Ĺ��캯�������У�salary��bonus��Ӧ�Ĳ����ֱ���������Ĭ��ֵ��salary = 20000, bonus = 0.1��
	Manager(string _name, string _position, float _salary = 20000, float _bonus = 0.1) :Employee(_name, _salary), position(_position), bonus(_bonus) {};
	float getBonus();
	const string& getPosition();
	void raiseSalary(float percent);
	void show();//��������������ְλ�Լ�������Ϣ
private:
	string position;//�����ְλ
	float bonus;//�������
};
