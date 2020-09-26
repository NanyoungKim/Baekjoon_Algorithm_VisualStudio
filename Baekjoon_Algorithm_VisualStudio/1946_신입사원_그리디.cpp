#include <iostream>
#include <vector>
#include <map>

using namespace std;


int getMin(int a, int b) {
	return a < b ? a : b;
}

int main() {


	int T, num, g1, g2;
	cin >> T;





	for (int testcase = 0; testcase < T; testcase++) {

		cin >> num;	//신입사원 수


		int cnt = num;

		map<int, int> umap;
		map<int, int> ::iterator it;
		map<int, int> ::iterator it2;

		vector<map<int, int> ::iterator> vec;

		for (int i = 0; i < num; i++) {
			cin >> g1 >> g2;
			umap.insert(pair<int, int>(g1, g2));

		}
		for (it = umap.begin(); it != umap.end(); it++) {
			vec.push_back(it);
		}

		int minG2 = vec[0]->second;

		for (int i = 1; i < vec.size(); i++) {

			if (vec[i]->second > minG2) cnt--;
			minG2 = getMin(minG2, vec[i]->second);

		}
		


		cout << cnt << endl;
		vec.clear();
		umap.clear();

	}




	return 0;
}