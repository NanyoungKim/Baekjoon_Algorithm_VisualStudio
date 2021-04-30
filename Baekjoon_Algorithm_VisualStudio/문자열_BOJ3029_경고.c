#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int change(char c1, char c2) {
	
	int res = 0;
	if (c1 == '0') {
		res = c2 - '0';
	}
	else {
		res = (c1 - '0') * 10 + (c2 - '0');
	}
	return res;
}



int main() {


	char curTime[9], nextTime[9];
	scanf("%s", curTime);
	scanf("%s", nextTime);

	int cur_h = change(curTime[0], curTime[1]);
	int cur_m = change(curTime[3], curTime[4]);
	int cur_s = change(curTime[6], curTime[7]);

	int next_h = change(nextTime[0], nextTime[1]);
	int next_m = change(nextTime[3], nextTime[4]);
	int next_s = change(nextTime[6], nextTime[7]);


	if (cur_h==next_h && cur_m==next_m && cur_s==next_s) {
		printf("24:00:00");
	}
	else {

		if (cur_s > next_s) {
			next_m -= 1;
			next_s += 60;
		}
		int s = next_s - cur_s;

		if (cur_m > next_m) {
			next_h -= 1;
			next_m += 60;
		}
		int m = next_m - cur_m;

		int h;
		if (cur_h > next_h) {
			h = (24 - cur_h) + next_h;
		}
		else {
			h = next_h - cur_h;
		}


		if (h < 10) {
			printf("0");
		}
		printf("%d:", h);


		if (m < 10) printf("0");
		printf("%d:", m);

		if (s < 10) printf("0");
		printf("%d", s);


	}

	return 0;

}