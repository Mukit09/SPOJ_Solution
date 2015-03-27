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
int i,j,l,n,cs=1,cnt,sm,fg;
char ch[25];

struct node
{
    bool ok;
    node *nxt[30];
    char st[25];

    node()
    {
        ok=false;
        int i;
        rep(i,0,26)
        nxt[i]=0;
    }
}*root;

void insert()
{
    node *nw=root;
    int i,j;
    rep(i,0,l)
    {
        j=ch[i]-97;
        if(!(nw->nxt[j]))
        nw->nxt[j]=new node();
        nw=nw->nxt[j];
    }
    nw->ok=true;
    strcpy(nw->st,ch);
}

void go(node *nw)
{
    int i,j;
    rep(i,0,26)
    {
        if(nw->nxt[i])
        {
            if(nw->nxt[i]->ok)
            {
                fg=1;
                printf("%s\n",nw->nxt[i]->st);
            }
            go(nw->nxt[i]);
        }
    }
}

void search()
{
    int i,j,fg=0;
    node *nw=root;
    rep(i,0,l)
    {
        j=ch[i]-97;
        if(nw->nxt[j])
        nw=nw->nxt[j];
        else
        break;
    }
    if(i==l)
    go(nw);
}

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

   	while(~scanf("%d",&n))
   	{
   	    root = new node();
   	    while(n--)
   	    {
   	        scanf("%s",ch);
   	        l=strlen(ch);
   	        insert();
   	    }
   	    scanf("%d",&n);
   	    while(n--)
   	    {
   	        scanf("%s",ch);
   	        printf("Case #%d:\n",cs++);
   	        fg=0;
   	        l=strlen(ch);
   	        search();
   	        if(!fg)
   	        puts("No match.");
   	    }
    }
   	return 0;
}
