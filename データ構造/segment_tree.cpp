//http://tsutaj.hatenablog.com/entry/2017/03/29/204841
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
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
class segment_tree {
private:
	int n;
	vector<int>node;
	const int INF = numeric_limits<signed>::max();
public:
	segment_tree(vector<int>v) {
		//���̔z��v���Z�O�����g�؂ŕ\������
		// �ŉ��i�̃m�[�h���͌��z��̃T�C�Y�ȏ�ɂȂ�ŏ��� 2 �p -> ����� n �Ƃ���
		// �Z�O�����g�ؑS�̂ŕK�v�ȃm�[�h���� 2n-1 �ł���
		int sz = v.size();//�v�f��
		n = 1;
		while (n < sz) {
			n *= 2;
		}
		node.resize(2 * n - 1, INF);
		//�ŉ��i�ɒl����ꂽ��ɁA���̒i���珇�Ԃɒl������
		for (int i = 0; i < sz; i++) {
			node[i + n - 1] = v[i];
		}
		//�l������ɂ́A�����̎q�̓�l������΂���
		for (int i = n - 2; i >= 0; i--) {
			node[i] = min(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	void update(int x, int val) {//x�Ԗڂ̗v�f��val�ɍX�V����
								 //�ŉ��i�̃m�[�h�ɃA�N�Z�X����
		x += (n - 1);
		//�ŉ��i�̃m�[�h���X�V������A���Ƃ͐e�ɂ̂ڂ��čX�V���Ă���
		node[x] = val;
		while (x > 0) {
			x = (x - 1) / 2;
			node[x] = min(node[2 * x + 1], node[2 * x + 2]);
		}
	}
	/*
	�u��� [a,b) �ɂ���v�f�̍ŏ��l�𓚂���v���Ƃ��l���܂��B
	�����̂��߁A�N�G���ŗ^����ꂽ��� (���ۂɌv�Z���������) ���u�v����ԁv�A
	�e�m�[�h���J�o�[���Ă����Ԃ��u�Ώۋ�ԁv�ƒ�`���܂� (����)�B
	����������ɂ́A�ȉ��� 3 �̏�񂪕K�v�ɂȂ�܂��B

	�v����Ԃ͂ǂ̂悤�ȋ�Ԃ��H
	���܎���������m�[�h�͉��Ԗڂ��H
	����������m�[�h�͂ǂ̂悤�ȋ�Ԃ��H (�Ώۋ�Ԃ͂ǂ̂悤�ɂȂ��Ă��邩�H)

	�v����ԂƑΏۋ�Ԃ̊֌W�ɂ���ďꍇ���������܂��B
	*/
	// �v����� [a, b) ���̗v�f�̍ŏ��l�𓚂���
	// k := ����������m�[�h�̃C���f�b�N�X
	// �Ώۋ�Ԃ� [l, r) �ɂ�����
	int getmin(int a, int b, int k = 0, int l = 0, int r = -1) {
		//�ŏ��ɌĂяo���ꂽ���̑Ώۋ�Ԃ�[0,n)
		if (r < 0) {
			r = n;
		}
		// �v����ԂƑΏۋ�Ԃ������Ȃ� -> �K���ɕԂ�
		if (r <= a || b <= l) {
			return INF;
		}
		// �v����Ԃ��Ώۋ�Ԃ����S�ɔ핢 -> �Ώۋ�Ԃ𓚂��̌v�Z�Ɏg��
		if (a <= l && r <= b) return node[k];
		// �v����Ԃ��Ώۋ�Ԃ̈ꕔ��핢 -> �q�ɂ��ĒT�����s��
		// �����̎q�� vl �E �E���̎q�� vr �Ƃ��Ă���
		// �V�����Ώۋ�Ԃ́A���݂̑Ώۋ�Ԃ𔼕��Ɋ���������
		int vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
		int vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);
		return min(vl, vr);


	}
};
signed main() {
	my_io();
	int n, q;
	cin >> n >> q;
	segment_tree segtree(vector<int>(n, numeric_limits<signed>::max()));
	for (int i = 0; i < q; i++) {
		int com;
		cin >> com;
		if (com == 0) {
			int x, val;
			cin >> x >> val;
			segtree.update(x, val);
		}
		else if (com == 1) {
			int a, b;
			cin >> a >> b;
			cout << segtree.getmin(a, b + 1) << endl;
		}
	}
	return 0;
}