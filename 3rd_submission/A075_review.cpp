// 이해못한 코드

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
    for (int n : numbers)
        if (!n) ++zero;
    if (zero == numbers.size())
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