#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int map[50][50];
vector<pair<int, int>> initVirus;	//처음 2(바이러스) 위치
int visited[10] = { 0 };			//처음 2(바이스) 활성 선택 여부
vector<int> virusIdx;				//전체 바이러스 중 M개를 담는 벡터
//위 오 아 왼
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int N, M;
int space = 0;	//빈칸
vector<int> ansVec;
void spreadBFS() {

	int maxSecond = 0;
	int fromStart[50][50];
	int initLoc[50][50];
	memset(fromStart, 0, sizeof(fromStart));
	memset(initLoc, 0, sizeof(initLoc));
	queue<pair<int, int>> que;
	//vector<pair<int, int>> deadToLive;
	int cnt = 0;

	for (int i = 0; i < virusIdx.size(); i++) {	//M개
		que.push(initVirus[virusIdx[i]]);
		initLoc[initVirus[virusIdx[i]].first][initVirus[virusIdx[i]].second] = 1;		//처음 바이러스가 있던 시작점
	}
	while (!que.empty()) {
		int r = que.front().first;
		int c = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N ||
				map[nr][nc]==1 || fromStart[nr][nc]!=0 || initLoc[nr][nc]==1) continue;
			
			
			fromStart[nr][nc] = fromStart[r][c] + 1;
			que.push(make_pair(nr, nc));
			if (map[nr][nc] == 0) {	//바이러스 아니고 빈칸인 경우에
				cnt++;
				if (maxSecond < fromStart[nr][nc]) maxSecond = fromStart[nr][nc];
			}

		}

	}
	cout << "max : " << maxSecond << endl;
	cout << cnt << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << fromStart[i][j] << " ";
		}cout << endl;
	}
	cout << "\n\n";
	if(cnt == space){
		cout <<"cnt : " << cnt << endl;
		ansVec.push_back(maxSecond); 
	}
}


void pickDFS(int toPick, int start) {

	if (toPick == 0) {

		spreadBFS();
	}

	for (int i = start; i < initVirus.size(); i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			virusIdx.push_back(i);
			pickDFS(toPick - 1, i);
			virusIdx.pop_back();
			visited[i] = 0;
		}


	}



}


int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				initVirus.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 0) space++;
		}
	}


	//initVec에서 활성상태로 만들 바이러스 M개 고르기
	pickDFS(M, 0);
	
	if (ansVec.size() == 0) cout << -1;
	else {
		sort(ansVec.begin(), ansVec.end());
		cout << ansVec[0];
	}
	return 0;
}