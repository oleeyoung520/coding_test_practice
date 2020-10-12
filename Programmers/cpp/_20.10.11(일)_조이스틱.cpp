#include <string>
#include <vector>
#include <tuple>
#include <iostream>
using namespace std;

tuple<int, int> getIndex(vector<bool> nameBool, int curIdx) {
    int idx = 0;
    int moveCount = 0;

    for (int i = 1; i < nameBool.size(); i++) {
        int rightIdx = (curIdx + i) % nameBool.size();
        int leftIdx = (curIdx - i >= 0) ? (curIdx - i) : nameBool.size() + (curIdx - i);
        if (nameBool[rightIdx] == false) {
            idx = rightIdx;
            moveCount = i;
            break;
        }
        if (nameBool[leftIdx] == false) {
            idx = leftIdx;
            moveCount = i;
            break;
        }
    }

    return make_pair(idx, moveCount);
}

int solution(string name) {
    int answer = 0;
    vector<bool> nameBool(name.length(), false);
    int nameCnt = name.length();

    for (int i = 0; i < name.length(); i++) {
        if (name[i] == 'A') {
            nameBool[i] = true;
            nameCnt--;
        }
    }

    int idx = 0;
    while (nameCnt > 0) {
        if (nameBool[idx] == false) {
            int upLen = name[idx] - 'A';
            int downLen = 'Z' - name[idx] + 1;
            int upDownLen = (upLen > downLen) ? downLen : upLen;
            answer += upDownLen;

            nameBool[idx] = true;
            nameCnt--;
        }
        if (nameCnt > 0) {
            tuple<int, int> retTmp = getIndex(nameBool, idx);
            idx = get<0>(retTmp);
            answer += get<1>(retTmp);
        }

    }

    return answer;
}