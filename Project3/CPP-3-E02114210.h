#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class BankAccount;
class Bank {
public:
	Bank();//Ĭ�Ϲ��캯��
	Bank(string name);//�вι���
	int registerAccount(string name, double money);//Ϊ����ע��һ���˻�
	void closeAccount(int number);//�ر�һ�������˻�
	void deposit(int number, double money);//ִ�д�����
	void withdraw(int number, double money);//ִ��ȡ�����
	void show();
	int getActiveAccount();//���������ܻ�˻���Ŀ
	double getAllBalance();//���������ܴ����
	static void setRate(double newRate);//�޸����еĴ������
	static double getRate();//�������д������
	const BankAccount& getAccount(int number);//�����˻���Ӧ���˻�����
	static int EmptyAccountNumber;
private:
	vector<BankAccount> accounts;//�����е������˻���Ϣ
	string name;//��������
	static double rate;//���еĴ������
	int _number = 1;//��һ����ע��������˻����˻�
	int findAccount(int number);//�ӳ�Աaccounts���ҵ�ָ���˻����˻�
};
class BankAccount
{
public:
	string getName();//�˻���
	int getNumber();//�˻�
	double getBalance();//������
	double getRate();//����
	bool getActive();//��Ч�˻���ʶ
	BankAccount() :name("Empty"), balance(0), rate(0), active(false), number(Bank::EmptyAccountNumber) {}//Ĭ�Ϲ��캯��
	double getInterest()const;//���ظ��˻���ǰ�Ĵ����Ϣ
	void show()const;//��ʾ�˻��Ļ������˻���������
	friend class Bank;
private:
	string name;//�˻���
	int number;//�˺�
	double balance;//������
	double rate;//����
	bool active;//��Ч�˻���ʶ
	void setName(string name);//�޸��˻���
	void deposit(double money);//���˻����
	bool withdraw(double money);//���˻�ȡ��
	void close();//�ر��˻�
	BankAccount(string name, int number, double balance, double rate);//˽�й��캯��
};
