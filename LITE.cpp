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
#    codeforces = Mukit09                                             #
#    topcoder = mukitmkbs25                                           #
#    codechef = mukit_mkbs                                            #
#    uva = mkbs_cse09                                                 #
#    spoj = mkbs_cse09                                                #
#    usaco = mukitmk1                                                 #
#    CSE, CUET                                                        #
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
int i,j,l,n,cs=1,cnt,sm,fg,a[si],u,v;
char ch[si];

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
    int sm,x;
}tree[si*3];

void build(int node,int lft,int rht)
{
    if(lft==rht)
    {
        tree[node].x=tree[node].sm=0;
        return;
    }
    int lc,rc,m;
    m=(lft+rht)/2;
    lc=node*2;
    rc=l+1;
    build(lc,lft,m);
    build(rc,m+1,rht);
    tree[node].sm=tree[node].x=0;
}

void update(int node,int lft,int rht)
{
    if(u>rht||v<lft)
    return;
    if(lft>=u&&rht<=v)
    {
        tree[node].x=1-tree[node].x;
        tree[node].sm=rht-lft+1-tree[node].sm;
        return;
    }
    int m,lc,rc;
    m=(lft+rht)/2;
    lc=node*2;
    rc=lc+1;
    update(lc,lft,m);
    update(rc,m+1,rht);
    if(tree[node].x)
    tree[node].sm=rht-lft+1-tree[lc].sm-tree[rc].sm;
    else
    tree[node].sm=tree[lc].sm+tree[rc].sm;
}

int query(int node,int lft,int rht,int ii,int jj)
{
    if(lft>jj||rht<ii)
    return 0;
    if(lft>=u&&rht<=v)
    return tree[node].sm;
    int lc,rc,m,ret;
    m=(lft+rht)/2;
    lc=node*2;
    rc=lc+1;

    if(m<ii)
    ret=query(rc,m+1,rht,ii,jj);
    else if(m>=jj)
    ret=query(lc,lft,m,ii,jj);
    else
    {
        ret=query(lc,lft,m,ii,m);
        ret+=query(rc,m+1,rht,m+1,jj);
    }
    if(tree[node].x)
    return jj-ii+1-ret;
    return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int m;
   	while(~scanf("%d%d",&n,&m))
   	{
   	    sm=cnt=0;
		fg=1;
		build(1,1,n);
		while(m--)
		{
		    int chk;
		    scanf("%d%d%d",&chk,&u,&v);
		    if(!chk)
		    update(1,1,n);
		    else
		    {
		        int ans=query(1,1,n,u,v);
		        printf("%d\n",ans);
		    }
		}
    }
   	return 0;
}
