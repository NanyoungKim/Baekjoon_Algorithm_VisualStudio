#include <iostream>

using namespace std; 


int main() {

	int dp[1001][10];
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 9; j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 0; i <= 1000; i++) {
		dp[i][0] = 1;
	}

	for (int i = 2; i <= 1000; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k] % 10007;
			}
		}
	}


	int N; 
	cin >> N;

	int ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += dp[N][i];
	}
	cout << ans;

	return 0;
}