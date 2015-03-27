#include<stdio.h>
#include<math.h>
#define si 1000010

long long save[si];

int main()
{
	long long i,n,l,p,m,t,fg;
	for(i=0;i<=si-10;i++)
		save[i]=i*i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		l=sqrt(n);
		m=n/2;
		p=sqrt(m);
		if(save[l]==n||(p*p==save[p]&&2*p*p==n))
		{
			printf("Yes\n");
			continue;
		}
		fg=0;
		for(i=l;save[i]>=(n/2);i--)
		{
			p=n-save[i];
			m=sqrt(p);
			if(m*m+save[i]==n)
			{
				fg=1;
				break;
			}
		}
		if(fg)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}