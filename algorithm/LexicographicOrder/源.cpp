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
int f(int i, int k) {//第i个字符打头的长度等于k的升序字符串个数
	int code = 0;
	if (k == 1) {//字符串长度等于1的升序字符串个数为1
		return 1;
	}
	for (int j = i + 1; j < 27; j++) {//递归调用f函数
		code += f(j, k - 1);
	}
	return code;
}
int g(int k) {//长度等于k的升序字符串总个数
	int code = 0;
	for (int i = 1; i < 27; i++) {//分别计算以26个字母开头的的长度等于k的升序字符串个数
		code += f(i, k);
	}
	return code;
}
int cal(char str[]) {
	int code = 0;
	int len = strlen(str);

	for (int j = 1; j < len; j++) {//计算长度小于这个字符串的升序字符串总个数
		code += g(j);
	}

	int start = str[0] - 'a' + 1;//字符串首字母所代表的序号
	for (int j = 1; j < start; j++) {//计算长度等于这个字符串长度，字符串首字母序号比这个字符串首字母序号小的升序字符串总个数
		code += f(j, len);
	}

	for (int j = 1; j < len; j++) {//子字符串从str[j]开始（升序字符串的首字母相同情况）
		int begin = str[j] - 'a' + 1;//子字符串首字母所代表的序号
		for (int i = start + 1; i < begin; i++) {//计算长度等于这个字符串长度-j，子字符串首字母序号比这个子字符串首字母序号小的子升序字符串总个数
			code += f(i, len - j);
		}
		start = begin;
	}
	return code + 1;
}
int main()
{
	ifstream ifs;
	ifs.open("input.txt", ios::in);//打开input.txt文件
	ofstream ofs;
	ofs.open("output.txt", ios::out);//打开output.txt文件
	int num = 0;//保存将要输入的字符串个数
	char a[30];//依次保存每次计算的字符串
	ifs >> num;
	for (int i = 0; i < num; i++)
	{
		ifs >> a;
		if (error(a)) {
			cout << a << "\t" << cal(a) << endl;//计算编码并输出到命令行
			ofs << cal(a) << endl;//在output.txt文件中写入
		}
		else {
			cout << a << "\t" << "输入格式错误" << endl;
			ofs << "输入格式错误" << endl;
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