#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {


	int T, num, g1, g2;
	cin >> T;





	for (int testcase = 0; testcase < T; testcase++) {

		cin >> num;	//���Ի�� ��
		unordered_map<int, int> umap;

		for (int i = 0; i < num; i++) {

			cin >> g1 >> g2;	//����, ���� ����
			int cnt = 0;

			if (umap.size() == 0) {				//ó���� �׳� ����
				umap.insert(pair<int, int>(g1, g2));
			}

			else {
				unordered_map<int, int> ::iterator it;
				unordered_map<int, int> ::iterator temp;




				for (it = umap.begin(); it != umap.end(); it++) {

					temp = it;
					if ((it->first > g1) || (it->second > g2)) {		//���� �����Ϸ��°� ������ �ִ� �ͺ��� ���� �ΰ� �� �ϳ��� ũ�� 					
						cnt++;

					}
					if ((it->first > g1) && (it->second > g2)) {		//�����ؾ���
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