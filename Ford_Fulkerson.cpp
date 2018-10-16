//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp
#include<bits/stdc++.h>
#pragma warning(disable:4996)
#ifdef _MSC_VER
#  define __builtin_popcount __popcnt
#endif
#define int long long
using namespace std;
using ll = long long;
using ld = long double;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
inline void my_io() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout << fixed << setprecision(10);
}
int INF = numeric_limits<int>::max();
struct edge {
	int from, to, cap, rev;//rev�͋t�ӂ�index  to:�s����,cap:�e��,rev:�t(G[e.to][e.rev]�ŋt�ӂ̍\���̂ɃA�N�Z�X�ł���B)
};
int v, e;//���_���@�ӂ̐�
vector<vector<edge>>g;
vector<bool>used;
void add_edge(int from,int to, int cap) {
	g[from].push_back(edge{ from, to, cap, (int)g[to].size() });//g[to].size()�Ŏ��̍s�Ŏ擾�����
	g[to].push_back(edge{ to, from, 0, (int)g[from].size()-1});
}
int dfs(int v, int t, int f) {//v����t�ɗ�����ő�
	if (v == t) {//�I�_�܂ł��ǂ蒅������
		return f;
	}
	used[v] = true;
	for (int i = 0; i < g[v].size(); i++) {
		edge &e = g[v][i];//�����Ă��钸�_����L�тĂ���ӂ��Q�Ƃ��Ă���(�R�s�[�ł͂Ȃ��I�I)
		if (!used[e.to] && e.cap>0) {//���̕ӂ̍s������܂����ׂĂ��Ȃ��āA�ӂ̗e�ʂɂ��]�T������
			int d = dfs(e.to, t, min(f, e.cap));//cap�𒴂��Ȃ��ڈ�t�𗬂�
			if (d > 0) {//�����Ă���Ȃ�
				e.cap -= d;//��������cap�������
				g[e.to][e.rev].cap += d;//���������t�ӂ�cap�𑝂₷
				return d;
			}

		}
	
	}
	return 0;//���������Ȃ�����
}
int max_flow(int s, int t) {//s����t�ւ̍ő嗬
	int flow = 0;
	for (;;) {
		for (int i = 0; i<used.size(); i++) {
			used[i] = false;
		}
		int f = dfs(s, t, INF);
		if (f == 0) {
			return flow;//�������������Ȃ��̂ō��܂ŗ������ʂ̘a��Ԃ�
		}
		flow += f;
	}

}
signed main(){
	int v, e;
	cin >> v >> e;
	g.resize(v);
	used.resize(v);
	for (int i = 0; i < e; i++) {
		int from, to, cap;
		cin >> from >> to >> cap;
		add_edge(from, to, cap);
	}
	cout << max_flow(0, v - 1) << endl;
	return 0;
}
