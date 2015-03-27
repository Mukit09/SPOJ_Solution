#include<stdio.h>
#define si 1010
#define inf 1<<30
#define min(a,b) (a<b ?a:b)
int mx_o,mx_n,n,dp[si][25][81],ox[si],ni[si],w[si];

int rec(int ind,int tk_o,int tk_n)
{
	if(ind>n)
	{
		if(tk_o>=mx_o&&tk_n>=mx_n)
			return 0;
		return inf;
	}

	if(tk_o>=mx_o&&tk_n>=mx_n)
		return 0;
	if(dp[ind][tk_o][tk_n]!=-1)
		return dp[ind][tk_o][tk_n];
	int p=inf;

	p=min(p,rec(ind+1,tk_o,tk_n));
	p=min(p,w[ind]+rec(ind+1,tk_o+ox[ind]>mx_o?mx_o:tk_o+ox[ind],tk_n+ni[ind]>mx_n?mx_n:tk_n+ni[ind]));
	return dp[ind][tk_o][tk_n]=p;
}

int main()
{
	int t,i,j,k,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&mx_o,&mx_n);
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&ox[i],&ni[i],&w[i]);
			for(j=0;j<=mx_o;j++)
				for(k=0;k<=mx_n;k++)
					dp[i][j][k]=-1;
		}
		ans=rec(1,0,0);
		printf("%d\n",ans);
	}
	return 0;
}