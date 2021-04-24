#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int N, Q;
int A[7][7];			//얼음의 양
vector<int> vecL;

//위 오 아 왼
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

void leftIceChk() {	//(r,c) 주변에 얼음 있는 칸 몇개인지...3개,4개면 트루



	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nr = i + dr[k];
				int nc = j + dc[k];
				if (nr<1 || nr>N || nc<1 || nc>N) continue;

				if (A[nr][nc] > 0) cnt++;

			}
			if (cnt < 3 && A[i][j]>0) {
				A[i][j] -= 1;
			}
		}
	}

}




void rotateFunc(int s, int e) {	//돌리려는 격자의 시작점과 끝점

	for (; s < e; s++, e--) {//layer 점점 안쪽으로
		for (int i = s, j = e; i < e; i++, j--) {	//한칸씩 옮기기
			int tmp = A[s][j];
			A[s][j] = A[i][s];
			A[i][s] = A[i][e];
			A[i][e] = A[j][e];
			A[j][e] = tmp;
		}
	}


}


int main() {

	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < Q; i++) {
		int L; cin >> L;
		vecL.push_back(L);
	}

	for (int i = 0; i < vecL.size(); i++) {
		int len = (int)pow(2, vecL[i]);	//부분 격자 한변 길이

		int cnt = (N*N) / (len*len);	//회전시킬 박스 수

		int s = 1, e = N;
		for (int k = 0; k < cnt; k++) {
			cout << s << " " << e << endl;
			rotateFunc(s, e);


			leftIceChk();		//얼음의 양 줄어듦

			e += len;
			if (e > N) {
				s += len;
				e = 1;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(A[i][j])
		}
	}





	return 0;
}