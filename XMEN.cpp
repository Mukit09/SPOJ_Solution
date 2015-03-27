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
#define distance(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

//typedef __int64 i64;

int i,j,l,n,x=1,a[si],cur,in[si];
map<int,int>mp;

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

void b_search(int lo,int hi,int val)
{
	int mid;
	while(lo<=hi)
	{
		mid=(lo+hi)/2;
		if(in[mid]<val)
			lo=mid+1;
		else
			hi=mid-1;
	}
	in[lo]=val;
}
int main()
{
	int t,u;
	scanf("%d",&t);
   	while(t--)
   	{
		scanf("%d",&n);
		j=1;
		FOR(i,1,n)
		{
			scanf("%d",&a[i]);
			mp[a[i]]=j++;
		}
		j=1;
		FOR(i,1,n)
		{
			scanf("%d",&u);
			if(mp[u])
				a[j++]=mp[u];
		}
		cur=0,i=1;
		in[cur++]=a[i++];
		while(i<=n)
		{
			if(in[cur-1]<a[i])
				in[cur++]=a[i];
			else
				b_search(0,cur-1,a[i]);
			i++;
		}
		printf("%d\n",cur);
		mp.clear();
    }
   	return 0;
}