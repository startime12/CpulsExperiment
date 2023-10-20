#include<iostream>
using namespace std;
//  O(n*c*d) + O(n)
int main() {
	//声明参数和数据输入
	int n; // 物品个数
	cout << "物品个数 n = ";
	cin >> n;

	int c; // 背包容量（最大承受重量）
	int d; // 背包最大容积
	int* w = new int[n + 1]; // 记录物品重量,首位不用
	int* b = new int[n + 1]; // 记录物品体积,首位不用
	int* v = new int[n + 1]; // 记录物品价值,首位不用
	int* x = new int[n + 1]; // 记录背包内存放了哪些物品。0表示没有放，1表示放了。首位不用。

	cout<<"背包容量（最大承受重量） c = ";
	cin>>c;

	cout<<"背包最大容积 d = ";
	cin>>d;

	cout<<"每个物品的重量wi: "; 
	for (int i = 1; i <= n; i++)
		cin>>w[i];
	cout << "每个物品的体积bi: ";
	for (int i = 1; i <= n; i++)
		cin>>b[i];
	cout << "每个物品的价值vi: "; 
	for (int i = 1; i <= n; i++)
		cin>>v[i];

	// 动态规划找最优解 
	int i, j, k;
	//声明并初始化dp[n+1][c+1][d+1]
	int*** dp;//创建三重指针
	dp = new int** [n + 1];//为第一维分配空间
	for (int i = 0; i < n + 1; i++)
	{
		dp[i] = new int* [c + 1];//为第二维分配空间
		for (int j = 0; j < c + 1; j++)
		{
			dp[i][j] = new int[d + 1];//为第三维分配空间
			for (int k = 0; k < d + 1; k++)dp[i][j][k] = 0;// 其内元素都置为零，这里同时也完成了第一行的初始化
		}
			
	}

	for (i = 1; i <= n; i++) {
		for (j = 0; j <= c; j++) { //会出现j=w[i]的情况，所以遍历包含必须有j=0，下面k同理 
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
	// 打印dp[n][c][d],即问题的最优值
	cout << "maxValue = " << dp[n][c][d] << endl;

	// 计算x[i]，即分析最终背包内有哪些物品 
	for (i = n, j = c, k = d; i > 0; i--) {
		if (dp[i][j][k] == dp[i - 1][j][k]) { // 没有变化，说明没有选取 
			x[i] = 0;
		}
		else {
			x[i] = 1; // 有变化，说明该物品被选取了  
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

/* 一个测试用例如下
5
10
10
2 2 6 5 4
2 2 6 5 4
6 3 5 4 6
答案
maxValue = 15
x[i] = 11001
*/

