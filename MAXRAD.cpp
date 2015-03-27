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

//typedef __int64 i64;
typedef long long i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int i,j,fg,n,k1,k2;

double res[si];

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

/*
int ara[si],cnt_p=1,pr[si];

void sieve()
{
	int num=si-5,i,j,root;
	root=sqrt(num);
	pr[cnt_p++]=2;
	ara[1]=1;
	for(i=3;i<=num;i=i+2)
	{
		if(ara[i]==0)
		{
		    pr[cnt_p++]=i;
			if(i<=root)
			{
				for(j=i*i;j<=num;j+=2*i)
					ara[j]=1;
			}
		}
    }
}
*/

struct ss
{
    double x,y;

}stru[si];

bool cmp(ss aa,ss bb)
{
    if(fabs(aa.x-bb.x)<eps)
    return aa.y<bb.y;
    return aa.x<bb.x;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int t;
    scanf("%d",&t);
   	while(t--)
   	{
   	    scanf("%d",&n);
		fg=1;
		rep(i,0,n)
        scanf("%lf%lf",&stru[i].x,&stru[i].y);
		sort(stru,stru+n,cmp);

		double d1,d2,mx=0.0,mn1,mn2,p,q,r,s;

		rep(i,0,n)
		{
		    mn1=9999999.0;
		    mn2=9999999.0;
		    rep(j,i+1,n)
		    {
		        p=stru[i].x;
		        q=stru[i].y;
		        r=stru[j].x;
		        s=stru[j].y;
                d1=sqrt((p-r)*(p-r)+(q-s)*(q-s));
                d2=d1/2.0;
                if(d2<1.0)
                {
                    fg=0;
                    break;
                }
                d1=d1-1.0;
                if(mn1>d1)
                {
                    mn1=d1;
                    k1=j;
                }
            }
            rev(j,i-1,0)
            {
                p=stru[i].x;
		        q=stru[i].y;
		        r=stru[j].x;
		        s=stru[j].y;
                d1=sqrt((p-r)*(p-r)+(q-s)*(q-s));
                d2=d1/2.0;
                if(d2<1.0)
                {
                    fg=0;
                    break;
                }
                d1=d1-1.0;
                if(mn2>d1)
                {
                    mn2=d1;
                    k2=j;
                }
            }
            if(!fg)
            break;
            if(mn1>mn2)
            mn1=mn2;

            if(mx<mn1)
            mx=mn1;
		}

		if(!fg)
        puts("-1.000000");
        else
		printf("%lf\n",mx+eps);
    }
   	return 0;
}
