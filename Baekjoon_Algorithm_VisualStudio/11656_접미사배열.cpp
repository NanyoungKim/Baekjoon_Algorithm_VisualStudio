#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {


	string input = "baekjoon";
	vector<string> ansVec;
	
	int n = input.length();//8
	int start;
	string str = "";
	
	for (start = 0; start < n; start++) {
		for (int cnt = start; cnt < n; cnt++) {
			str += input[cnt];
		}
		ansVec.push_back(str);
	//	cout << str << endl;
		str = "";
	}


	sort(ansVec.begin(), ansVec.end());
	for (int i = 0; i < ansVec.size(); i++) cout << ansVec[i] << endl;

	return 0;
}