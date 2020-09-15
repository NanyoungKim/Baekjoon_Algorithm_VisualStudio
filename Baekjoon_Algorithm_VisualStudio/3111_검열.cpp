#include <iostream>
//#include <sstream>
#include <string>
#include <algorithm>

using namespace std;



int firstFind(string T, string A) {
	int cnt = 0;
	int ans = 0;
	bool chk = false;

	for (int i = 0; i < T.length()-A.length() + 1; i++) {
		for (int j = 0; j < A.length(); j++) {
			if (T[i] != A[j]) {
				cnt = 0;
				break;
			}
			else {
				if (cnt == 1) {
					ans = i;
				}
				if (cnt == A.length()) {
					chk = true;
					return i;
				}
			}
		}
	}
	if (!chk) return -1;
}


int lastFind(string T, string A) {


	for (int i = T.length() - 1; i > T.length() - A.length() - 1; i--) {
		for (int j = A.length() - 1, j >= 0; j--) {
			]



		}
	}

}



int main() {

	string A, T;
	
	int first, last;

	cin >> A >> T;

	bool chk = false;
	while (1) {
		chk = !chk;

		if (chk) {

			first = firstFind(T, A);
			if (first != -1) {
				T.erase(first, A.length());
			}
			else {
				break;
			}


			/*first = T.find(A);
			if (first == string::npos)  break;
			else {
				T.erase(first, A.length());
			}*/
		}
		else {
			//int last = T.find_last_of(A);
			/*last = T.rfind(A);
			if (last == string::npos) break;
			else {
				T.erase(last, A.length());
			}*/
		}
	}
	
	








	cout << T;




	return 0;
}