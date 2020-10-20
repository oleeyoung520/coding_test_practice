#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    queue<tuple<string, int>> qu;
    map<string, tuple<int, int>> timeline;
    map<string, int> curMap;

    set<string> kind_set;
    for (int i = 0; i < gems.size(); i++) {
        kind_set.insert(gems[i]);
    }
    int kind = kind_set.size();
    int min_length = gems.size();
    for (int i = 0; i < gems.size(); i++) {
        qu.push(make_pair(gems[i], i + 1));
        curMap[gems[i]]++;
        while (true) {
            if (!qu.empty() && curMap[get<0>(qu.front())] > 1) {
                curMap[get<0>(qu.front())] -= 1;
                qu.pop();
            } else {
                break;
            }
        }
        if (curMap.size() == kind) {
            int cnt = get<1>(qu.back()) - get<1>(qu.front());
            if (min_length > cnt) {
                answer[0] = get<1>(qu.front());
                answer[1] = get<1>(qu.back());
                min_length = cnt;
            }
        }
    }

    return answer;
}