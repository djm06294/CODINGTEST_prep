// 24.01.21 SUN
// JooYoung Kim
// https://www.acmicpc.net/problem/17211

#include <iostream>
#include <bitset>
using namespace std;

int main() {
    unsigned int N, today_mood;
    float GG, GB,BG, BB;
    float G_sum=0., B_sum=0.;
    cin>>N>>today_mood;
    cin>>GG>>GB>>BG>>BB;

    __uint128_t moods = 0;  //최대 101일
    moods = today_mood << N;
    __uint128_t max = (2^N-1)|(today_mood<<N);//오늘 제외한 모든날이 bad

    int i=1;
    float tmp = 1.;
    while(moods <= max) {
        cout<<"i"<<i<<" ";
        cout<< bitset<2>((moods>>N-i) % 0b100) << endl;
        switch ((moods>>N-i) % 0b100) {
            case 0b00: tmp *= GG; break;
            case 0b01: tmp *= GB; break;
            case 0b10: tmp *= BG; break;
            case 0b11: tmp *= BB; break;
        } 
        if(i++==N) {    //i==N인지 확인하고 i++
            
            if(moods%2 == 0) {
                G_sum+=tmp;
                // cout<<"Gtmp"<<tmp<<endl;
            } else {
                B_sum+=tmp;
                // cout<<"Btmp"<<tmp<<endl;
            }
            i=1;
            tmp = 1.;
            moods++;
        }
    }

    cout<<(int)(G_sum*1000)<<endl;
    cout<<(int)(B_sum*1000)<<endl;
}
