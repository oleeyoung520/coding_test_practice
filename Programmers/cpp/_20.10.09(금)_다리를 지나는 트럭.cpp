#include <string>
#include <vector>
#include <queue>
#include <tuple>
//#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 1;
    int onWeight = 0;
    queue<tuple<int, int>> truck_on_bridge;
    // 0: time, 1: truck ¹«°Ô

    for (int i = 0; i < int(truck_weights.size()); i++) {
        int curWeight = truck_weights[i];
        if (!truck_on_bridge.empty() && get<0>(truck_on_bridge.front()) == time) {
            onWeight -= get<1>(truck_on_bridge.front());
            truck_on_bridge.pop();
        }
        if (onWeight + curWeight > weight) {
            time = get<0>(truck_on_bridge.front());
            i--;
            continue;
        }
        else {
            onWeight += curWeight;
            truck_on_bridge.push(make_pair(time + bridge_length, curWeight));
            time++;
        }
    }
    if (!truck_on_bridge.empty()) {
        time = get<0>(truck_on_bridge.back());
    }

    return time;
}