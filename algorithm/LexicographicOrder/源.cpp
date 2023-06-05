#include<cstdio> 
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;
bool error(char str[]) {
	int len = strlen(str);
	if (len > 6) {
		return false;
	}
	for (int i = 1; i < len; i++) {
		if (str[i] <= str[i - 1]) {
			return false;
		}
	}
	return true;
}
int f(int i, int k) {//��i���ַ���ͷ�ĳ��ȵ���k�������ַ�������
	int code = 0;
	if (k == 1) {//�ַ������ȵ���1�������ַ�������Ϊ1
		return 1;
	}
	for (int j = i + 1; j < 27; j++) {//�ݹ����f����
		code += f(j, k - 1);
	}
	return code;
}
int g(int k) {//���ȵ���k�������ַ����ܸ���
	int code = 0;
	for (int i = 1; i < 27; i++) {//�ֱ������26����ĸ��ͷ�ĵĳ��ȵ���k�������ַ�������
		code += f(i, k);
	}
	return code;
}
int cal(char str[]) {
	int code = 0;
	int len = strlen(str);

	for (int j = 1; j < len; j++) {//���㳤��С������ַ����������ַ����ܸ���
		code += g(j);
	}

	int start = str[0] - 'a' + 1;//�ַ�������ĸ����������
	for (int j = 1; j < start; j++) {//���㳤�ȵ�������ַ������ȣ��ַ�������ĸ��ű�����ַ�������ĸ���С�������ַ����ܸ���
		code += f(j, len);
	}

	for (int j = 1; j < len; j++) {//���ַ�����str[j]��ʼ�������ַ���������ĸ��ͬ�����
		int begin = str[j] - 'a' + 1;//���ַ�������ĸ����������
		for (int i = start + 1; i < begin; i++) {//���㳤�ȵ�������ַ�������-j�����ַ�������ĸ��ű�������ַ�������ĸ���С���������ַ����ܸ���
			code += f(i, len - j);
		}
		start = begin;
	}
	return code + 1;
}
int main()
{
	ifstream ifs;
	ifs.open("input.txt", ios::in);//��input.txt�ļ�
	ofstream ofs;
	ofs.open("output.txt", ios::out);//��output.txt�ļ�
	int num = 0;//���潫Ҫ������ַ�������
	char a[30];//���α���ÿ�μ�����ַ���
	ifs >> num;
	for (int i = 0; i < num; i++)
	{
		ifs >> a;
		if (error(a)) {
			cout << a << "\t" << cal(a) << endl;//������벢�����������
			ofs << cal(a) << endl;//��output.txt�ļ���д��
		}
		else {
			cout << a << "\t" << "�����ʽ����" << endl;
			ofs << "�����ʽ����" << endl;
		}
		
	}
	ifs.close();
	ofs.close();
	return 0;
}
/*
dfj
.
..
a..
b..
c..
de.
dfg
dfh
dfi
dfj
*/