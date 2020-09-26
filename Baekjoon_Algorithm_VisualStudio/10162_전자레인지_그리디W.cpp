#include <iostream>

using namespace std;

int main() {

	int T, a = 0, b = 0, c = 0;
	cin >> T;

	if (T % 10 != 0) cout << -1;
	else {

		a = T / 300;
		T %= 300;
		b = T / 60;
		T %= 60;
		c = T / 10;

		cout << a << " " << b << " " << c;

	}



	return 0;
}