#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int map[50][50];
vector<pair<int, int>> initVirus;	//ó�� 2(���̷���) ��ġ
int visited[10] = { 0 };			//ó�� 2(���̽�) Ȱ�� ���� ����
vector<int> virusIdx;				//��ü ���̷��� �� M���� ��� ����
//�� �� �� ��
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int N, M;
int space = 0;	//��ĭ
vector<int> ansVec;
void spreadBFS() {

	int maxSecond = 0;
	int fromStart[50][50];
	int initLoc[50][50];
	memset(fromStart, 0, sizeof(fromStart));
	memset(initLoc, 0, sizeof(initLoc));
	queue<pair<int, int>> que;
	int cnt = 0;

	for (int i = 0; i < virusIdx.size(); i++) {	//M��
		que.push(initVirus[virusIdx[i]]);
		initLoc[initVirus[virusIdx[i]].first][initVirus[virusIdx[i]].second] = 1;		//ó�� ���̷����� �ִ� ������
	}
	while (!que.empty()) {
		int r = que.front().first;
		int c = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N ||		//���� ����ų�
				map[nr][nc] == 1 || fromStart[nr][nc] != 0 || initLoc[nr][nc] == 1) continue;	//���̰ų�, �̹� ���̷��� �����ų�, ó�� Ȱ�����̷��� ��ġ�� ��ŵ

			//��ĭ�̴� ��Ȱ�����̷����̴� �� ��
			fromStart[nr][nc] = fromStart[r][c] + 1;
			que.push(make_pair(nr, nc));

			//��Ȱ�� ���̷��� �ƴϰ� ��ĭ�� ��쿡
			if (map[nr][nc] == 0) {
				cnt++;		//��ĭ���� ���̷��� ���� �� ĭ�� �� ī��Ʈ
				if (maxSecond < fromStart[nr][nc]) maxSecond = fromStart[nr][nc];	//�� ��쿡�� �ִ�� �ɸ� �� ����ϱ�
			}

		}

	}

	if (cnt == space) {			//��� ��ĭ�� �� �������� 
		ansVec.push_back(maxSecond);
	}
}


void pickDFS(int toPick, int start) {			//��ü ���̷��� �� M�� ��

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


	//initVec���� Ȱ�����·� ���� ���̷��� M�� ����
	pickDFS(M, 0);

	if (ansVec.size() == 0) cout << -1;
	else {
		sort(ansVec.begin(), ansVec.end());
		cout << ansVec[0];
	}
	return 0;
}