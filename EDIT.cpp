#include<stdio.h>
#include<string.h>
#define min(a,b) (a<b?a:b)
char ch[1003];
int main()
{
	int l,i;
	while(gets(ch))
	{
		l=strlen(ch);
		int cst1=0;
		for(i=0;i<l;i++)
		{
			if(i%2==0)
			{
				if(ch[i]>=65&&ch[i]<=90)
					cst1++;
			}
			else
			{
				if(ch[i]>=97&&ch[i]<=122)
					cst1++;
			}
		}
		int cst2=0;
		for(i=0;i<l;i++)
		{
			if(i%2==1)
			{
				if(ch[i]>=65&&ch[i]<=90)
					cst2++;
			}
			else
			{
				if(ch[i]>=97&&ch[i]<=122)
					cst2++;
			}
		}
		printf("%d\n",min(cst1,cst2));
	}
	return 0;
}