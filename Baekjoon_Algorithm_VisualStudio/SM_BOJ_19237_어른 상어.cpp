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
pair<int, pair<int, int>> sharkMap[21][21];	//���� ��� ��ȣ
Shark sharkArr[400];
int N, M, k;

//x, �� �� �� ��
int dr[5] = { 0,-1,1,0,0 };
int dc[5] = { 0,0,0,-1,1 };


//1�� ������ k����
void decreaseK() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (sharkMap[i][j].first==-1 && sharkMap[i][j].second.second > 0) {		//�� ���� �ڸ��� ������ �����ִ� ĭ�̸�
				sharkMap[i][j].second.second -= 1;
			}
		}
	}

}
void goOut(vector<int> vec, int left, int nr, int nc) {		//vec �߿��� left ���� �� ��������
	//sharkArr ó��
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] != left) {	//�������� ��������
			sharkArr[vec[i]].live = false;
		}
	}
	//sharkMap ó��
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
	
	//��� m ������ ����
	for (int i = 1; i <= M; i++) {
		int dir; cin >> dir;
		sharkArr[i].d = dir;
	}

	//��� m ������ �켱����
	for (int m = 1; m <= M; m++) {

		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				cin >> sharkArr[m].dirArr[i][j];
			}
		}
	}



	int leftSharkCnt = M;		//���� �ȿ� �����ִ� ��� �� 
	int sec = 0;

	while (sec <= 1000) {

		if (leftSharkCnt == 1 && sharkArr[1].live == true) break;


		vector<int> tmp[21][21];	//�����̰����� ��� ��ȣ ���� 
		//��� 1������ M������ ���ÿ� �̵�
		for (int s = 1; s <= M; s++) {
			if (sharkArr[s].live == false) continue;	//�̹� ���� ���

			pair<int, int> sameSmellLoc = make_pair(-1, -1);
			int toSameSmellmoveDir = 0;
			int curR = sharkArr[s].r;
			int curC = sharkArr[s].c;
			int curD = sharkArr[s].d;


			//�ƹ��͵� ���� �� ĭ(k<=0) -> �ڽ��� ���� �ִ� ĭ 
			bool isEmpty = false;
			int nr, nc, nd;

			//1�ܰ�
			for (int i = 1; i <= 4; i++) {
				nd = sharkArr[s].dirArr[curD][i];		
				nr = curR + dr[nd];
				nc = curC + dc[nd];
				if (nr <= 0 || nr > N || nc <= 0 || nc > N) continue;

				if (sharkMap[nr][nc].first == -1 && sharkMap[nr][nc].second.second<=0) {		//��ĭ�̰� ���� ���� 
					
					isEmpty = true; 
					sharkMap[curR][curC].first = -1;									//����ĭ ��� ���ֱ�
					break;
				}
				else if (sharkMap[nr][nc].second.second >= 0 && sharkMap[nr][nc].second.first == s) {
					if (sameSmellLoc.first == -1) {	//�������� ���� ù ��ġ�� ����
						sameSmellLoc.first = nr;
						sameSmellLoc.second = nc;
						toSameSmellmoveDir = nd;
					}
				}

			}

			//2�ܰ�
			if (isEmpty == false) {
				//������ ������ �� ������ �ִ� ĭ���� �̵� 
				sharkMap[sameSmellLoc.first][sameSmellLoc.second] = make_pair(s, make_pair(s, k));
				sharkArr[s].r = sameSmellLoc.first;
				sharkArr[s].c = sameSmellLoc.second;
				sharkArr[s].d = toSameSmellmoveDir;

				
				sharkMap[curR][curC].first = -1;					//�̵� �� ���� ��ġ �ִ��� ����
			}

			else {
				sharkArr[s].r = nr;		sharkArr[s].c = nc;		sharkArr[s].d = nd;
				tmp[nr][nc].push_back(s);			//�ϴ� �ĺ��� ŵ
			}
		}


		//3�ܰ� 
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (tmp[i][j].size() == 0) continue;
				else if (tmp[i][j].size() == 1) {
					int shark_num = tmp[i][j][0];
					sharkMap[i][j] = make_pair(shark_num, make_pair(shark_num, k));
				}
				else {	//2�� �̻�
					int mini = 1000;
					for (int k = 0; k < tmp[i][j].size(); k++) {
						if (mini > tmp[i][j][k]) mini = tmp[i][j][k];
					}
					goOut(tmp[i][j], mini, i, j);	//(i,j)�� mini�� �� �����
					leftSharkCnt = leftSharkCnt - tmp[i][j].size() + 1;	//�Ѱ��� ���� �� ������

				}
			}
		}

		//4�ܰ�
		//��� �̵� �Ϸ� �� 
		decreaseK();


		//��� ��� ���ÿ� �̵� �� sec ����
		sec++;


	}

	if (sec > 1000) cout << -1;
	else cout << sec;


	return 0;
}