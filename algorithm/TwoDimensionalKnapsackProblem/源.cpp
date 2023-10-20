#include<iostream>
using namespace std;
//  O(n*c*d) + O(n)
int main() {
	//������������������
	int n; // ��Ʒ����
	cout << "��Ʒ���� n = ";
	cin >> n;

	int c; // ����������������������
	int d; // ��������ݻ�
	int* w = new int[n + 1]; // ��¼��Ʒ����,��λ����
	int* b = new int[n + 1]; // ��¼��Ʒ���,��λ����
	int* v = new int[n + 1]; // ��¼��Ʒ��ֵ,��λ����
	int* x = new int[n + 1]; // ��¼�����ڴ������Щ��Ʒ��0��ʾû�зţ�1��ʾ���ˡ���λ���á�

	cout<<"���������������������� c = ";
	cin>>c;

	cout<<"��������ݻ� d = ";
	cin>>d;

	cout<<"ÿ����Ʒ������wi: "; 
	for (int i = 1; i <= n; i++)
		cin>>w[i];
	cout << "ÿ����Ʒ�����bi: ";
	for (int i = 1; i <= n; i++)
		cin>>b[i];
	cout << "ÿ����Ʒ�ļ�ֵvi: "; 
	for (int i = 1; i <= n; i++)
		cin>>v[i];

	// ��̬�滮�����Ž� 
	int i, j, k;
	//��������ʼ��dp[n+1][c+1][d+1]
	int*** dp;//��������ָ��
	dp = new int** [n + 1];//Ϊ��һά����ռ�
	for (int i = 0; i < n + 1; i++)
	{
		dp[i] = new int* [c + 1];//Ϊ�ڶ�ά����ռ�
		for (int j = 0; j < c + 1; j++)
		{
			dp[i][j] = new int[d + 1];//Ϊ����ά����ռ�
			for (int k = 0; k < d + 1; k++)dp[i][j][k] = 0;// ����Ԫ�ض���Ϊ�㣬����ͬʱҲ����˵�һ�еĳ�ʼ��
		}
			
	}

	for (i = 1; i <= n; i++) {
		for (j = 0; j <= c; j++) { //�����j=w[i]����������Ա�������������j=0������kͬ�� 
			for (k = 0; k <= d; k++) {
				if (j >= w[i] && k >= b[i]) {
					dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - w[i]][k - b[i]] + v[i]);
				}
				else {
					dp[i][j][k] = dp[i - 1][j][k];
				}
			}
		}
	}
	// ��ӡdp[n][c][d],�����������ֵ
	cout << "maxValue = " << dp[n][c][d] << endl;

	// ����x[i]�����������ձ���������Щ��Ʒ 
	for (i = n, j = c, k = d; i > 0; i--) {
		if (dp[i][j][k] == dp[i - 1][j][k]) { // û�б仯��˵��û��ѡȡ 
			x[i] = 0;
		}
		else {
			x[i] = 1; // �б仯��˵������Ʒ��ѡȡ��  
			j -= w[i];
			k -= b[i];
		}
	}
	cout<< "x[i] = ";
	for (int i = 1; i <= n; i++) {
		cout<<x[i];
	}puts("");

	return 0;
}

/* һ��������������
5
10
10
2 2 6 5 4
2 2 6 5 4
6 3 5 4 6
��
maxValue = 15
x[i] = 11001
*/

