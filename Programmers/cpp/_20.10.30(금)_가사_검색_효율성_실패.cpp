#include <string>
#include <vector>
#include <regex>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    map<int, vector<string>> lenMap;
    for(int i = 0; i < words.size(); i++) {
        lenMap[words[i].length()].push_back(words[i]);
    }
    
    
    for (int i = 0; i < queries.size(); i++) {
        int len = queries[i].length();
        if(queries[i][0] == '?' && queries[i][len-1] == '?') {
            answer.push_back(lenMap[len].size());
        } else {
            if(queries[i][0] == '?') {
                // front
                int idx = -1;
                // '?'가 아닌 지점까지 이분탐색
                int start = 0;
                int end = len-1;
                while(true) {
                    int mid = (start + end) / 2;
                    if(queries[i][mid] != '?') {
                        end = mid;
                    } else {
                        start = mid;
                    }
                    if(start == end -1) {
                        idx = end;
                        break;
                    }
                }
                
                // len의 길이를 갖고 있고 idx~(len-1)까지 substr이 같은 word를 찾는 것
                int tmp = 0;
                for(int j = 0; j < lenMap[len].size(); j++) {
                    if(lenMap[len][j].substr(idx) == queries[i].substr(idx)) {
                        tmp++;
                    }
                }
                answer.push_back(tmp);
            } else if(queries[i][len-1] == '?') {
                // back
                int idx = -1;
                // '?'일 때까지 이분탐색
                int start = 0;
                int end = len-1;
                while(true) {
                    int mid = (start + end) / 2;
                    if(queries[i][mid] == '?') {
                        end = mid;
                    } else {
                        start = mid;
                    }
                    if(start == end -1) {
                        idx = start;
                        break;
                    }
                }

                // len의 길이를 갖고 있고 idx~(len-1)까지 substr이 같은 word를 찾는 것
                int tmp = 0;
                for(int j = 0; j < lenMap[len].size(); j++) {
                    if(lenMap[len][j].substr(0, idx+1) == queries[i].substr(0, idx+1)) {
                        tmp++;
                    }
                }
                answer.push_back(tmp);
            }
        }    
    }
    
    
    return answer;
}