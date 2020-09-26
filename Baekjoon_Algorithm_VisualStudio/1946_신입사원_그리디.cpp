#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {


	int T, num, g1, g2;
	cin >> T;





	for (int testcase = 0; testcase < T; testcase++) {

		cin >> num;	//신입사원 수
		unordered_map<int, int> umap;

		for (int i = 0; i < num; i++) {

			cin >> g1 >> g2;	//서류, 면접 순위
			int cnt = 0;

			if (umap.size() == 0) {				//처음엔 그냥 넣음
				umap.insert(pair<int, int>(g1, g2));
			}

			else {
				unordered_map<int, int> ::iterator it;
				unordered_map<int, int> ::iterator temp;




				for (it = umap.begin(); it != umap.end(); it++) {

					temp = it;
					if ((it->first > g1) || (it->second > g2)) {		//새로 삽입하려는게 기존에 있던 것보다 순위 두개 중 하나라도 크면 					
						cnt++;

					}
					if ((it->first > g1) && (it->second > g2)) {		//삭제해야함
						umap.erase(it);
						it = temp;
						cnt--;
					}

				}
				if (cnt == umap.size()) {
					umap.insert(pair<int, int>(g1, g2));
				}

			}



		}

		cout << umap.size() << endl;
		umap.clear();

	}



	return 0;
}