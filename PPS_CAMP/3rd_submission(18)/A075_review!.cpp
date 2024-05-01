// 문제: 합쳐서 가장 큰 수를 생성하기
// 살짝 이해못한 코드
// four 함수가 어떤 의미를 가지고 돌아가는지 이해가 잘 안된다.
// 숫자의 우선순위를 자리수에 따라 다른 계산을 함으로서 나타낸 것 같다.
// 정답 출력시에 int를 string으로 변환하기 위해 중간에 stringstream을 사용했다는 것이 특이하다.

// stringstream의 쓰임새가 궁금하다.

#include <string>
#include <vector>
#include <sstream>
using namespace std;

int four(int n) {
    if (n > 999)
        return n;
    else if (n > 99)
        return n * 10 + n / 100;
    else if (n > 9)
        return n * 101;
    else if (n > 0)
        return n * 1111;
    else
        return 0;
}
string solution(vector<int> numbers) {
    string answer = "";
    int zero = 0;
    for (int n : numbers)   // 0 개수 세어주기
        if (!n) ++zero;
    if (zero == numbers.size()) // 모두 0이면 0 반환
        return "0";

    for (int i = 1; i < numbers.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (four(numbers[i]) > four(numbers[j])) 
                swap(numbers[i], numbers[j]);
        }
    }
    for (int n : numbers) {
        stringstream s;
        s << n;
        string c = s.str();
        answer += c;
    }
    return answer;
}