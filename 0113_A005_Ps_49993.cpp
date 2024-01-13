// 24.01.13 SAT
// Jooyoung Kim
// https://school.programmers.co.kr/learn/courses/30/lessons/49993

#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for(auto& skillT:skill_trees) {
        int idx=0;
        cout << endl << skillT << endl;
        
        for(auto& c:skill) {
            // skill not found
            if(skillT.find(c) == string::npos) {
                idx = skillT.length(); // 다음 스킬 배울 수 없음
                continue;
            }
            
            // skill found
            cout << c << " found at " << skillT.find(c) << endl;
            if(idx > skillT.find(c)) {
                answer--;
                break;
            }
            idx = skillT.find(c);
        }

        answer++;
        cout << "ans" << answer << endl;
    }
    return answer;
}

int main() {
    string skill = "CBD";
    vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};
    cout<<solution(skill, skill_trees);
}