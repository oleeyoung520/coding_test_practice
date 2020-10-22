#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < int(scoville.size()); i++) {
        pq.push(scoville[i]);
    }
    while(pq.top() < K) {
        if(int(pq.size()) < 2) {
            return -1;
        }
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        pq.push(min1 + 2*min2);
        answer++;
    }

    return answer;
}
