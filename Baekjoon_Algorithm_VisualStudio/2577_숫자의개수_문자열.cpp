#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	
	int a, b, c, res, cnt;
	string str;
	vector<int> vec;
	cin >> a >> b >> c;

	res = a * b * c;

	str = to_string(res);

	for (int i = 0; i < str.length(); i++) {
		vec.push_back((int)str[i]-48);
	}
	
	for (int i = 0; i < 10; i++) {
		
		cnt = count(vec.begin(), vec.end(), i);
		cout << cnt << "\n";
		
	}



	 

	return 0;
}