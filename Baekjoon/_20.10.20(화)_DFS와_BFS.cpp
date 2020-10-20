#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

void DFS(vector<vector<int>> adjMat, int start, int N) {
	stack<int> st;
	vector<bool> visited(N, false);
	st.push(start);
	cout << start + 1;
	visited[start] = true;
	while (!st.empty()) {
		int v = st.top();
		bool flag = false;
		for (int i = 0; i < adjMat[v].size(); i++) {
			if (visited[adjMat[v][i]]) {
				continue;
			} else {
				st.push(adjMat[v][i]);
				cout << " " << adjMat[v][i] + 1;
				visited[adjMat[v][i]] = true;
				flag = true;
				break;
			}
		}
		if (!flag) {
			st.pop();
		}
	}
}

void BFS(vector<vector<int>> adjMat, int start, int N) {
	queue<int> qu;
	vector<bool> visited(N, false);
	qu.push(start);
	cout << start + 1;
	visited[start] = true;
	while (!qu.empty()) {
		int v = qu.front();
		qu.pop();

		for (int i = 0; i < adjMat[v].size(); i++) {
			if (visited[adjMat[v][i]]) {
				continue;
			} else {
				qu.push(adjMat[v][i]);
				cout << " " << adjMat[v][i] + 1;
				visited[adjMat[v][i]] = true;
			}
		}
	}
}

int main(void) {
	int answer = 0;
	int N, M, V;
	//freopen("input_DFS¿Í_BFS.txt", "r", stdin);
	cin >> N >> M >> V;
	V--;
	vector<vector<int>> adjMat(N);
	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		adjMat[n1-1].push_back(n2-1);
		adjMat[n2-1].push_back(n1-1);
	}
	for (int i = 0; i < N; i++) {
		sort(adjMat[i].begin(), adjMat[i].end());
	}
	DFS(adjMat, V, N);
	cout << endl;
	BFS(adjMat, V, N);

	return 0;
}