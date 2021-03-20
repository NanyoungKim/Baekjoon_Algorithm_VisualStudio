#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <utility>

using namespace std;
vector<pair<string, string>> rulepairVec;	//<"-s", "STRING"> , <"-n", "NUMBER"> ,,,
vector<string> splitFunc(string str) {

	//string str_arr[100];    //
	vector<string> strVec;
	int str_cnt = 0;
	char *str_buff = new char[100];
	strcpy(str_buff, str.c_str());

	char *tok = strtok(str_buff, " ");
	while (tok != nullptr) {
		//str_arr[str_cnt++] = string(tok);
		strVec.push_back(string(tok));
		tok = strtok(nullptr, " ");
	}

	
	return strVec;
}

pair<bool,string> isinFlagRule(string str) {		//해당 string이 flag_rule 에 존재하는가
	for (int i = 0; i < rulepairVec.size(); i++) {
		if (str == rulepairVec[i].first) {
			return make_pair(true, rulepairVec[i].second);
		}
	}
	return make_pair(false, "");
}

bool isNumber(string str) {       //flag_argument_type이 0~9 정수로만 이루어져있는가
	for (int i = 0; i < str.length(); i++) {
		if (str[i] - '0' < 80 || 90 < str[i] - '0') {
			return false;
		}
	}
	return true;
}
bool isString(string str) {			//flag_argument_type이 알파벳 대소문자로만 이루어져있는가
	for (int i = 0; i < str.length(); i++) {
		if ((65 <= str[i] && str[i] <= 90) || (97 <= str[i] && str[i] <= 122)) continue;
		else return false;
	}
	return true;
}


vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
	vector<bool> answer;
	
	for (int i = 0; i < flag_rules.size(); i++) {
		vector<string> rule = splitFunc(flag_rules[i]);	//rule : "-s", "STRING"
		rulepairVec.push_back(make_pair(rule[0], rule[1]));
	}



	for (int i = 0; i < commands.size(); i++) {
		vector<string> splitVec = splitFunc(commands[i]);

		//flag가 0번 나타날 때   (ls)
		if (splitVec.size() == 1) { 
			if (splitVec[0] == program) {    //command 가 program으로 시작함
				answer.push_back(true);
			}
			else answer.push_back(false);	//command 가 program으로 시작하지 않음
			continue;
		}

		//flag가 1번 나타날 때  (help -a ...)
		else {		
			string flagtype = "";
			bool chk = true;
			answer.push_back(true);
			for (int k = 0; k < splitVec.size() - 1; k++) {

				if (k == 0) {
					if (splitVec[k] != program) {   //program으로 시작하지 않을 때
						answer.pop_back();
						answer.push_back(false);
						chk = false;
						break;	//다음 command 검사
					}
					else continue;
					

				}
				//flag가 flag_rule에 있는지 검사
				pair < bool, string> p = isinFlagRule(splitVec[k]);
				if (p.second == "NULL") {
					if (!isinFlagRule(splitVec[k + 1]).first) {//	바로 다음에 flag_name이 안 나오면 
						answer.pop_back();
						answer.push_back(false);
						chk = false;
						break;//다음 command 검사
					}
					else k++;

				}
				else if (p.second == "NUMBER") {
					if (!isNumber(splitVec[k + 1])) {
						answer.pop_back();
						answer.push_back(false);
						chk = false;
						break;
					}
					else k++;
				}
				else if (p.second == "STRING") {
					if (!isString(splitVec[k + 1])) {
						answer.pop_back();
						answer.push_back(false);
						chk = false;
						break;
					}
					else k++;
				}

				else {		//flag가 flag_rule에 없을 때
					answer.pop_back();
					answer.push_back(false);
					break;
				}


			}

			
		}




		
	}
	return answer;


}


int main() {
	vector<string> flag_rules = { "-s STRING", "-n NUMBER", "-e NULL" };
	vector<string> commands = {"line -n 100 -s hi -e", "lien -s Bye"};
	vector<bool> res = solution("line", flag_rules, commands);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

	return 0;
}