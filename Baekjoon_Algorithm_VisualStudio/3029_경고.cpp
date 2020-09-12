#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;






int main(){

	int resH, resM, resS;
	string curTime, throwTime;
	cin >> curTime >> throwTime;

	vector<int> curVec, throwVec;
	char strbuf[100], strbuf2[100];
	strcpy(strbuf, curTime.c_str);
	strcpy(strbuf2, throwTime.c_str);

	char *tok = strtok(strbuf, ":");
	char *tok2 = strtok(strbuf2, ":");

	while (tok != nullptr) {
		curVec.push_back(int(tok));
	}
	while (tok2 != nullptr) {
		throwVec.push_back(int(tok2));
	}



	while (curVec[0] != throwVec[0]) {

		curVec[0] += 1;
		resH++;
		if (curVec[0] == 24) curVec[0] = 0;
	}

	while (curVec[1] != throwVec[1]) {

		curVec[1] += 1;
		resM++;
		if (curVec[1] == 59) curVec[1] = 0;
	}

	while (curVec[2] != throwVec[2]) {

		curVec[2] += 1;
		resS++;
		if (curVec[2] == 59) curVec[2] = 0;
	}




	cout << resH << ":" << resM << ":" << resS;





	return 0;
}
