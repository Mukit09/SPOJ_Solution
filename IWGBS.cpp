/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 1275 (10334 - Ray Through Glasses) */
/* SUBMISSION: 09572386 */
/* SUBMISSION TIME: 2011-12-18 15:52:05 */
/* LANGUAGE: 3 */

#include<stdio.h>
#include<string.h>

int main()
{
	char *fibo[10005]={0};
	fibo[0]="1";
	fibo[1]="2";
	int l1=strlen(fibo[0]);
	int l2=strlen(fibo[1]);
	long i,l;
	for(i=2;i<=10005;i++)
	{
		char str[10005];
		if(l1>=l2)
		{
			l=l1;
		}
		else
		{
			l=l2;
		}
		int ca=0;
		long j,k,m,p;
		for(j=l1-1,k=l2-1,m=0,p=0;p<l;j--,k--,m++,p++)
		{
			int s1;
			if(j<0)
			{
				fibo[i-2][j]='0';
			}
			s1=fibo[i-2][j]-48;
			int s2;
			if(k<0)
			{
				fibo[i-1][k]='0';
			}
			s2=fibo[i-1][k]-48;
			int ans=0;
			ans+=s1+s2+ca;
			if(ans>9)
			{
				str[m]=(ans-10)+48;
				ca=1;
			}
			else
			{
				str[m]=ans+48;
				ca=0;
			}
		}
		if(ca>0)
		{
			str[m]=ca+48;
			m++;
		}
		str[m]='\0';
		fibo[i]=new char[m+1];
		long y=0,x;
		for(x=m-1;x>=0;x--,y++)
		{
			fibo[i][y]=str[x];
		}
		fibo[i][y]='\0';
		l1=strlen(fibo[i-1]);
		l2=strlen(fibo[i]);
	}
	long n;
	while(scanf("%ld",&n)!=EOF)
	{
		printf("%s\n",fibo[n]);
	}

	return 0;
}
/*
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;

// Define Some Variables
#define eps 1e-14
#define si 1010
#define pi acos(-1.0)
#define inf (1<<30)-1
#define mod 1000000000 //10^9

//Define Some Functions
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

typedef __int64 i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int i,j,l,n,x=1,cnt,sm,fg,dp[si][2];

i64 bmod(i64 a,i64 b)
{
    if(b==0)
        return 1;
    i64 x=bmod(a,b/2);
    x=(x*x)%mod;
    if(b%2==1)
        x=(x*a)%mod;
    return x;
}

int gcd(int a,int b)
{
    while(b>0)
    {
        a%=b;
        a^=b;
        b^=a;
        a^=b;
    }
    return a;
}


i64 lcm(i64 a,i64 b)
{
	return ((a*b)/gcd(a,b));
}

int rec(int cnt,int dig)
{
    if(cnt==n)
    return 1;
    int &ret=dp[cnt][dig];
    if(ret!=-1)
    return ret;
    if(!dig)
    ret=rec(cnt+1,1);
    else
    {
        int p=rec(cnt+1,0);
        int q=rec(cnt+1,1);
        ret=p+q;
      //  ret=1+rec(cnt+1,0)+rec(cnt+1,1)+1;
    }
    return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

   	while(~scanf("%d",&n))
   	{
   	    mem(dp,-1);
   	    int ans=rec(1,1)+rec(1,0);
   	    printf("%d\n",ans);
    }
   	return 0;
}
*/
