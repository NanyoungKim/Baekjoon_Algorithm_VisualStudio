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
//x, ��, ��, ��, ��
int dr[5] = { 0,-1,1,0,0 };
int dc[5] = { 0,0,0,1,-1 };


int getBottomShark(int col) {
	for (int r = 1; r <= R; r++) {
		if (map[r][col].size() != 0) {
			return r;
		}
	}
	return -1;	//�� �ٿ� ��� ���� ��� -1 ����
}

void moveShark() {
	vector<Shark> tmpVec;

	//�迭 ���鼭 ��� ������ �̵���Ŵ
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			for (int k = 0; k < map[i][j].size(); k++) {//1����

				int nowDirection = map[i][j][k].d;
				int r = i;
				int c = j;
				int nr, nc;
				int move;

				//�ð� �ʰ� �ذ� �κ� ~
				if (nowDirection == 1 || nowDirection == 2) {
					move = map[i][j][k].s % ((R - 1) * 2);				//R-1 * 2 �� �����̸� ���� �״���� ä�� ó�� �ڸ��� ���ƿ�
				}
				else {
					move = map[i][j][k].s % ((C - 1) * 2);				
				}
				//~ �ð� �ʰ� �ذ� �κ� 


				for (int p = 0; p < move; p++) {	//�ӷ�(�̵��ؾ��ϴ� ĭ ��)�� �̵�
					nr = r + dr[nowDirection];
					nc = c + dc[nowDirection];

					if (nr<1 || nr>R) {		//���� �Ѿ�� ���� ��ȯ

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
					r = nr; c = nc; //����

				}
				//�ű� ��ġ ã���� �ӽ� ���Ϳ� �ְ�, �ű�� ���� ��� ���� ����
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

			if (map[i][j].size() >= 2) {		//�� ĭ�� �θ��� �̻� ������ 
				int maxSize = 0;
				int maxIdx = 0;

				for (int k = 0; k < map[i][j].size(); k++) {	//���� ū ��� ã�Ƽ�
					if (maxSize < map[i][j][k].z) {
						maxSize = map[i][j][k].z;
						maxIdx = k;
					}
				}
				Shark shark = map[i][j][maxIdx];	//�� �� ���� ����
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
		//��� ���� �Է� �ޱ�
		for (int t = 0; t < M; t++) {
			int r, c, s, d, z;
			cin >> r >> c >> s >> d >> z;
			Shark shark = Shark(r, c, s, d, z);
			map[r][c].push_back(shark);
			sharkVec.push_back(shark);
		}


		//���ÿ� 1~C ���� �̵�
		for (int i = 1; i <= C; i++) {
			int sharkRow = getBottomShark(i);
			if (sharkRow != -1) {					//���ÿ� �Ʒ��� ��� ������ 

				//���� �Ʒ� �ִ� ��� ����
				ans += map[sharkRow][i][0].z;

				map[sharkRow][i].clear();


			}
			//��� �̵�
			moveShark();

			//���� ū ��� 1������ ����� ��ƸԱ�
			eatShark();

		}


		cout << ans;
	}


	return 0;
}