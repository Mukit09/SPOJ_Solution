		/****** BISMILLAHIR RAHMANIR RAHIM ********\

/*********************************************************************\
#   |--\     /--|  |           |   |	     -----  /-------------\   #
#   |   \   /   |  |           |   |    /      |           |          #
#   |    \ /    |  |           |   |  /        |           |          #
#   |           |  |           |   |/          |           |          #
#   |           |  |           |   |\          |           |          #
#   |           |  |           |   |  \        |           |          #
#   |           |   \         /    |    \      |           |          #
#  ---         ---   \______ /     |         -----       -----        #
#                                                                     #
#                                                                     #
#                                                                     #
#    			codeforces = Mukit09                                  #
#    			topcoder = mukitmkbs25                                #
#    			codechef = mukit_mkbs                                 #
#    			uva = mkbs_cse09                                      #
#    			spoj = mkbs_cse09                                     #
#    			CSE, CUET                                             #
#    facebook : https://www.facebook.com/hesitated.mkbs?ref=tn_tnmn   #
#                                                                     #
#                                                                     #
\*********************************************************************/

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
#define pb push_back
#define mpair make_pair
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < eps ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

typedef long long i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
i64 i,j,l,n,cs=1,cnt,sm,fg;

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
		ara[i+1]=1;
    }
}
*/

/*
struct P
{
    double x,y;
    P(double x=0,double y=0)
    {
        this->x=x;
        this->y=y;
    }
};

P MV(P aa,P bb) {return P(bb.x-aa.x,bb.y-aa.y);}  //Make Vector
double DP(P aa,P bb){return (aa.x*bb.x+aa.y*bb.y);} // Dot Product
double CP(P aa,P bb){return aa.x*bb.y-aa.y*bb.x;} // Cross Product
double VA(P aa){return sqrt(DP(aa,aa));} // Value of Vector aa
double TRIANGLE(P aa,P bb){return CP(aa,bb)/2.0;} // Area of Triangle using CP
P ROT(P aa,double rad){return P(aa.x*cos(rad)-aa.y*sin(rad),aa.x*sin(rad)+aa.y*cos(rad));}//Rotaion with rad
P VL(P aa,double len){double v=VA(aa);return P(aa.x*len/v,aa.y*len/v);}// Make Vector of 'len' length
*/

i64 u,v,s;
struct ss
{
    i64 sm,p;
}tree[si*3];

void build(i64 node,i64 lft,i64 rht)
{
    if(lft==rht)
    {
        tree[node].sm=tree[node].p=0;
        return ;
    }
    i64 lc,rc,m;
    lc=node<<1;
    rc=lc+1;
    m=(lft+rht)>>1;
    build(lc,lft,m);
    build(rc,m+1,rht);
    tree[node].sm=tree[node].p=0;
}

void update(i64 node,i64 lft,i64 rht)
{
    if(lft>v||rht<u)
    return;
    if(lft>=u&&rht<=v)
    {
        tree[node].p+=s;
        tree[node].sm+=(rht-lft+1)*s;
        return;
    }
    i64 lc,rc,m;
    lc=node<<1;
    rc=lc+1;
    m=(lft+rht)>>1;
    update(lc,lft,m);
    update(rc,m+1,rht);
    tree[node].sm=tree[lc].sm+tree[rc].sm+(rht-lft+1)*tree[node].p;
}

i64 query(i64 node,i64 lft,i64 rht,i64 tot)
{
    if(lft>v||rht<u)
    return 0;
    if(lft>=u&&rht<=v)
    return tree[node].sm+tot*(rht-lft+1);
    i64 lc,rc,m;
    lc=node<<1;
    rc=lc+1;
    m=(lft+rht)>>1;
    return query(lc,lft,m,tot+tree[node].p)+query(rc,m+1,rht,tot+tree[node].p);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    i64 t,q,chk;
    scanf("%lld",&t);
   	while(t--)
   	{
   	    scanf("%lld%lld",&n,&q);
   	    build(1,1,n);
   	    while(q--)
   	    {
   	        scanf("%lld%lld%lld",&chk,&u,&v);
   	        if(!chk)
   	        {
   	            scanf("%lld",&s);
   	            update(1,1,n);
   	        }
   	        else
            printf("%lld\n",query(1,1,n,0));
   	    }
    }
   	return 0;
}
