#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m;
int b[5005][5005];
int sumb[5005][5005];
int x1,x2,y1,y2;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x1>>y1>>x2>>y2;
        b[x1][y1]+=1;
        b[x2+1][y1]-=1;
        b[x1][y2+1]-=1;
        b[x2+1][y2+1]+=1;
    }
    long r=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sumb[i][j]=sumb[i][j-1]+sumb[i-1][j]-sumb[i-1][j-1]+b[i][j];
            r+=((i+j)^sumb[i][j]);
        }
    }
    cout<<r;
    return 0;
}
