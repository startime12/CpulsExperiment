#include<string>
#include<iostream>
#include<fstream>
using namespace std;

string sets[100000];
long long cnt = 0;
void halfSet(int num,int start,int now) {
	sets[now] = to_string(num) + sets[start] ;
	cout << sets[now] << endl;
	cnt++;
	if (num == 1) {
		return;
	}
	for (int i = 1; i <= num / 2; i++) {
		halfSet(i, now, now + 1);
	}
}

int main()
{
	ifstream ifs;
	ifs.open("input.txt", ios::in);//��input.txt�ļ�
	ofstream ofs;
	ofs.open("output.txt", ios::out);//��output.txt�ļ�
	int n = 0;//���潫Ҫ������ַ�����
	ifs >> n;
	//cin >> n;
	if (n > 0 && n < 1000)  {

		halfSet(n, 0, 0);
		cout << cnt << endl;
		ofs << cnt << endl;//��output.txt�ļ���д��
	}
	else {
		cout << n << "\t" << "�����ʽ����" << endl;
		ofs << "�����ʽ����" << endl;
	}
	ifs.close();
	ofs.close();
	return 0;
}
