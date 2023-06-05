#include"CPP-5-E02114210.h"
void Employee::raiseSalary(float percent) {
	//��н�Ĳ���Ϊ��salary = salary * (1 + percent)��
	salary = salary * (1 + percent);
}

void Employee::show() {
	cout << "Name = " << name << ",Salary = " << salary << endl;
}

float Employee::getSalary() {
	return salary;
}
const string& Employee::getName() {
	return name;
}

void Employee::setSalary(float _salary) {
	salary = _salary;
}
void Employee::setName(string _name) {
	name = _name;
}

float Manager::getBonus() {
	return bonus;
}
const string& Manager::getPosition() {
	return position;
}

void Manager::raiseSalary(float percent) {
	//��н�㷨Ϊ:salary = salary*(1 + percent + bonus)
	setSalary(getSalary() * (1 + percent + bonus));
}

void Manager::show() {//��������������ְλ�Լ�������Ϣ
	cout << "Employee Type: Manager" << ",Name = " << getName() << ",Position = " << position << ",Salary = " << getSalary() << endl;
}

int main() {
	cout << "E02114210 ������" << endl;
	Employee tom("Tom");
	tom.show();
	tom.raiseSalary(0.1);
	tom.show();
	Manager ceo("Peter", "CEO", 30000, 0.1);
	ceo.show();
	ceo.raiseSalary(0.15);
	ceo.show();
	return 0;
}