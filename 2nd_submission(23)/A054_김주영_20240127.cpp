// 24.01.27 SAT
// JooYoung Kim
// https://school.programmers.co.kr/learn/courses/30/lessons/64061

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> basket;
    int answer = 0;

    for(auto& i:moves) {
        int tmp = -1;

        for(auto& j:board) {
            if(j[i] == 0) continue;
            else {
                tmp = j[i];
                j[i] = 0;
                break;                
            }
        }

        if(tmp == -1) continue;

        if(basket.empty() || basket.back()!=tmp) {
            basket.push_back(tmp);
        } else {
            answer+=2;
            basket.pop_back();
        }
    }
    
    return answer;
}