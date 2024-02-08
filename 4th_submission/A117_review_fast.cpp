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