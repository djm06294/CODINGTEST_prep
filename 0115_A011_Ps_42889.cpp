// 24.01.15 MON
// Jooyoung Kim
// https://school.programmers.co.kr/learn/courses/30/lessons/42889

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
typedef pair<float, int> p;

bool compare(p i, p j) {
    if (i.first > j.first) return true;
    else if(i.first == j.first) {   // 이 부분 없으면 몇개 사례가 틀림. 자동으로 정렬 안해주나봄.
        if(i.second < j.second) return true;
    }
    return false;

}

vector<int> solution(int N, vector<int> stages) {
    vector<p> sorting;
    vector<int> answer;
    int* cleared = new int[N]();
    int* Ncleared = new int[N]();

    for(auto& i: stages) {
        for(int j=0; j<i; j++) cleared[j]++;
        if(i!=N+1) Ncleared[i-1]++;
    }
    // cout<<"Cleared"<<endl;
    // for(int i=0; i<N; i++) {
    //     cout<<"ST"<<i+1<<" cl:" <<cleared[i]<<", ncl:" <<Ncleared[i]<< endl;
    // }


    for(int i=0; i<N; i++) {
        if(cleared[i]!=0) {
            sorting.push_back(make_pair(Ncleared[i]/(float)cleared[i], i));
        } else {
            sorting.push_back(make_pair(0.,i));
        }
    }
    sort(sorting.begin(), sorting.end(), compare);

    // cout<<endl;
    // for(auto& i: sorting) {
    //     cout << i.first << " " << i.second+1 << endl;
    // }

    for(auto& i: sorting) {
        answer.push_back(i.second+1);
    }

    return answer;
}

int main() {
    solution(4, {4,4,4,4,4});
}