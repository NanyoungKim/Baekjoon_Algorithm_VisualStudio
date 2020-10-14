#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char alpha[26];

int findFunc(char c) {

	int ans = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == c) {
			ans = i;
			
			return ans;
		}
	}
	return -1;
}





int main() {
	int ans[26];
	for (int i = 0; i < 26; i++) {
		alpha[i] = 'a' + i;
		ans[i] = -1;
	}

	char str[200];

	//memset(ans, -1, 26);

	scanf("%s", str);
	//printf("%d", strlen(str));



	
	for (int i = 0; i < strlen(str); i++) {
		int idx = findFunc(str[i]);
		//printf("idx : %d  ", idx);
		if (ans[idx] == -1) {
			ans[idx] = i;
			//printf("%d\n", ans[idx]);
		}
		
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", ans[i]);
	}

	
}