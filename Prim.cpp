#include<vector>
#include<iostream>
#include<queue>
#include<functional>
using namespace std;

constexpr int INF = 1e9;

struct edge
{
	int from, to, cost;
	bool operator>(const edge& other)
	const{
		return cost > other.cost;
	}
};

using edges= vector<edge>;
using graph = vector<edges>;

void add_edge(graph& g,int from,int to,int cost)
{
	g[from].push_back(edge{ from,to,cost });
	g[to].push_back(edge{ to,from,cost });
}

edges prim(const graph& g)
{
	const int N = g.size();
	vector<bool>used(N);
	used[0] = true;
	priority_queue<edge, vector<edge>, greater<edge>>que;
	for (auto e:g[0])
	{
		que.push(e);
	}
	edges mst;
	while (!que.empty())
	{
		auto e = que.top();
		que.pop();
		if (used[e.to])
		{
			continue;
		}
		mst.push_back(e);
		used[e.to] = true;
		for (auto new_e:g[e.to])
		{
			que.push(new_e);
		}


	}
	return mst;


	
}
int main()
{
	int V, E;
	cin >> V >> E;
	graph g(V);
	for (int i = 0; i < E; i++)
	{
		int s, t, w;
		cin >> s >> t >> w;
		add_edge(g, s, t, w);
	}
	const auto mst = prim(g);
	int ans = 0;
	for (auto& e : mst)
	{
		ans += e.cost;
	}
	cout << ans << endl;
	return 0;
}
/*
�����o�֐��i����͉��Z�q�I�[�o�[���[�h�ł��������j�̂��̈ʒu�ɂ��� const �̈Ӗ���
���̊֐��̌Ăяo���ɂ���āC�I�u�W�F�N�g�̓�����Ԃ��ς��Ȃ��Ƃ����ۏ؂ɂȂ�܂�
�܂荡��ł���΁Coperator > ���Ăяo����Ă��Cedge �̒��g�̃f�[�^�͕ς��Ȃ���C�Ƃ������Ƃ��C�֐��̐錾���_�Ŗ������Ă���Ƃ������Ƃł�
�G���[���o�闝�R�ɂ��Ăł���
std::sort �̃f�t�H���g�̋����ł́Cstd::less ���g���܂�
�i�܂� < �ł���
std::less<edge> �̌Ăяo�����̈����̌^�� (const edge& e1, const edge& e2) �ł���C�ǂ���� const ���t���Ă��܂�
�܂�Cstd::less �̒��ŁCe1 �ɂ� e2 �ɂ��ύX�������邱�Ƃ��o���Ȃ��Ƃ������Ƃ��Ӗ����܂��D
�������̎��ɁCe1 �i���邢�� e2�j�� const �łȂ������o�֐����Ăяo�����Ƃ��o���Ă��܂��ƁC�I�u�W�F�N�g�̏�Ԃ��ς��\��������Ce1 �� const �ł��邱�Ƃɔ������e�ł��܂���D
���������ăG���[�ƂȂ�܂��D
const �������ꍇ�C���̊֐����Ăяo���Ă�������Ԃ��ς��Ȃ����Ƃ��R���p�C���ɂ킩��̂ŁCstd::less<edge> �̂Ȃ��� e1 < e2 ���Ăяo����Ă��C���Ȃ��Ƃ����킯�ł�
�����������̃R�[�h�� greater �������͂��Ȃ̂ŁCless �� greater �ɒu�������ĖႦ��Γ����ł�
�Ђ��`�����ɂȂ��Ă��܂����iC++�����I�^�N�����i���߂�


doi [19:01]
�@less �̈�����e1���邢��e2��const�ł��邱�Ƃ�bool operator>(const edge& other)�ň�����const�ł��邱�Ƃɂ���Ă��߂���Ȃ��̂ł��傤���H

suibaka [19:02]
e1 > e2 �Ƃ����Ƃ��Cother �� e2 �ɂȂ��Ă������͂����̂ł����Ce1 �͂�������Ȃ��̂Ń_���ł���
�Ⴆ�� operator �̒�`�� edge �̊O�ɏo���āC

bool operator>(const edge& e1, const edge& e2) {
return e1.cost > e2.cost;
}

�Ƃ��Ζ��Ȃ��ł��D


suibaka [19:33]
�����o�֐��́C�Öق̂����Ɂi�l��ɂ͌����Ȃ����ǁj�������ɂ��̃I�u�W�F�N�g�̃|�C���^���n����Ă��܂�
w.f(42) �Ȃ� f(&w, 42) �݂����ȃC���[�W�ł�
�����܂ł͑��v�ł���

doi [19:34]
���v�ł�

suibaka [19:35]
�����o�֐��� const �C������ƁC���� this �|�C���^�� const ���t���܂�
����ƁCthis �|�C���^���w����̃f�[�^�̕ύX���_���Ƃ����Ӗ��ɂȂ�܂���
f() �� const �C������Ă���̂ŁCthis->data = arg �� this �� const �Ȃ̂łł��܂���D
g �͖��Ȃ��ł��Dthis �� const ����Ȃ�����D
#include <iostream>
using namespace std;

class widget {
public:
widget() : data(0) {}


void f(int arg) const {
data = arg; // error
}
void g(int arg) {
data = arg; // ok
}

private:
int data;
};

// widget::f, g �͂��������Ӗ����Ǝv���Ɨǂ�

// void f(const this �|�C���^, int arg) {
//	this->data = arg;
//}
// void g(widget* w, int arg) {
// this->data = arg;
//}
//
// �����o�֐��̑�1�����ɂ́C�Öق̂����� this �|�C���^���n����Ă���D
// �����o�֐��� const �C������ƁC���� this �|�C���^�� const �����D
// ������Cthis->data = arg �� const �C������Ă���ƃG���[�ɂȂ�D
// g �̕��� const ����Ȃ��̂ŁCthis->data ��OK

int main() {
widget w;
w.f(42); // error
w.g(42); // ok
return 0;
}
*/