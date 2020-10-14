#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;

int main(void) {
	int N = 0;

	//freopen("input_Επ»η.txt", "r", stdin);
	cin >> N;

	vector<tuple<int, int>> tpVec;
	for (int i = 0; i < N; i++) {
		int T, P;
		cin >> T >> P;
		tpVec.push_back(make_pair(T, P));
	}

	vector<int> maxPrice(N, 0);
	for (int i = N - 1; i >= 0; i--) {
		int end_time = i + get<0>(tpVec[i]) - 1;
		int curPrice = get<1>(tpVec[i]);

		if (end_time >= N) {
			continue;
		} else if(end_time + 1 == N) {
			maxPrice[i] = curPrice;
		} else {
			maxPrice[i] = curPrice + *max_element(maxPrice.begin() + end_time + 1, maxPrice.end());
		}
	}
	cout << *max_element(maxPrice.begin(), maxPrice.end());
	return 0;
}