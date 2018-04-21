//���D��T��
//https://abc007.contest.atcoder.jp/tasks/abc007_3
#include<vector>
#include<iostream>
#include<string>
#include<queue>

#define MAX_N 100
#define MAX_M 100
using namespace std;
const int INF = 100000000;
string maze[MAX_N];
int N, M;
int sx, sy;//start
int gx, gy;//goal
int d[MAX_N][MAX_M];//�e�_�܂ł̍ŒZ�����̔z��
					//�ړ�4�����̃x�N�g��
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

//(sx,sy)����(gx,gy)�̍ŒZ����
//���ǂ���Ȃ���INF
int bfs()
{
	queue<pair<int, int>>que;
	//�S�Ă̓_��INF�ŏ�����
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			d[i][j] = INF;
		}
	}
	//�X�^�[�g�n�_���L���[�ɓ���A���̓_�̋�����0�ɂ���
	que.push(make_pair(sx, sy));
	d[sy][sx] = 0;

	//�L���[����ɂȂ�܂Ń��[�v
	while (que.size())
	{
		//�L���[�̐擪�����o��
		pair<int, int> p = que.front();
		que.pop();
		//���o���Ă�����Ԃ��S�[���Ȃ�T������߂�
		if (p.first == gx && p.second == gy)
		{
			break;
		}
		//�ړ�4���������[�v
		for (int i = 0; i < 4; i++)
		{
			//�ړ�������̓_��(nx,ny)�Ƃ���
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			//�ړ����\���̔���Ƃ��łɖK�ꂽ���Ƃ����邩�̔���(d[nx][ny]!=INF�Ȃ�K�ꂽ���Ƃ�����)
			if ((0 <= ny && ny < N) && (0 <= nx && nx < M) && (maze[ny][nx] != '#') && (d[ny][nx] == INF))
			{
				//�ړ��ł���Ȃ�L���[�ɓ���A���̓_�̋�����p����̋���+1�Ŋm�肷��
				que.push(make_pair(nx, ny));
				d[ny][nx] = d[p.second][p.first] + 1;
			}
		}
	}
	return d[gy][gx];
}
int main()
{

	cin >> N >> M;

	cin >> sy >> sx; sx--; sy--;

	cin >> gy >> gx; gx--; gy--;
	for (int i = 0; i < N; i++)
	{
		cin >> maze[i];
	}
	int res = bfs();
	cout << res << endl;
	return 0;

}