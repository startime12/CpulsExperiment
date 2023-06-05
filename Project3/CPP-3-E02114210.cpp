#include"CPP-3-E02114210.h"
void BankAccount::setName(string name) {//�޸��˻���
	this->name = name;
}
void BankAccount::deposit(double money) {//���˻����
	balance += money;
}
bool BankAccount::withdraw(double money) {//���˻�ȡ��
	if (money > balance) {
		return false;
	}
	else {
		balance -= money;
		return true;
	}
}
void BankAccount::close() {//�ر��˻�
	active = false;
}
BankAccount::BankAccount(string name, int number, double balance, double rate){//˽�й��캯��
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
double BankAccount::getInterest()const{//���ظ��˻���ǰ�Ĵ����Ϣ
	return balance * rate;
}
void BankAccount::show()const{//��ʾ�˻��Ļ������˻���������
	cout << "Name:" << name << ",Number:" << number << ",Balance:" << balance << ",Interest Rate:" << rate ;
	if (active)cout << ",Normal Account." << endl;
	else cout << ",Closed Account." << endl;
}



int Bank::findAccount(int number){//�ӳ�Աaccounts���ҵ�ָ���˻����˻�
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i].getNumber() == number) {
			return i;
		}
	}
	return -1;
}


int Bank::EmptyAccountNumber;
double Bank::rate;
Bank::Bank(){//Ĭ�Ϲ��캯��
}
Bank::Bank(string name){//�вι���
	this->name = name;
	_number = 1; 
	EmptyAccountNumber = -1; 
}
int Bank::registerAccount(string name, double money){//Ϊ����ע��һ���˻�
	BankAccount b(name, _number++, money, rate);
	accounts.push_back(b);
	return _number-1;
}
void Bank::closeAccount(int number){//�ر�һ�������˻�
	int index = findAccount(number);
	if (index != -1) {
		accounts[index].close();
	}
}
void Bank::deposit(int number,double money){//ִ�д�����
	int index = findAccount(number);
	if (index != -1) {
		accounts[index].deposit(money);
	}
}
void Bank::withdraw(int number, double money) {//ִ��ȡ�����
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
int Bank::getActiveAccount(){//���������ܻ�˻���Ŀ
	int activeAccount = 0;
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i].getActive())
			activeAccount++;
	}
	return activeAccount;
}
double Bank::getAllBalance(){//���������ܴ����
	int allBalance = 0;
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i].getActive())
			allBalance+=accounts[i].getBalance();
	}
	return allBalance;
}
void Bank::setRate(double newRate){//�޸����еĴ������
	rate = newRate;
}
double Bank::getRate(){//�������д������
	return rate;
}
const BankAccount& Bank::getAccount(int number){//�����˻���Ӧ���˻�����
	int index = findAccount(number);
	if (index != -1) {
		return accounts[index];
	}
}

int main() {
	cout << "������ E02114210\n";

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