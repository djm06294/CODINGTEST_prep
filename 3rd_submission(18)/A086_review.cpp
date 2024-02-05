// 문제: 숫자를 영어로 읽었을 때 사전순으로 정렬하기

// 모든 숫자 알파벳을 map으로 정의하고 시작했다는 부분이 코드를 깔끔하게 만드는 것 같다.
// sort의 cmp함수 내에서 영단어로 변경 후 비교까지 모든 작업이 일어나게 해준 것이 깔끔하다.

// 한줄 if문(?:문)이 어떤 변수에 넣을 값을 선택할 때도 사용 가능하다는 것을 처음 알게 되었다. (18-19줄)

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<int, string> m = {
  {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"},
  {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, {0, "zero"}
};

bool cmp(int a, int b) {
  string sa = (a / 10) ? m[a / 10] + " " + m[a % 10] : m[a % 10];
  string sb = (b / 10) ? m[b / 10] + " " + m[b % 10] : m[b % 10];
  return sa < sb;
}

void solve(void) {
  int m, n; cin >> m >> n;
  vector<int> v;
  for (int i=m; i<=n; i++) v.push_back(i);
  sort(v.begin(), v.end(), cmp);

  for (int i=0; i<v.size(); i++) {
    cout << v[i] << " ";
    if (i % 10 == 9) cout << "\n";
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}