#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define inf 9999999
#define si 2010
queue<int>q;
vector<int>ve[si];

int visit[si],cst[si],fg;

void bfs(int node)
{
	int c,d,l,i;
	q.push(node);
	while(!q.empty())
	{
		c=q.front();
		visit[c]=1;
		l=ve[c].size();
		for(i=0;i<l;i++)
		{
			d=ve[c][i];
			if(visit[d]==0)
			{
				visit[d]=1;
				q.push(d);
				if(cst[d]==0)
					cst[d]=cst[c]+1;
				else
					cst[d]=cst[c]-1;
			}
			else if(cst[c]==cst[d])
				fg=0;
		}
		q.pop();
	}
}

int main()
{
	int t,i,n,e,u,v,k=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&e);
		for(i=1;i<=n;i++)
		{
			visit[i]=0;
			cst[i]=inf;
			ve[i].clear();
		}
		for(i=1;i<=e;i++)
		{
			scanf("%d%d",&u,&v);
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		fg=1;
		for(i=1;i<=n;i++)
		{
			if(visit[i]==0)
			{
				cst[i]=0;
				bfs(i);
			}
			if(!fg)
				break;
		}
		printf("Scenario #%d:\n",k++);
		if(fg)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
	}
	return 0;
}