// 문제: 원형으로 이어져 있는 버스역 중 출발지에서 도착지까지 가는 단시간 구하기.

// 두 방향 다 계산 할 필요 없이, 한 방향을 계산했으면 나머지 거리를 합한게 다른 방향이므로 총 거리에서 빼줬다는 부분이 똑똑했다!

class Solution {
public:
int distanceBetweenBusStops(vector<int>&distance,int start,int destination) {
        int n=distance.size(),sum=0,remainingSum=0;
        if(start>destination) swap(start,destination);
        for(int i=start;i<destination;i++) sum+=distance[i];
        for(int x:distance) remainingSum+=x;
        remainingSum-=sum;
        return min(sum,remainingSum);
    }
};