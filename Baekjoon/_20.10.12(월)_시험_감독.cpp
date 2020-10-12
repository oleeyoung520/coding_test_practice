//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
	long long answer = 0;
	int N;
	//freopen("input_시험_감독.txt", "r", stdin);
	cin >> N;
	
	vector<int> A(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	int B, C;
	cin >> B >> C;
	
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		answer++;
		if (A[i] > 0) {
			answer += ceil((double)A[i] / (double)C);
		}
	}

	cout << answer;
	
	return 0;
}