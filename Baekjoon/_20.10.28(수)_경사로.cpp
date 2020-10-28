#include <iostream>
#include <vector>
using namespace std;

int N, L;
int answer = 0;
vector<vector<int>> map;

void checkRoad(vector<int> &road) {
    vector<bool> slope(N, false);
    int j;
    for(j = 1; j < N; j++) {
        int prev = road[j-1];
        if(slope[j] || road[j] == prev) continue;
        else if(road[j] - prev == 1) {
            // 증가
            if(j-L < 0) break;
            bool flag = false;
            for(int k = j-1; k >= j-L; k--) {
                if(road[k] != prev || slope[k]) {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            else {
                for(int k = j-1; k >= j-L; k--) {
                    slope[k] = true;
                }
            }
        } else if(prev - road[j] == 1) {
            // 감소
            if(j-1+L >= N) break;
            bool flag = false;
            for(int k = j; k <= j-1+L; k++) {
                if(road[k] != road[j] || slope[k]) {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            else {
                for(int k = j; k <= j-1+L; k++) {
                    slope[k] = true;
                }
            }
        } else {
            break;
        }
    }
    if(j == N) {
        answer++;
    }
}

int main(void) {
    cin >> N >> L;
    map.assign(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    // 가로
    for(int i = 0; i < N; i++) {
        vector<int> road = map[i];
        checkRoad(road);
    }
    // 세로
    for(int i = 0; i < N; i++) {
        vector<int> road;
        for(int j = 0; j < N; j++) {
            road.push_back(map[j][i]);
        }
        checkRoad(road);
    }

    cout << answer << endl;
    return 0;
}