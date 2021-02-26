#include <iostream>
#include <vector>
using namespace std;



int main() {


	vector<int> vec;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		vec.push_back(num);
	}

	vector<int> vecArr[1000];
	int dp[1000] = { 0 };
	dp[0] = 1;
	vecArr[0].push_back(vec[0]);

	int dp2[1000] = { 0 };
	dp2[N - 1] = 1;
	vector<int> vecArr2[1000];
	vecArr2[N - 1].push_back(vec[N - 1]);


	int arr1[1000] = { 0 }; arr1[0] = 1;
	int arr2[1000] = { 0 }; arr2[N - 1] = 1;


	for (int i = 1; i < N; i++) {

		dp[i] = 1;
		vecArr[i].push_back(vec[i]);


		for (int j = 0; j < i; j++) {
			if (vec[i] > vec[j]) {
				if (dp[j] + 1 > dp[i]) {
					vecArr[i].clear();
					vecArr[i] = vecArr[j];
					vecArr[i].push_back(vec[i]);
					dp[i] = dp[j] + 1;
				}
			}
		}
		for (int k = 0; k < vecArr[i].size(); k++) { cout << vecArr[i][k] << " "; } cout << endl;

		arr1[i] = vecArr[i].size();



	}




	for (int i = N - 2; i >= 0; i--) {

		dp2[i] = 1;
		vecArr2[i].push_back(vec[i]);

		for (int j = N - 1; j > i; j--) {
			if (vec[i] > vec[j]) {
				if (dp2[j] + 1 > dp2[i]) {
					vecArr2[i].clear();
					vecArr2[i] = vecArr2[j];
					vecArr2[i].push_back(vec[i]);
					dp2[i] = dp[j] + 1;
				}
			}
		}

		for (int k = 0; k < vecArr2[i].size(); k++) { cout << vecArr2[i][k] << " "; } cout << endl;
		arr2[i] = vecArr2[i].size();
	}





	int m = arr1[0] + arr2[0];
	for (int i = 1; i < N; i++) {
		if (m < arr1[i] + arr2[i]) m = arr1[i] + arr2[i];
	}
	cout << m - 1;


	return 0;
}