#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {


	int T, num, g1, g2;
	cin >> T;





	for (int testcase = 0; testcase < T; testcase++) {

		cin >> num;	//신입사원 수


		int cnt = 0;

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

		for (int j = 0; j < vec.size()-1; j++) {
			for (int i = j; i < vec.size() - 1; i++) {

				if (vec[j]->second < vec[i + 1]->second) {
					vec.erase(vec.begin() + i + 1);
					i--;
				}
			}
		}
		


		cout << vec.size() << endl;
		vec.clear();
		umap.clear();

	}




	return 0;
}