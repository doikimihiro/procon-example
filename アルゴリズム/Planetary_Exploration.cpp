//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560
//二次元累積和
#include<vector>
#include<iostream>
#include<string>
using namespace std;
int J[1001][1001];
int O[1001][1001];
char str[1001][1001];
//Iの数は全体からJ,Oを引いて求める方針
int main()
{
	int M, N, K;//Mは縦の長さ　Nは横の長さ　Kはクエリの数
	cin >> M >> N >> K;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> str[i][j];
		}
	}//str[M][N]で惑星の情報を持った
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (str[i][j] == 'J')
			{
				J[i + 1][j + 1]++;
			}
			if (str[i][j] == 'O')
			{
				O[i + 1][j + 1]++;
			}
		}
	}
	//二次元累積和の横の部分
	for (int i = 0; i <= M; i++)
	{
		int p = 0;
		int q = 0;
		for (int j = 0; j <= N; j++)
		{
			p = p + J[i][j];
			J[i][j] = p;
			q = q + O[i][j];
			O[i][j] = q;
		}
	}
	//二次元累積和の縦の部分
	for (int j = 0; j <= N; j++)
	{
		int p = 0;
		int q = 0;
		for (int i = 0; i <= M; i++)
		{
			p = p + J[i][j];
			J[i][j] = p;
			q = q + O[i][j];
			O[i][j] = q;
		}
	}
	for (int i = 0; i < K; i++)
	{
		int a, b, c, d;//調べる領域を指定する座標
		cin >> a >> b >> c >> d;
		int j = J[c][d] - J[a - 1][d] - J[c][b - 1] + J[a - 1][b - 1];
		int o = O[c][d] - O[a - 1][d] - O[c][b - 1] + O[a - 1][b - 1];
		cout << j <<" "<< o <<" " << (c - a + 1)*(d - b + 1) - j - o << endl;
	}
	return 0;
}