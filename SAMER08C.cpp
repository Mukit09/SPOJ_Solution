
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
#define si 100010
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
int i,j,l,n,x=1,cnt,sm,fg,a[si],dp[si],res[si],m;


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

int rec(int ind)
{
    if(ind>m)
    return 0;
    int &ret=dp[ind];
    if(ret!=-1)
    return ret;
    ret=a[ind]+rec(ind+2);
    ret=max(ret,rec(ind+1));
    return ret;
}

int rec_col(int ind)
{
    if(ind>n)
    return 0;
    int &ret=dp[ind];
    if(ret!=-1)
    return ret;
    ret=res[ind]+rec_col(ind+2);
    ret=max(ret,rec_col(ind+1));
    return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
  	while(~scanf("%d%d",&n,&m)&&(n||m))
   	{
		sm=cnt=0;
		fg=1;
		fr(i,1,n)
		{
		    fr(j,1,m)
		    {
                scanf("%d",&a[j]);
                dp[j]=-1;
		    }
            res[i]=rec(1);
		}
		fr(i,1,n)
		dp[i]=-1;
		printf("%d\n",rec_col(1));
    }
   	return 0;
}
