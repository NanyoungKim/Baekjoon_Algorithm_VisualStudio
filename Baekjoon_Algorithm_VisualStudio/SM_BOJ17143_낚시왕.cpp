#include <iostream>
#include <vector>
using namespace std;

class Shark {

public:
	int r, c, s, d, z;
	Shark(int _r, int _c, int _s, int _d, int _z) {
		r = _r;
		c = _c;
		s = _s;
		d = _d;
		z = _z;

	}
};

int R, C, M;

vector<Shark> map[101][101];
vector<Shark> sharkVec;
//x, 위, 아, 오, 왼
int dr[5] = { 0,-1,1,0,0 };
int dc[5] = { 0,0,0,1,-1 };


int getBottomShark(int col) {
	for (int r = 1; r <= R; r++) {
		if (map[r][col].size() != 0) {
			return r;
		}
	}
	return -1;	//그 줄에 상어 없는 경우 -1 리턴
}

void moveShark() {
	vector<Shark> tmpVec;

	//배열 돌면서 상어 있으면 이동시킴
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			for (int k = 0; k < map[i][j].size(); k++) {//1마리

				int nowDirection = map[i][j][k].d;
				int r = i;
				int c = j;
				int nr, nc;
				int move;

				//시간 초과 해결 부분 ~
				if (nowDirection == 1 || nowDirection == 2) {
					move = map[i][j][k].s % ((R - 1) * 2);				//R-1 * 2 번 움직이면 방향 그대로인 채로 처음 자리로 돌아옴
				}
				else {
					move = map[i][j][k].s % ((C - 1) * 2);				
				}
				//~ 시간 초과 해결 부분 


				for (int p = 0; p < move; p++) {	//속력(이동해야하는 칸 수)번 이동
					nr = r + dr[nowDirection];
					nc = c + dc[nowDirection];

					if (nr<1 || nr>R) {		//범위 넘어가면 방향 젼환

						if (nowDirection == 1) {
							nowDirection = 2;
							nr = r + dr[nowDirection];
							nc = c + dc[nowDirection];
						}
						else if (nowDirection == 2) {
							nowDirection = 1;
							nr = r + dr[nowDirection];
							nc = c + dc[nowDirection];
						}

					}
					if (nc<1 || nc>C) {
						if (nowDirection == 3) {
							nowDirection = 4;
							nr = r + dr[nowDirection];
							nc = c + dc[nowDirection];
						}
						else if (nowDirection == 4) {
							nowDirection = 3;
							nr = r + dr[nowDirection];
							nc = c + dc[nowDirection];
						}
					}
					r = nr; c = nc; //갱신

				}
				//옮길 위치 찾고나서 임시 벡터에 넣고, 옮기기 전의 상어 정보 삭제
				tmpVec.push_back(Shark(r, c, map[i][j][k].s, nowDirection, map[i][j][k].z));
				map[i][j].clear();

			}
		}
	}
	for (int i = 0; i < tmpVec.size(); i++) {
		Shark shark = tmpVec[i];
		int r = shark.r;
		int c = shark.c;
		map[r][c].push_back(shark);
	}
}
void eatShark() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {

			if (map[i][j].size() >= 2) {		//한 칸에 두마리 이상 있으면 
				int maxSize = 0;
				int maxIdx = 0;

				for (int k = 0; k < map[i][j].size(); k++) {	//가장 큰 상어 찾아서
					if (maxSize < map[i][j][k].z) {
						maxSize = map[i][j][k].z;
						maxIdx = k;
					}
				}
				Shark shark = map[i][j][maxIdx];	//그 상어만 빼고 삭제
				map[i][j].clear();
				map[i][j].push_back(shark);
			}

		}
	}
}


int main() {
	int ans = 0;

	cin >> R >> C >> M;
	if (M == 0) {
		cout << 0;
	}
	else {
		//상어 정보 입력 받기
		for (int t = 0; t < M; t++) {
			int r, c, s, d, z;
			cin >> r >> c >> s >> d >> z;
			Shark shark = Shark(r, c, s, d, z);
			map[r][c].push_back(shark);
			sharkVec.push_back(shark);
		}


		//낚시왕 1~C 까지 이동
		for (int i = 1; i <= C; i++) {
			int sharkRow = getBottomShark(i);
			if (sharkRow != -1) {					//낚시왕 아래에 상어 있으면 

				//가장 아래 있는 상어 낚시
				ans += map[sharkRow][i][0].z;

				map[sharkRow][i].clear();


			}
			//상어 이동
			moveShark();

			//제일 큰 상어 1마리만 남기고 잡아먹기
			eatShark();

		}


		cout << ans;
	}


	return 0;
}