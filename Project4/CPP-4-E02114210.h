#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class Matrix {
public:
	Matrix();//Ĭ�Ϲ��캯��
	Matrix(int _rows, int _cols, const int* values);//�вι��캯��
	Matrix(int _rows, int _cols, int _value);//�вι��캯��
	Matrix(const Matrix& M);//�������캯��
	Matrix& operator=(const Matrix& N);//������ֵ����
	~Matrix();//��������
	int get(const int row, const int col);//���ݲ���ָ�����к�row���к�col���ؾ����ж�Ӧ���е�Ԫ��
	void set(const int row, const int col, int val);// �������row�е�col�е�Ԫ��ֵ�޸�Ϊval
	Matrix transpose();//���ؾ����ת��
	Matrix reshape(int _rows,int _cols);//�ı������״
	Matrix clone();//����������¡һ�ݲ����ظ�������
	Matrix mul(Matrix &N);//ʵ�־���ĳ˷�����
	void show()const;//�ڿ���̨�����pData��ֵ�������վ������״�������Ԫ��
	static Matrix eyes(const int rows);//����һ��rows��rows�еĵ�λ����󣬲����ظö���
	static Matrix ones(const int rows);//����һ��rows��rows�е�ȫ1�������
private:
	int* pData;//ָ���ž���������ڴ�
	int* pRefCount;//ָ��pData�����ü�����
	int rows;//����
	int cols;//����
	int rowStep;//��������ͬһ��Ԫ��M[i,j]��M[i+1,j]��pData���±�ľ���
	int colStep;//��������ͬһ��Ԫ��M[i,j]��M[i,j+1]��pData���±�ľ���
	int getInd(int i,int j);//���ٻ�ȡ����Ԫ��M[i,j]��pData�е��±�
};