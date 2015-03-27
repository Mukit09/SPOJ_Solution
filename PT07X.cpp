#include<stdio.h>
#include<vector>
#define si 100010
#define min(a,b) (a<b ?a:b)
using namespace std;
vector<long>ve[si];
long dp[si][5],par[si];

long rec(long node,long fg)
{
	if(ve[node].size()==0)
		return 1;
	if(dp[node][fg]!=-1)
		return dp[node][fg];
	long i,u,sm=0;
	for(i=0;i<ve[node].size();i++)
	{
		u=ve[node][i];
		if(u!=par[node])
		{
			par[u]=node;
			if(fg)
				sm+=min(rec(u,0),rec(u,1));
			else
				sm+=rec(u,1);
		}
	}
	dp[node][fg]=fg+sm;
	return dp[node][fg];
}

int main()
{
	long n,i,u,v,sm;
	while(~scanf("%ld",&n))
	{
		for(i=1;i<n;i++)
		{
			scanf("%ld%ld",&u,&v);
			ve[u].push_back(v);
			ve[v].push_back(u);
			dp[i][0]=dp[i][1]=par[i]=-1;
		}
		dp[i][0]=dp[i][1]=par[i]=-1;
		sm=min(rec(1,0),rec(1,1));
		printf("%ld\n",sm);
		for(i=1;i<=n;i++)
			ve[i].clear();
	}
	return 0;
}