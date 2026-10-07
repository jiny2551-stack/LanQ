#include <iostream>
#include <algorithm>
// sort(a,a+n)--nlogn
#include <iostream>
#include <algorithm>
// sort(a, a+n) -- nlogn
using namespace std;
const int MAXN = 100005;
int s[MAXN];
int e[MAXN];
int first[MAXN];
int last[MAXN];
// 找到最后一个 < j的下标-个数
int last_less(int *a, int n, int j)
{
    int l = 0, r = n - 1;
    int ans = -1; // 初始化为 -1，表示没找到
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] < j)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans + 1; // 下标加 1 就是个数,如果 ans=-1，返回 0
}
// 找到第一个 > j的下标 ans
int first_greater(int *a, int n, int j)
{
    int l = 0, r = n - 1;
    int ans = n; // 初始化为 n，表示没找到
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] > j)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return n - ans; // 总数减去下标就是个数,如果 ans=n，返回 0
}
int main()
{
    int n, m;
    cin >> n >> m;

    int cnt = 0; // 非空弹幕的数量（跳过 b==0 的空弹幕）
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (b == 0)
        {
            continue; // 持续0秒：空区间，永远不会出现在视野，忽略
        }
        s[cnt] = a;
        e[cnt] = a + b;
        cnt++;
    }

    sort(s, s + cnt);
    sort(e, e + cnt);

    for (int j = 0; j < m; j++)
    {
        int x, y;
        cin >> x >> y;
        if (y == 0)
        {
            cout << 0 << endl; // 观测持续0秒：空区间，答案恒为0
            continue;
        }
        int f = x;
        int l = x + y;
        int result = cnt - last_less(e, cnt, f + 1) - first_greater(s, cnt, l - 1);
        cout << result << endl;
    }

    return 0;
}
/*
#include <iostream>
#include <algorithm>
// sort(a,a+n)--nlogn
#include <iostream>
#include <algorithm>
// sort(a, a+n) -- nlogn
using namespace std;
const int MAXN = 100005;
int s[MAXN];
int e[MAXN];
int first[MAXN];
int last[MAXN];
// 找到最后一个 < j的下标-个数
int last_less(int *a, int n, int j)
{
    int l = 0, r = n - 1;
    int ans = -1; // 初始化为 -1，表示没找到
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] < j)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans + 1; // 下标加 1 就是个数,如果 ans=-1，返回 0
}
// 找到第一个 > j的下标 ans
int first_greater(int *a, int n, int j)
{
    int l = 0, r = n - 1;
    int ans = n; // 初始化为 n，表示没找到
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] > j)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return n - ans; // 总数减去下标就是个数,如果 ans=n，返回 0
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> e[i];
        e[i] = s[i] + e[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> first[i] >> last[i];
        last[i] = first[i] + last[i];
    }

    sort(s, s + n);
    sort(e, e + n);

    for (int j = 0; j < m; j++)
    {
        int f = first[j];
        int l = last[j];
        int result = n - last_less(e, n, f + 1) - first_greater(s, n, l - 1);
        cout << result << endl;
    }

    return 0;
}

*/