#include<cstdio> 
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;
int cnt = 0;
string s[50000];
template<class Type>
bool judge(Type list[], int k, int i) {//判断此排列是否会与前面排列重复
	if (i > k) {
		for (int t = k; t < i; t++) {
			if (list[t] == list[i])
				return false;
		}
	}
	return true;
}

template<class Type>
inline void Swap(Type& a, Type& b) {//将a，b两个元素互换
	Type temp = a;
	a = b;
	b = temp;
}

template<class Type>
void Perm(Type list[], int k, int m) {//产生list[k:m]的所有排列
	if (k == m) {//只剩下1个元素
		cnt++;
		for (int i = 0; i <= m; i++) {
			cout << list[i];
		}
		s[cnt - 1] = list;
		cout << endl;
	}
	else {//还有多个元素待排列，递归产生排序
		for (int i = k; i <= m; i++) {
			if (judge(list, k, i)) {//判断排列是否重复
				Swap(list[k], list[i]);//交换k位置和i位置的两个元素
				Perm(list, k + 1, m);//产生list[k+1:m]的所有排列
				Swap(list[k], list[i]);//将刚刚的交换还原，到下一位进行元素交换
			}
		}
	}
}

int main()
{
	ifstream ifs;
	ifs.open("input.txt", ios::in);//打开input.txt文件
	ofstream ofs;
	ofs.open("output.txt", ios::out);//打开output.txt文件
	int num = 0;//保存将要输入的字符个数
	char arr[30];//保存输入的字符串
	ifs >> num;
	ifs >> arr;
	if (strlen(arr) != num) {
		cout << arr << "\t" << "输入格式错误" << endl;
		ofs << "输入格式错误" << endl;
	}
	else {
		Perm<char>(arr, 0, num - 1);
		cout << cnt << endl;
		for (int i = 0; i < cnt; i++) {
			ofs << s[i] << endl;
		}
		ofs << cnt << endl;//在output.txt文件中写入
	}
	ifs.close();
	ofs.close();
	return 0;
}