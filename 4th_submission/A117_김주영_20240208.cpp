// 24.02.08 THU
// JOOYOUNG KIM
// https://leetcode.com/problems/distance-between-bus-stops/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int dist1=0, dist2=0;

        for(int i=start; i!=destination; i=(i+1)%n) {
            dist1 += distance[i];
            cout<<"1:"<<i<< " " << dist1<<endl;
        }
        
        for(int i=destination; i!=start; i=(i+1)%n) {
            dist2 += distance[i];
            cout<<"2:"<<i<< " " << dist2<<endl;
        }

        return dist1<dist2 ? dist1 : dist2;
    }
};

int main() {
    Solution s;
    vector<int> v = {1,2,3,4};
    cout<<s.distanceBetweenBusStops(v, 0,1);
}