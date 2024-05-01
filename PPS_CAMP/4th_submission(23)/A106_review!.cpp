// 문제: 문자열 s에 등장하지 않는 알파벳 대문자의 아스키 코드 값의 합을 구하기.

// r은 모든 대문자 아스키 코드를 합한 값이고, 문자열에 존재하는 char의 아스키 코드를 빼주는 식으로 구현했다. 짧게 구현한 것이 특징 인 것 같다.

// 왜 cstido를 사용한건지 궁금함.

#include <cstdio>

int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		char s[1001];
		int a[99] = { 0, },r=2015;
		scanf("%s", s);
		for (int i = 0; s[i]; i++) if(!a[s[i]]) a[s[i]]=1,r-=s[i];
		printf("%d\n", r);
	}
	return 0;
}