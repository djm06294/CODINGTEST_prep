// 24.04.18 THU
// JooYoung Kim
// "[S/W 문제해결 기본] 1일차 - Flatten"
// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV139KOaABgCFAYh&categoryId=AV139KOaABgCFAYh&categoryType=CODE&problemTitle=&orderBy=RECOMMEND_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=1

#include <iostream>
#include <set>
#include <fstream>
using namespace std;

void printBoxes(multiset<int> & boxes, int dump) {
    cout<<endl<<dump<<endl;
    for(auto i:boxes) cout<<i<<" ";
    cout<<endl;
} 

int dumping(multiset<int> & boxes, int dump) {
    
    for(int i=0; i<dump; i++) {
        int min, max;
        min = *(boxes.begin());
        max = *(--boxes.end());

        if(max-min <= 1)
            return max-min;
        
        boxes.erase(boxes.begin());
        boxes.erase(--boxes.end());

        boxes.insert(min+1);
        boxes.insert(max-1);
        // cout<<boxes.size()<<endl;
        // printBoxes(boxes, dump);
    }

    return *(--boxes.end()) - *(boxes.begin());
}

int main() {
    ifstream txtfile("C:\\Users\\jooyoung\\Downloads\\input.txt", ios_base::in);
    if(txtfile.is_open())
        cin.rdbuf(txtfile.rdbuf());

    for(int t=1; t<=10; t++) {
        multiset<int> boxes;
        int dump;
        cin>>dump;

        for(int i=0; i<100; i++) {
            int tmp;
            cin>>tmp;
            boxes.insert(tmp);
        }

        int ans = dumping(boxes, dump);
        cout<<"#"<<t<<" "<<ans<<"\n";
    }
}