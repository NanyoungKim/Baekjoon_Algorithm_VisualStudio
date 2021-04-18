#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> vecArrA[100];

int rowSize() {
	int row = 0;
	for (int i = 0; i < 100; i++) {
		if (vecArrA[i].size() != 0) {
			row++;
		}
		else {
			return row;
		}
	}
}
int colSize() {
	int col = 0;
	return vecArrA[0].size();

}

void resetArr(int size, vector<int> origin[], vector<int> tmp[]) {

	for (int i = 0; i < size; i++) {
		origin[i] = tmp[i];
	}
}



void operationR(int rowsize) {
	vector<int> tmpArr[100];
	int maxi = 0;
	vector<int> s;
	for (int i = 0; i < rowsize; i++) {
		sort(vecArrA[i].begin(), vecArrA[i].end());

		vector<pair<int,int>> vec;

		for (int j = 0; j < vecArrA[i].size(); j++) {
			int num = vecArrA[i][j];
			int cnt = count(vecArrA[i].begin(), vecArrA[i].end(), num);
			if (num != 0) {
				vec.push_back(make_pair(cnt,num));
			}
			j += (cnt - 1);
		}
		sort(vec.begin(), vec.end());


		tmpArr[i].clear();
		for (int k = 0; k < vec.size(); k++) {
			tmpArr[i].push_back(vec[k].second);
			tmpArr[i].push_back(vec[k].first);
		}
		s.push_back(vec.size()*2);
		if (vec.size()*2 > maxi) maxi = vec.size()*2;			//행의 크기 구하기
	}

	for (int i = 0; i < rowsize; i++) {
		for (int j = 0; j < (maxi - s[i]); j++) {
			tmpArr[i].push_back(0);
		}
	}


	resetArr(rowsize, vecArrA, tmpArr);
	
}
void operationC(int colsize) {

	vector<int> tmpArr[100];
	vector<int> s;

	for (int col = 0; col < colsize; col++) {
		vector<int> tmpVec;
		for (int row = 0; row < rowSize(); row++) {
			tmpArr[col].push_back(vecArrA[row][col]);
		}
		sort(tmpArr[col].begin(), tmpArr[col].end());
	}

	

	int maxi = 0;
	for (int i = 0; i < colsize; i++) {

		sort(tmpArr[i].begin(), tmpArr[i].end());
		vector<pair<int, int>> vec;
		for (int j = 0; j < tmpArr[i].size(); j++) {
			int num = tmpArr[i][j];
			int cnt = count(tmpArr[i].begin(), tmpArr[i].end(), num);
			if (num != 0) {
				vec.push_back(make_pair(cnt, num));
			}
			j += (cnt - 1);
		}
		sort(vec.begin(), vec.end());
		tmpArr[i].clear();
		for (int k = 0; k < vec.size(); k++) {
			tmpArr[i].push_back(vec[k].second);
			tmpArr[i].push_back(vec[k].first);
		}

		s.push_back(vec.size() * 2);
		if (maxi < vec.size() * 2) maxi = vec.size() * 2;

	}

	for (int i = 0; i < colsize; i++) {
		for (int j = 0; j < maxi - s[i]; j++) {
			tmpArr[i].push_back(0);
		}
	}


	for (int i = 0; i < maxi; i++) {
		vecArrA[i].clear();
		for (int j = 0; j < colsize; j++) {
			vecArrA[i].push_back(tmpArr[j][i]);
		}
	}


}


int main() {

	int r, c, k;
	cin >> r >> c >> k;


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int num; cin >> num;
			vecArrA[i].push_back(num);
		}
	}

	bool chk = false;
	int i;
	for (i = 0; i <= 100; i++) {
		if (vecArrA[r-1][c-1] == k) {
			chk = true;
			break;
		}
		int rs = rowSize();
		int cs = colSize();

		if (rs>=cs) {
			operationR(rs);
			for (int i = 0; i < rowSize(); i++) {
				for (int j = 0; j < vecArrA[i].size(); j++) {
					cout << vecArrA[i][j] << " ";
				}cout << endl;
			}
			cout << "\n\n";
		}

		else {
			operationC(cs);
			for (int i = 0; i < rowSize(); i++) {
				for (int j = 0; j < vecArrA[i].size(); j++) {
					cout << vecArrA[i][j] << " ";
				}cout << endl;
			}
			cout << "\n\n";
		}


		
	}



	if (!chk) cout << -1;
	else cout << i;
	


	return 0;
}