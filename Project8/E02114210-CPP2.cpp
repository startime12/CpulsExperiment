#include"E02114210-CPP2.h"
People::People() {
	People::number++;
}
CSAT::CSAT() {
	CSAT::number++;
}
SE::SE() {
	SE::number++;
}
void p() //输出到达人数函数
{
	cout << "到达的总人数为：" << People::number << ", 计算机科学与技术专业到达人数为： " << CSAT::number << "， 软件工程专业到达人数为： " << SE::number << endl;
}
int People::number = 0, CSAT::number = 0, SE::number = 0;
int main() {
	cout << "江茜妮 E02114210\n";
	p();
	CSAT c1, c2, c3; //计算机科学与技术专业到达三人
	SE s1, s2, s3; //软件工程专业到达三人
	p(); //输出到达人数
	CSAT* c4 = new CSAT; //计算机科学与技术专业到达一人
	CSAT* c5 = new CSAT;//计算机科学与技术专业到达一人
	SE* s4 = new SE;//软件工程专业到达一人
	p();//输出到达人数
	delete c4;
	delete c5;
	delete s4;
}