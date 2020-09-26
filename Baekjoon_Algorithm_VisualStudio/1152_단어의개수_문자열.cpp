#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {



	string str;
	getline(cin, str);

	
	
	char *str_buff = new char[str.length()];
	vector<string> strVec;


	strcpy(str_buff, str.c_str());

	char *tok = strtok(str_buff, " ");
	while (tok != nullptr) {
		strVec.push_back(string(tok));
		tok = strtok(nullptr, " ");
	}

	for (int i = 0; i < strVec.size(); i++) {
		cout << strVec[i] << endl;
	}
	cout << strVec.size();

	return 0;
}
