//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0225
//���j�I���t�@�C���h��
//�I�C���[�H
#include<iostream>
#include<vector>
#include<string>
using namespace std;




int par[26];
int r[26];//rank

void init(int n)//���_�̐��������ɂ��ď�����
{
	for (int i = 0; i < n; i++)
	{
		r[i] = 0;
		par[i] = i;
	}
}

int root(int x)
{
	if (par[x] == x)
	{
		return x;
	}
	else
	{
		return par[x] = root(par[x]);
	}
}

bool same(int x, int y)
{
	return root(x) == root(y);
}

void unite(int x, int y)
{
	x = root(x);
	y = root(y);
	if (x == y)
	{
		return;
	}
	if (r[x] < r[y])
	{
		par[x] = y;
	}
	else if (r[x] > r[y])
	{
		par[y] = x;
	}
	else if (r[x] == r[y])
	{
		par[x] = y;
		r[y]++;
	}
}



int main()
{
	int n;//�P��̐�

	while (cin >> n, n)
	{
		init(26);//�O���t�̒��_�̐�=�A���t�@�x�b�g�̐�=26
		vector<string>word(n);
		for (auto& s : word)
		{
			cin >> s;
		}

		vector<int> in(26), out(26);
		for (auto& s : word)
		{
			const auto first = s[0] - 'a', last = s.back() - 'a';//�ŏ��ƍŌ�̕��������o���@-'a'��a-z��0-25�ɑΉ������Ă���
			in[first]++;//������
			out[last]++;//�o����
			unite(first, last);//���_(�A���t�@�׃b�g)first,last�������W���ɑ�����
		}
		bool ok = true;
		int comp_num = 0;//�W���̐�
		for (int i = 0; i < 26; i++)
		{
			comp_num += (in[i] && root(i) == i);
			ok &= in[i] == out[i];
		}
		ok &= (comp_num == 1);
		if (ok)
		{
			cout << "OK" << endl;
		}
		else
		{
			cout << "NG" << endl;
		}
	}


	return 0;
}