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
void p() //���������������
{
	cout << "�����������Ϊ��" << People::number << ", �������ѧ�뼼��רҵ��������Ϊ�� " << CSAT::number << "�� �������רҵ��������Ϊ�� " << SE::number << endl;
}
int People::number = 0, CSAT::number = 0, SE::number = 0;
int main() {
	cout << "������ E02114210\n";
	p();
	CSAT c1, c2, c3; //�������ѧ�뼼��רҵ��������
	SE s1, s2, s3; //�������רҵ��������
	p(); //�����������
	CSAT* c4 = new CSAT; //�������ѧ�뼼��רҵ����һ��
	CSAT* c5 = new CSAT;//�������ѧ�뼼��רҵ����һ��
	SE* s4 = new SE;//�������רҵ����һ��
	p();//�����������
	delete c4;
	delete c5;
	delete s4;
}