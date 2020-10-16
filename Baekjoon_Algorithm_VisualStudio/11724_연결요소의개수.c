#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int **arr; 
int *chk;
int N, M;
int cnt = 0;

void dfs(int row) {

	chk[row] = 1;
	for (int i = 1; i <= N; i++) {		//�� ���� ���鼭 �˻�

		if (arr[row][i] == 1 && chk[i] == 0) {		//�湮 ���߰� ��������� 
			dfs(i);
		}
	}

	


}



int main() {

	int node1, node2;
	scanf("%d %d", &N, &M);

	chk = malloc(sizeof(int) * (N+1));		//�湮�ߴ��� üũ
	memset(chk, 0, (N+1)* sizeof(chk));

	//for (int i = 0; i <= N; i++) printf("%d ", chk[i]);

	arr = (int**)malloc(sizeof(int*) * (N+1));
	for (int i = 0; i < N+1; i++) {
		arr[i] = (int*)malloc(sizeof(int) * (N+1));
	}


	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			
			arr[i][j] = 0;
		}
		

	}



	for (int i = 0; i < M; i++) {

		scanf("%d%d", &node1, &node2);
		arr[node1][node2] = 1;
		arr[node2][node1] = 1;
	}
	

	for (int i = 1; i <= N; i++) {

		if (chk[i] == 0){	//�湮 ���� �������� 
			cnt++;
			dfs(i);//�� ��忡 ���� ����
		}
	}
	
	printf("%d", cnt);


	free(chk);
	for (int i = 0; i <= N; i++) {
		free(arr[i]);
	}
	free(arr);
	
}