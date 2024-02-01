// C++98로 푼 답
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