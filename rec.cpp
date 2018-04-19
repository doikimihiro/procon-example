//�ċA
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B&lang=jp
#include<vector>
#include<iostream>
#include<algorithm>
#define MAX_N 101
#define MAX_W 10001

using namespace std;
int n,W;
int w[MAX_N];
int v[MAX_N];

//i�Ԗڈȍ~�̉ו�����d���̑��a��j�ȉ��ɂȂ�悤�ɑI��
int rec(int i, int j)
{
	int res;
	if (i == n)
	{
		//�����i���͎c���Ă��Ȃ�
		res = 0;
	}
	else if (j < w[i])
	{
		//���̕i���͓���Ȃ�
		res = rec(i + 1, j);
	}
	else
	{
		res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}
	return res;
}
int main()
{
	cin >> n >> W;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i] >> w[i];
	}
	cout << rec(0, W) << endl;
}