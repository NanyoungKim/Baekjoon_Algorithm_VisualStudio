#include <iostream>
#include <string>
#include <bitset>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

string tentoBinary(int n) {

	int remain;
	stack<int> stk;
	string str = "";

	while (n != 0) {
		
		remain = n % 2;
		stk.push(remain);
		n = n / 2;

		

	}

	while(!stk.empty()){
		str += to_string(stk.top());
		stk.pop();
	}

	return str;
}

int solution(int N) {

	string binary = tentoBinary(N);
	int cnt = 1;
	bool chk = false;
	vector<int> cntVec;

	int len = binary.length();
	
	for (int i = 0; i < len - 1; i++) {

		if (binary[i] == '0' && binary[i + 1] == '0') {
			cnt++;
			chk = true;

		}
		else if (chk == false && (binary[i] == '0' && binary[i + 1] == '1')) {

			cntVec.push_back(cnt);
		}
		if (chk == true && binary[i + 1] == '1') {
			cntVec.push_back(cnt);
			cnt = 1;
			chk = false;
		}

	}

	sort(cntVec.begin(), cntVec.end());
	
	for (int i = 0; i < cntVec.size(); i++) {
		cout << cntVec[i] << " ";
	}


	return cntVec.size()!= 0 ? cntVec[cntVec.size() - 1] : 0;



}


int main() {

	cout << solution(1162);




	return 0;
}