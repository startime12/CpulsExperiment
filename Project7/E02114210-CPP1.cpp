#include"E02114210-CPP1.h"
double Triangle::getRe() {
	int a = (x - x2) * (x - x2) + (y - y2) * (y - y2);
	int b = (x - x3) * (x - x3) + (y - y3) * (y - y3);
	int c = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
	this->re = sqrt(a) + sqrt(b) + sqrt(c);
	return re;
}
int main() {
	cout << "������ E02114210" << endl;
	cout << "�������������꣺" << endl;
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	Triangle t(x1, y1, x2, y2, x3, y3);
	cout << "��������Ϊ" << "a:" << "x=" << x1 << ",y=" << y1 << ";" << "b:" << "x=" << x2 << ",y=" << y2 << ";" << "c:" << "x=" << x3 << ",y=" << y3 << endl;
	cout << "�ܳ�Ϊ" << t.getRe();
	return 0;
}