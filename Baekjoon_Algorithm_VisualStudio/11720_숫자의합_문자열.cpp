#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {

	int N;
	cin >> N;

	string num;
	cin >> num;

	int sum = 0;
	for (int i = 0; i < num.length(); i++) {

		sum += (int)num[i] - 48;
	}
	cout << sum;





	return 0;
}