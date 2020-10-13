#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;

bool cmpTuple(tuple<int, int, int> t1, tuple<int, int, int> t2) {
	if (get<1>(t1) == get<1>(t2)) {
		return get<2>(t1) < get<2>(t2);
	} else {
		return get<1>(t1) < get<1>(t2);
	}
}

tuple<int, int, int> findNextFish(vector<vector<int>> board, int shark_size, tuple<int, int> curPos) {
	vector<vector<bool>> flagBoard(board.size(), vector<bool>(board.size(), false));
	flagBoard[get<0>(curPos)][get<1>(curPos)] == true;

	vector<tuple<int, int, int>> nodes;
	nodes.push_back(make_tuple(get<0>(curPos), get<1>(curPos), 0));
	vector<int> dx{ -1, 0, 1, 0 };
	vector<int> dy{ 0, -1, 0, 1 };
	vector<tuple<int, int, int>> retVec;

	//BFS로 가장 가까운 먹을 수 있는 물고기 찾기
	int stopBranchCnt = -1;
	while (nodes.size() > 0) {
		tuple<int, int, int> curNode = nodes[0];
		int nextBranchCnt = get<2>(curNode) + 1;
		if (stopBranchCnt != -1 && stopBranchCnt < nextBranchCnt) {
			break;
		}
		
		for (int i = 0; i < 4; i++) {
			int nextX = get<0>(curNode) + dx[i];
			int nextY = get<1>(curNode) + dy[i];
			if (nextX < 0 || nextY < 0 || nextX >= board.size() || nextY >= board.size() ||
				board[nextX][nextY] == 9 || board[nextX][nextY] > shark_size ||
				flagBoard[nextX][nextY] == true) {
				continue;
			} else {
				if (board[nextX][nextY] > 0 && board[nextX][nextY] < shark_size) {
					stopBranchCnt = nextBranchCnt;
					retVec.push_back(make_tuple(nextBranchCnt, nextX, nextY));
				}
				nodes.push_back(make_tuple(nextX, nextY, nextBranchCnt));
				flagBoard[nextX][nextY] = true;
			}
		}
		nodes.erase(nodes.begin());
	}


	if (retVec.size() == 0) {
		return make_tuple(-1, -1, -1);
	} else {
		sort(retVec.begin(), retVec.end(), cmpTuple);
		return retVec[0];
	}
}

int main(void) {
	int time = 0;
	int N = 0;
	tuple<int, int> sharkPos;
	//freopen("input_아기_상어.txt", "r", stdin);
	cin >> N;
	vector<vector<int>> board(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				sharkPos = make_pair(i, j);
			}
		}
	}

	int shark_size = 2;
	int countForSizeUp = 0;
	int i = 0; 
	while (true) {
		tuple<int, int, int> retFineNextFish = findNextFish(board, shark_size, sharkPos);
		if (get<0>(retFineNextFish) == -1) {
			break;
		} else {
			time += get<0>(retFineNextFish);
			board[get<0>(sharkPos)][get<1>(sharkPos)] = 0;
			sharkPos = make_pair(get<1>(retFineNextFish), get<2>(retFineNextFish));
			board[get<0>(sharkPos)][get<1>(sharkPos)] = 9;
			countForSizeUp++;
			if (countForSizeUp == shark_size) {
				shark_size++;
				countForSizeUp = 0;
			}
		}
	}

	cout << time;
	return 0;
}