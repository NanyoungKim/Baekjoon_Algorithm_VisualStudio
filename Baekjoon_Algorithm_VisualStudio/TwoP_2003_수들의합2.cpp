#include <iostream>


using namespace std;


int main() {


	int sum;
	int ans = 0;
	int N, M;
	cin >> N >> M;
	int arr[10000] = { 0 };
	for (int i = 0; i < N; i++) { cin >> arr[i]; }

	for (int i = 0; i < N; i++) {
		sum = 0;
		for (int j = i; j < N; j++) {
			sum += arr[j];
			if (sum == M) ans++;
			if (sum > M) break;
		}
		
	}

	cout << ans;

	return 0;
}