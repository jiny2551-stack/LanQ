#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
ull base=131;
ull a[10010];//第i个字符串对应的哈希值
char s[10010];
int n,ans=1;
ull hashs(char *s){
    ull ans=0;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        //注意要类型转换
        ans=ans*base+(ull)s[i];
    }
    return ans;

}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        a[i]=hashs(s);
    }
    //求出N个字符串中共有多少个不同的字符串
    //先排序，再找和前一个一样的字符有几个
    sort(a+1,a+n+1);//对数组a，标从1 ~ n的元素排
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}