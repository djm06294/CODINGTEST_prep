// 문제: 원형으로 이어져 있는 버스역 중 출발지에서 도착지까지 가는 단시간 구하기

// i의 범위에 따라 어떤 방향으로 갈때의 distance인지 파악해준 것이 똑똑하다. 그리고 나는 start가 dest보다 클 경우를 대비해서 i를 나눠줬는데, 그냥 start를 dest보다 작게 만들고 시작하는 것도 더 나은 것 같다.

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    int clockwise = 0;
    int counterclockwise = 0;

    if (start > destination)
      swap(start, destination);

    for (int i = 0; i < distance.size(); ++i) {
      if (i >= start && i < destination)
        clockwise += distance[i];
      else
        counterclockwise += distance[i];
    }

    return min(clockwise, counterclockwise);
    }
};