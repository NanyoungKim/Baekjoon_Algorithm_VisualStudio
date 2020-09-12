#include <iostream>

using namespace std;


int answer = 100000000;
int N, K;
void func(int k, int cnt) {

	if (k == N) {

		if (answer > cnt) {
			answer = cnt; //더 작은게 답

		}
		return;

	}
	if (k < N) return;

	//if (k <= 0) return;
	if (k % 2 == 0) {
		func(k / 2, cnt + 1);

	}
	else {

		func(k - 1, cnt + 1);
		func(k + 1, cnt + 1);

	}




}



int main() {


	cin >> N >> K;

	func(K, 0);

	cout << answer;




	return 0;
}