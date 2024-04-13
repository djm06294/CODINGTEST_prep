// 문제: 문자열 s에 등장하지 않는 알파벳 대문자의 아스키 코드 값의 합을 구하기.

// a 행렬에 각 알파벳의 존재여부를 저장한다. 그 후에 a 행렬의 값이 1 인경우 세지 않고, 0인 경우 세도록 구현하였다.

#include <stdio.h>

int main ()
{
	int  n, sum, i, j;
	char s[1050];
	
	scanf ("%d", &n);
	for (i=1;i<=n;i++)
	{
		int a[100]={};
		sum=0;
		scanf ("%s", s);
		for(j=0;s[j]!='\0';j++)
		{
			a[s[j]]=1;
		}
		for(j=65;j<=90;j++)
		{
			sum=sum+j*(1-a[j]);
		}
		printf ("%d\n",sum);
	}
}