#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {


	int a, b;


	scanf("%d %d", &a, &b);
	
	int ans1, ans2, ans3;

	int b1, b2, b3;

	b1 = b / 100;		//3
	b2 = (b - b1 * 100) / 10;		//8
	b3 = (b - b1 * 100 - b2 * 10);

	ans1 = b3 * a;
	ans2 = b2 * a;
	ans3 = b1 * a;



	int ans = ans1 + ans2 * 10 + ans3 * 100;

	printf("%d\n%d\n%d\n%d", ans1, ans2, ans3, ans);

	
		

}