// C++98로 푼 답
// 문제: 세번째 큰 수 찾기

// std::sort가 array도 적용가능하다는 것을 알고 간다!
// 원리는 비슷한듯.
#include <stdio.h>
#include <algorithm>

int main() {
    int a[10], t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 10; i++)
            scanf("%d", a + i);
        std::sort(a, a + 10);
        printf("%d\n", a[7]);
    }
}