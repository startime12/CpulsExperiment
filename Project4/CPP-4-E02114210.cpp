#pragma once
#include"CPP-4-E02114210.h"
int Matrix::getInd(int i, int j){//快速获取矩阵元素M[i,j]在pData中的下标
	return i * rowStep + j * colStep;
}
Matrix::Matrix():rows(0),cols(0),pData(nullptr){//默认构造函数
	pRefCount = new int;
	(*pRefCount) = 1;
}
Matrix::Matrix(int _rows, int _cols, const int* values) {//有参构造函数
	rows = _rows;
	cols = _cols;
	rowStep = _cols;
	colStep = 1;
	int size = _rows * _cols;
	pData = new int[size];
	for (int i = 0; i < size; i++) {
		pData[i] = values[i];
	}
	pRefCount = new int;
	(*pRefCount)=1;
}

Matrix::Matrix(int _rows, int _cols, int _value){//有参构造函数
	rows = _rows;
	cols = _cols;
	rowStep = _cols;
	colStep = 1;
	int size = _rows * _cols;
	pData = new int[size];
	for (int i = 0; i < size; i++) {
		pData[i] = _value;
	}
	pRefCount = new int;
	(*pRefCount) = 1;
}

Matrix::Matrix(const Matrix& M){//拷贝构造函数
	this->rows = M.rows;
	this->cols = M.cols;
	this->rowStep = M.rowStep;
	this->colStep = M.colStep;
	this->pData = M.pData;
	this->pRefCount = M.pRefCount;
	(*pRefCount)++;
}

Matrix& Matrix::operator=(const Matrix& N){//拷贝赋值函数
	(*pRefCount)--;
	if ((*pRefCount) == 0) {
		delete pData;
		delete pRefCount;
	}
	this->rows = N.rows;
	this->cols = N.cols;
	this->rowStep = N.rowStep;
	this->colStep = N.colStep;
	this->pData = N.pData;
	this->pRefCount = N.pRefCount;
	(*pRefCount)++;
	return *this;
}

Matrix::~Matrix(){//析构函数
	(*pRefCount)--;
	if ((*pRefCount) == 0) {
		cout << "delete memeroy at " << pData << endl;
		delete pData;
		delete pRefCount;
	}
}

int Matrix::get(const int row, const int col){//根据参数指定的行号row和列号col返回矩阵中对应行列的元素
	if (row >= this->rows || col >= this->cols) {
		return NAN;
	}
	return pData[getInd(row, col)];
}

void Matrix::set(const int row, const int col, int val){// 将矩阵第row行第col列的元素值修改为val
	if (row >= this->rows || col >= this->cols) {
		return;
	}
	pData[getInd(row, col)] = val;
}

Matrix Matrix::transpose(){//返回矩阵的转置
	Matrix M;
	M.rows = this->cols;
	M.cols = this->rows;
	M.rowStep = this->colStep;
	M.colStep = this->rowStep;
	M.pData = this->pData;
	M.pRefCount = this->pRefCount;
	(*M.pRefCount)++;
	return M;
}

Matrix Matrix::reshape(int _rows, int _cols){//改变矩阵形状
	Matrix M;
	if (_rows * _cols == rows * cols) {
		M.rows = _rows;
		M.cols = _cols;
		M.rowStep = _cols;
		M.colStep = 1;
		M.pData = this->pData;
		M.pRefCount = this->pRefCount;
		(*M.pRefCount)++;
		return M;
	}
	return M;
}

Matrix Matrix::clone(){//将矩阵对象克隆一份并返回给调用者
	Matrix M(rows, cols, 0);
	M.rowStep = rowStep;
	M.colStep = colStep;
	int size = rows * cols;
	M.pData = new int[size];
	for (int i = 0; i < size; i++) {
		M.pData[i] = this->pData[i];
	}
	M.pRefCount = new int;
	(*M.pRefCount) = 1;
	return M;
}

Matrix Matrix::mul(Matrix& N){//实现矩阵的乘法运算
	Matrix M(rows, N.cols, 0);
	N = N.transpose();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < N.rows; j++) {
			int res = 0;
			for (int k = 0; k < cols; k++) {
				res = res + get(i, k) * N.get(j, k);
			}
			M.set(i, j, res);
		}
	}
	return M;
}

void Matrix::show()const {//在控制台上输出pData的值，并按照矩阵的形状输出矩阵元素
	cout << pData << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int ind = i * rowStep + j * colStep;
			cout << this->pData[ind] << " ";
		}
		cout << endl;
	}
}

Matrix Matrix::eyes(const int rows){//生成一个rows行rows列的单位阵对象，并返回该对象
	int* value = new int[rows * rows];
	for (int i = 0; i < rows * rows; i++) {
		value[i] = 0;
	}
	for (int i = 0; i < rows; i++) {
		value[i * rows + i * 1] = 1;
	}
	Matrix M(rows, rows, value);
	return M;
}

Matrix Matrix::ones(const int rows){//生成一个rows行rows列的全1矩阵对象
	int* value = new int[rows * rows];
	for (int i = 0; i < rows*rows; i++) {
		value[i] = 1;
	}
	Matrix M(rows, rows, value);
	return M;
}

int main() {
	cout << "江茜妮 E02114210\n";

	int x[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	//用数组x构造一个3行4列的矩阵对象M1
	Matrix M1(3, 4, x);

	cout << "=========M1:=========\n";
	M1.show();

	//M1的转置，M2与M1共享存储。
	Matrix M2 = M1.transpose();
	cout << "=========M2:=========\n";
	M2.show();

	//用M1拷贝构造M3，M3与M1共享存储。
	Matrix M3(M1);
	cout << "=========M3:=========\n";
	M3.show();//M3与M1内容相同

	//将M1克隆得到M4,M4与M1不共享存储
	Matrix M4 = M1.clone();
	cout << "=========M4:=========\n";
	M4.show();//M4与M1内容相同

	//修改M3[0,1]为-2
	M3.set(0, 1, -2);
	cout << "=========M3:=========\n";
	M3.show();//M3[0,1]变为-2
	cout << "=========M1:=========\n";
	M1.show();//M1[0,1]也变为-2
	cout << "=========M4:=========\n";
	M4.show();//M4[0,1]仍然为1，保持不变

	//将M2形状修改为2行6列，得到M5，M5与M2共享存储
	Matrix M5 = M2.reshape(2, 6);
	cout << "=========M5:=========\n";
	M5.show();

	cout << "=========M5.transpose:=========\n";
	M5.transpose().show();

	Matrix I = Matrix::eyes(4);
	cout << "=========I:=========\n";
	I.show();

	Matrix M6 = M4.mul(I);
	cout << "=========M6:========\n";
	M6.show();

	Matrix One = Matrix::ones(4);
	cout << "=========One:=========\n";
	One.show();

	cout << "=========M4*One:=========\n";
	M4.mul(One).show();

	return 0;
}
