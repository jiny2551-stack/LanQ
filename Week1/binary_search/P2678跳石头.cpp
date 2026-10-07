#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int s; // L
int m, n;
int d[50005];
// 终点石头单独考虑
int judge(int mid, int m, int n)
{
    int x = 0;
    int *now = &d[0], *next = &d[1];
    for (int i = 1; i <= n; i++)
    {
        if ((*next - *now) < mid)
        {
            x++;
            next++;
        }
        else
        {
            now = next;
            next++;
        }
    }
    // next == &d[n + 1]
    if ((*next - *now) < mid)
    {
        x++;
    }
    if (x <= m)
    {
        return 1;
    }
    return 0;
}

int main()
{
    cin >> s >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    // 起点
    d[0] = 0;
    // 终点
    d[n + 1] = s;
    int l = 1, r = s, mid = 0;
    int ans = 0;
    // 千万别忘了判断若没有石头的情况
    if (n == 0)
    {
        cout << s << endl;
        return 0;
    }

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (judge(mid, m, n))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}