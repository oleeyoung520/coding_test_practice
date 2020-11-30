#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> snail;
    for(int i = 1; i <= n; i++) {
        snail.push_back(vector<int>(i, 0));
    }
    
    int flag = 0;
    int number = 1;
    int x = 0, y = 0;
    
    while(flag != 4) {
        // 내려
        flag++;
        for(; x < n; x++) {
            if(snail[x][y] != 0) {
                break;
            } else {
                snail[x][y] = number;
                number++;
            }
        }
        x--;
        y++;
        
        if(flag == n) {
            break;
        }

        // 오른쪽으로
        flag++;
        for(; y <= x; y++) {
            if(snail[x][y] != 0) {
                break;
            } else {
                snail[x][y] = number;
                number++;
            }
        }
        y -= 2;
        x--;

        // 대각선
        flag++;
        for(; x > 0; x--, y--) {
            if(snail[x][y] != 0) {
                break;
            } else {
                snail[x][y] = number;
                number++;
            }
        }
        x += 2;
        y++;
        
        if(flag == n) {
            break;
        }

    }
    
    for(vector<int> s: snail) {
        for(int v: s) {
            answer.push_back(v);
            // cout << v << " ";
        }
        // cout << endl;
    }    
    
    return answer;
}