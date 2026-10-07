// n/3=m……a--m+a/3=b……c--b+c/3=d……e
//+m+b+……直到整除为止或者就是商为0，除几次加几次除数
#include <iostream>
using namespace std;
long ms(long n)
{
    long m = n / 3, k = n % 3;
    long sum = m;
    while (k != 0)
    {
        n += m;
        sum += k;
        m = sum / 3;
        k = sum % 3;
    }
    return n;
}
int main()
{
    long n;
    cin >> n;
    long l = 1, r = n;
    long ans;

    while (l <= r)
    {
        long mid = (l + r) / 2;
        long result = ms(mid);
        if (result >= n)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int buy = 1; // 从买 1 根开始尝试
    while (true) {
        int total = 0;   // 总共吃到的冰棍数
        int sticks = 0;  // 手上的木棒数
        int current = buy; // 当前这一轮能吃到的冰棍数
        while (current > 0) {
            total += current;       // 吃掉这些冰棍
            sticks += current;      // 获得同样数量的木棒

            current = sticks / 3;   // 每 3 个木棒换 1 根新冰棍
            sticks = sticks % 3;    // 兑换后剩下的木棒
        }
        // 如果买 buy 根，吃到的总数 >= 目标 n，说明 buy 就是答案
        if (total >= n) {
            cout << buy << endl;
            break;
        }
        buy++; // 否则，尝试多买 1 根
    }
    return 0;
}
*/
/*
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int k;
    cin>> k;

    int n;
    int m = n / 3,k = n % 3;
    int sum = m;
    while (m != 0)
    {
        n += m;
        sum += k;
        m = sum / 3;
        k = sum % 3;
    }
    cout << n << endl;
    return 0;
}*/