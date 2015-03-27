#include<stdio.h>
#include<math.h>

int main()
{
	int t,xr,n,a,cnt,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		xr=cnt=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			xr=xr^a;
			if(a==1)
				cnt++;
		}
		if(cnt==n&&cnt%2==1)
			printf("Brother\n");
		else if(cnt==n&&cnt%2==0)
			printf("John\n");
		else if(xr)
			printf("John\n");
		else 
			printf("Brother\n");
	}
	return 0;
}