//https://www.slideshare.net/iwiwi/ss-3578491

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N = 131072;

int n;
int dat[MAX_N * 2 - 1];
//������
void init()
{
	//�S�Ă̒l��INT_MAX
	for (int i = 0; i < 2 * n - 1; i++)
	{
		dat[i] = INT_MAX;
	}
}

//i�Ԗڂ̒l��x�ɕύX
void update(int i, int x)
{
	//�t�̃m�[�h�̔ԍ�
	i += n - 1;
	dat[i] = x;
	//���Ȃ���X�V
	while (i > 0)
	{
		i = (i - 1) / 2;
		dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
	}

}


//[a,b)�̍ŏ��l�����߂�
//k�Ԗڂ̃m�[�h�@�͈͂�[l,r)

int query(int a, int b, int k, int l, int r)
{
	if (r <= a || b <= l)
	{
		return INT_MAX;
	}
	if (a <= l && r <= b)
	{
		return dat[k];
	}
	else
	{
		int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return min(vl, vr);
	}

}




int main()
{

}
