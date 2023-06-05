#include<string>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int minDistance(string word1, string word2) {
	int len1 = word1.length();
	int len2 = word2.length();
	// 有一个字符串为空串 边界状态
	if (len1 == 0 || len2 == 0) {
		return len1 + len2;
	}
	//D[i][j] 表示 word1 的前 i 个字母和 word2 的前 j 个字母之间的编辑距离。
	vector<vector<int>> D(len1 + 1, vector<int>(len2 + 1));
	// 边界状态初始化
	for (int i = 0; i < len1 + 1; i++) {
        D[i][0] = i;
    }
    for (int j = 0; j < len2 + 1; j++) {
        D[0][j] = j;
    }
	for (int i = 1; i < len1 + 1; i++) {
		for (int j = 1; j < len2 + 1; j++) {
			//word1增
			int add = D[i - 1][j] + 1;
			//word1删
			int del = D[i][j - 1] + 1;
			//word1改
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
	ifs.open("input.txt", ios::in);//打开input.txt文件
	ofstream ofs;
	ofs.open("output.txt", ios::out);//打开output.txt文件
	int n = 0;//保存将要输入的字符个数
	ifs >> w1;
	ifs >> w2;
	ofs << minDistance(w1, w2);
	ifs.close();
	ofs.close();
	return 0;
}