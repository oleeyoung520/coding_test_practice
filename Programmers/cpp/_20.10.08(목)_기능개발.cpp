#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int back = -1;
    int len = 0;

    for (int i = 0; i < int(progresses.size()); i++) {
        int rd = ceil((100 - progresses[i]) / (double)speeds[i]);
        if (i == 0) {
            back = rd;
            len++;
        }
        else if (back != -1 && back < rd) {
            answer.push_back(len);
            back = rd;
            len = 1;
        }
        else {
            len++;
        }
    }
    answer.push_back(len);

    return answer;
}