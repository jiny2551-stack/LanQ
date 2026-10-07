#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 100005;
double x[MAXN], y[MAXN], s[MAXN];
// 最大速度最小化->二分最大速度-
/*
没必要>二分最小时间；而且到达时间≠离开时间
用上一个离开时间和v计算出的到达时间应该和到达时间比
*/
/*发现存在ym<yn,当m>n时，不能全部取最晚时间，也不能简单的从后往前推算，因为你保证了后面一个时间长就
可能导致前面时间短，但是变短的那个路程万一他的 s 很小会导致你错过了最大值
4 9，6 10，7 8；6 7 8 10;所以不如按照确定递增的x来算r的初始值*/
// 一直超时
double max(double a, double b)
{
    return a > b ? a : b;
}
double min(double a, double b)
{
    return a < b ? a : b;
}
int judge(double mid, int n)
{
    double leave_time = 0, arrive_time;
    for (int i = 1; i <= n; i++)
    {
        arrive_time = leave_time + s[i] / mid;
        if (arrive_time <= x[i])
        {
            leave_time = max(leave_time, x[i]);
            // leave_time=x[i];
        }
        else if (arrive_time > y[i])
        {
            return 0;
        }
        else
        {
            // 在区间内立刻走
            leave_time = arrive_time;
        }
    }
    return 1;
}
int main()
{
    int n;
    cin >> n;
    double l = 1e-4, r = 1e9, mid;
    x[0] = 0, y[0] = 0;
    int ans;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i] >> s[i];
        // double temp = max(0, y[i] - x[i - 1]);
        // maxtime = min(r, temp);
    }

    while (l < r)
    {
        // 保留2位小数
        mid = (l + r) / 2.00;
        mid = floor(mid * 1000) / 1000.0;
        if (judge(mid, n))
        { // 速度太大了->算出的到达时间 小于等于 最早到达时间
            r = mid;
            ans = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << ans << endl;
    return 0;
}
