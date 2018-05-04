//���W���k
//�a�{150�y�[�W
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX_N 100
using namespace std;
//���D��T���p
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

//w*h�̊i�q��@n�{�̒���
int W, H, N;
int X1[MAX_N], X2[MAX_N], Y1[MAX_N], Y2[MAX_N];
//�h��Ԃ��p
bool fld[MAX_N * 6][MAX_N * 6];

int compress(int* x1, int* x2, int w)
{
	vector<int>xs;

	for (int i = 0; i < N; i++)
	{
		for (int d = -1; d <= 1; d++)
		{
			int tx1 = x1[i] + d;
			int tx2 = x2[i] + d;
			if (1 <= tx1 && tx1 <= W)
			{
				xs.push_back(tx1);
			}
			if (1 <= tx2 && tx2 <= W)
			{
				xs.push_back(tx2);
			}
		}
	}
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());

	for (int i = 0; i < N; i++)
	{
		x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
		x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
	}
	return xs.size();
}
int solve()
{

	//���W���k
	W = compress(X1, X2, W);
	H = compress(Y1, Y2, H);
	//���̂��镔����h��Ԃ�
	memset(fld, 0, sizeof(fld));
	for (int i = 0; i < N; i++)
	{
		for (int y = Y1[i]; y <= Y2[i]; y++)
		{
			for (int x = X1[i]; x <= X2[i]; x++)
			{
				fld[y][x] = true;
			}
		}
	}
	//�̈�𐔂���
	int ans = 0;
	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			if (fld[y][x])
			{
				continue;
			}
			ans++;
			//���D��T��
			queue<pair<int, int>>que;
			que.push(make_pair(x, y));
			while (!que.empty())
			{
				//queue�̐擪�����o��
				int sx = que.front().first;
				int sy = que.front().second;
				que.pop();

				for (int i = 0; i < 4; i++)
				{
					int tx = sx + dx[i];
					int ty = sy + dy[i];
					if (tx < 0 || W <= tx || ty < 0 || H <= ty)
					{
						continue;
					}
					if (fld[ty][tx])
					{
						continue;
					}
					que.push(make_pair(tx, ty));
					fld[ty][tx] = true;
				}
			}
		}
	}
	return ans;
}

int main()
{
	cin >> W >> H >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X1[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> X2[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> Y1[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> Y2[i];
	}
	cout << solve() << endl;
	
}



/*
unique
�d�������v�f��������B

���̊֐��́A�ׂ荇�����d���v�f���������v�f���A�͈͂̐擪�ɏW�߂�B
���̊֐��ɂ���ăR���e�i���璼�ڗv�f���폜����A�R���e�i�̗v�f��������悤�Ȃ��Ƃ͂Ȃ��B
�R���e�i������ۂɗv�f���폜����ꍇ�́A���̊֐��̖߂�l�Ƃ��āA
�擪�ɏW�߂�ꂽ�d���Ȃ��͈̖͂����̎����w���C�e���[�^���Ԃ邽�߁A
���̃C�e���[�^����ăR���e�i��erase()�����o�֐��Ȃǂ��Ăяo���A�폜���s�����ƁB
���̊֐��̖߂�l�Ƃ��ĕԂ����C�e���[�^�ȍ~�̒l�͖��K��B
{1,1,2,2,3}->{1,2,3,2,3}
*/