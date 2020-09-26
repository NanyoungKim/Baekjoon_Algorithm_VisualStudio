#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {


	
	
	int T = 0;
	cin >> T;


	for (int test = 0; test < T; test++) {

		string str;
		cin >> str;

		int cnt = 0;
		int sum = 0;

		for (int i = 0; i < str.length(); i++) {

			if (str[i] == 'O') {

				++cnt;
				sum += cnt;


			}
			else {
				cnt = 0;
			}

		}

		cout << sum << "\n";
	}
	

	return 0;
}