#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

	char alphaS[26];
	char alphaB[26];
	int cnt[26];
	
	memset(cnt, 0, sizeof(cnt));

	for (int i = 0; i < 26; i++) {
		alphaS[i] = 'a' + i;
		alphaB[i] = 'A' + i;
	}

	char word[1000001];
	scanf("%s", word);

	for (int i = 0; i < strlen(word); i++) {
		
		for (int j = 0; j < 26; j++) {
			if (word[i] == alphaS[j] || word[i] == alphaB[j]) {
				cnt[j]++;
				break;
			}

		}

	}

	int max = 0;
	int chkIdx = 0;
	char answer;
	
	for (int i = 0; i < 26; i++) {
		if (cnt[i] > max) {
			max = cnt[i];
			chkIdx = i;
		}
	}
	answer = alphaB[chkIdx];

	for (int i = 0; i < 26; i++) {
		if (max == cnt[i] && chkIdx != i) {
			answer = '?';
			break;
		}
	}

	printf("%c", answer);
	


}