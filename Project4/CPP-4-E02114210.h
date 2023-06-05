#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class Matrix {
public:
	Matrix();//默认构造函数
	Matrix(int _rows, int _cols, const int* values);//有参构造函数
	Matrix(int _rows, int _cols, int _value);//有参构造函数
	Matrix(const Matrix& M);//拷贝构造函数
	Matrix& operator=(const Matrix& N);//拷贝赋值函数
	~Matrix();//析构函数
	int get(const int row, const int col);//根据参数指定的行号row和列号col返回矩阵中对应行列的元素
	void set(const int row, const int col, int val);// 将矩阵第row行第col列的元素值修改为val
	Matrix transpose();//返回矩阵的转置
	Matrix reshape(int _rows,int _cols);//改变矩阵形状
	Matrix clone();//将矩阵对象克隆一份并返回给调用者
	Matrix mul(Matrix &N);//实现矩阵的乘法运算
	void show()const;//在控制台上输出pData的值，并按照矩阵的形状输出矩阵元素
	static Matrix eyes(const int rows);//生成一个rows行rows列的单位阵对象，并返回该对象
	static Matrix ones(const int rows);//生成一个rows行rows列的全1矩阵对象
private:
	int* pData;//指向存放矩阵数组的内存
	int* pRefCount;//指向pData的引用计数器
	int rows;//行数
	int cols;//列数
	int rowStep;//相邻两行同一列元素M[i,j]与M[i+1,j]在pData中下标的距离
	int colStep;//相邻两行同一列元素M[i,j]与M[i,j+1]在pData中下标的距离
	int getInd(int i,int j);//快速获取矩阵元素M[i,j]在pData中的下标
};