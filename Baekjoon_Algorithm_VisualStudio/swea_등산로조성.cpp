#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#include <utility>

using namespace std;


int map[8][8] = { 0 };
int visited[8][8] = { 0 };
int fromStart[8][8] = { 0 };

//위,오,아,왼
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

vector<pair<int, int>> sp;   //startpair

priority_queue<int, pair<int, int >> pque;

int ans = 0;
int N, K;
bool flag = true;



void DFS(int r, int c, int k) {






	for (int i = 0; i < 4; i++) {

		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr >= 4 || nr < 0 || nc >= 4 || nc < 0 || visited[nr][nc] == 1) continue;   //범위 벗어나거나 이미 방문했으면


		if (map[r][c] > map[nr][nc] && flag) {        //전진 가능하면 (안 깎을 때)
			visited[nr][nc] = 1;
			fromStart[nr][nc] = fromStart[r][c] + 1;
			DFS(nr, nc, k);
			visited[nr][nc] = 0;
		}

		else if (map[r][c] <= map[nr][nc] && !flag) {                               //전진 불가능하면 (깎을 때)

			int need = map[nr][nc] - map[r][c] + 1;   //최소한 need 만큼 깎아야 전진 가능

			if (need > k) continue;                  //need가 깎을 수 있는 깊이보다 커버리면 pass



			for (int j = need; j <= k; j++) {             //최소 깎을 수 있는 깊이부터 최대 깎을 수 있는 깊이까지 검사

				flag = true;//깎을 수 있음

				int tmp = map[nr][nc];
				map[nr][nc] = tmp - j;
				visited[nr][nc] = 1;

				if (fromStart[nr][nc] >= fromStart[r][c] + 1) continue;
				DFS(nr, nc, k - j);
				visited[nr][nc] = 0;
				map[nr][nc] = tmp;


				flag = false;//이미 깎아서 다른 칸은 못 깎음

			}

		}

	}
}

int main() {

	int T;
	cin >> T;

	int max = 0, cnt = 1;
	for (int test_case = 1; test_case <= T; test_case++) {
		ans = 0;

		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				pque.push(make_pair(map[i][j], make_pair(i,j)));
			}
		}

		max = pque.top().first;
		pque.pop();
		while (1) {
			if (max == pque.top().front) {
				cnt++;
				pque.pop();
				int row = pque.top().second.first;
				int col = pque.top().second.second;
				sp.push_back(make_pair(row, col));
			}
			else break;
		}


		for (int i = 0; i < sp.size(); i++) {

			
			visited[sp[i].first][sp[i].second] = 1;
			DFS(sp[i].first, sp[i].second, K);

		}





	}

}