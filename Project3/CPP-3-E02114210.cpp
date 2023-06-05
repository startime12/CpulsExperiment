#include"CPP-3-E02114210.h"
void BankAccount::setName(string name) {//修改账户名
	this->name = name;
}
void BankAccount::deposit(double money) {//向账户存款
	balance += money;
}
bool BankAccount::withdraw(double money) {//从账户取款
	if (money > balance) {
		return false;
	}
	else {
		balance -= money;
		return true;
	}
}
void BankAccount::close() {//关闭账户
	active = false;
}
BankAccount::BankAccount(string name, int number, double balance, double rate){//私有构造函数
	this->name = name;
	this->number = number;
	this->balance = balance;
	this->rate = rate;
	this->active = true;
}



string BankAccount::getName() { return name; }
int BankAccount::getNumber() { return number; }
double BankAccount::getBalance() { return balance; }
double BankAccount::getRate() { return rate; }
bool BankAccount::getActive() { return active; }
double BankAccount::getInterest()const{//返回该账户当前的存款利息
	return balance * rate;
}
void BankAccount::show()const{//显示账户的户名、账户、余额、利率
	cout << "Name:" << name << ",Number:" << number << ",Balance:" << balance << ",Interest Rate:" << rate ;
	if (active)cout << ",Normal Account." << endl;
	else cout << ",Closed Account." << endl;
}



int Bank::findAccount(int number){//从成员accounts中找到指定账户的账户
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i].getNumber() == number) {
			return i;
		}
	}
	return -1;
}


int Bank::EmptyAccountNumber;
double Bank::rate;
Bank::Bank(){//默认构造函数
}
Bank::Bank(string name){//有参构造
	this->name = name;
	_number = 1; 
	EmptyAccountNumber = -1; 
}
int Bank::registerAccount(string name, double money){//为银行注册一个账户
	BankAccount b(name, _number++, money, rate);
	accounts.push_back(b);
	return _number-1;
}
void Bank::closeAccount(int number){//关闭一个银行账户
	int index = findAccount(number);
	if (index != -1) {
		accounts[index].close();
	}
}
void Bank::deposit(int number,double money){//执行存款操作
	int index = findAccount(number);
	if (index != -1) {
		accounts[index].deposit(money);
	}
}
void Bank::withdraw(int number, double money) {//执行取款操作
	int index = findAccount(number);
	if (index != -1) {
		accounts[index].withdraw(money);
	}
}
void Bank::show() {
	for (int i = 0; i < accounts.size(); i++) {
		if(accounts[i].getActive())
			accounts[i].show();
	}

	cout << "Current Deposit Insterest=" << rate << ",#Accounts=" << getActiveAccount() << ",Total Deposit=" << getAllBalance() << endl;
}
int Bank::getActiveAccount(){//返回银行总活动账户数目
	int activeAccount = 0;
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i].getActive())
			activeAccount++;
	}
	return activeAccount;
}
double Bank::getAllBalance(){//返回银行总存款金额
	int allBalance = 0;
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i].getActive())
			allBalance+=accounts[i].getBalance();
	}
	return allBalance;
}
void Bank::setRate(double newRate){//修改银行的存款利率
	rate = newRate;
}
double Bank::getRate(){//返回银行存款利率
	return rate;
}
const BankAccount& Bank::getAccount(int number){//返回账户对应的账户对象
	int index = findAccount(number);
	if (index != -1) {
		return accounts[index];
	}
}

int main() {
	cout << "江茜妮 E02114210\n";

	Bank bank("ICBC");
	bank.setRate(0.013);

	cout << "==================Bank:ICBC==============" << endl;

	int id1 = bank.registerAccount("MaYun", 10000);
	int id2 = bank.registerAccount("MaHua", 13200);
	bank.show();

	cout << "\n*****************************************\n";
	cout << "==================Bank:ICBC==============" << endl;
	bank.setRate(0.015);
	int id3 = bank.registerAccount("Musk", 10270);
	int id4 = bank.registerAccount("Zhang", 19080);
	bank.show();

	cout << "\n*****************************************\n";
	bank.closeAccount(id3);
	bank.getAccount(id3).show();
	cout << "==================Bank:ICBC==============" << endl;
	bank.withdraw(id4, 2000);
	bank.show();
	cout << "\n*****************************************\n";
	int id5 = bank.registerAccount("Wang", 7790);
	bank.getAccount(id5).show();
	bank.deposit(id5, 10000);
	bank.getAccount(id5).show();
	cout << "interest = ";
	cout << bank.getAccount(id5).getInterest() << endl;
	cout << "==================Bank:ICBC==============" << endl;

	bank.show();

	return 0;
}