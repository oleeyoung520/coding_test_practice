#include <string>
#include <vector>
#include <map>
//#include <iostream>
using namespace std;

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    int len = arr.size();

    while (len > 1) {
        vector<vector<map<int, int>>> newMapArr(len / 2, vector<map<int, int>>(len / 2));
        vector<vector<int>> newArr(len / 2, vector<int>(len / 2, 0));
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                newMapArr[i / 2][j / 2][arr[i][j]]++;
            }
        }
        for (int i = 0; i < len / 2; i++) {
            for (int j = 0; j < len / 2; j++) {
                if (newMapArr[i][j].size() > 1) {
                    answer[0] += newMapArr[i][j][0];
                    answer[1] += newMapArr[i][j][1];
                    newArr[i][j] = -1;
                } else if (newMapArr[i][j].size() == 1) {
                    newArr[i][j] = (newMapArr[i][j].begin()->first);
                }
            }
        }

        arr = newArr;
        len /= 2;
    }
    if (arr[0][0] == 0) {
        answer[0] += 1;
    } else if (arr[0][0] == 1) {
        answer[1] += 1;
    }
    return answer;
}