#include<cstdio> 
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;
int cnt = 0;
string s[50000];
template<class Type>
bool judge(Type list[], int k, int i) {//�жϴ������Ƿ����ǰ�������ظ�
	if (i > k) {
		for (int t = k; t < i; t++) {
			if (list[t] == list[i])
				return false;
		}
	}
	return true;
}

template<class Type>
inline void Swap(Type& a, Type& b) {//��a��b����Ԫ�ػ���
	Type temp = a;
	a = b;
	b = temp;
}

template<class Type>
void Perm(Type list[], int k, int m) {//����list[k:m]����������
	if (k == m) {//ֻʣ��1��Ԫ��
		cnt++;
		for (int i = 0; i <= m; i++) {
			cout << list[i];
		}
		s[cnt - 1] = list;
		cout << endl;
	}
	else {//���ж��Ԫ�ش����У��ݹ��������
		for (int i = k; i <= m; i++) {
			if (judge(list, k, i)) {//�ж������Ƿ��ظ�
				Swap(list[k], list[i]);//����kλ�ú�iλ�õ�����Ԫ��
				Perm(list, k + 1, m);//����list[k+1:m]����������
				Swap(list[k], list[i]);//���ոյĽ�����ԭ������һλ����Ԫ�ؽ���
			}
		}
	}
}

int main()
{
	ifstream ifs;
	ifs.open("input.txt", ios::in);//��input.txt�ļ�
	ofstream ofs;
	ofs.open("output.txt", ios::out);//��output.txt�ļ�
	int num = 0;//���潫Ҫ������ַ�����
	char arr[30];//����������ַ���
	ifs >> num;
	ifs >> arr;
	if (strlen(arr) != num) {
		cout << arr << "\t" << "�����ʽ����" << endl;
		ofs << "�����ʽ����" << endl;
	}
	else {
		Perm<char>(arr, 0, num - 1);
		cout << cnt << endl;
		for (int i = 0; i < cnt; i++) {
			ofs << s[i] << endl;
		}
		ofs << cnt << endl;//��output.txt�ļ���д��
	}
	ifs.close();
	ofs.close();
	return 0;
}