#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	int N, cnt = 0, answer = 0;
	scanf("%d", &N);

	char arr[10];
	

	if (1 <= N && N <= 99) {
		answer = N;
	}
	else {

		for (int i = 100; i <= N; i++) {
			sprintf(arr, "%d", i);

			if (arr[0] - arr[1] == arr[1] - arr[2]) cnt++;
			
		}
		answer = cnt + 99;
	}
	

	printf("%d", answer);
}