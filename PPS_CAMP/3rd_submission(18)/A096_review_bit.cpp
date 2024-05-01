// 문제: 주어진 unsigned int를 2진수로 생각했을 때 1의 개수 구하기.

// bit에 대한 문제인만큼 bit 연산자를 사용하면 속도 / 메모리가 빨라 /적어지는 것 같다.
// &(AND) 연산자랑 >>(shift) 연산자를 사용해서 구현했다.

#include <iostream>
#include <stdint.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;
        while(n!=0){
            if(n&1){
                count++;
            }
            n = n>>1;
        }
        return count;
    }
};