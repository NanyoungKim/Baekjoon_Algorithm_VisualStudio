#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

pair<int,int> func(char c1, char c2){
    if(c1=='z'){//0
        return make_pair(0, 4);
    }
    else if(c1=='o'){//1
        return make_pair(1, 3);
    }
    else if(c1=='t'){ //2,3
        if(c2=='w') return make_pair(2,3);
        else return make_pair(3,5);
    }
    else if(c1=='f'){//4,5
        if(c2=='o') return make_pair(4,4);
        else return make_pair(5,4);
    }
    else if(c1=='s'){//6,7
        if(c2=='i') return make_pair(6,3);
        else return make_pair(7,5);
    }
    else if(c1=='e'){//8
        return make_pair(8,5);
    }
    else if(c1=='n'){//9
        return make_pair(9,4);
    }
    else{
        return make_pair(c1-'0', 1);
    }
}

int solution(string s) {
    int answer = 0;
    
    int idx = 0;
    while(idx < s.length()){
   
        pair<int,int> p = func(s[idx], s[idx+1]);
        //cout << s[idx] << " " << p.first << " " << p.second << endl;
        answer = answer*10 + p.first;
        ///cout << answer << "\n\n";
        idx += p.second;
    }
    
    return answer;
}

