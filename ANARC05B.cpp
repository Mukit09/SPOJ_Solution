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
#define si 10010
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

typedef long long i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int i,j,l,n,m,b[si],a[si],dp[si][3];
map<int,int>mp1,mp2;

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

int rec(int ind,int chk)
{
    if(chk==1&&ind>n)
    return 0;
    if(chk==2&&ind>m)
    return 0;
    int &ret=dp[ind][chk];
    if(ret!=-1)
    return ret;
    int x;
    if(chk==1)
    {
        ret=a[ind]+rec(ind+1,1);
        x=mp2[a[ind]];
        if(x)
        ret=max(ret,a[ind]+rec(x+1,2));
    }
    else
    {
        ret=b[ind]+rec(ind+1,2);
        x=mp1[b[ind]];
        if(x)
        ret=max(ret,b[ind]+rec(x+1,1));
    }
    return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

   	while(~scanf("%d",&n)&&n)
   	{
		fr(i,1,n)
		{
			scanf("%d",&a[i]);
			mp1[a[i]]=i;
		}
		scanf("%d",&m);
		fr(i,1,m)
		{
		    scanf("%d",&b[i]);
		    mp2[b[i]]=i;
		}
		mem(dp,-1);
		int ans=max(rec(1,1),rec(1,2));
		printf("%d\n",ans);
		mp1.clear();
		mp2.clear();
    }
   	return 0;
}
