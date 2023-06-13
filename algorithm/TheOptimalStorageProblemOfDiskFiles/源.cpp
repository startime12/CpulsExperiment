#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
/*������a��ֵ����ʹ��Ԫ�صķֲ����м����������μ���*/
void strageSort(int n, vector<int>& a) {
    int i, k, mid;
    sort(a.begin(), a.end(), cmp);
    mid = n / 2;
    vector<int>b(n + 1);
    b[mid] = a[0];
    for (i = 1, k = 1; i < n; i++, k++) {   //����a��ֵ�ֲ����м����������μ���
        b[mid - k] = a[i];
        i++;
        if (i != n)
            b[mid + k] = a[i];
    }
    for (int i = 0; i < n; i++) {        //���仯���a����
        a[i] = b[i];
    }
}
double  minStorage(int n, vector<int>& a) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    double result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {    //�Ӵŵ�0-n-1���������ǵĴŵ���ļ���ʱ��
            result += (a[i] * 1.0 / sum) * (a[j] * 1.0 / sum) * (j - i);
        }
    }
    return result;
}
int main() {
    string w1, w2;
    ifstream ifs;
    ifs.open("input.txt", ios::in);//��input.txt�ļ�
    ofstream ofs;
    ofs.open("output.txt", ios::out);//��output.txt�ļ�
    int n = 0;//���潫Ҫ������ַ�����
    ifs >> n;
    vector<int>a(n+1);
    for (int i = 0; i < n; i++) {
        ifs >> a[i];
    }
    strageSort(n, a);
    ofs << minStorage(n, a);
    ifs.close();
    ofs.close();
    return 0;
}
/*
5
55 33 22 11 9
*/