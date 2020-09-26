#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {


	int T, num, g1, g2;
	cin >> T;





	for (int testcase = 0; testcase < T; testcase++) {

		cin >> num;	//신입사원 수


		int cnt = 0;

		unordered_map<int, int> umap;
		unordered_map<int, int> ::iterator it;
		unordered_map<int, int> ::iterator it2;

		vector<unordered_map<int, int> ::iterator> vec;

		for (int i = 0; i < num; i++) {

			cin >> g1 >> g2;
			umap.insert(pair<int, int>(g1, g2));



		}
		for (it = umap.begin(); it != umap.end(); it++) {
			vec.push_back(it);
		}


		for (int i = 0; i < vec.size(); i++) {
			for (int j = 0; j < vec.size(); j++) {
				if (i != j) {

					if ((vec[i]->first > vec[j]->first) && (vec[i]->second > vec[j]->second)) {  //ㅂ;교기준인 i가 둘다 j 보다 크면 : 탈락
						vec.erase(vec.begin() + i);
						i--;
						break;
					}

				}
			}
		}


		cout << vec.size() << endl;
		vec.clear();
		umap.clear();

	}




	return 0;
}