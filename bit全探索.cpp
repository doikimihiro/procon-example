#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n = 5;

	// {0, 1, ..., n-1} �̕����W���̑S�T��
	for (int bit = 0; bit < (1 << n); ++bit)
	{
		/* bit �ŕ\�����W���̏��������� */


		/* ������Ƃł��Ă��邱�Ƃ��m�F���Ă݂� */
		// bit �̕\���W�������߂�
		vector<int> S;
		for (int i = 0; i < n; ++i) {
			if (bit & (1 << i)) { // i �� bit �ɓ��邩�ǂ���
				S.push_back(i);
			}
		}

		// bit �̕\���W���̏o��
		cout << bit << ": {";
		for (int i = 0; i < (int)S.size(); ++i) {
			cout << S[i] << " ";
		}
		cout << "}" << endl;
	}
}