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
#define si 30010
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
int i,j,u,n,cs=1;
char ch[si];

struct ss
{
    int x,y;
}tree[si*3];

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

void build(int node,int lft,int rht)
{
    if(lft==rht)
    {
        if(ch[lft-1]=='(')
        tree[node].x=1,tree[node].y=0;
        else
        tree[node].x=0,tree[node].y=1;
        return;
    }
    int l,r,mid;
    l=node*2;
    r=l+1;
    mid=(lft+rht)/2;
    build(l,lft,mid);
    build(r,mid+1,rht);
    tree[node].x=tree[node].y=0;
    if(tree[l].x>=tree[r].y)
    tree[node].x=(tree[l].x-tree[r].y);
    else
    tree[node].y=(tree[r].y-tree[l].x);
    tree[node].x+=tree[r].x;
    tree[node].y+=tree[l].y;
}

void update(int node,int lft,int rht)
{
    if(u>rht||u<lft)
    return ;
    if(u==lft&&lft==rht)
    {
        if(tree[node].x==1)
        tree[node].x=0,tree[node].y=1;
        else
        tree[node].x=1,tree[node].y=0;
        return ;
    }
    int l,r,mid;
    l=node*2;
    r=l+1;
    mid=(lft+rht)/2;
    update(l,lft,mid);
    update(r,mid+1,rht);
    tree[node].x=tree[node].y=0;
    if(tree[l].x>=tree[r].y)
    tree[node].x=tree[l].x-tree[r].y;
    else
    tree[node].y=tree[r].y-tree[l].x;
    tree[node].x+=tree[r].x;
    tree[node].y+=tree[l].y;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int q;
   	while(~scanf("%d",&n))
   	{
   	 //   mem(tree,0);
   	    scanf("%s%d",ch,&q);
   	    build(1,1,n);
   	    printf("Test %d:\n",cs++);
		while(q--)
		{
		    scanf("%d",&u);
		    if(n&1==1&&!u)
            {
                continue;
            }
            else if(n&1==1)
            continue;
		    if(!u)
		    {
		        if(!tree[1].x&&!tree[1].y)
		        puts("YES");
		        else
		        puts("NO");
		    }
		    else
		    update(1,1,n);
		}
    }
   	return 0;
}

