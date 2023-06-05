#pragma once
#include<cstdio>
#include<iostream>
using namespace std;

class People {
public:
	static int number;
	People();
};
class CSAT :public People {
public:
	static int number;
	CSAT();
};
class SE :public People {
public:
	static int number;
	SE();
};