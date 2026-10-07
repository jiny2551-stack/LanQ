//本身输入就是正方形矩阵，如果求和sum=n方说明他就是全1正方形因为sum等于此时的面积
#include<iostream>
#include <algorithm>
using namespace std;
int n,m;
int a[105][105];
int b[105][105];//前缀和数组
int ans;//最大的边长
int flag=0;//标记是否为1
//b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
int l;//边长
int sum;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==1)
            {
                flag=1;
            }
            b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
        }
    }
    if(flag==0)
    {
        cout<<0;
        return 0;
    }else{
        //最小是为1
        ans=1;
        //注意n和m取小的那个
        l=2;
        while(l<=min(n,m))
        {
            for(int i=l;i<=n;i++){
                for(int j=1;j<=m;j++){//枚举正方形右下角角标
                    sum=b[i][j]-b[i-l][j]-b[i][j-l]+b[i-l][j-l];
                    if(sum==l*l)
                    {
                        ans=max(ans,l);
                    }
                }
            }
            //同一轮l不能变阶
            l++;
        }
    }
    cout<<ans;
    return 0;
}