#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;


int A[21][21];
//�� �� �� ��
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int divideMap[21][21];
int N;


//1~N ���̿� �������� ���� üũ
bool chk(int r, int c) {
	if (r<1 || r>N || c<1 || c>N) return false;
	return true;
}

//1~4 ���ű��� ǥ��. 5�� �̹� ǥ�õǾ� �ִ� ��� �н�
int  getpartOne(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int i = 1; i < x + d1; i++) {
		for (int j = 1; j <= y; j++) {
			if (divideMap[i][j] != 5) {		//5���� ������ ���� ��
				divideMap[i][j] = 1;
				sum += A[i][j];
			}
		}
	}
	return sum;
}
int getpartTwo(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int i = 1; i <= x + d2; i++) {		//1~4
		for (int j = y + 1; j <= N; j++) {	//6~7
			if (divideMap[i][j] != 5) {
				divideMap[i][j] = 2;
				sum += A[i][j];
			}
		}
	}
	return sum;
}
int getpartThree(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int i = x + d1; i <= N; i++) {		//i = 5,6,7
		for (int j = 1; j < y - d1 + d2; j++) {
			if (divideMap[i][j] != 5) {
				divideMap[i][j] = 3;
				sum += A[i][j];
			}

		}
	}return sum;
}
int getpartFour(int x, int y, int d1, int d2) {
	int sum = 0;

	for (int i = x + d2 + 1; i <= N; i++) {
		for (int j = y - d1 + d2; j <= N; j++) {
			if (divideMap[i][j] != 5) {
				divideMap[i][j] = 4;
				sum += A[i][j];
			}
		}
	}return sum;
}

//5���ű��� ǥ��. ���� �Ѿ�� �ٸ� ���ű����� ũ�Ⱑ �ּ� 1�̻� ���� �ʴ� ��� false ����
bool divide(int x, int y, int d1, int d2) {
	memset(divideMap, 0, sizeof(divideMap));

	divideMap[x][y] = 5;
	int initR = x;
	int initC = y;

	//1
	for (int k = 0; k < d1; k++) {
		int nr = initR + 1;
		int nc = initC - 1;
		if (!chk(nr, nc)) {
			return false;
		}
		initR = nr;
		initC = nc;
		for (int col = nc; col <= y; col++) {
			divideMap[nr][col] = 5;
		}

	}
	//2
	int initR2 = x;
	int initC2 = y;
	for (int k = 0; k < d2; k++) {
		int nr = initR2 + 1;
		int nc = initC2 + 1;
		if (!chk(nr, nc)) {
			return false;
		}
		initR2 = nr;
		initC2 = nc;
		for (int col = y; col <= nc; col++) {
			divideMap[nr][col] = 5;
		}

	}

	//3
	int startR = x + d1;
	int startC = y - d1;
	for (int k = 0; k < d2; k++) {
		int nr = startR + 1;
		int nc = startC + 1;
		if (!chk(nr, nc)) {
			return false;
		}
		startR = nr;
		startC = nc;
		for (int col = nc; col <= y - d1 + d2; col++) {
			divideMap[nr][col] = 5;
		}

	}


	int startR2 = x + d2;
	int startC2 = y + d2;
	for (int k = 0; k < d1; k++) {
		int nr = startR2 + 1;
		int nc = startC2 - 1;
		if (!chk(nr, nc)) {
			return false;
		}
		startR2 = nr;
		startC2 = nc;
		for (int col = y - d1 + d2; col <= nc; col++) {
			divideMap[nr][col] = 5;
		}

	}

	return true;

}



int main() {

	cin >> N;
	int sumA = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			sumA += A[i][j];
		}
	}

	//�� ĭ�� ���鼭 ������ ����

	int mini = 987654321;
	for (int x = 1; x <= N; x++) {		//��
		for (int y = 1; y <= N; y++) {		//��

			for (int d1 = 1; d1 <= 18; d1++) {
				for (int d2 = 1; d2 <= 18; d2++) {
					if (x + d1 + d2 > N) break;


					if (!divide(x, y, d1, d2)) continue;

					int sum1 = getpartOne(x, y, d1, d2);
					int sum2 = getpartTwo(x, y, d1, d2);
					int sum3 = getpartThree(x, y, d1, d2);
					int sum4 = getpartFour(x, y, d1, d2);
					int sum5 = sumA - (sum1 + sum2 + sum3 + sum4);

					//�� ���ű��� ũ��� �ּ� 1ĭ �̻�
					if (sum1 >= 1 && sum2 >= 1 && sum3 >= 1 && sum4 >= 1 && sum5 >= 1) {// ���ű��� ������ ��� �ϳ� �����ؾ� �ϰ�
						vector<int> vec = { sum1, sum2, sum3, sum4, sum5 };
						sort(vec.begin(), vec.end());

						int maxNum = vec[4];
						int minNum = vec[0];
						if (mini > maxNum - minNum) mini = maxNum - minNum;
					}

				}
			}
		}
	}

	cout << mini;



	return 0;
}