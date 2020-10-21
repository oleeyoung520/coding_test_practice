#include <iostream>
#include <vector>
using namespace std;
 
int N, M, H;
int ans = 4;
vector<vector<bool>> ladder;
 
 
bool ladderGame(void) {
    for (int i = 1; i <= N; i++) {
        int marker = i;
        for (int j = 1; j <= H; j++) {
            if (ladder[marker][j]) marker++;
            else if (ladder[marker-1][j]) marker--;
        }
        if (marker != i) return false;
    }
    return true;
}
 
void addLine(int idx, int cnt) {
    if (cnt > 3) return;
    
    if (ladderGame()) {
        ans = (ans > cnt)? cnt: ans;
        return;
    }
 
    for (int i = idx; i <= H; i++) {
        for (int j = 1; j < N; j++) {
            if (ladder[j][i]) continue;
            if (ladder[j-1][i]) continue;
            if (ladder[j+1][i]) continue;
            ladder[j][i] = true;
            addLine(i, cnt+1);
            ladder[j][i] = false;
        }
    }
}
                            
int main(void) {
    cin >> N >> M >> H;
    ladder.assign(N+1, vector<bool>(H+2, false));
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ladder[b][a] = true;
    }
    addLine(1, 0); 
    if (ans == 4) ans = -1;
    cout << ans << endl;

    return 0;
}