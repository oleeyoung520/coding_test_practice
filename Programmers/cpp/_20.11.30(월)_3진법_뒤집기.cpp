#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    string tenToThree = "";
    while(n != 0) {
        tenToThree += to_string(n % 3);
        n /= 3;
    }
    
    int threePow = 1;
    for(int i = tenToThree.length() - 1; i >= 0; i--) {
        answer += ((int)tenToThree[i] - '0')* threePow;
        // cout << tenToThree[i] << " " << threePow << "=>"<< atoi(tenToThree[i].c_str) * threePow << endl;
        threePow *= 3;
    }
    
    return answer;
}