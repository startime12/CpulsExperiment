#pragma once
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
class Point {
protected:
	int x, y;
public:
	Point(int a, int b) :x(a), y(b) {};
};
class Triangle :public Point{
private:
	int x2, y2, x3, y3;
	double re;
public:
	Triangle(int a, int b, int c, int d, int e, int f):Point(a, b), x2(c), y2(d), x3(e), y3(f) {}
	double getRe();
};