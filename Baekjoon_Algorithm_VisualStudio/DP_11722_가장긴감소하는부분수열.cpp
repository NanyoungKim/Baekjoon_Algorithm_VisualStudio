#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N; cin >> N;
	vector<int> vec;
	vector<int> vecArr[1000];
	int dp[1001] = { 0 };


	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		vec.push_back(num);
	}
	dp[0] = 1;
	vecArr[0].push_back(vec[0]);



	vector<int> longVec = vecArr[0];
	for (int i = 1; i < vec.size(); i++) {


		vecArr[i].push_back(vec[i]);

		dp[i] = 1;

		
		for (int j = 0; j < i; j++) {
			if (vec[i] < vec[j]) {
				if (dp[j] + 1 > dp[i]) {
					vecArr[i].clear();
					vecArr[i] = vecArr[j];
					vecArr[i].push_back(vec[i]);
					dp[i] = dp[j] + 1;
				}
			}
		}
		

		if (longVec.size() < vecArr[i].size()) {
			longVec = vecArr[i];
		}
		
		
	}





	cout << longVec.size();

	return 0;
}