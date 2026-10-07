#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
ull base=131;

struct data
{
    ull x,y;
}a[10010];

char s[10010];
int n,ans=1;
ull mod1=19260817;
ull mod2=19660813;

ull hash1(char s[])
{
    int len=strlen(s);
    ull ans=0;
    for (int i=0;i<len;i++)
        ans=(ans*base+(ull)s[i])%mod1;
    return ans;
}

ull hash2(char s[])
{
    int len=strlen(s);
    ull ans=0;
    for (int i=0;i<len;i++)
        ans=(ans*base+(ull)s[i])%mod2;
    return ans;
}

bool comp(data a,data b)
{
    return a.x<b.x;
}

main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s);
        a[i].x=hash1(s);
        a[i].y=hash2(s);
    }
    sort(a+1,a+n+1,comp);
    for (int i=2;i<=n;i++)
        if (a[i].x!=a[i-1].x || a[i-1].y!=a[i].y)
            ans++;
    printf("%d\n",ans);
    return 0;
}

