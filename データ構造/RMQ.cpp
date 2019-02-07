//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
#include<vector>
#include<iostream>
#include<algorithm>
#include <stdint.h>
#include <math.h>

using namespace std;
const int INF = (1<<31) - 1;
class segment_tree {
private:
	int n;
	vector<int> node;
public:
	//���z����Z�O�����g�؂ŕ\������
	segment_tree(vector<int>v) {
		
		int sz = v.size();
		//�ŉ��i�̃m�[�h���͌��z��̃T�C�Y�ȏ�ɂȂ�ŏ���2�p->�����n�Ƃ���
		n = 1;
		while (n < sz) {
			n *= 2;
		}
		node.resize(2 * n - 1, INF);
		//�ŉ��i��������
		for (int i = 0; i < sz; i++) {
			node[i + n - 1] = v[i];
		}
		//�e�̒l�����߂Ă���
		for (int i = n - 2; i >= 0; i--) {
			node[i] = min(node[2 * i + 1], node[2 * i + 2]);
		}
	}

	void update(int x, int val) {
		x += (n - 1);
		node[x] = val;
		while (x > 0) {
			x = (x - 1) / 2;
			node[x] = min(node[2 * x + 1], node[2 * x + 2]);
		}
	}
	//[a,b)�̍ŏ��l�����߂�
	//k�Ԗڂ̃m�[�h�@�͈͂�[l,r)
	int query(int a, int b, int k=0, int l=0, int r=-1) {
		if (r < 0) {
			r = n;
		}
		if (r <= a || b <= l)
		{
			return INF;
		}
		if (a <= l && r <= b)
		{
			return node[k];
		}
		else
		{
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return min(vl, vr);
		}
	}

};

int main() {
	int N;
	int Q;
	cin >> N >> Q;
	segment_tree seg(vector<int>(N, INF));
	for (int i = 0; i < Q; i++) {
		int c, x, y;
		cin >> c >> x >> y;
		if (c == 0) {
			seg.update(x, y);
		}
		else {
			cout << seg.query(x, y + 1) << endl;
		}
	}
}





