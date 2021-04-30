#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {


	//a = 97

	int N;
	scanf("%d", &N);

	int ans = 0;
	int chkArr[26];

	
	
	for (int i = 0; i < N; i++) {

		memset(chkArr, 0, sizeof(chkArr));
		char str[101];
		scanf("%s", str);
		int idx = 0;
		int chk = 1;
		while (1) {
			
			if (str[idx] == '\0') { break; }

			char c = str[idx];
			if (chkArr[c - 97] == 1) {			//이미 나온 경우
				if (str[idx - 1] != str[idx]) {
					chk = 0;
					break;
				}
			}
			else {
				chkArr[c - 97] = 1;
			}

			idx++;
		}
		
		if (chk == 1) ans += 1;


	}
	printf("%d", ans);


	return 0;
}