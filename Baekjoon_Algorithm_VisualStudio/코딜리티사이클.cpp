#include <iostream>
#include <vector>
using namespace std;


vector<int> solution(vector<int> &A, int K) {
	// write your code in C++14 (g++ 6.2.0)
	int size = A.size();
	int tmp;
	for (int i = 0; i < K; i++) {


		for (int j = size - 1; j > 0; j--) {

			tmp = A[size - 1];
			A[j] = A[j - 1];

		}
		A[0] = tmp;
	

	}

	return A;


}


int main() {

	vector<int> Arr = { 3,8,9,7,6 };
	vector<int> res = solution(Arr,3);


	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}


	return 0;
}