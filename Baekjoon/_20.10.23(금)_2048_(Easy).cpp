#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX_CASE 5
using namespace std;


vector<vector<int>> allCase;
void DFS(int cnt, vector<int> dirCase) {
	if (cnt == MAX_CASE) {
		allCase.push_back(dirCase);
		return;
	} 
	for (int i = 0; i < 4; i++) {
		dirCase[cnt] = i;
		DFS(cnt + 1, dirCase);
	}
	return;
}

vector<int> swipeDir(vector<vector<int>> board, int dir, int i) {
	int jStart, jEnd, j;
	if (dir % 2 == 0) {
		jStart = board.size() - 1;
		jEnd = -1;
		j = -1;
	} else {
		jStart = 0;
		jEnd = board.size();
		j = 1;
	}
	vector<vector<int>> newRowVec;
	vector<int> newRow;
	while(jStart != jEnd) {
		int b = (dir < 2) ? board[i][jStart] : board[jStart][i];
		jStart += j;
		if (b == 0) {
			continue;
		} else {
			if (newRow.size() > 0 && b == newRow.back()) {
				newRow.pop_back();
				newRow.push_back(b * 2);
				newRowVec.push_back(newRow);
				newRow.clear();
			} else {
				newRow.push_back(b);
			}
		}
		
	}
	newRowVec.push_back(newRow);
	vector<int> retVec;
	for (int i = 0; i < newRowVec.size(); i++) {
		for (int nr : newRowVec[i]) {
			retVec.push_back(nr);
		}
	}
	while (retVec.size() < board.size()) {
		retVec.push_back(0);
	}
	return retVec;
}

vector<vector<int>> play2048(vector<vector<int>> board, int dir) {
	// dir; 0: µ¿, 1: ¼­, 2: ³², 3: ºÏ
	int N = board.size();
	for (int i = 0; i < N; i++) {
		vector<int> newRow = swipeDir(board, dir, i);

		if (dir == 0) {
			for (int j = N - 1; j >= 0; j--) {
				board[i][j] = newRow[N - 1 - j];
			}
		} else if (dir == 1) {
			for (int j = 0; j < N; j++) {
				board[i][j] = newRow[j];
			}
		} else if (dir == 2) {
			for (int j = N - 1; j >= 0; j--) {
				board[j][i] = newRow[N - 1 - j];
			}
		} else {
			for (int j = 0; j < N; j++) {
				board[j][i] = newRow[j];
			}
		}
		
	}
	return board;
}


int main(void) {
	int N;
	//freopen("input_2048_(Easy).txt", "r", stdin);
	cin >> N;
	vector<vector<int>> board(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}


	vector<int> dirCase(MAX_CASE);
	DFS(0, dirCase);

	int answer = 0;
	for (int i = 0; i < allCase.size(); i++) {
		int maxVal = 0;
		vector<vector<int>> newBoard = board;
		vector<int> dirCase = allCase[i];
		for (int d : dirCase) {
			newBoard = play2048(newBoard, d);			
		}
		vector<int> tmp;
		for (vector<int> nb : newBoard) {
			tmp.push_back(*max_element(nb.begin(), nb.end()));
		}
		maxVal = *max_element(tmp.begin(), tmp.end());
		answer = (answer < maxVal) ? maxVal : answer;
	}
	cout << answer;
	return 0;
}