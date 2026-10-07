// int minEatingSpeed(vector<int>& piles, int h)
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

long getTime(vector<int> &piles, int mid)
{
    int n = piles.size();
    long time = 0;
    for (int i = 0; i < n; i++)
    {
        time += piles[i] / mid;
        if (piles[i] % mid != 0)
        {
            time++;
        }
    }
    return time;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int l = 1;
    int r, mid;
    long time;
    int ans;
    int n = piles.size();
    r = piles[0];
    for (int i = 1; i < n; i++)
    {
        r = max(r, piles[i]);
    }
    while (l <= r)
    {
        mid = (l + r) / 2;
        time = getTime(piles, mid);
        if (time <= h)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> piles;
    int n, h, a;
    cin >> n >> h;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        piles.push_back(a);
    }
    int ans = minEatingSpeed(piles, h);
    cout << ans << endl;
    return 0;
}
