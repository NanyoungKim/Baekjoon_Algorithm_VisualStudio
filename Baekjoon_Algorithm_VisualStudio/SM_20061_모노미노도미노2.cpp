#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int red[4][4];
int blue[4][6];
int green[6][4];
int ans = 0;
//열 지우는 함수
void delColBlue(int col) {
	for (int r = 0; r < 4; r++) {
		blue[r][col] = 0;
	}
}
void delRowGreen(int row) {
	for (int c = 0; c < 4; c++) {
		green[row][c] = 0;
	}
}


int maxBlue(int row) {//걸리지 않을때까지 오른쪽 또는 아래로 밀었을 때 

	for (int col = 0; col <= 5; col++) {
		if (blue[row][col] == 1) {
			return col - 1;
		}
	}return 5;
}
int maxGreen(int col) {
	for (int row = 0; row <= 5; row++) {
		if (green[row][col] == 1) {
			return row - 1;
		}
	}return 5;
}

//STEP 1 : 블록 놓기 
void shiftFunc(int t, int x, int y) {

	if (t == 1) {
		blue[x][maxBlue(x)] = 1;
		green[maxGreen(y)][y] = 1;

	}
	else if (t == 2) {	//1*2
		int c = maxBlue(x);
		blue[x][c] = 1;
		blue[x][c - 1] = 1;

		int r = maxGreen(y);
		int r2 = maxGreen(y + 1);
		if (r < r2) {
			green[r][y] = 1;
			green[r][y + 1] = 1;
		}
		else {
			green[r2][y] = 1;
			green[r2][y + 1] = 1;
		}

	}
	else {	//2*1
		int c = maxBlue(x);
		int c2 = maxBlue(x + 1);
		if (c < c2) {
			blue[x][c] = 1;
			blue[x + 1][c] = 1;
		}
		else {
			blue[x][c2] = 1;
			blue[x + 1][c2] = 1;
		}

		int r = maxGreen(y);
		green[r][y] = 1;
		green[r - 1][y] = 1;
	}
}

void eraseAndpushBlue(int col) {
	for (int c = col; c >= 1; c--) {
		for (int r = 0; r < 4; r++) {
			blue[r][c] = blue[r][c - 1];
		}
	}
}
void eraseAndpushGreen(int row) {
	for (int r = row; r >= 1; r--) {
		for (int c = 0; c < 4; c++) {
			green[r][c] = green[r - 1][c];
		}
	}
}

//STEP 2 : 가장 오른쪽 또는 아래부터 4칸 다 찬 줄을 찾아서 삭제하고 shift
void getFullLine() {
	//blue
	for (int c = 5; c >= 2; c--) {
		int cnt = 0;
		for (int r = 0; r < 4; r++) {
			if (blue[r][c] == 0) break;
			else cnt++;
		}
		if (cnt == 4) {
			ans++;
			eraseAndpushBlue(c);
			c++;
		}
	}
	//green
	for (int r = 5; r >= 2; r--) {
		int cnt = 0;
		for (int c = 0; c < 4; c++) {
			if (green[r][c] == 0) break;
			else cnt++;
		}
		if (cnt == 4) {
			ans++;
			eraseAndpushGreen(r);
			r++;
		}

	}

}

//STEP 3 : 0, 1 번째 줄에 블록 있을 때 있는 줄의 수 만큼 shift
void specialBlue() {
	int cnt = 0;
	for (int c = 0; c <= 1; c++) {
		for (int r = 0; r < 4; r++) {
			if (blue[r][c] == 1) {
				cnt++;
				break;
			}
		}
	}
	for (int c = 5; c >= 2; c--) {
		for (int r = 0; r < 4; r++) {
			blue[r][c] = blue[r][c - cnt];
		}
	}
	delColBlue(1);
	delColBlue(0);
}

void specialGreen() {
	int cnt = 0;
	for (int r = 0; r <= 1; r++) {
		for (int c = 0; c < 4; c++) {
			if (green[r][c] == 1) {
				cnt++;
				break;
			}
		}
	}
	for (int r = 5; r >= 2; r--) {
		for (int c = 0; c < 4; c++) {
			green[r][c] = green[r - cnt][c];
		}
	}
	delRowGreen(0);
	delRowGreen(1);
}


//블록 수 카운트
int tileBlue() {
	int res = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			if (blue[i][j] == 1) res++;
		}
	}
	return res;
}
int tileGreen() {
	int res = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (green[i][j] == 1) res++;
		}
	}
	return res;
}



int main() {

	int N; cin >> N;

	memset(red, 0, sizeof(red));
	memset(blue, 0, sizeof(blue));
	memset(green, 0, sizeof(green));
	for (int T = 0; T < N; T++) {

		int t, x, y;
		cin >> t >> x >> y;

		shiftFunc(t, x, y);	//빨간색에서 파란색, 초록색 보드로 타일 밀기
		getFullLine();
		specialBlue();
		specialGreen();
	}
	cout << ans << "\n" << tileBlue() + tileGreen();


	return 0;
}