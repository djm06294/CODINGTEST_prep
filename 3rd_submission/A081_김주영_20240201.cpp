// 24.02.01 THU
// JOOYOUNG KIM
// https://www.acmicpc.net/problem/2693

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;

    while(T--) {
        vector<int> v;
        for(int i=0; i<10; i++) {
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end(), greater<>());

        cout<<v[2]<<endl;
    }
}

// C++98로 푼 답
// #include <stdio.h>
// #include <algorithm>

// int main() {
//     int a[10], t;
//     scanf("%d", &t);
//     while (t--) {
//         for (int i = 0; i < 10; i++)
//             scanf("%d", a + i);
//         std::sort(a, a + 10);
//         printf("%d\n", a[7]);
//     }
// }