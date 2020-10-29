#include <iostream>
#include <vector>
using namespace std;

vector<int> S;
vector<bool> visited;

void Comb(int idx, int cnt) {
    if(cnt == 6) {
        for(int i = 0; i < visited.size(); i++) {
            if(visited[i]) {
                cout << S[i] << " ";
            }
        }
        cout << endl;
        return;
    }
    for(int i = idx; i < visited.size(); i++) {
        if(visited[i]) continue;
        visited[i] = true;
        Comb(i, cnt+1);
        visited[i] = false;
    }
}


int main(void) {
    while(1) {
        int k;
        cin >> k;
        if(k == 0) break;
        S.assign(k, 0);
        visited.assign(k, false);
        for(int i = 0; i < k; i++) {
            cin >> S[i];
        }
        Comb(0, 0);
        cout << endl;
    }
    return 0;
}