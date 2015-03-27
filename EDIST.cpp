#include<stdio.h>
#include<string.h>
#define si 3005
#define min(a,b) (a<b?a:b)
int dp[si][si],l1,l2;
char ch1[si],ch2[si];

int rec(int i,int j)
{
	if(i<0&&j<0)
		return 0;
	else if(i<0||j<0)
		return i<0?(j+1):(i+1);
	int &ret=dp[i][j];
	if(ret!=-1)
		return ret;
	ret=rec(i,j-1)+1;
	ret=min(ret,rec(i-1,j)+1);
	if(ch1[i]==ch2[j])
		ret=min(ret,rec(i-1,j-1));
	else
		ret=min(ret,rec(i-1,j-1)+1);
	return ret;
}

int main()
{
	int i,j,t;
	scanf("%d",&t);
	while(getchar()!='\n');
	while(t--)
	{
		gets(ch1);
		gets(ch2);
		l1=strlen(ch1);
		l2=strlen(ch2);
		for(i=0;i<l1;i++)
		{
			for(j=0;j<l2;j++)
				dp[i][j]=-1;
		}
		printf("%d\n",rec(l1-1,l2-1));
	}
	return 0;
}