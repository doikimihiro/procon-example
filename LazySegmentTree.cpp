//http://tsutaj.hatenablog.com/entry/2017/03/30/224339
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=jp
#include<bits/stdc++.h>
#pragma warning(disable:4996)
#ifdef _MSC_VER
#  define __builtin_popcount __builtin_popcountll
#  define __builtin_popcountll __popcnt
#endif
#define int long long
using namespace std;
using ll = long long;
using ld = long double;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
inline void my_io() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout << fixed << setprecision(10);
}
class LazySegmentTree{
private:
	int n;
	vector<ll>node, lazy;
public:
	LazySegmentTree(vector<ll>v) {
		int sz = (int)v.size();
		n = 1; while (n < sz)n *= 2;
		node.resize(2 * n - 1);
		lazy.resize(2 * n - 1, 0);

		for (int i = 0; i<sz; i++)node[i + n - 1] = v[i];
		for (int i = n - 2; i >= 0; i--)node[i] = node[i * 2 + 1] + node[i * 2 + 2];
	}
	//k�Ԗڂ̃m�[�h�ɂ��Ēx���]�����s��
	void eval(int k, int l, int r) {
		//�x���z�񂪋�łȂ��ꍇ�A���m�[�h�y�юq�m�[�h�ւ̒l�̓`�d��������
		if (lazy[k] != 0) {
			node[k] += lazy[k];
			//�ŉ��i���ǂ����̃`�F�b�N������
			//�q�m�[�h�͐e�m�[�h��1/2�͈̔͂ł��邽�ߓ`�d������Ƃ��͔����ɂ���
			if (r - l > 1) {
				lazy[2 * k + 1] += lazy[k] / 2;
				lazy[2 * k + 2] += lazy[k] / 2;
			}

			// �`�d���I������̂ŁA���m�[�h�̒x���z�����ɂ���
			lazy[k] = 0;
		}
	}
	void add(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		

		
		//�͈͊O�Ȃ牽�����Ȃ�
		if (b <= l || r <= a) {
			eval(k, l, r);
			return;
		}
		//���S�ɔ핢���Ă���Ȃ�΁A�x���]���ɒl����ꂽ��ɕ]��
		if (a <= l && r <= b) {
			lazy[k] += (r - l)*x;
			eval(k,l,r);//���낳�Ȃ��Ǝ���else��node[k] = node[2 * k + 1] + node[2 * k + 2];�Ŗ�肪�N���� node[k]�𐳂����l�ɂ���
		}
		//�����łȂ��Ȃ�q�m�[�h�̒l���ċA�I�Ɍv�Z���Čv�Z�ς݂̒l��������Ă���
		else {
			// k �Ԗڂ̃m�[�h�ɑ΂��Ēx���]�����s��
			eval(k, l, r);
			//k�Ԗڂ̃m�[�h�ɑ΂��Ēx���]�����s��
			add(a, b, x, 2 * k + 1, l, (l + r) / 2);
			add(a, b, x, 2 * k + 2, (l + r) / 2, r);
			node[k] = node[2 * k + 1] + node[2 * k + 2];
		}
	}
	ll getsum(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = n;
		if (b <= l || r <= a) return 0;

		// �֐����Ăяo���ꂽ��]���I
		eval(k, l, r);
		if (a <= l && r <= b) return node[k];
		ll vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
		ll vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
		return vl + vr;
	}
};
signed main() {
	my_io();
	int n, q;
	cin >> n >> q;
	vector<int>a(n, 0);
	LazySegmentTree Lsegtree(a);
	for (int i = 0; i < q; i++) {
		int b;
		cin >> b;
		if (b == 0) {
			int s, t, x;
			cin >> s >> t >> x;
			s--;
			Lsegtree.add(s, t, x);
		}
		else if(b == 1){
			int s, t;
			cin >> s >> t;
			s--;
			cout << Lsegtree.getsum(s, t) << endl;
		}
	}
	return 0;
}

