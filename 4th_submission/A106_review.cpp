#include<cstdio>
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