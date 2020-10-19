#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            answer++;
            visited[i] = true;
            queue<int> net;
            for (int j = i + 1; j < int(computers[i].size()); j++) {
                if (!visited[j] && computers[i][j] == 1) {
                    net.push(j);
                }
            }
            int n = 0;
            while (int(net.size()) != 0) {
                int netIdx = net.front();
                net.pop();
                visited[netIdx] = true;
                for (int j = i + 1; j < int(computers[netIdx].size()); j++) {
                    if (!visited[j] && computers[netIdx][j] == 1) {
                        net.push(j);
                    }
                }
                n++;
            }
        }
    }
    return answer;
}