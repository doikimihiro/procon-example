//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0022&lang=jp

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	int n;
	int sum[5001] = {};
	while (cin >> n, n)
	{
		//�ݐϘa�̔z������
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			sum[i + 1] = sum[i] + a;
		}

		//������������z��̒�����ő�l��I��
		int ret = sum[1];
		for (int i = 0; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				ret = max(ret, sum[j] - sum[i]);
			}
		}
		cout << ret << endl;
	}
}