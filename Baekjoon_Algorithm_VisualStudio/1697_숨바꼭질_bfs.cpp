#include <iostream>
#include <queue>
#include <cstdio>        // less
#include <functional>    // greater

using namespace std;

  //¼öºó, µ¿»ý
int N, K;
int answer;
bool visit[100000] = { 0, };
int bfs(queue<int> que) {
	
	int time = 0;
	

	while (1) {

		int size = que.size();
		
		for (int i = 0; i < size; i++) {

			int n = que.front();
			que.pop();


			if (n == K) {
				return time;
			}


			if (0 <= n - 1 && visit[n-1] == 0) {
				que.push(n - 1);
				visit[n - 1] = 1;
			}
			if (n + 1 <= 100000 && visit[n+1] == 0 ) {
				que.push(n + 1);
				visit[n + 1] = 1;
			}
			if (2 * n <= 100000 && visit[2*n] == 0) {
				que.push(2 * n);
				visit[2 * n] = 1;
			}


		}
		
		time++;

		
		
		







	}




}

int main() {

	
	queue<int> que;
	cin >> N >> K;
	que.push(N);
	cout << bfs(que);



	return 0;
}