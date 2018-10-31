//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A&lang=jp
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
int x, y, e;
vector<vector<int>>G;//�O���t�̗אڃ��X�g�\��
vector<int>match;//�}�b�`���O�̃y�A
vector<bool>used;//���꒸�_���n�_�Ƃ���DFS���s��Ȃ��悤�ɂ���
//u��v�����ԕӂ��O���t�ɒǉ�����
void add_edge(int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}
//�����p�X��DFS�ŒT��
bool bi_dfs(int v) {
	used[v] = true;
	for (int i = 0; i<G[v].size(); i++) {
		int u = G[v][i], w = match[u];
		if (w < 0) {
			match[v] = u;
			match[u] = v;
			return true;
		}
		else if (used[w] == false) {
			if (bi_dfs(w)) {
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
	}
	return false;
}
//�񕔃O���t�̍ő�}�b�`���O�����߂�
int bipartitea_matching() {
	int res = 0;
	fill(match.begin(), match.end(), -1);
	for (int v = 0; v<x+y; v++) {
		if (match[v]<0) {//���_v�̃}�b�`���O�̃y�A�������_�łȂ��ꍇ
			fill(used.begin(), used.end(), false);
			if (bi_dfs(v)) {
				res++;
			}
		}
	}
	return res;
}

signed main() {
	cin >> x >> y >> e;
	G.resize(x + y);
	match.resize(x + y);
	used.resize(x + y);
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		v += x;
		add_edge(u, v);
	}
	cout << bipartitea_matching() << endl;
	return 0;
}

