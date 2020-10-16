#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {


	char word[101];
	memset(word, 0, sizeof(word));

	scanf("%s", word);
	
	for (int i = 0; i < strlen(word); i++) {

		if ((i % 10 == 0) && (i != 0)) printf("\n");

		printf("%c", word[i]);


	}
}