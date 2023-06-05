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
	ifs.open("input.txt", ios::in);//打开input.txt文件
	ofstream ofs;
	ofs.open("output.txt", ios::out);//打开output.txt文件
	int n = 0;//保存将要输入的字符个数
	ifs >> n;
	//cin >> n;
	if (n > 0 && n < 1000)  {

		halfSet(n, 0, 0);
		cout << cnt << endl;
		ofs << cnt << endl;//在output.txt文件中写入
	}
	else {
		cout << n << "\t" << "输入格式错误" << endl;
		ofs << "输入格式错误" << endl;
	}
	ifs.close();
	ofs.close();
	return 0;
}
