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
#define distance(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

//typedef __int64 i64;

int i,j,l,n,x=1,cnt,sm,fg,a[si];
char ch[si];

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

int main()
{
	int k;
	while(gets(ch))
	{
		if(strcmp(ch,"00e0")==0)
			break;
		n=(ch[0]-48)*10+(ch[1]-48);
		int m=ch[3]-48;
		FOR(i,1,m)
			n*=10;
		int ans=0;
		k=1;
		int i;
		for(i=0;;i++)
		{
			if(ans+k>n)
				break;
			ans+=k;
			k*=2;
		}
		m=n-ans;
		int res;
		if(!m)
		{
			res=n;
			goto prnt;
		}
		res=m*2-1;
prnt:
		printf("%d\n",res);
	}
	return 0;
}