#include <iostream>
#include <vector>
#include <utility>

using namespace std;


class Shark {
public:
	int r, c, d;
	int dirArr[5][5];
	bool live;
	Shark() {}
	Shark(int _r, int _c, int _d, int _dirArr[5][5], bool _live) {
		r = _r;
		c = _c;
		d = _d;
		for (int i = 1; i <=4; i++) {
			for (int j = 1; j<=4; j++) {
				dirArr[i][j] = _dirArr[i][j];
			}
		}
		live = _live;
	}
};
pair<int, pair<int, int>> sharkMap[21][21];	//현재 상어 번호
Shark sharkArr[400];
int N, M, k;

//x, 위 아 왼 오
int dr[5] = { 0,-1,1,0,0 };
int dc[5] = { 0,0,0,-1,1 };


//1초 지나서 k감소
void decreaseK() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (sharkMap[i][j].first==-1 && sharkMap[i][j].second.second > 0) {		//상어가 떠난 자리에 냄새가 남아있는 칸이면
				sharkMap[i][j].second.second -= 1;
			}
		}
	}

}
void goOut(vector<int> vec, int left, int nr, int nc) {		//vec 중에서 left 빼고 다 내보내기
	//sharkArr 처리
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] != left) {	//나머지들 내보내기
			sharkArr[vec[i]].live = false;
		}
	}
	//sharkMap 처리
	sharkMap[nr][nc] = make_pair(left, make_pair(left, k));
}



int main() {

	cin >> N >> M >> k;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int sharkNum; cin >> sharkNum;
			if (sharkNum != 0) {
				sharkMap[i][j] = make_pair(sharkNum, make_pair(sharkNum, k));
				sharkArr[sharkNum].r = i;
				sharkArr[sharkNum].c = j;
				sharkArr[sharkNum].live = true;
			}
			else {
				sharkMap[i][j] = make_pair(-1, make_pair(-1, 0));
			}
		}
	}
	
	//상어 m 마리의 방향
	for (int i = 1; i <= M; i++) {
		int dir; cin >> dir;
		sharkArr[i].d = dir;
	}

	//상어 m 마리의 우선순위
	for (int m = 1; m <= M; m++) {

		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				cin >> sharkArr[m].dirArr[i][j];
			}
		}
	}



	int leftSharkCnt = M;		//격자 안에 남아있는 상어 수 
	int sec = 0;

	while (sec <= 1000) {

		if (leftSharkCnt == 1 && sharkArr[1].live == true) break;


		vector<int> tmp[21][21];	//움직이고나서의 상어 번호 저장 
		//상어 1번부터 M번까지 동시에 이동
		for (int s = 1; s <= M; s++) {
			if (sharkArr[s].live == false) continue;	//이미 나간 상어

			pair<int, int> sameSmellLoc = make_pair(-1, -1);
			int toSameSmellmoveDir = 0;
			int curR = sharkArr[s].r;
			int curC = sharkArr[s].c;
			int curD = sharkArr[s].d;


			//아무것도 없는 빈 칸(k<=0) -> 자신의 냄새 있는 칸 
			bool isEmpty = false;
			int nr, nc, nd;

			//1단계
			for (int i = 1; i <= 4; i++) {
				nd = sharkArr[s].dirArr[curD][i];		
				nr = curR + dr[nd];
				nc = curC + dc[nd];
				if (nr <= 0 || nr > N || nc <= 0 || nc > N) continue;

				if (sharkMap[nr][nc].first == -1 && sharkMap[nr][nc].second.second<=0) {		//빈칸이고 냄새 없음 
					
					isEmpty = true; 
					sharkMap[curR][curC].first = -1;									//현재칸 상어 없애기
					break;
				}
				else if (sharkMap[nr][nc].second.second >= 0 && sharkMap[nr][nc].second.first == s) {
					if (sameSmellLoc.first == -1) {	//내냄새와 같은 첫 위치만 저장
						sameSmellLoc.first = nr;
						sameSmellLoc.second = nc;
						toSameSmellmoveDir = nd;
					}
				}

			}

			//2단계
			if (isEmpty == false) {
				//위에서 저장한 내 냄새가 있는 칸으로 이동 
				sharkMap[sameSmellLoc.first][sameSmellLoc.second] = make_pair(s, make_pair(s, k));
				sharkArr[s].r = sameSmellLoc.first;
				sharkArr[s].c = sameSmellLoc.second;
				sharkArr[s].d = toSameSmellmoveDir;

				
				sharkMap[curR][curC].first = -1;					//이동 후 현재 위치 있던거 삭제
			}

			else {
				sharkArr[s].r = nr;		sharkArr[s].c = nc;		sharkArr[s].d = nd;
				tmp[nr][nc].push_back(s);			//일단 후보들 킵
			}
		}


		//3단계 
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (tmp[i][j].size() == 0) continue;
				else if (tmp[i][j].size() == 1) {
					int shark_num = tmp[i][j][0];
					sharkMap[i][j] = make_pair(shark_num, make_pair(shark_num, k));
				}
				else {	//2개 이상
					int mini = 1000;
					for (int k = 0; k < tmp[i][j].size(); k++) {
						if (mini > tmp[i][j][k]) mini = tmp[i][j][k];
					}
					goOut(tmp[i][j], mini, i, j);	//(i,j)에 mini번 상어만 남기기
					leftSharkCnt = leftSharkCnt - tmp[i][j].size() + 1;	//한개만 빼고 다 내보냄

				}
			}
		}

		//4단계
		//상어 이동 완료 후 
		decreaseK();


		//모든 상어 동시에 이동 후 sec 증가
		sec++;


	}

	if (sec > 1000) cout << -1;
	else cout << sec;


	return 0;
}