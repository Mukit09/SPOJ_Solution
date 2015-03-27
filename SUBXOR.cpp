        /****** BISMILLAHIR RAHMANIR RAHIM ********\

/*********************************************************************\
#   |--\     /--|  |           |   |         -----  /-------------\   #
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
#               codeforces = Mukit09                                  #
#               topcoder = Mukit09                                    #
#               codechef = mukit_mkbs                                 #
#               uva = Mukit09                                         #
#               spoj = mkbs_cse09                                     #
#               CSE, CUET                                             #
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
int i,j,l,n,cs=1,cnt,sm,fg,a[si],k;

struct node
{
    node *nxt[2];
    int lft,rht;

    node()
    {
        lft=rht=0;
        nxt[0]=nxt[1]=0;
    }
}*root;

void insert(node *nw,int v,int bit)
{
    if(bit<0)
    return;
    int chk=(1<<bit)&v;
    chk=chk?1:0;
    if(!(nw->nxt[chk]))
    nw->nxt[chk]=new node();
    insert(nw->nxt[chk],v,bit-1);
    if(chk)
    nw->rht++;
    else
    nw->lft++;
}

int query(node *nw, int v, int bit)
{
    if(bit<0 || !nw)
    return 0;
    int kk=(1<<bit)&k;
    int vv=(1<<bit)&v;
    if(kk)
    {
        if(vv)
        return nw->rht+query(nw->nxt[0],v,bit-1);
        else
        return nw->lft+query(nw->nxt[1],v,bit-1);
    }
    else
    {
        if(vv)
        return query(nw->nxt[1],v,bit-1);
        else
        return query(nw->nxt[0],v,bit-1);
    }
}

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

    int t;
    scanf("%d",&t);
   	while(t--)
   	{
   	    scanf("%d%d",&n,&k);
   	    root = new node();

   	    insert(root,0,19);
		i64 xr=0,ans=0;
		fr(i,1,n)
		{
		    scanf("%d",&a[i]);
		    xr^=a[i];
		    ans+=query(root,xr,19);
		    insert(root,xr,19);
		}
		printf("%lld\n",ans);
    }
   	return 0;
}
