#include<iostream>
#include<cmath>
using namespace std;

typedef struct complex
{
    float real;
    float image;
}complex;

complex i, j;
void print(complex i) {
    if (i.image < 0) {
        cout << i.real << "-" << -i.image << "i";
    }
    else{
        cout << i.real << "+" << i.image << "i";
    }
}
void outputRoot(complex i, complex j) {
    cout << "x1=";
    print(i);
    cout << ",";
    cout << "x2=";
    print(j);
}
void outputEqu(float a, float b, float c) {
    cout << "(" << a << "," << b << "," << c << ")" << endl;
}
bool calculation(float a, float b, float c) {
    if (a == 0) {
        return false;
    }
    float e = b * b - 4 * a * c;
    float u = 0, v = 0;
    u = -b / (float)(2 * a);
    v = -sqrt(abs(e)) / (float)(2 * a);
    if (e < 0)
    {
        i.real = u;
        i.image = v;
        j.real = u;
        j.image = -v;
    }
    else if (e == 0) {
        i.real = u;
        i.image = 0;
        j.real = u;
        j.image = 0;
    }
    else {
        i.real = u + v;
        i.image = 0;
        j.real = u - v;
        j.image = 0;
    }
    return true;
}
void test(float a, float b, float c) {
    outputEqu(a, b, c);
    if (!calculation(a, b, c))
        cout << "输入非法";
    else
        outputRoot(i, j);
}
int main() {
    float a = 0, b = 0, c = 0;
    cout << "江茜妮 E02114210" << endl;
    scanf_s("a = %f, b = %f, c = %f", &a, &b, &c);
    test(a, b, c);
    return 0;
}