//https://qiita.com/nomikura/items/1518bc8a6e04d2580b0d
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
const long double PI = acos(-1.0);
inline void my_io() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout << fixed << setprecision(10);
}
char Board[H][W]; // �Q�[���̏�Ԃ�����

				  // �Ֆʂ�]������֐��B�����̓��_�����߂�B
int value() {
	// ���g������
}

int MIN_MAX(int turn) {
	// �I�ǂ�����Ֆʂ̒l��Ԃ�
	if (turn == END) return value();

	if (/*�����̋ǖ�*/) {
		int Max = -INF;
		for () {
			// ���̔ՖʂŎ������łĂ邷�ׂĂ̏�Ԃ��
			Max = max(Max, MIN_MAX(turn + 1));
		}
		return Max;
	}
	else { // ����̋ǖ�
		int Min = INF;
		for () {
			// ���̔Ֆʂő��肪�łĂ邷�ׂĂ̏�Ԃ��
			Min = min(Min, MIN_MAX(turn + 1));
		}
		return Min;
	}
}
signed main() {
	my_io();
	int myPoint = MIN_MAX(0);

}
