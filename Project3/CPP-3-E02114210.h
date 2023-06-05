#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class BankAccount;
class Bank {
public:
	Bank();//默认构造函数
	Bank(string name);//有参构造
	int registerAccount(string name, double money);//为银行注册一个账户
	void closeAccount(int number);//关闭一个银行账户
	void deposit(int number, double money);//执行存款操作
	void withdraw(int number, double money);//执行取款操作
	void show();
	int getActiveAccount();//返回银行总活动账户数目
	double getAllBalance();//返回银行总存款金额
	static void setRate(double newRate);//修改银行的存款利率
	static double getRate();//返回银行存款利率
	const BankAccount& getAccount(int number);//返回账户对应的账户对象
	static int EmptyAccountNumber;
private:
	vector<BankAccount> accounts;//该银行的所有账户信息
	string name;//银行名称
	static double rate;//银行的存款利率
	int _number = 1;//下一个新注册的银行账户的账户
	int findAccount(int number);//从成员accounts中找到指定账户的账户
};
class BankAccount
{
public:
	string getName();//账户名
	int getNumber();//账户
	double getBalance();//存款余额
	double getRate();//利率
	bool getActive();//有效账户标识
	BankAccount() :name("Empty"), balance(0), rate(0), active(false), number(Bank::EmptyAccountNumber) {}//默认构造函数
	double getInterest()const;//返回该账户当前的存款利息
	void show()const;//显示账户的户名、账户、余额、利率
	friend class Bank;
private:
	string name;//账户名
	int number;//账号
	double balance;//存款余额
	double rate;//利率
	bool active;//有效账户标识
	void setName(string name);//修改账户名
	void deposit(double money);//向账户存款
	bool withdraw(double money);//从账户取款
	void close();//关闭账户
	BankAccount(string name, int number, double balance, double rate);//私有构造函数
};
