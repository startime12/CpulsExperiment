#include<string>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int minDistance(string word1, string word2) {
	int len1 = word1.length();
	int len2 = word2.length();
	// ��һ���ַ���Ϊ�մ� �߽�״̬
	if (len1 == 0 || len2 == 0) {
		return len1 + len2;
	}
	//D[i][j] ��ʾ word1 ��ǰ i ����ĸ�� word2 ��ǰ j ����ĸ֮��ı༭���롣
	vector<vector<int>> D(len1 + 1, vector<int>(len2 + 1));
	// �߽�״̬��ʼ��
	for (int i = 0; i < len1 + 1; i++) {
        D[i][0] = i;
    }
    for (int j = 0; j < len2 + 1; j++) {
        D[0][j] = j;
    }
	for (int i = 1; i < len1 + 1; i++) {
		for (int j = 1; j < len2 + 1; j++) {
			//word1��
			int add = D[i - 1][j] + 1;
			//word1ɾ
			int del = D[i][j - 1] + 1;
			//word1��
			int modify = D[i - 1][j - 1];
			if (word1[i - 1] != word2[j - 1]) modify += 1;
			D[i][j] = min(modify, min(add, del));
		}
	}
	return D[len1][len2];
}
int main()
{
	string w1, w2;
	ifstream ifs;
	ifs.open("input.txt", ios::in);//��input.txt�ļ�
	ofstream ofs;
	ofs.open("output.txt", ios::out);//��output.txt�ļ�
	int n = 0;//���潫Ҫ������ַ�����
	ifs >> w1;
	ifs >> w2;
	ofs << minDistance(w1, w2);
	ifs.close();
	ofs.close();
	return 0;
}