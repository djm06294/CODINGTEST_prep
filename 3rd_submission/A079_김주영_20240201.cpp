// 24.02.01 THU
// JOOYOUNG KIM
// https://school.programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(auto v:commands) {
        int i=v[0]-1, j=v[1]-1, k=v[2]-1;
        vector<int> tmpV;
        
        for(i ; i<=j; i++)
            tmpV.push_back(array[i]);
        
        sort(tmpV.begin(), tmpV.end());

        answer.push_back(tmpV[k]);
    }

    return answer;
}