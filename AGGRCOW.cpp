#include<stdio.h>
#include<algorithm>
using namespace std;

#define rep(i,a,b) for(i=a;i<b;i++)

int a[100010],n,c;

 bool can(int tmp)
{
    int i,nw=a[0],cTmp=c-1;

    for(i=1;i<n;i++)
    {
        if(nw+tmp>a[i])
            continue;
        nw=a[i];
        cTmp--;
    }
    return cTmp<=0;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i;
        scanf("%d%d",&n,&c);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int lo=0,hi=a[n-1],mid,j,ans=0;
        i=0;
        while(i<=200)
        {
            i++;
            mid=(lo+hi)/2;
            if(can(mid))
            {
                ans=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
