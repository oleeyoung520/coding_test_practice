#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;

int BFS(vector<vector<int>> adjMat) {
    queue<tuple<int, int>> qu;
    vector<bool> visited(adjMat.size(), false);
    
    int maxHeight = 0;
    int maxCnt = 0;
    
    int start = 0;
    qu.push(make_pair(0, start));
    visited[start] = true;
    while(!qu.empty()) {
        tuple<int, int> curTup = qu.front();
        int curHeight = get<0>(curTup);
        int curNode = get<1>(curTup);
        qu.pop();
        
        for(int i = 0; i < adjMat[curNode].size(); i++) {
            if(visited[adjMat[curNode][i]]) {
                continue;
            } else {
                qu.push(make_pair(curHeight + 1, adjMat[curNode][i]));
                visited[adjMat[curNode][i]] = true;
                if(maxHeight < curHeight + 1) {
                    maxHeight = curHeight + 1;
                    maxCnt = 0;
                }
                if(maxHeight == curHeight + 1) {
                    maxCnt++;
                }
            }
        }
    }
    
    return maxCnt;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> adjMat(n);
    
    for(int i = 0; i < edge.size(); i++) {
        int n1 = edge[i][0] - 1;
        int n2 = edge[i][1] - 1;
        adjMat[n1].push_back(n2);
        adjMat[n2].push_back(n1);
    }
     answer = BFS(adjMat);
    
    return answer;
}