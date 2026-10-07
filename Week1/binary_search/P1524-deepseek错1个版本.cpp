#include <iostream>
#include <iomanip>   // 必须包含，用于输出保留两位小数
#include <algorithm> // 用于 max 函数
using namespace std;

const int MAXN = 200005;
double x[MAXN], y[MAXN], s[MAXN];

// 不用自己写 max 了，algorithm 里的 std::max 支持 double
// 如果一定要自己写，注意参数类型是 double
double my_max(double a, double b)
{
    return a > b ? a : b;
}

// 判断函数：当速度为 v 时，能否按时送达
int judge(double v, int n)
{
    double leave_time = 0.0; // 出发地离开时间为 0

    for (int i = 1; i <= n; i++)
    {
        // 1. 计算到达第 i 个地点的时间
        double arrive_time = leave_time + s[i] / v;

        // 2. 超过最晚签收时间，速度太慢，失败
        if (arrive_time > y[i])
        {
            return 0;
        }

        // 3. 根据到达时间决定离开时间
        if (arrive_time <= x[i])
        {
            // 到得太早，必须等到 x[i] 才能离开
            leave_time = x[i];
        }
        else
        {
            // 到达时间在合法区间内，签收完立刻走
            leave_time = arrive_time;
        }
    }
    return 1; // 全部成功
}

int main()
{
    // 输入加速，防止 TLE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i] >> s[i];
    }

    // 二分速度，初始范围设为极小到极大
    double l = 1e-4, r = 1e9, mid;

    // 固定循环 100 次，精度足够，绝无 TLE
    for (int i = 0; i < 100; i++)
    {
        mid = (l + r) / 2.0;

        if (judge(mid, n))
        {
            // 速度足够快，尝试更慢的速度（向 l 逼近）
            r = mid;
        }
        else
        {
            // 速度太慢，必须加快（向 r 逼近）
            l = mid;
        }
    }

    // 输出答案
    // 关键点：+ 1e-9 是为了修正浮点数运算误差，保证四舍五入到正确的两位小数
    cout << fixed << setprecision(2) << r + 1e-9 << endl;

    return 0;
}