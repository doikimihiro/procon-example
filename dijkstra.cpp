//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B&lang=jp
#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int INF = numeric_limits<int>::max();
struct edge {
	int from, to, cost;
};
vector<int> dijkstra(int s, vector<vector<edge>>&graph) {//���_s����ق��̂��ׂĂ̒��_�̍ŒZ��������ꂽvector��Ԃ�
	//�ȉ�pair<int,int>��first�͍ŒZ���� second�͒��_�ԍ�
	int n = graph.size();
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>que;
	vector<int>d(n, INF);//���_s����̍ŒZ����
	d[s] = 0;//�X�^�[�g�n�_����X�^�[�g�n�_�̋����̓[��
	que.push(pair<int, int>(0, s));
	while (!que.empty()) {
		pair<int, int>p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first) {
			continue;
		}
		for (int i = 0; i < graph[v].size(); i++) {
			edge e = graph[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(pair<int, int>(d[e.to], e.to));
			}
	    }
	}
	return d;
}

int main() {
	int n;//���_��
	cin >> n;
	vector<vector<edge>>graph;
	graph.resize(n);
	
	for (int i = 0; i < n; i++) {
		int u, k;
		cin >> u >> k;
		for (int j = 0; j < k; j++) {
			int to, cost;
			cin >> to >> cost;
			edge e;
			e.from = u;
			e.to = to;
			e.cost = cost;
			graph[u].push_back(e);
		}
	}
	vector<int> d=dijkstra(0, graph);
	for (int i = 0; i < n; i++) {
		cout << i << " " << d[i] << endl;
	}

}
