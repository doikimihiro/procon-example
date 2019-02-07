#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
int main() {
	int N, W;
	scanf("%d%d", &N, &W);
	vector<int>v(N);
	vector<int>w(N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &v[i],&w[i]);
	}
	// dp[n+1][W+1] : �ŏ��͑S�� 0
	vector<vector<int>> dp(N + 1, vector<int>(W + 1));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= W; j++) {
			if (j + w[i] <= W) {
				// ���� i �Ԗڂ̕i��������Ȃ�A������Ƃ��̂��Ƃ��l����
				dp[i+1][j + w[i]] = max(dp[i+1][j + w[i]], dp[i][j] + v[i]);
			}
			// ���Ȃ������Ƃ��̂��Ƃ��l����
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
		}
	}
	// ���߂�̂� n �Ԗڂ܂łŏd�� W �ȉ��̏ꍇ�̉��l�̑��a�̍ő�l
	 printf("%d\n",dp[N][W]);
	 return 0;
}






