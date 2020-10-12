#include <string>
#include <vector>
#include <stack>
#include <tuple>
#include <iostream>
using namespace std;


vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), -1);
    stack<tuple<int, int>> st;
    for (int i = 0; i < int(prices.size()); i++) {
        if (st.empty() || get<0>(st.top()) <= prices[i]) {
            st.push(make_pair(prices[i], i));
        }
        else {
            int idx = -1;
            while (!st.empty() && get<0>(st.top()) > prices[i]) {
                idx = get<1>(st.top());
                answer[idx] = i - idx;
                st.pop();
            }
            st.push(make_pair(prices[i], i));
        }
    }
    for (int i = 0; i < int(answer.size()); i++) {
        if (answer[i] != -1) {
            continue;
        }
        answer[i] = int(answer.size()) - i - 1;
    }

    return answer;
}